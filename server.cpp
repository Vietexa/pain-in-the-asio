#include "include/server.h"
#include "include/session.h"




    server::server(asio::io_context& io, short port)
        : acceptor_(io, tcp::endpoint(tcp::v4(), port))
    {
        do_accept();
    }


    void server::do_accept()
    {
        acceptor_.async_accept(
            [this](std::error_code ec, tcp::socket socket)
            {
                if (!ec)
                {
                    std::make_shared<session>(std::move(socket))->start();
                }

                do_accept();
            });
    }
