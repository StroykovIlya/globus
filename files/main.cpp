#include <QCoreApplication>
#include <iostream>
#include <sys/stat.h>
#include <fcntl.h>
#include <QString>
#include <unistd.h>
#include <stdio.h>
#define MAX_READ 256
#define MAX_WRITE 256

using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    cout<<"write some text\n";
    int i=0;
        char* Wbuffer = new char[i];
        do
        {
           Wbuffer[i]= getchar();
           if (Wbuffer[i] == '\n') break;
           i++;
        } while (true);
        char Rbuffer [MAX_READ];
        int fd=open("/home/ilya/new.txt",O_WRONLY);
        if (fd==-1)
            cout<< "error of openning\n";
        if(write(fd,Wbuffer,MAX_WRITE)==-1)
            cout<< "error of writing\n";
        close(fd);
        int fd1=open("/home/ilya/new.txt",O_RDONLY);
        if (read(fd1,Rbuffer,MAX_READ)==-1)
            cout<<"error\n";
        printf("file contents: %s\n",Rbuffer);
        close(fd1);




    return a.exec();
}
