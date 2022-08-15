#include<bits/stdc++.h>
using namespace std;
using namespace std::chrono;

long maxsize = 1e7;
vector<float> arr[10000000];
vector<float> query;

struct point{
	long index;
	long distance;
};

long find_distance(vector<float> &a, vector<float> &b)
{
	long dist = 0;
	for(int i = 0; i<100; i++)
		dist += round(a[i]-b[i])*round(a[i]-b[i]);
	return dist;
}

// comparator overloading to give the cutomized comparator to priority_queue which compares strut variables based on the distance.

struct comparedist {
    bool operator()(point const& p1, point const& p2)
    {
        return p1.distance > p2.distance;
    }
};

int main()
{
	string mytext;
	ifstream readme("data.txt");

	long i = 0;
	
	// Reads the data from the file.
	
	cout<<"Readig the data...."<<endl;
	while(getline(readme,mytext))
	{
		stringstream ss(mytext);
	    string word;
	    while (ss >> word) {
	        float num_float = std::stof(word);
	        arr[i].push_back(num_float);
	    }
	    //cout<<arr[i].size()<<endl;
	    i++;
	}
	readme.close();
	
	// Generates random vector as query.
	
	cout<<"Generating the query..."<<endl;
	vector<float> query;
	for(int i = 0; i<100; i++)
		query.push_back(float(rand()/float(RAND_MAX))*(rand()%100000));

	for(int i = 0; i<100; i++) cout<<query[i]<<",";
	cout<<endl;
	
	cout<<"Finding the 10 nearest points......"<<endl;

	auto start = high_resolution_clock::now();

	priority_queue<point,vector<point>,comparedist> pq;

	// index of the point in the array and its distance is pushed in the priority queue.
	
	for(long i = 0; i<10000000; i++)
	{
		long x = find_distance(query,arr[i]);
		point y;
		y.distance = x;
		y.index = i;
		pq.push(y);
	}
	for(int i = 0; i<10; i++)
	{
		point v = pq.top();
		pq.pop();
		for(int j = 0; j<100; j++)
			cout<<arr[v.index][j]<<" ";
		cout<<endl;
	}
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<seconds>(stop - start);
	cout<<"time taken to find the ans : "<<duration.count()<<" Seconds"<<endl;
	return 0;
}
