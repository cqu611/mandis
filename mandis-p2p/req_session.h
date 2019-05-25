#ifndef MANDIS_MANDIS_REQ_SESSION_H_
#define MANDIS_MANDIS_REQ_SESSION_H_

#include <boost/bind.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/asio.hpp>
#include <boost/array.hpp>
#include "../include/logger.h"

namespace p2pnet {
    class ReqSession {
    public:
        ReqSession(boost::asio::io_context& ioc, const std::string ip, const int port, std::string& msg,
            logger::Logger* logger);
        ~ReqSession() { }

        int DoReqStore(std::string key, std::string block_path);
        int DoReqAccess(std::string key, std::string block_path);
        int DoReqSync(std::string msg);
        std::string DoReqFind(std::string key);
        int DoPing();

    private:
        std::string& msg_;
        boost::asio::io_context& ioc_;
        boost::asio::ip::tcp::socket socket_;
        boost::asio::ip::tcp::endpoint ep_;
        logger::Logger* logger_ = nullptr;
    };


}

#endif // !MANDIS_MANDIS_REQ_SESSION_H_
