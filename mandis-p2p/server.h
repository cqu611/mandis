#ifndef MANDIS_MANDIS_P2P_SERVER_H_
#define MANDIS_MANDIS_P2P_SERVER_H_

#include <boost/asio.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/function.hpp>
#include <boost/noncopyable.hpp>

#include "../include/logger.h"
#include "session.h"

namespace p2pnet {
    typedef boost::shared_ptr<Session> session_ptr; 

    class Server : private boost::noncopyable
    {
    public:
        explicit Server(logger::Logger *logger, int port);
        virtual ~Server();

        void SetFindCallback(callback_fn cfn) { rsp_find_callback_ = cfn; }
        void SetStoreCallback(callback_fn cfn) { rsp_store_callback_ = cfn; }
        void SetSyncCallback(callback_fn cfn) { rsp_sync_callback_ = cfn; }

        void Start();
        void Stop();

    private:
        void Run();
        void HandleAccept(session_ptr session, const boost::system::error_code& ec);

    private:
        boost::asio::io_service ios_;
        boost::asio::ip::tcp::acceptor acceptor_;
        logger::Logger * logger_ = nullptr;
        callback_fn rsp_find_callback_;
        callback_fn rsp_store_callback_;
        callback_fn rsp_sync_callback_;
    };

}

#endif // !MANDIS_MANDIS_P2P_SERVER_H_
