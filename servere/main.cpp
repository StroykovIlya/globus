#include <QCoreApplication>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <iostream>
#include <sys/stat.h>
#include <fcntl.h>
#include <QString>
#include <unistd.h>
#include <stdio.h>

int main(int argc, char *argv[])
{   std::cout<<"server\n";
    QCoreApplication a(argc, argv);
    int sock, listener;//hi
        struct sockaddr_in addr;
        char buf[1024];
        int bytes_read;

        listener = socket(AF_INET, SOCK_STREAM, 0);
        if(listener < 0)
        {
            perror("socket\n");
            exit(1);
        }

        addr.sin_family = AF_INET;
        addr.sin_port = htons(3425);
        addr.sin_addr.s_addr = htonl(INADDR_ANY);
        if(bind(listener, (struct sockaddr *)&addr, sizeof(addr)) < 0)
        {
            perror("bind\n");
            exit(2);
        }

        listen(listener, 1);

        while(1)
        {
            sock = accept(listener, NULL, NULL);
            if(sock < 0)
            {
                perror("accept\n");
                exit(3);
            }

            while(1)
            {
                bytes_read = recv(sock, buf, 1024, 0);
                if (bytes_read <= 0) { strcpy(buf, ""); break; }

                printf(buf);
                send(sock, buf, bytes_read, 0);
            }

            close(sock);
        }
    return a.exec();
}
