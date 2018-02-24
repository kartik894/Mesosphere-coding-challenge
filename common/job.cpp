#include "../include/job.h"

// To initilize a job requirement
Job::Job(pair<int,int> requirements) {
	request.first = requirements.first;
	request.second = requirements.second;
}

// return the request details
pair<int,int> Job::getRequest() {
	return request;
}

// Assign this job to a node
bool Job::assign_job_to_node(Node &node) {
	return node.allocateResources(request.first);
}
