#ifndef BST_HPP
#define BST_HPP

#include <memory>
#include <stdexcept>

enum class Direction
{
  LEFT,
  RIGHT
};

template <typename Key, typename Value>

class Bst
{
public:

	//default construtor. time complexity = O(1).
	Bst()
	{
		root = nullptr;
		sizer = 0;
	}

	//perameterized constructor. time complexity = O(1).
	Bst(Bst const& bst)
	{
		root = bst.root;
		sizer = bst.sizer;
	}

	//inital add functin. Gets values and creates new node to be added
	//time complexity = O(1).
	void add(Key const& key, Value const& value)
	{
		auto a = std::make_shared<node>(nullptr, nullptr, key, value);
		myAdd(a);
		sizer++;
	}

	// updates value at key. time complexity = O(n).
	void update(Key const& key, Value const& value)
	{
		std::shared_ptr<node> temp = root;
		while (temp != nullptr)
		{
			if (temp->key == key)
			{
				temp->value = value;
				return;
			}
			else if (key < temp->key)
			{
				temp = temp->left;
			}
			else
			{
				temp = temp->right;
			}
		}
		throw std::runtime_error("key does not exist. Add to list first using .add");
	}

	//initial remove function. time complexity = O(1).
	void remove(Key const& key)
	{
		if (root == nullptr)
		{
			throw std::runtime_error("key does not exist. Add to list first using .add");
		}
		remove1(root, key);
		sizer--;
	}

	//finds value at key.time complexity = O(n).
	Value& at(Key const& key)
	{
		std::shared_ptr<node> temp = root;
		while (temp != nullptr)
		{
			if (temp->key == key)
			{
				return temp->value;
			}
			else if (key < temp->key)
			{
				temp = temp->left;
			}
			else
			{
				temp = temp->right;
			}
		}
		throw std::runtime_error("key does not exist. Add to list first using .add");
	}

	//same thing as at...time complexity = O(n).
	Value& operator[](Key const& key)
	{
		std::shared_ptr<node> temp = root;
		while (temp != nullptr)
		{
			if (temp->key == key)
			{
				return temp->value;
			}
			else if (key < temp->key)
			{
				temp = temp->left;
			}
			else
			{
				temp = temp->right;
			}
		}
		throw std::runtime_error("key does not exist. Add to list first using .add");
	}

	//follows a given path thorugh the vector and returns the value at the node. 
	//time complexity = O(n).
	Value traverse(std::vector<Direction> const& path)
	{
		std::shared_ptr<node> temp = root;
		size_t a = path.size();
		for (size_t i = 0; i < a; i++)
		{
			if (path[i] == Direction::RIGHT) 
			{
				if (temp->right != nullptr)
				{
					temp = temp->right;
				}
				else
				{
					throw std::runtime_error("key does not exist. Add to list first using .add");
				}
			}
			else if (path[i] == Direction::LEFT)
			{
				if (temp->left != nullptr)
				{
					temp = temp->left;
				}
				else
				{
					throw std::runtime_error("key does not exist. Add to list first using .add");
				}
			}
		}
		return temp->value;
	}

	//returns size of BST. time complexity = O(1).
	size_t size()
	{
		return sizer;
	}

private:

	//struct for each node in BST
	struct node
	{
		std::shared_ptr<node> right;
		std::shared_ptr<node> left;
		Value value;
		Key key;

		node(std::shared_ptr<node> right1, std::shared_ptr<node> left1, Key key1, Value val)
		{
			right = right1;
			left = left1;
			value = val;
			key = key1;
		}
		
	};

	//second remove funtion. Finds node to remove and passes on node to last remove function. 
	void remove1(std::shared_ptr<node> root2, Key key)
	{
		if (key < root2->key)
		{
			if (root2->left == nullptr)
			{
				throw std::runtime_error("key does not exist. Add to list first using .add");
			}
			remove1(root2->left, key);
		}
		else if (key > root2->key)
		{
			if (root2->right == nullptr)
			{
				throw std::runtime_error("key does not exist. Add to list first using .add");
			}

			remove1(root2->right, key);
		}
		else
		{
			myRemove(root2);
		}	
	}

	//last remove 
	void myRemove(std::shared_ptr<node> root1)
	{
		std::shared_ptr<node> attachPoint;
		if (root1->right == nullptr)
		{
			root1->value = root1->left->value;
			root1->key = root1->left->key;
			root1->left = nullptr;
		}
		else if (root1->left == nullptr)
		{
			root1->value = root1->right->value;
			root1->key = root1->right->key;
			root1->right = nullptr;
		}
		else
		{
			attachPoint = root1->right;
			while (attachPoint->left != nullptr)
			{
				attachPoint = attachPoint->left;
			}
			root1->value = attachPoint->value;
			root1->key = attachPoint->key;
			while (attachPoint->right != nullptr)
			{
				attachPoint->value = attachPoint->right->value;
				attachPoint->key = attachPoint->right->key;
				attachPoint = attachPoint->right;
			}
			attachPoint = nullptr;
		}
	}

	//checks add function to make sure root exists.
	void myAdd(std::shared_ptr<node> a)
	{
		if (root == nullptr)
		{
			root = a;
			return;
		}
		recurAdd(root, a);
	}

	//adds to the BST recursivly
	void recurAdd(std::shared_ptr<node> branch, std::shared_ptr<node> a)
	{
		if (a->key > branch->key)
		{
			if (branch->right != nullptr)
			{
				recurAdd(branch->right, a);
			}
			else
			{
				branch->right = a;
			}

		}
		else if (a->key < branch->key)
		{
			if (branch->left != nullptr)
			{
				recurAdd(branch->left, a);
			}
			else
			{
				branch->left = a;
			}

		}
		return;
	}

	//root is the first node in the BST
	std::shared_ptr<node> root;
	//size of BST container. 
	size_t sizer;
};

#endif