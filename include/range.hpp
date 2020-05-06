#if !defined(COUSAR_RANGE_H)
#define COUSAR_RANGE_H

#include <memory>
#include <vector>

namespace cousar {
template <typename T, typename Allocator = std::allocator<T>>
class Range : public std::vector<T, Allocator> {
   public:
    typedef typename std::vector<T, Allocator>::value_type value_type;
    typedef typename std::vector<T, Allocator>::reference reference;
    typedef typename std::vector<T, Allocator>::const_reference const_reference;
};
}  // namespace cousar

#endif  // COUSAR_RANGE_H
