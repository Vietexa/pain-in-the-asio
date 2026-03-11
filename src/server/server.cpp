#include "include/server.hpp"
#include "include/session.hpp"
#include "include/chat.hpp"




    Server::Server(asio::io_context& io, short port, Chat& chat)
        : acceptor_(io, tcp::endpoint(tcp::v4(), port)),
          chat_(chat)
    {
        do_accept();
    }


    void Server::do_accept()
    {
        acceptor_.async_accept(
            [this](std::error_code ec, tcp::socket socket)
            {
                if (!ec)
                {
                    std::make_shared<Session>(std::move(socket),chat_)->start();
                }

                do_accept();
            });
    }
