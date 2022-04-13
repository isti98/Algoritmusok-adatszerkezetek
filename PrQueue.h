
#include <iostream>

//Prioritási sor adatszerkezet

template<class V, class P>
class PrNode
{
	public:
				PrNode		(){};
				PrNode		(const V& v, const P& p, PrNode<V,P>* n)	:next(n), value(v), priority(p){}
		void 		setValue	(const V& v)					{value=v;}
		V 		getValue	()const					{return value;}
		void 		setNext	( PrNode<V,P>* n)				{next=n;}
		PrNode<V,P>* 	getNext	()const					{return next;}
		P 		getPriority	()const					{return priority;}
		void 		setPriority	(const P& p)					{priority=p;}
		
		typedef enum Exception{NULLPTR} Exception;
		
				~PrNode(){};
	private:
		P 		priority;
		V 		value;
		PrNode<V,P>* 	next;
};



template<class V, class P>
class PrQueue
{
	private:
		PrNode<V,P>* 			first;
		unsigned int 			size;
		
	public:
						PrQueue			(): first(nullptr), size(0){}
		
		typedef enum Exception{EMPTYPRQUEUE}Exception;
		
		void 				add				(const V& v, const P& p);
		V 				remove				();
		V 				getFirst			()const{return first->getValue();}
		bool 				isEmpty			()const{return size==0;}
		void setEmpty();
		
						~PrQueue			(){setEmpty();}
};

template<class V,class P>
void 			PrQueue<V,P>::add		(const V& v, const P& p)
{
	if(isEmpty())
	{
		first=new PrNode<V,P>(v,p,nullptr);
		
	}else
	{
		PrNode<V,P>* current=first;
		PrNode<V,P>* prev=first;
		while(current!=nullptr && current->getPriority()>=p)
		{
			prev=current;
			current=current->getNext();
		}
		PrNode<V,P>* newNode=new PrNode<V,P>(v,p,current);
		if(prev==current)
		{
			first=newNode;		
		}else
		{
			prev->setNext(newNode);
		}
	}
	size++;
}

template<class V, class P>
V 			PrQueue<V, P>::remove			()
{
	if(!isEmpty())
	{
		PrNode<V,P>* max=first;
		first=first->getNext();
		V _value=max->getValue();
		delete max;
		size--;
		return _value;
	}else
	{
		throw(EMPTYPRQUEUE);
	}
}

template<class V, class P>
void 			PrQueue<V, P>::setEmpty		()
{
	for(int i=0; i<size; i++)
	{
		remove();
	}
}

