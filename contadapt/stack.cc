#include <iostream>
#include <stack>

using namespace std;


int main(int argc, char const *argv[])
{
    stack<int> st;
    int a = 2;
    st.push(1);
    st.push(std::move(a));
    st.emplace(3);
    st.push(3);
    st.top() = 4;

    cout<< "stack  size(): " << st.size()<<endl;
    cout<< "stack context: ";
    while(!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;

    return 0;
}
