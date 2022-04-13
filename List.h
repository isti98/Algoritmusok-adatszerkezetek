
#include <iostream>

//Lista adatszerkezet

template<class T>
class Node
{
	public:
					Node			(){};
					Node			(const T& v,Node<T>* n):next(n), value(v){}
		void 			setValue		(const T& v){value=v;}
		T 			getValue		()const{return value;}
		void 			setNext		( Node<T>* n){next=n;}
		Node<T>* 		getNext		()const{return next;}
		
		typedef enum Exception{NULLPTR} Exception;
		
					~Node(){};
	private:
		T 			value;
		Node<T>* 		next;
};

template<class T>
class List
{
	public:
					List			():next(nullptr),length(0){};
		
		typedef enum Expection{NULLPTR,OUTOFINDEX}Expection;
		
		Node<T>* 		getNode		(const unsigned int index)const;
		unsigned int 		getLength		()const{return length;}
		void 			insert			(const T& v, const unsigned int index);
		void 			erase			(const unsigned int index);
		void 			setEmpty		();
		void 			sort			();
		void 			print			()const;
		
		//inline ostream& operator<<(ostream& os, const List& l)const;
		//inline istream& operator>>(istream& is, List& l);
		
					~List			();
	private:	
		unsigned int 		length;
		Node<T>* 		next;

};
template<class T>
void 			List<T>::setEmpty			()
{
	for(int i=0; i<length;i++)
	{
		erase(0);
	}
	next=nullptr;
}

template<class T>
void 			List<T>::print				()const
{
	for(Node<T>* i=next; i!=nullptr; i=i->getNext())
	{
		std::cout<<i->getValue()<<" ";
	}
	std::cout<<std::endl;
}

template<class T>
			List<T>::~List				()
{
	setEmpty();
}

template<class T>
Node<T>* 		List<T>::getNode			(const unsigned int index)const
{
	if(index>length)
	{
		throw(OUTOFINDEX);
	}else{
		Node<T>* current=next;
		for(int i=0; i<index; i++)
		{
			current=current->getNext();
		}
		return current;
	}
}

template<class T>
void 			List<T>::insert			(const T& v, const unsigned int index)
{
	if(index>length)
	{
		throw (OUTOFINDEX);
	}else
	{
		if(index==0)
		{
			Node<T>* newNode=new Node<T>(v, this->next);
			this->next=newNode;			
		}else{
			Node<T>* current=next;
			for(int i=1; i<index; i++)	
			{
				current=current->getNext();
			}
			Node<T>* newNode=new Node<T>(v,current->getNext());
			current->setNext(newNode);
		}
		length++;
	}
}

template<class T>
void 		List<T>::erase				(const unsigned int index)
{
	if(index>length)
	{
		throw(OUTOFINDEX);
	}else
	{
		Node<T>* delItem;
		if(index==0)
		{
			delItem=next;
			this->next=delItem->getNext();
		}else{
			Node<T>* current=next;
			for(int i=1;i<index;i++)
			{
				current=current->getNext();
			}
			delItem=current->getNext();
			current->setNext(delItem->getNext());
			delete delItem;
			length--;
		}
	}
}

