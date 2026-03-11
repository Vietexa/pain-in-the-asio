#include <asio.hpp>
#include <iostream>
#include <memory>
#include "include/chat.hpp"
#include "include/server.hpp"



int main()
{
    try
    {
        asio::io_context io;

        std::unique_ptr<Chat> chat = std::make_unique<Chat>();
        Server s(io, 12345, *chat);

        io.run();
    }
    catch (std::exception& e)
    {
        std::cerr << e.what() << std::endl;
        return -1;
    }

    return 0;

}