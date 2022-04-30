
//Kupac adatszerkezet dinamikus tömbbel ábrázolva

#include "Vector.h"
#include <iostream>

template<class T>
class HeapArray : protected Vector<T>
{
	public:
					HeapArray		(){}
					HeapArray		(const T* data, const unsigned int size);
		
		bool 			isEmpty		()const {return Vector<T>::getSize()==0;}
		T&			getMax			()const;
		T			removeMax		();
		void 			insert			(const T& k);
		
		friend std::ostream&	operator<<		(std::ostream& os, HeapArray<int>* const ha);
		
					~HeapArray		(){};
	protected:
		//T*			data;
		//unsigned int		size;
		//unsigned int		maxSize;
		
		void 			sink			(const unsigned int index);
		void 			lift			(const unsigned int index);	
		
	private:
};

std::ostream&				operator<<		(std::ostream& os, HeapArray<int>* const ha)
{
	for(int i=0; i<ha->Vector<int>::getSize(); i++)
	{
		os<<ha->Vector<int>::data[i]<<" ";
	}
	return os;
}

template< class T>
				HeapArray<T>::HeapArray		(const T* list, const unsigned int size)
{
	for(int i=0; i<size; i++)
	{
		insert(list[i]);
	}
}	
	
template< class T>
void				HeapArray<T>::sink			(const unsigned int index)
{	
	int i=index;
	int j=(index+1)*2-1;	
	bool lesser=true;
	while(j < Vector<T>::getSize() && lesser)
	{
		if(j+1<Vector<T>::getSize() && Vector<T>::data[j]<Vector<T>::data[j+1])
		{
			if(Vector<T>::data[j+1]>Vector<T>::data[i])
			{
				j=j+1;
				T sgd=Vector<T>::data[i];
				Vector<T>::data[i]=Vector<T>::data[j];
				Vector<T>::data[j]=sgd;
				i=j;
				j=(j+1)*2-1;
			}else{
				lesser=false;
			}
		}
		else if(Vector<T>::data[j]>Vector<T>::data[i]){
			T sgd=Vector<T>::data[i];
			Vector<T>::data[i]=Vector<T>::data[j];
			Vector<T>::data[j]=sgd;		
			i=j;
			j=(j+1)*2-1;
		}else
		{
			lesser=false;
		}
	}
}						
template< class T>		
void 				HeapArray<T>::lift			(const unsigned int index)			
{
	int i=index;
	int j=(index+1)/2-1;
	while(j >= 0 && Vector<T>::data[j]<Vector<T>::data[i])
	{
		T sgd = Vector<T>::data[i];
		Vector<T>::data[i]=Vector<T>::data[j];
		Vector<T>::data[j]=sgd;
		i=j;
		j=(i+1)/2-1;
	}	
}
template< class T>
T&				HeapArray<T>::getMax			()const
{
	return Vector<T>::data[0];
}					
	
template< class T>
void				HeapArray<T>::insert			(const T& e)
{
	Vector<T>::add(e,Vector<T>::getSize());
	lift(Vector<T>::getSize()-1);
}										
	
template< class T>
T				HeapArray<T>::removeMax			()
{
	T max=Vector<T>::data[0];
	Vector<T>::data[0]=Vector<T>::data[Vector<T>::getSize()-1];
	Vector<T>::size--;
	sink(0);
	return max;
}
