#include "include/session.hpp"
#include "include/chat.hpp"
#include <asio/write.hpp>
#include <iostream>

    Session::Session(tcp::socket socket, Chat& chat)
        : 
        socket_(std::move(socket)),
        chat_(chat)
        
        {
        
            
        }

    void Session::start()
    {
        chat_.counter += 1;
        current_s_id = chat_.counter;
        chat_.users.emplace(chat_.counter,shared_from_this());
        do_read();
    }

    void Session::do_read()
    {   
        auto self(shared_from_this());
        
        socket_.async_read_some(
            asio::buffer(read_buf_),
            [this, self](std::error_code ec, std::size_t length)
            {
                std::cout << "Received " << length << " bytes\n";
                if (!ec)
                {
                    send_all(length);
                    do_read();
                }
            });
    }

    void Session::do_write(std::size_t length)
    {
        auto self(shared_from_this());

        asio::async_write(
            socket_,
            asio::buffer(read_buf_),
            [this, self](std::error_code ec, std::size_t size)
            {
                if (!ec)
                {
                    do_read();
                }
            });
    }

    void Session::disconnect() {
    asio::error_code ec;

    socket_.shutdown(asio::ip::tcp::socket::shutdown_both, ec); // NOLINT(bugprone-unused-return-value)
    if (ec && ec != asio::error::not_connected) {
        std::cerr << "Shutdown failed: " << ec.message() << "\n";
    }

    socket_.close(ec); // NOLINT(bugprone-unused-return-value)
    if (ec) {
        std::cerr << "Close failed: " << ec.message() << "\n";
    }
    
}

void Session::send_all(size_t length){
auto self(shared_from_this());

for (auto& [index, session] : chat_.users){
    if (current_s_id == index) continue;
    int session_index = index;
    asio::async_write(session->socket_,
    asio::buffer(read_buf_, length),
    [self,this, session_index](std::error_code ec, std::size_t size){
        std::cout << "The session index is " << session_index << "\n";
    });
}

}


