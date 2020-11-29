#include <orders-interpreter/Orders.hpp>

const std::map<oi::EOperation, std::string> orders = {{oi::EOperation::WRITE_RECORD, "write"},
                                                      {oi::EOperation::READ_RECORD, "read"},
                                                      {oi::EOperation::DISPLAY_IN_ORDER_OF_KEY, "display"},
                                                      {oi::EOperation::REORGANIZE_FILE, "reorganize"}};

const std::string& oi::to_string(EOperation e) { return orders.at(e); }

oi::EOperation oi::to_enum(const std::string& str)
{
    return std::find_if(orders.begin(), orders.end(), [&](const auto& pair) { return str == pair.second; })
        ->first;
}
