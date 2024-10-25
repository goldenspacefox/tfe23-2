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

    // Seed with a real random value, if available
    std::random_device r;

    // Choose a random mean between 1 and 100
    std::default_random_engine e1(r());
    std::uniform_int_distribution<int> uniform_dist(1, 100);
    int rand_value = uniform_dist(e1);

    std::vector<unsigned int> numbers;
    auto start = std::chrono::system_clock::now();
    for (int i = 0; i < counter; i++)
    {
        numbers.push_back(uniform_dist(e1));
    }
    auto end = std::chrono::system_clock::now();

    auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    fmt::println("The inserting took: {}", elapsed);
    //fmt::println("The random vector: [ {} ]", fmt::join(numbers, ", "));


    fmt::println("Let's sort the numbers vector");
    fmt::println("--------------------------------------------------------------------------");

    start = std::chrono::system_clock::now();
    std::sort(numbers.begin(), numbers.end(), std::less<int>());
    end = std::chrono::system_clock::now();

    fmt::println("The sorted numbers vector");
    fmt::println("--------------------------------------------------------------------------");


    //fmt::println("The sorted vector: [ {} ]", fmt::join(numbers, ", "));
    elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    fmt::println("The sorting took: {}", elapsed);
    return 0; /* exit gracefully*/
}
