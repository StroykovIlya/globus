#include <QCoreApplication>
#include <iostream>
#include <QVector>
#include <QList>
#include <QMap>
#include <sstream>
#include<QString>
#include<algorithm>
#include<iterator>
using namespace std;
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    cout << "choose a container for work: vector; list; map\n ";
    string TypeOfContainer;
    cin >> TypeOfContainer;
    if (TypeOfContainer=="vector") {
        char str1 [256];
        cout << "write numbers through the space\n";
        cin.ignore();
        cin.getline(str1,256);
        stringstream ss(str1);
        QVector <double> vec1;
        double num;
        while (ss>>num){
            vec1.push_back(num);
        }
        cout << "numbers in your vector :\n";
        for(auto i : vec1)
            cout <<"element "<< i <<"\n" ;
        cout << "choose the operation:change; add; remove\n ";
        string TypeOfOperation;
        cin >> TypeOfOperation;
        if(TypeOfOperation=="add"){
            cout << "what element add\n";
            double re;
            cin >> re;
            vec1.push_back(re);
            cout << "New vector is:\n";
            for(auto i : vec1)
                cout <<"element "<< i <<"\n" ;

        } else if(TypeOfOperation=="change"){
            double OldElement;
            double NewElement;
            cout << "what element should be changed?\n";
            cin >> OldElement;
            cout << "on what element?\n";
            cin >> NewElement;
            QMutableVectorIterator <double> it (vec1);
            while (it.hasNext()){
                if(it.next()==OldElement){
                   it.setValue(NewElement);}
            }
                cout << "New vector is:\n";
                for(auto i : vec1)
                    cout <<"element "<< i <<"\n";

        } else if(TypeOfOperation=="remove"){
            double ReElement;

            cout <<"Write value for removing\n";
            cin >> ReElement;
            auto it = remove(vec1.begin(),vec1.end(),ReElement);
            vec1.erase(it, vec1.end());
            cout << "New vector is:\n";
            for(auto i : vec1)
                cout <<"element "<< i <<"\n";
                }
        else{
            cout << "Write Operation correctly";
        }




    }  else if (TypeOfContainer=="list"){
        char str2 [256];
        cout << "write words through the space\n";
        cin.ignore();
        cin.getline(str2,256);
        stringstream ss1(str2);
        QList <string> list1;
        string numb;
        while (ss1>>numb){
            list1.push_back(numb);
        }
        cout << "words in your list :\n";
        for(auto j : list1)
            cout <<"element "<< j <<"\n" ;
        cout << "choose the operation:change; add; remove\n ";
        string TypeOfOperation1;
        cin >> TypeOfOperation1;
        if(TypeOfOperation1=="add"){
            cout << "what word add\n";
            string re1;
            cin >> re1;
            list1.push_back(re1);
            cout << "New list is:\n";
            for(auto j : list1)
                cout <<"element "<< j <<"\n" ;

        } else if(TypeOfOperation1=="change"){
            string OldElement1;
            string NewElement1;
            cout << "what element should be changed?\n";
            cin >> OldElement1;
            cout << "on what element?\n";
            cin >> NewElement1;
            QMutableListIterator <string> it (list1);
            while (it.hasNext()){
                if(it.next()==OldElement1){
                   it.setValue(NewElement1);}
            }
                cout << "New list is:\n";
                for(auto j : list1)
                    cout <<"element "<< j <<"\n";

        } else if(TypeOfOperation1=="remove"){
            string ReElement1;

            cout <<"Write word for removing\n";
            cin >> ReElement1;
            auto it = remove(list1.begin(),list1.end(),ReElement1);
            list1.erase(it, list1.end());
            cout << "New list is:\n";
            for(auto j : list1)
                cout <<"element "<< j <<"\n";
                }
        else{
            cout << "Write Operation correctly";
        }


    } else if (TypeOfContainer=="map"){

        QMap<string,string> MapPhonebook;
        string stop;
        while (stop!="stop"){
        string MKey;
        string MValue;
        cout << "write key\n";
        cin >> MKey;
        cout << "write value\n";
        cin >> MValue;
        MapPhonebook[MKey]=MValue;
        QMap<string,string>  :: iterator it=MapPhonebook.begin();
        for (;it!=MapPhonebook.end();++it){
        cout << "Name:"<< it.key()<<" "
        << "Phone:"<< it.value()<<"\n";
        }
        cout<<"to exit write stop or to continue write anything other\n";
        cin >> stop;
        }
        string name;
        cout << "find name\n";
        cin >> name;
        QMap<string,string>::iterator it=MapPhonebook.find(name);
        for (;it !=MapPhonebook.end() && it.key()==name;++it){
            cout<< it.value()<<"\n";
        }

    } else {
        cout << "Write the name of the container correctly\n";
    }
    return a.exec();
}
