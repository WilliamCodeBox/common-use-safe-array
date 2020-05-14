#if !defined(COUSAR_ARRAY_H)
#define COUSAR_ARRAY_H

#include "types.hpp"

namespace cousar {
class Vector2d {
  public:
    Vector2d();
    Vector2d(const scalar &x, const scalar &y);

    /* Getters */

    /* Setters */
    void set(const Vector2d &v);
    void set(const scalar &x, const scalar &y);

    Vector2d &operator=(Vector2d const &v);
    Vector2d &operator+=(Vector2d const &v);
    Vector2d &operator-=(Vector2d const &v);
    Vector2d &operator*=(scalar a);
    Vector2d &operator/=(scalar a);

    friend Vector2d operator+(const Vector2d &v1, const Vector2d &v2);
    friend Vector2d operator+(const Vector2d &v, const scalar &a);
    friend Vector2d operator+(const scalar &a, const Vector2d &v);

    friend Vector2d operator-(const Vector2d &v1, const Vector2d &v2);
    friend Vector2d operator-(const Vector2d &v, const scalar &a);

    friend scalar operator*(const Vector2d &v1, const Vector2d &v2);
    friend Vector2d operator*(const Vector2d &v, const scalar &a);
    friend Vector2d operator*(const scalar &a, const Vector2d &v);

    friend Vector2d operator/(const Vector2d &v, const scalar &a);

  private:
    scalar m_x;
    scalar m_y;
};
} // namespace cousar

#endif // COUSAR_ARRAY_H
