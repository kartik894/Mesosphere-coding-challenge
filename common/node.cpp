#include "../include/node.h"

Node::Node() {
	id = -1;
	resources = -1;
}

// To initialize node details
Node::Node(int id_no, int resources_available) {
	id = id_no;
	resources = resources_available;
}

// copy constructor
Node::Node(const Node &node) {
	id = node.id;
	resources = node.resources;
}

// get ID for the node
int Node::getID() {
	return id;
}

// get resources allocated to the node
int Node::getResources() {
	return resources;
}

// alter resource allocation to the node
void Node::setResources(int resources_available) {
	resources = resources_available;
}

// Add resources to the node
void Node::incrementResources(int additional) {
	resources += additional;
}

// Assign resources to a job
bool Node::allocateResources(int allocate) {
	// if resources are not available, return false
	if (resources < allocate) 
		return false;

	resources -= allocate;
	return true;
}
