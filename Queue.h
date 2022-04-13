
//Sor adatszerkezet

template<class T>
class Queue
{
	private:
		T*			 	data;
		unsigned int 			maxSize;
		unsigned int 			begin;
		unsigned int 			size;
		
	public:
						Queue(const unsigned int s);
		
		typedef enum Exception{FULLQUEUE,EMPTYQUEUE}Exception;
		
		void 				push				(const T&);
		T 				remove				();
		T 				first				()const;
		unsigned int 			getSize			()const{return size;}
		bool 				isFull				()const{return maxSize==size;}
		bool 				isEmpty			()const{return size==0;}
		void 				setEmpty			(){begin=0;size=0;}
		
						~Queue				(){free(data);} 
};

template<class T>
						Queue<T>::Queue		(const unsigned int s):maxSize(s), begin(0), size(0)
{
	data=(T*)malloc(sizeof(T)*maxSize);
}
template<class T>
void 						Queue<T>::push			(const T& e)
{
	if(!isFull())
	{
		data[(begin+size) % maxSize]=e;
		size++;
	}else{
		throw(FULLQUEUE);
	}
}
template<class T>
T 						Queue<T>::remove		()
{
	if(!isEmpty())
	{
		unsigned int i=begin;
		size--;
		begin=(begin+1) % maxSize;
		return data[i];
	}else{
		throw(EMPTYQUEUE);
	}

}
template<class T>
T 						Queue<T>::first		()const
{
	if(!isEmpty())
	{
		return data(begin);
	}else{
		throw(EMPTYQUEUE);
	}
}

