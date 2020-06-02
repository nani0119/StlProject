#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
    queue<string> q;
    q.push("there");
    q.push("are");
    q.push("some");
    q.push("words");

    cout << q.size() << endl;
    cout << "queue front:" << q.front() << endl;
    cout << "queuw back :" << q.back() << endl;

    cout << "queue context:";
    while(!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
    return 0;
}