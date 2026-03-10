#include <asio.hpp>
#include <iostream>
#include "include/server.hpp"



int main()
{
    try
    {
        asio::io_context io;

        server s(io, 12345);

        io.run();
    }
    catch (std::exception& e)
    {
        std::cerr << e.what() << std::endl;
        return -1;
    }

    return 0;

}