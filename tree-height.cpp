#include <algorithm>
#include <iostream>
#include <vector>
#include<queue>
#if defined(__unix__) || defined(__APPLE__)
#include <sys/resource.h>
#endif

class Node;

class Node {
public:
	int key;
	Node *parent;
	std::vector<Node *> children;

	Node() {
		this->parent = NULL;
	}

	void setParent(Node *theParent) {
		parent = theParent;
		parent->children.push_back(this);
	}
};


int printNodes(std::vector<Node>& nodes, int rootIndex){
	std::queue <std::pair< Node *, int>>nodesQueue;
	std::vector<std::vector<int>> tree;
	Node nParent = nodes[rootIndex];
	Node n;
	int j = 0;
	//int h = 0;
	int level = 0;
	nodesQueue.push(std::make_pair(&nParent, 1));

	while (!nodesQueue.empty()){
		n = *nodesQueue.front().first;
		level = nodesQueue.front().second;
		nodesQueue.pop();
		//std::cout << n.key << "\n";
		if (n.children.size() != 0){
			for (int i = 0; i < n.children.size(); ++i){
				//nChild = *(nParent.children[i]);
				nodesQueue.push(std::make_pair(n.children[i], level + 1));
				//tree[j].push_back()
			}
			//h++;
		}
	
	}
	return level;
}
int getBaseNode(std::vector<Node>& nodes){
	for (int i = 0; i < nodes.size(); ++i){
		//if (nodes[i].)
	}
	return 0;

}

int main_with_large_stack_space() {
	std::ios_base::sync_with_stdio(0);
	int rootIndex;
	int n;
	std::cin >> n;

	std::vector<Node> nodes;
	nodes.resize(n);
	for (int child_index = 0; child_index < n; child_index++) {
		int parent_index;
		std::cin >> parent_index;
		if (parent_index >= 0)
			nodes[child_index].setParent(&nodes[parent_index]);
		else
			rootIndex = child_index;
		nodes[child_index].key = child_index;
	}
	std::cout << printNodes(nodes, rootIndex);

	
	system("pause");
	return 0;
}

int main(int argc, char **argv)
{
#if defined(__unix__) || defined(__APPLE__)
	// Allow larger stack space
	const rlim_t kStackSize = 16 * 1024 * 1024;   // min stack size = 16 MB
	struct rlimit rl;
	int result;

	result = getrlimit(RLIMIT_STACK, &rl);
	if (result == 0)
	{
		if (rl.rlim_cur < kStackSize)
		{
			rl.rlim_cur = kStackSize;
			result = setrlimit(RLIMIT_STACK, &rl);
			if (result != 0)
			{
				std::cerr << "setrlimit returned result = " << result << std::endl;
			}
		}
	}

#endif
	return main_with_large_stack_space();
}
