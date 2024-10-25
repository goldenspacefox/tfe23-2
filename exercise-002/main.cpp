#include <fmt/chrono.h>
#include <fmt/format.h>

#include <algorithm> /* needed for the std::sort */
#include <random>
#include <vector> /* Does provide std::vector */

#include "CLI/CLI.hpp"
#include "config.h"


//Global variable
int foo;

int bar = 100;
int bar2 = 42;

auto main(int argc, char** argv) -> int
{
    /**
     * CLI11 is a command line parser to add command line options
     * More info at https://github.com/CLIUtils/CLI11#usage
     */
    auto counter{20};           /* set a default of 20 */
    CLI::App app{PROJECT_NAME}; /* create an instance of an App with the variable name app*/
    try
    {
        app.set_version_flag("-V,--version", fmt::format("{} {}", PROJECT_VER, PROJECT_BUILD_DATE));
        /* Add an command lime option -c or --count and fill the variable counter */
        app.add_option("-c,--count", counter, "How many items to insert");
        app.parse(argc, argv);
    }
    catch (const CLI::ParseError& e)
    {
        return app.exit(e);
    }

    fmt::println("Hello exercise two");
    fmt::println("The value of variable foo: {} and the address {}",foo,fmt::ptr(&foo));
    fmt::println("TThe value of variable bar: {} and the address {}",bar,fmt::ptr(&bar));
    fmt::println("The value of variable bar2: {} and the address {}",bar2,fmt::ptr(&bar2));

    return 0; 
}
