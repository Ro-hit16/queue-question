#include<iostream>
#include <vector>
#include <algorithm>
#include<queue>
using namespace std;
int main(){
queue<int>q;

q.push(12);
q.push(13);
q.push(99);                               

cout<< "queue front :"<<q.front() <<endl;
cout<<"size of queue is :"<<q.size()<<endl;

q.pop();
q.pop();
cout<< "queue front :"<<q.front() <<endl;

q.pop();
if(q.empty()){
    cout<<"queue is empty"<<endl;
}
else{
    cout<<"queue is not empty"<<endl;
}
return 0;

}