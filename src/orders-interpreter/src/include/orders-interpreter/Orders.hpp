#ifndef ORDERS_HPP
#define ORDERS_HPP

#include <map>
#include <string_view>
#include <utility>

using namespace std::string_view_literals;

namespace oi
{
enum class EOperation
{
    WRITE_RECORD,
    READ_RECORD,
    DISPLAY_IN_ORDER_OF_KEY,
    REORGANIZE_FILE,
};

const std::string& to_string(EOperation e);
EOperation to_enum(const std::string& str);
}  // namespace oi

#endif  // ORDERS_HPP