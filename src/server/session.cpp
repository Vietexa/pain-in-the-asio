#include "include/session.h"

    session::session(tcp::socket socket)
        : socket_(std::move(socket)) {

            
        }

    void session::start()
    {
        do_read();
    }

    void session::do_read()
    {
        auto self(shared_from_this());

        socket_.async_read_some(
            asio::buffer(data_),
            [this, self](std::error_code ec, std::size_t length)
            {
                if (!ec)
                {
                    do_write(length);
                }
            });
    }

    void session::do_write(std::size_t length)
    {
        auto self(shared_from_this());

        std::string hi = "Hi there";

        asio::async_write(
            socket_,
            asio::buffer(hi.c_str(), hi.length()),
            [this, self](std::error_code ec, std::size_t size)
            {
                if (!ec)
                {
                    do_read();
                }
            });
    }

