#include <QCoreApplication>
#include <iostream>
#include <QVector>
#include <QList>
#include <QMap>
#include <sstream>
#include <QString>
#include <algorithm>
#include <iterator>
#include <pthread.h>
#include <stdlib.h>
#include <errno.h>
#include <stdio.h>
#include <chrono>
#include <unistd.h>


using namespace std;;
pthread_mutex_t  mtx=PTHREAD_MUTEX_INITIALIZER;
pthread_spinlock_t sp; //=PTHREAD_MUTEX_INITIALIZER;



void print(char ch)
{
    for (int i = 0; i < 5; i++)
    {
        for (int i = 0; i < 10; i++)
        {
            cout << ch;
            usleep(20000);
        }
        cout << endl;
    }
    cout << endl;
}

void *fthread (void *arg) {

    //pthread_spin_lock(&sp);
    //pthread_mutex_lock(&mtx);
    print('!');
    //pthread_mutex_unlock(&mtx);
    //pthread_spin_unlock(&sp);
}

void *fthread1(void *arg) {

    //pthread_spin_lock(&sp);
    //pthread_mutex_lock(&mtx);
    print('?');
    //pthread_mutex_unlock(&mtx);
    //pthread_spin_unlock(&sp);

}

int main(int argc, char *argv[])
{
    pthread_spin_init(&sp, 0);

    QCoreApplication a(argc, argv);
    int id1, id2, result;
        pthread_t thread1, thread2;
    result = pthread_create(&thread1, NULL, fthread, &id1);
        if (result != 0) {
            perror("First thread creation \n");
            return EXIT_FAILURE;
        }
     result = pthread_create(&thread2, NULL, fthread1, &id2);
        if (result != 0) {
             perror("Second thread creatiob \n");
             return EXIT_FAILURE;
        }

     result = pthread_join(thread1, NULL);
         if (result != 0) {
             perror("Waiting for the first thread!!!!!!!!\n");
             return EXIT_FAILURE;
         }
         result = pthread_join(thread2, NULL);
         if (result != 0) {
             perror("Waiting for the second thread!!!!!!!!\n");
             return EXIT_FAILURE;
         }
         printf("Done\n");
             return EXIT_SUCCESS;
    return a.exec();
}
