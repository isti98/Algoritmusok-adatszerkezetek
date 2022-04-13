
//Verem adatszerkezet

template <class T>
class Stack
{
	private: 
		T* 				data;
		unsigned int 			size;
		unsigned int 			maxSize; 
	public:
						Stack				(const unsigned int s);
		
		typedef enum Exception{FULLSTACK,EMPTYSTACK}Exception; 
		
		void 				push				(const T& e);
		T 				top				()const;
		T 				pop				();
		bool 				isFull				()const{return size==maxSize;}
		bool 				isEmpty			()const{return size==0;}
		void 				setEmpty			(){size=0;}
						~Stack				();
};

template<class T>
				Stack<T>::Stack			(const unsigned int s):maxSize(s), size(0)
{
	data=(T*)malloc(sizeof(T)*maxSize);	
}

template<class T>
				Stack<T>::~Stack			()
{
	free(data);
}

template<class T>
void 				Stack<T>::push				(const T& e)
{
	if(!isFull())
	{
		data[size]=e;
		size++;
	}else
	{
		throw(FULLSTACK);
	}
}

template<class T>
T 				Stack<T>::pop				()
{
	if(!isEmpty())
	{
		size--;
		return data[size];
	}else{
		throw(EMPTYSTACK);
	}
}

template<class T>
T 				Stack<T>::top				()const
{
	if(!isEmpty())
	{
		return data[size-1];
	}else{
		throw(EMPTYSTACK);
	}
}
