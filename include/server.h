#pragma once
#include <asio.hpp>
using asio::ip::tcp;

class server
{
    tcp::acceptor acceptor_;

    public:
    server(asio::io_context& io, short port);
    
    private:
    void do_accept();


};