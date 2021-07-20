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
/*cj */
char message[] = "Hello there i'm second!\n";
char buf[sizeof(message)];
int main(int argc, char *argv[])
{   std:: cout<<"client2\n";
    QCoreApplication a(argc, argv);
    int sock;
        struct sockaddr_in addr;

        sock = socket(AF_INET, SOCK_STREAM, 0);
        if(sock < 0)
        {
            perror("socket\n");
            exit(1);
        }

        addr.sin_family = AF_INET;
        addr.sin_port = htons(3425);
        addr.sin_addr.s_addr = htonl(INADDR_LOOPBACK);
        if(connect(sock, (struct sockaddr *)&addr, sizeof(addr)) < 0)
        {
            perror("connect\n");
            exit(2);
        }

        send(sock, message, sizeof(message), 0);
        recv(sock, buf, sizeof(message), 0);

        printf(buf);
        close(sock);

    return a.exec();
}
