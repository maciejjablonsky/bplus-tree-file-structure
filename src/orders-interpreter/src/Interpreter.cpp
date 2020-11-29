#include <Interpreter.hpp>
#include <orders-interpreter/Tui.hpp>
#include <algorithm>

template <typename OutputContainer, typename InputIt, typename UnaryOperation>
OutputContainer transform_and_create(InputIt begin, InputIt end, UnaryOperation operation)
{
    OutputContainer container;
    std::transform(std::forward<InputIt>(begin), std::forward<InputIt>(end), container.begin(), std::forward<UnaryOperation>(operation));
    return container;
}

oi::Interpreter::Interpreter(const orders_vector& orders)
    : orders_(transform_and_create<std::vector<oi::EOperation>>(
          orders.begin(), orders.end(), [&](const oi::order& o) { return oi::to_enum(o); }))
{
}