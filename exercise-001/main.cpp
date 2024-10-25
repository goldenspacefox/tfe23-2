#include <fmt/chrono.h>
#include <fmt/format.h>

#include "CLI/CLI.hpp"
#include "config.h"

auto main(int argc, char **argv) -> int
{
    /**
     * CLI11 is a command line parser to add command line options
     * More info at https://github.com/CLIUtils/CLI11#usage
     */ 
    // Set a default of 20
    auto counter{20};
    //create an instance of an App
    CLI::App app{PROJECT_NAME}; 

    try
    {
        app.set_version_flag("-V,--version", fmt::format("{} {}", PROJECT_VER, PROJECT_BUILD_DATE));
        // Add an command line option -c or --count and fill the variable counter
        app.add_option("-c,--count", counter, "How many items to insert");
        app.parse(argc, argv);
    }
    catch (const CLI::ParseError &e)
    {
        return app.exit(e);
    }

    /**
     * The {fmt} lib is a cross platform library for printing and formatting text
     * it is much more convenient than std::cout and printf
     * More info at https://fmt.dev/latest/api.html
     */
    fmt::print("Hello, {}!\n", app.get_name());

    fmt::print("Value of, {}!\n", argc);

    //fmt::print("Value of argv[0], {}!\n", argv[0]); -> possible null pointer exception 

    fmt::print("Counter value: {}\n", counter);

    /* INSERT YOUR CODE HERE */

    return 0; /* exit gracefully*/
}
