
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
		if(current->getKey()<k)
		{
			current=current->getRight();
		}else{
			current=current->getLeft();
		}
	}
	if(pa_cur==nullptr)
	{
		Tree<T>::key=k;
	}else
	{
		Tree<T>* newNode = new SearchTree<T>(k, nullptr, nullptr, pa_cur);
		if(k>pa_cur->getKey())
		{
			pa_cur->setRight(newNode);	
		}else
		{
			pa_cur->setLeft(newNode);
		}
	}
}
template<class T>
Tree<T>*			SearchTree<T>::search			(const T& k)const
{
	const Tree<T>* result;
	if( Tree<T>::key==k)
	{	
		result = this;
	}
	else if(k>Tree<T>::key) 
	{
		if(Tree<T>::right!=nullptr)
		{
			result = Tree<T>::right->search(k);
		}else{
			result = nullptr;
		}
	}else{
		if(Tree<T>::left!=nullptr)
		{
			result = Tree<T>::left->search(k);
		}else{
			result = nullptr;
		}
	}
	return const_cast<Tree<T>*>(result);
}
template<class T>
Tree<T>*			SearchTree<T>::search_iter		(const T& k)const
{
	const Tree<T>* current=this;
	while(current!= nullptr && current->getKey()!=k)
	{
		if(k>current->getKey())
		{
			current=current->getRight();
		}else{
			current=current->getLeft();
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
	Tree<T>* result=Tree<T>::parent;
	if(Tree<T>::right != nullptr)
	{
		result=Tree<T>::right->min();
	}else{
		const Tree<T>* child=this;
		while( result!=nullptr && result->getRight()==child)
		{
			child=result;
			result=result->getParent();
		}
	}
	return result;
}

template<class T>
void				SearchTree<T>::remove			()
{
	
}

template<class T>
void 			SearchTree<T>::inorder			()const
{			
	if(Tree<T>::left!=nullptr)Tree<T>::left->inorder();
	std::cout<<Tree<T>::key<<" ";
	if(Tree<T>::right!=nullptr)Tree<T>::right->inorder();
}

template<class T>
void 			SearchTree<T>::preorder		()const
{
	std::cout<<Tree<T>::key<<" ";
	if(Tree<T>::left!=nullptr)Tree<T>::left->preorder();
	if(Tree<T>::right!=nullptr)Tree<T>::right->preorder();		
}
template<class T>
void			SearchTree<T>::postorder		()const
{
	if(Tree<T>::left!=nullptr)Tree<T>::left->postorder();
	if(Tree<T>::right!=nullptr)Tree<T>::right->postorder();
	std::cout<<Tree<T>::key<<" ";
}
	
