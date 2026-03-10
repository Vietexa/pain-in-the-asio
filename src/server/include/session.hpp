#pragma once
#include <asio.hpp>
using asio::ip::tcp;

class session : public std::enable_shared_from_this<session>
{
    tcp::socket socket_;
    std::array<char, 1024> data_;
    public:
    session(tcp::socket socket);
    void start();
    void do_read();
    void do_write(std::size_t length);
};