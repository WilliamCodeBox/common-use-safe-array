#if !defined(COUSAR_ARRAY_H)
#define COUSAR_ARRAY_H

#include <cstdint>

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
          m_data_size(0),
          m_own_data(true) {}
    Array(int64_t size)
        : m_len(0),
          m_rows(0),
          m_cols(0),
          m_resize_chunk(2),
          m_data(nullptr),
          m_data_size(0),
          m_own_data(true) {}

    ~Array() {
        if (m_own_data) {
            delete[] m_data;
            m_data = nullptr;
        }
    }

   private:
    int64_t m_len;
    int64_t m_rows;
    int64_t m_cols;
    int64_t m_resize_chunk;

    T* m_data;
    int64_t m_data_size;
    bool m_own_data;
};
}  // namespace cousar

#endif  // COUSAR_ARRAY_H
