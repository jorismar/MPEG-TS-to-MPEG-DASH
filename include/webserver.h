#ifndef WEBSERVER_H
#define WEBSERVER_H

#include <string>
#include <thread>
#include <chrono>
#include <fcntl.h>
#include <cstdio>
#include <cstddef>

#include "buffer.h"
#include "socket.h"
#include "util.h"
#include "virtualfile.h"
#include "http.h"
#include "dash.h"

class Webserver {
    private:
        Http * header;
        Socket * socket;
        Buffer * page_buffer;
        Buffer ** v_dash_buffer;
        Buffer ** a_dash_buffer;
        t_socket client;
        std::string page_path;
        std::string dash_path;
        t_pos dash_frag_count;
        bool alive;
        int port;
        int dash_profile;
        
    public:
        Webserver(int, int, Buffer**, Buffer**, std::string, std::string, bool);
        virtual ~Webserver();
        
        bool openConnection();
        void start();
        void stop();
        
        VirtualFile* getFile(std::string);
        VirtualFile* readFile(std::string, std::string);
        VirtualFile* readExternalBuffer(std::string);
        void startClient(t_socket);
        void startTest(t_socket);
        
        void setPort(int);
};

#endif

/*
http://www.anirudhtom.com/2011/03/live-streaming-video-tutorial-for.html
http://download.tsi.telecom-paristech.fr/gpac/doc/libgpac/mpegts_8h.html#structtag__m2ts__es
https://pt.wikipedia.org/wiki/Signal.h
http://pubs.opengroup.org/onlinepubs/7908799/xns/syssocket.h.html
http://www.gdsw.at/languages/c/programming-bbrown/c_075.htm
http://www.cplusplus.com/reference/cstdio/setbuf/
http://www.tutorialspoint.com/unix_sockets/socket_server_example.htm
http://www.cplusplus.com/reference/ctime/


*/