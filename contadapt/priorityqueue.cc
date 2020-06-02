#include <iostream>
#include <queue>

using namespace std;


int main(int argc, char const *argv[])
{
    priority_queue<float> pq;
    pq.push(1.1);
    pq.push(2.2);
    pq.push(0);
    pq.push(5.5);

    cout << "priority size:" << pq.size() << endl;

    cout << "priority :";
    while(!pq.empty())
    {
        cout << pq.top() << " ";
        pq.pop(); 
    } 
    cout << endl;
    return 0;
}
