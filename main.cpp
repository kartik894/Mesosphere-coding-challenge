#include <vector>
#include <stdlib.h>
#include <climits>
#include <iostream>
#include <queue>
#include "include/scheduler.h"

using namespace std;

#define N_NODES 1000
#define N_JOBS 3000


// Generate 'n' nodes with random resources in the range - [2,32]
vector<Node> generateNodes(int n) {
	srand(time(NULL));
	int resources = rand() % 31 + 2;
	vector<Node> listNodes;
	for(int i = 0; i < n; i++) {
		Node temp (i, resources);
		resources = rand() % 31 + 2;
		listNodes.push_back(temp);
	}
	return listNodes;
}

// Generate 'm' jobs with a random resource units and times
vector<Job> generateJobs(int m) {
	srand(time(NULL));
	int times = rand() % 5 + 1; // [1,5]
	int resources = rand() % 10 + 1; // [1,10]

	vector<Job> jobs;
	for(int i = 0; i < m; i++) {
		Job temp (make_pair(resources, times));
		jobs.push_back(temp);
		times = rand() % 5 + 1; // [1,5]
		resources = rand() % 10 + 1; // [1,10]
	}
	return jobs;
}

int main() {
	vector<Node> nodes = generateNodes(N_NODES);
	vector<Job> jobs = generateJobs(N_JOBS);
	
	// All nodes connect to the scheduler
	Scheduler scheduler (nodes);

	// Filling the scheduler with the job stream
	for(int i = 0; i < jobs.size(); i++) {
		// Uncomment the following to print node resources after every job assignment
		/*
		cout<<"Node details:\n";
		nodes = scheduler.getList();
		for(int j = 0; j < nodes.size(); j++) {
			cout<<nodes[j].getID()<<" "<<nodes[j].getResources()<<endl;
		}
		*/
		pair<bool, int> isScheduled = scheduler.schedule(jobs[i]);
		if (isScheduled.first == false) {
			cout<<"Couldn't schedule job "<<i<<" at the nodes. Insufficient resources available.\n";
		}
		else {
			cout<<"Scheduled job "<<i<<" on Node #"<<isScheduled.second<<endl;
		}

	}
	return 0;
}