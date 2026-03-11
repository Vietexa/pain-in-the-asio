#pragma once

#include "chat.hpp"
#include <asio.hpp>

using asio::ip::tcp;

class Chat;

class Session : public std::enable_shared_from_this<Session>
{
    

    tcp::socket socket_;
    int current_s_id;
    std::string username;
    std::array<char, 1024> read_buf_;
    Chat& chat_;
    public:
    Session(tcp::socket socket, Chat& chat);
    void start();
    

    private:
    void do_read();
    void do_write(std::size_t length);
    void disconnect();
    void send_all(std::size_t length);

};