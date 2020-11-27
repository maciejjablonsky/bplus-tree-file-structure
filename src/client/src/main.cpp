#include <fmt/format.h>
#include <cxxopts.hpp>

int main(const int argc, const char* argv[])
{
    cxxopts::Options opts(*argv, "Client app for b+tree file structure");
    opts.add_options()("i,input", "path to file containing index structure", cxxopts::value<std::string>())(
        "o,orders-list", "path to file with orders to execute, if not given interactive prompt is used",
        cxxopts::value<std::string>())("h,help", "print help");
    auto result = opts.parse(argc, argv);
    

    if (result.count("help"))
    {
        fmt::print("{}", opts.help({""}));
        std::exit(0);
    }
}
