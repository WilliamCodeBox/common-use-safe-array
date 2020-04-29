#if !defined(COUSAR_ARRAY_H)
#define COUSAR_ARRAY_H

#include <cstdint>
#include <memory>

#include "exception.hpp"

namespace cousar {
template <typename T>
class Array {
   public:
    Array()
        : m_len(0),
          m_rows(0),
          m_cols(0),
          m_resize_chunk(2),
          m_data(nullptr),
          m_data_size(0) {}
    Array(int64_t size)
        : m_len(0),
          m_rows(0),
          m_cols(0),
          m_resize_chunk(2),
          m_data(nullptr),
          m_data_size(0) {}

    ~Array() {
        if (m_own_data) {
            delete[] m_data;
            m_data = nullptr;
        }
    }

    void resize(int64_t new_size) {
        if (new_size > m_data_size) {
            m_data_size = new_size + m_resize_chunk;
            try {
                T* new_data = new T[m_data_size];
                std::make_unique<T>(new_data);

                // copy the original data into the new array
                if (m_len != 0) {
                    std::memcpy(new_data, m_data, m_len * sizeof(T));
                }
                // set to nullptr
                delete[] m_data;
                // then point to the new created array
                m_data = std::move(new_data);
            } catch (const std::bad_alloc& e) {
                throw new Exception("Out of memory!");
            }
        }
        m_len = new_size;
    }

   private:
    int64_t m_len;
    int64_t m_rows;
    int64_t m_cols;
    int64_t m_resize_chunk;

    std::unique_ptr<T>* m_data;
    int64_t m_data_size;
};
}  // namespace cousar

#endif  // COUSAR_ARRAY_H
