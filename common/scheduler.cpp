#include "../include/scheduler.h"

// Initialize the data structures
Scheduler::Scheduler(vector<Node> &nodes) {
	nodeList = nodes;
}

// Return the list of nodes
vector<Node> Scheduler::getList() {
	return nodeList;
}

// Iterate the nodeList and look for a node such that difference between allocated and requested resource is minimum
pair<bool, int> Scheduler::schedule(Job &job) {
	int n = nodeList.size();
	int id_choice = -1;
	int diff = INT_MAX;
	for(int i = 0; i < n; i++) {
		int temp = nodeList[i].getResources() - job.getRequest().first;
		if (temp > 0 && temp < diff) {
			diff = temp;
			id_choice = i;
		}
	}
	if (diff == INT_MAX) {
		return make_pair(false, -1);
	}
	bool attempt = job.assign_job_to_node(nodeList[id_choice]);
	return make_pair(attempt, nodeList[id_choice].getID());
}