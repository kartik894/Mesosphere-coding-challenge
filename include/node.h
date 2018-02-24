#ifndef NODE
#define NODE

using namespace std;

class Node {

	private:
		// resources for this node
		int resources;

		// Node ID
		int id;

	public:
		Node();
		
		// To initialize node details
		Node(int id_no, int resources_available);

		// copy constructor
		Node(const Node &node);

		// get ID for the node
		int getID();

		// get resources allocated to the node
		int getResources();

		// alter resource allocation to the node
		void setResources(int resources_available);

		// Add resources to the node
		void incrementResources(int additional);

		// Assign resources to a job
		bool allocateResources(int allocate);
};

#endif