#include<vector>
#include<iostream>
using namespace std;
int main(){
	vector<int>v;
	cout<<"cap="<<v.capacity()<<endl;
	v.push_back(5);
	cout<<"cap="<<v.capacity()<<endl;
	v.push_back(6);
	cout<<"size="<<v.size()<<endl;
	cout<<v.back()<<endl;
	cout<<v.front()<<endl;

	cout<<"before clear size="<<v.size()<<endl;
	v.clear();
	cout<<"after clear size="<<v.size()<<endl;
}
