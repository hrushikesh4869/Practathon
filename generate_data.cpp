#include<bits/stdc++.h>
using namespace std;
using namespace std::chrono;

int main()	
{
	float arr[100];
	ofstream myfile("data.txt",std::ios_base::app);
	auto start = high_resolution_clock::now();
	cout<<"Generating data......"<<endl;
	for(int i = 0; i<10000000; i++)
	{	
		//cout<<"generating "<<i<<"th vector"<<endl;
		for(int i = 0; i<100; i++)
		{
			myfile<<float(rand()/float(RAND_MAX))*(rand()%100000)<<" ";
		}
		myfile<<"\n";
	}
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<seconds>(stop - start);
	myfile.close();
	cout<<"time taken to generate data : "<<duration.count()<<endl;
	return 0;
}