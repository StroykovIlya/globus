#include <QCoreApplication>
#include <time.h>
#include <stdio.h>
using namespace std;
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    //Структуры для сохранения определенного времени
       struct timespec mt1, mt2;
       //Переменная для расчета дельты времени
       long int tt;

       //Определяем текущее время
       clock_gettime (CLOCK_REALTIME, &mt1);

       //Выводим определенное время на экран консоли
       printf("seconds: %ld\n",mt1.tv_sec);
       printf("nanoseconds: %ld\n",mt1.tv_nsec);

       //Определяем текущее время
       clock_gettime (CLOCK_REALTIME, &mt2);

       //Рассчитываем разницу времени между двумя измерениями
       tt=1000000000*(mt2.tv_sec - mt1.tv_sec)+(mt2.tv_nsec - mt1.tv_nsec);

       //Выводим результат расчета на экран
       printf ("wasted time: %ld ns\n",tt);

    return a.exec();
}
