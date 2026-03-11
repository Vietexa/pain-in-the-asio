#pragma once
#include "chat.hpp"
#include "session.hpp"
#include <asio.hpp>
using asio::ip::tcp;

class Server
{
    tcp::acceptor acceptor_;
    Chat& chat_;


    public:
    
    Server(asio::io_context& io, short port, Chat& chat);
    
    
    private:
    void do_accept();


};