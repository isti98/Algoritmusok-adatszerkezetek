
#include "Tree.h"

//Keresőfa adatszerkezet implemantcáija

template<class T>
SearchTree<T>*			SearchTree<T>::max			()const
{
	SearchTree<T>* current=this;
	while(current->right!=nullptr)
	{
		current=current->right;
	}
	return current;
}
template<class T>
SearchTree<T>*			SearchTree<T>::min			()const
{
	SearchTree<T>* current=this;
	while(current->left!=nullptr)
	{
		current=current->left;
	}
	return current;
}
template<class T>
void 				SearchTree<T>::insert			(const T& k)
{
	SearchTree<T>* pa_cur = nullptr;
	SearchTree<T>* current = this;
	while( current != nullptr )
	{
		pa_cur=current;
		if(current->getKey()< k)
		{
			current=current->right;
		}else{
			current=current->left;
		}
	}
	SearchTree<T>* newNode = new SearchTree<T>(k, nullptr, nullptr, pa_cur);
	if(pa_cur==nullptr)
	{
		Tree<T>::key=k;
	}else
	{
		if(k<=pa_cur->getKey())
		{
			pa_cur->setLeft(newNode);	
		}else
		{
			pa_cur->setRight(newNode);	
		}
	}
}
template<class T>
SearchTree<T>*			SearchTree<T>::search			(const T& k)const
{
	SearchTree<T>* result;
	if(this==nullptr || Tree<T>::key==k)
	{
		result = this;
	}else if(k<Tree<T>::key) 
	{
		result = Tree<T>::left->search(k);
	}else{
		result = Tree<T>::right->search(k);
	}
	return result;
}
template<class T>
SearchTree<T>*			SearchTree<T>::search_iter		(const T& k)const
{
	SearchTree<T>* current=this;
	while(current!= nullptr && current->key!=k)
	{
		if(k<current->key)
		{
			current=current->left;
		}else{
			current=current->right;
		}
	}
	return current;
}
template<class T>
SearchTree<T>*			SearchTree<T>::root			()const
{
	SearchTree<T>* current;
	while(current->parent!=nullptr)
	{
		current=current->parent;
	}
	return current;
}
template<class T>
SearchTree<T>*			SearchTree<T>::next			()const
{
	SearchTree<T>* result;
	if(Tree<T>::right != nullptr)
	{
		result=Tree<T>::right->min();
	}else{
		SearchTree<T> current=Tree<T>::parent;
		while(current!=nullptr && current->right==result)
		{
			result=current;
			current=current->parent;
		}
	}
	return result;
}

template<class T>
SearchTree<T>*			SearchTree<T>::remove			()
{
	SearchTree<T>* current;
	SearchTree<T>* pa_cur;
	if( Tree<T>::left == nullptr && Tree<T>::right == nullptr )
	{
		pa_cur=this;
	}else
	{
		pa_cur=next();
	}
	if(pa_cur->getLeft()!=nullptr)
	{
		current=pa_cur->getLeft();
	}else{
		current=pa_cur->getRight();
	}
	if(current!=nullptr)
	{
		current->setParent(pa_cur->getParent());
	}
	if(pa_cur->getParent()==nullptr)
	{
		SearchTree<T> cur=root;
	}else
	{ 
		if( pa_cur==pa_cur->getParent()->getLeft())
		{
			pa_cur->getParent()->setLeft(current);
		}else
		{
			pa_cur->getParent()->setRight(current);
		}
	}
	if(pa_cur!=current)
	{
		current->setKey(pa_cur->getKey());
	}
	return pa_cur;
}

template<class T>
void 			SearchTree<T>::inorder			()const
{				
	if(this != nullptr)
	{
		Tree<T>::left->inorder();
		std::cout<<Tree<T>::key<<" ";
		Tree<T>::right->inorder();
	}
	std::cout<<std::endl;
}

template<class T>
void 			SearchTree<T>::preorder		()const
{
			if(this != nullptr)
			{
				std::cout<<Tree<T>::key<<" ";
				Tree<T>::left->preorder();
				Tree<T>::right->preorder();
			}
			std::cout<<std::endl;
}
template<class T>
void			SearchTree<T>::postorder		()const
{
	if(this != nullptr)
	{
		Tree<T>::left->postorder();
		Tree<T>::right->postorder();
		std::cout<<Tree<T>::key<<" ";
	}
	std::cout<<std::endl;
}
	
