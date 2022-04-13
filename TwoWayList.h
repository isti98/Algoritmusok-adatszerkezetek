
#include <iostream>

//TwoWayLista adatszerkezet

template<class T>
class TwoWayNode
{
	public:
						TwoWayNode			(){};
						TwoWayNode			(TwoWayNode<T>* n, TwoWayNode<T>* p):next(n), prev(p){}
						TwoWayNode			(const T& v,TwoWayNode<T>* n, TwoWayNode<T>* p):next(n), value(v), prev(p){}
		typedef enum Exception{NULLPTR} Exception;
						
		void 				setValue			(const T& v){value=v;}
		T 				getValue			()const{return value;}
		void 				setNext			( TwoWayNode<T>* n){next=n;}
		TwoWayNode<T>* 		getNext			()const{return next;}
		void 				setPrev			( TwoWayNode<T>* p){prev=p;}
		TwoWayNode<T>* 		getPrev			()const{return prev;}
		
		virtual 			~TwoWayNode(){};
	
	protected:
		TwoWayNode<T>* 		next;
		TwoWayNode<T>* 		prev;
		
	private:
		T value;
};

template<class T>
class TwoWayList : public TwoWayNode<T>
{
	public:
						TwoWayList			(): length(0){TwoWayNode<T>(this,this);}
						TwoWayList			(T* t, const unsigned int l);
		
		typedef enum Expection{NULLPTR,OUTOFINDEX}Expection;
		
		TwoWayNode<T>*			getNode			(const unsigned int index)const;
		T 				get				(const unsigned int index)const{return getNode(index)->getValue();}
		unsigned int 			getLength			()const{return length;}
		void 				insert				(const T& v, const unsigned int index);
		void 				erase				(const unsigned int index);
		void 				setEmpty			();
		void 				sort				();
		void 				print				();
		
		//inline ostream& operator<<(ostream& os, const TwoWayList& l)const;
		//inline istream& operator>>(istream& is, TwoWayList& l);
		
		virtual 			~TwoWayList			();
		
	private:	
		unsigned int 			length;
		
	protected:

};

template<class T>
			TwoWayList<T>::TwoWayList			(T* t, const unsigned int l):length(l)
{
	TwoWayNode<T>* current=new TwoWayNode<T>(t[0], nullptr, this);
	TwoWayList::next=current;
	for(int i=1; i<length-1; i++)
	{
		TwoWayNode<T>* newNode=new TwoWayNode<T>(t[i],nullptr, current);
		current->setNext(newNode);
		current=newNode;
	}
	TwoWayNode<T>* newNode=new TwoWayNode<T>(t[length-1],this, current);
	current->setNext(newNode);
	TwoWayList<T>::prev=newNode;
}

template<class T>
void			TwoWayList<T>::setEmpty			()
{
	while(length!=0)
	{
		erase(0);
	}
}

template<class T>
void			TwoWayList<T>::print()
{
	for(TwoWayNode<T>* i=TwoWayNode<T>::next; i!=this; i=i->getNext())
	{
		std::cout<<i->getValue()<<" ";
	}
	std::cout<<std::endl;
}
template<class T>
TwoWayList<T>::~TwoWayList()
{
	setEmpty();
}

template<class T>
TwoWayNode<T>*			 TwoWayList<T>::getNode			(const unsigned int index)const
{
	if(index>=length)
	{
		throw(OUTOFINDEX);
	}else{
		TwoWayNode<T>* current;
		unsigned int mid=length/2;
		if(mid>=index)
		{
			current=TwoWayNode<T>::next;
			for(int i=0; i<index; i++)
			{
				current=current->TwoWayNode<T>::getNext();
			}
		}
		else{
			current=TwoWayNode<T>::prev;
			for(int i=0; i<length-index-1;i++)
			{
				current=current->getPrev();
			}
		}
		return current;
	}
}

template<class T>
void			 TwoWayList<T>::insert				(const T& v, const unsigned int index)
{
	if(index>length)
	{
		throw OUTOFINDEX;
	}
	else
	{
		TwoWayNode<T>* position;
		if(index==length)
		{
			position=this;	
		}else
		{
			position=getNode(index);
		}
		TwoWayNode<T>* prev_pos=position->getPrev();
		TwoWayNode<T>* newNode=new TwoWayNode<T>(v, position, prev_pos);
		prev_pos->setNext(newNode);
		position->setPrev(newNode);	
		length++;
	}
}

template<class T>
void 			TwoWayList<T>::erase				(const unsigned int index)
{
	if(index>=length)
	{
		throw(OUTOFINDEX);
	}else
	{
		TwoWayNode<T>* position=getNode(index);
		TwoWayNode<T>* prev_pos=position->TwoWayNode<T>::getPrev();
		prev_pos->TwoWayNode<T>::setNext(position->TwoWayNode<T>::getNext());
		position->TwoWayNode<T>::getNext()->TwoWayNode<T>::setPrev(prev_pos);
		delete position;	
		length--;
	}
}

