#include <fmt/format.h>
#include <cxxopts.hpp>
#include <orders-interpreter/Tui.hpp>
#include <tuple>

auto define_options(const std::string_view program_name)
{
    cxxopts::Options opts(program_name.data(), "Client app for b+tree file structure");
    opts.add_options()                                                                        /**/
        ("i,input", "Path to file containing index structure", cxxopts::value<std::string>()) /**/
        ("o,orders", "Path to file with orders to execute, if not given interactive prompt is used",
         cxxopts::value<std::string>()) /**/
        ("h,help", "Print help") /**/;
    return opts;
}

auto unpack_required_options(cxxopts::ParseResult& parse_result)
{
    return std::tuple{
        [&]() {
            if (parse_result.count("input") == 0)
            {
                throw cxxopts::option_required_exception("--input is needed to access database file");
            }
            return parse_result["input"].as<std::string>();
        }(),

        [&]() -> oi::orders_source {
            if (parse_result.count("orders"))
            {
                return parse_result["orders"].as<oi::orders_file_path>();
            }
            return oi::orders_from_prompt{};
        }()};
}

int main(const int argc, const char* argv[])
{
    auto opts = define_options(argv[0]);
    auto result = opts.parse(argc, argv);
    if (result.count("help"))
    {
        fmt::print("{}", opts.help());
        std::exit(0);
    }

    auto&& [input_file_path, orders_src] = unpack_required_options(result);
    oi::Tui tui(input_file_path, orders_src);
}
