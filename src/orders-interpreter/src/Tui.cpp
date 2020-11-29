#include <orders-interpreter/Tui.hpp>

template <typename... Args>
struct overloaded : Args...
{
    using Args::operator()...;
};

oi::Tui::Tui(const std::string& records_file_path, const orders_source& src) : records_file_path_(records_file_path), src_(src) {}
