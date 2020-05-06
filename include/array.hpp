#if !defined(COUSAR_ARRAY_H)
#define COUSAR_ARRAY_H

#include <cstdint>
#include <cstring>
#include <memory>

#include "exception.hpp"

namespace cousar {
template <typename T>
class Array {
    //*******************************************************************
    //* Constructors and Destructors
    //*******************************************************************
   public:
    Array()
        : m_len(0),
          m_rows(0),
          m_cols(0),
          m_resize_chunk(2),
          m_data(nullptr),
          m_capacity(0) {}
    Array(int64_t capacity)
        : m_len(0),
          m_rows(0),
          m_cols(0),
          m_resize_chunk(2),
          m_data(nullptr),
          m_capacity(capacity) {}

    Array(const Array<T>& arr)
        : m_len(0),
          m_rows(arr.m_rows),
          m_cols(arr.m_cols),
          m_data(nullptr),
          m_resize_chunk(arr.m_resize_chunk),
          m_capacity(0) {
        copy(arr);
    }

    ~Array() {
        delete[] m_data;
        m_data = nullptr;
    }

    //*******************************************************************
    //* Getters and Setters
    //*******************************************************************
    int64_t size() const { return m_len; }
    int64_t rows() const { return m_rows; }
    int64_t cols() const { return m_cols; }
    int64_t resize_chunk() const { return m_resize_chunk; }
    int64_t capacity() const { return m_capacity; }

    //*******************************************************************
    //* Operators overloading
    //*******************************************************************

    //*******************************************************************
    //* Public Member Methods
    //*******************************************************************
    void resize(int64_t new_capacity) {
        if (new_capacity > m_capacity) {
            m_capacity = new_capacity + m_resize_chunk;
            try {
                T* new_data = new T[m_capacity];
                // copy the original data into the new array
                if (m_len != 0) {
                    std::memcpy(new_data, m_data, m_len * sizeof(T));
                    std::copy()
                }
                // deallocate the original memory
                // free it
                delete[] m_data;
                // then point to the new created array
                m_data = new_data;
                new_data = nullptr;
            } catch (const std::bad_alloc& e) {
                throw new Exception("Out of memory!");
            }
        } else {
            throw new Exception(
                "Resize to smaller capacity, could loss original data.");
        }
        m_len = new_capacity;
    }

    void resize(int64_t n_rows, int64_t n_cols) {
        m_rows = n_rows;
        m_cols = n_cols;
        resize(m_rows * m_cols);
    }

    //*******************************************************************
    //* Member Variables
    //*******************************************************************
   private:
    int64_t m_len;
    int64_t m_rows;
    int64_t m_cols;
    int64_t m_resize_chunk;

    T* m_data;
    int64_t m_capacity;

    //*******************************************************************
    //* Private Member Methods
    //*******************************************************************
    void copy(const Array<T>& arr) {
        if (arr.m_rows == 0) {
            resize(arr.m_len);
        } else {
            resize(arr.m_rows, arr.m_cols);
        }
        m_data = new T[m_len];

        for (int64_t i = 0; i < m_len; i++) {
            m_data[i] = arr.m_data[i];
        }
    }
};
}  // namespace cousar

#endif  // COUSAR_ARRAY_H
