#ifndef TUI_HPP
#define TUI_HPP

#include <string>
#include <variant>
#include <type_traits>

namespace oi
{
using orders_file_path = std::string;
using orders_from_prompt = struct command_prompt
{
};
using orders_source = std::variant<orders_file_path, orders_from_prompt>;

class Tui
{
   public:
    Tui(const std::string & records_file_path, const orders_source& src);

   private:
    orders_source src_;
    std::string records_file_path_;
};
}  // namespace oi

static_assert(std::is_copy_assignable<oi::Tui>());
static_assert(std::is_copy_constructible<oi::Tui>());
static_assert(std::is_move_assignable<oi::Tui>());
static_assert(std::is_move_constructible<oi::Tui>());

#endif TUI_HPP