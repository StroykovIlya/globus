#include <QCoreApplication>
#include <time.h>
#include <stdio.h>
#include <iostream>
using namespace std;
/*данная программа вычисляет время, которое понадобилось для определения квадрата числа
*/
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    struct timespec mt1, mt2;
    long int tt;
    clock_gettime (CLOCK_REALTIME, &mt1);
    int num1;
    cout << "write number\n";
    cin >> num1;
    cout <<"square number:"<< num1*num1<<endl;
    clock_gettime (CLOCK_REALTIME, &mt2);
    tt=1000000000*(mt2.tv_sec - mt1.tv_sec)+(mt2.tv_nsec - mt1.tv_nsec);
    printf ("wasted time for this operation: %ld ns\n",tt);

    return a.exec();
}
