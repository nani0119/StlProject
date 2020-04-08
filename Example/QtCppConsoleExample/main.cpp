#include <QCoreApplication>
#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
    int i = 0;
    QCoreApplication a(argc, argv);
    std::cout<<"hello world"<<endl;
    std::cin>>i;
    cout<<i<<endl;

    return a.exec();
}
