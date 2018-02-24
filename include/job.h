#ifndef JOB
#define JOB

#include <utility>
#include "node.h"

using namespace std;

// class for a job in the stream
class Job
{	
	private:
		// A request is composed of a pair <resource_units, time>
		pair<int,int> request;

	public:
		// To initilize a job requirement
		Job(pair<int,int> requirements);

		// return the request details
		pair<int,int> getRequest();

		// Assign this job to a node
		bool assign_job_to_node(Node &node);
		
};

#endif