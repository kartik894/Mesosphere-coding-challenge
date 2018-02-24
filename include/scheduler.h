#ifndef SCHEDULER
#define SCHEDULER

#include "job.h"
#include <vector>
#include <climits>
#include <map>

using namespace std;

class Scheduler
{	
	private:
		// list of Nodes with information on how many resources are available
		vector <Node> nodeList;

	public:
		// Constructor to fill the nodeList
		Scheduler(vector<Node> &nodes);

		// Get List of all nodes
		vector<Node> getList();
		
		// Schedule the job on one of the nodes
		pair<bool, int> schedule(Job &job);
	
};

#endif