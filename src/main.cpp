#include <iostream>
#include <string>
#include <typeinfo>
#include <stdexcept>

#include "tg/dummy.hpp"

/**
 * @brief install a signal handler to catch SIGSEGV, SIGABRT, etc.
 * @details
 * For memory corruption etc.
 */
void main_init()
{
}

/**
 * @brief Put any code that needs to run here.
 */
void test_main()
{
    dummy_function();
}

int main(int argc, char** argv)
{
    main_init();
    try
    {
        test_main();
    }
    catch (std::exception& ex)
    {
        std::cerr
            << "\n\n\nException thrown. \nType: " << typeid(ex).name() << "\n\n"
            << std::flush
            << ex.what()
            << "\n\n\n" 
            << std::flush;
        std::cout
            << "Exiting on exception.\n\n"
            << std::flush;
        return 1;
    }
    catch (...)
    {
        std::cerr
            << "\n\n\nUnknown exception thrown.\n\n"
            << std::flush;
        std::cout
            << "Exiting on unknown exception.\n\n"
            << std::flush;
        return 1;
    }
    std::cout 
        << "\n\nNo exception thrown, exiting normally.\n\n" 
        << std::flush;
    return 0;
}
