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
#include <mutex>

using namespace std;
void * thread_func(void *arg){
    int i;
    int loc_id = * (int *) arg;
    for (i = 0; i < 4; i++) {
        printf("thread %i is working\n", loc_id);
        usleep(100);

    }

}

int main(int argc, char *argv[])

{

    QCoreApplication a(argc, argv);
    int id1, id2, result;
        pthread_t thread1, thread2;
    id1 = 1;
    result = pthread_create(&thread1, NULL, thread_func, &id1);
        if (result != 0) {
            perror("First thread creation \n");
            return EXIT_FAILURE;
        }
     id2 = 2;
            result = pthread_create(&thread2, NULL, thread_func, &id2);
            if (result != 0) {
                perror("Second thread creatiob \n");
                return EXIT_FAILURE;
            }
     usleep(400000);
     cout << "Waiting for the end\n";
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
