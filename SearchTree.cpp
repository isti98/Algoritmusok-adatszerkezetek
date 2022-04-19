
#include "Tree.h"

//Keresőfa adatszerkezet implemantcáija

template<class T>
Tree<T>*			SearchTree<T>::max			()const
{
	const Tree<T>* current=this;
	while(current->getRight()!=nullptr)
	{
		current=current->getRight();
	}
	return const_cast<Tree<T>*>(current);
}
template<class T>
Tree<T>*			SearchTree<T>::min			()const
{
	const Tree<T>* current=this;
	while(current->getLeft()!=nullptr)
	{
		current=current->getLeft();
	}
	return const_cast<Tree<T>*>(current);
}
template<class T>
void 				SearchTree<T>::insert			(const T& k)
{
	Tree<T>* pa_cur = nullptr;
	Tree<T>* current = this;
	while( current != nullptr )
	{
		pa_cur=current;
		if(current->getKey()< k)
		{
			current=current->getRight();
		}else{
			current=current->getLeft();
		}
	}
	Tree<T>* newNode = new SearchTree<T>(k, nullptr, nullptr, pa_cur);
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
Tree<T>*			SearchTree<T>::search			(const T& k)const
{
	const Tree<T>* result;
	if(this==nullptr || Tree<T>::key==k)
	{
		result = this;
	}else if(k<Tree<T>::key) 
	{
		result = Tree<T>::left->search(k);
	}else{
		result = Tree<T>::right->search(k);
	}
	return const_cast<Tree<T>*>(result);
}
template<class T>
Tree<T>*			SearchTree<T>::search_iter		(const T& k)const
{
	const Tree<T>* current=this;
	while(current!= nullptr && current->getKey()!=k)
	{
		if(k<current->getKey())
		{
			current=current->getLeft();
		}else{
			current=current->getRight();
		}
	}
	return const_cast<Tree<T>*>(current);
}
template<class T>
Tree<T>*			SearchTree<T>::root			()const
{
	Tree<T>* current;
	while(current->getParent()!=nullptr)
	{
		current=current->getParent();
	}
	return const_cast<Tree<T>*>(current);
}
template<class T>
Tree<T>*			SearchTree<T>::next			()const
{
	Tree<T>* result;
	if(Tree<T>::right != nullptr)
	{
		result=Tree<T>::right->min();
	}else{
		Tree<T>* current=Tree<T>::parent;
		while(current!=nullptr && current->getRight()==result)
		{
			result=current;
			current=current->getParent();
		}
	}
	return const_cast<Tree<T>*>(result);
}

template<class T>
Tree<T>*			SearchTree<T>::remove			()
{
	Tree<T>* current;
	Tree<T>* pa_cur;
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
		Tree<T>* cur=root();
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
	return const_cast<Tree<T>*>(pa_cur);
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
	
