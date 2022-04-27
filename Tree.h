
#include<iostream>

//Fa adatwzerekezetek deklarációja

#ifndef TREE_H
#define TREE_H


//Absztrakt osztály 
template<class T>
class Tree
{
	public:					
						
						Tree			():empty(true){}
		typedef enum Exception{EMPTYTREE,NULLPTR}Exception;
		
		T				getKey			()const{return key;}
		Tree<T>*			getParent		()const{return parent;}
		Tree<T>*			getLeft		()const{return left;}
		Tree<T>*			getRight		()const{return right;}
		bool 				isEmpty		()const{return empty; }
		void				setKey			(const T& k){key=k;}
		void				setParent		(Tree<T>* const p){parent=p;}
		void 				setLeft		(Tree<T>* const l){left=l;}
		void 				setRight		(Tree<T>* const r){right=r;}
		void 				set			(const Tree<T>* const t1);
		void				inorder		()const;
		void				preorder		()const;
		void				postorder		()const;
		Tree<T>*			root			()const;
		unsigned int 			high			()const;
		friend std::ostream&		operator<<		(std::ostream& os, Tree<T>* const t);
		
		virtual Tree<T>*		next			()const=0;
		virtual Tree<T>*		max			()const=0;
		virtual Tree<T>*		min			()const=0;
		virtual void 			insert			(const T& k)=0;
		virtual Tree<T>*		search			(const T& k)const=0;
		virtual Tree<T>*		search_iter		(const T& k)const=0;
		virtual void			remove			()=0;	

		virtual 			~Tree			(){};		
	protected:
		T	 			key;
		Tree<T>*			parent;
		Tree<T>* 			left;
		Tree<T>* 			right;	
		bool				empty;
		//unsigned int			high;
};
std::ostream&		operator<<		(std::ostream& os, Tree<int>* const t)
{
	if(t->getParent() != nullptr)	os<<"parent: "<<t->getParent()->getKey()<<std::endl;
	if(!t->isEmpty())		os<<"key: "<<t->getKey()<<std::endl;
	if(t->getLeft() != nullptr)	os<<"Left: "<<t->getLeft()->getKey()<<std::endl;
	if(t->getRight() != nullptr)	os<<"Right: "<<t->getRight()->getKey()<<std::endl;
	return os;
}
template<class T>
Tree<T>*			Tree<T>::root			()const
{
	Tree<T>* current;
	while(current->getParent()!=nullptr)
	{
		current=current->getParent();
	}
	return const_cast<Tree<T>*>(current);
}
template<class T>
void			Tree<T>::set		(const Tree<T>* const  t1)
{
	if(t1!=nullptr)
	{
		setRight(t1->getRight());
		setLeft(t1->getLeft());
		setParent(t1->getParent());
		setKey(t1->getKey()); 
		Tree<T>::empty=t1->isEmpty();
	}else{
		throw Exception::NULLPTR;
	}
}

template<class T>
void 			Tree<T>::inorder			()const
{		
	if(!Tree<T>::empty)
	{	
		if(Tree<T>::left!=nullptr)Tree<T>::left->inorder();
		std::cout<<Tree<T>::key<<" ";
		if(Tree<T>::right!=nullptr)Tree<T>::right->inorder();
	}
}	

template<class T>
void 			Tree<T>::preorder		()const
{
	if(!Tree<T>::empty)
	{
		std::cout<<Tree<T>::key<<" ";
		if(Tree<T>::left!=nullptr)Tree<T>::left->preorder();
		if(Tree<T>::right!=nullptr)Tree<T>::right->preorder();		
	}
}
template<class T>
void			Tree<T>::postorder		()const
{
	if(!Tree<T>::empty)
	{
		if(Tree<T>::left!=nullptr)Tree<T>::left->postorder();
		if(Tree<T>::right!=nullptr)Tree<T>::right->postorder();
		std::cout<<Tree<T>::key<<" ";
	}
}
template<class T>
unsigned int		Tree<T>::high			()const
{
	if(empty)
	{
		throw Exception::EMPTYTREE;
	}else
	{	
		unsigned int result;
		unsigned int maxLeft=0;
		unsigned int maxRight=0;
		if( left != nullptr) maxLeft= 1 + left->high();
		if( right != nullptr) maxRight = 1 + right->high();
		if( maxLeft>maxRight)
		{
			result=maxLeft;
		}else{
			result=maxRight;
		}
		return result;
	}
}
#endif


