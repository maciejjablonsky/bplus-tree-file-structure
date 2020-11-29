#ifndef ORDERS_INTERPRETER_HPP
#define ORDERS_INTERPRETER_HPP

#include <variant>
#include <string>
#include <vector>
#include <orders-interpreter/Orders.hpp>
#include <type_traits>

namespace oi
{
using order = std::string;
using orders_vector = std::vector<order>;

class Interpreter
{
   public:
    Interpreter(const orders_vector& src);
    void operator()();

   private:
    std::vector<oi::EOperation> orders_;
};
}  // namespace oi

static_assert(std::is_copy_assignable<oi::Interpreter>());
static_assert(std::is_copy_constructible<oi::Interpreter>());
static_assert(std::is_move_assignable<oi::Interpreter>());
static_assert(std::is_move_constructible<oi::Interpreter>());

#endif  // ORDERS_INTERPRETER_HPP