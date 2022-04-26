
#include <cstdlib>

//VEKTOR adatszerkezet
// DINAMIKUS TÖMB

template<class T>
class Vector
{
	public:
					Vector			():size(0), maxSize(1){data=(T*)malloc(sizeof(T));}
					Vector			(const T* const data, const unsigned int size);
		
		typedef enum Exception {OUTOFINDEX} Exception;
		
		void 			add			(const T& e, const unsigned int index);
		void 			remove			(const unsigned int index);
		unsigned int 		getSize		()const{return size;}
		T&		operator[]		(const unsigned int index);
		
	protected:
		T*			data;
		unsigned int		size;
		unsigned int		maxSize;
};


template< class T>
					Vector<T>::Vector			(const T* const data, const unsigned int dataSize)
{
	T* place=(T*)malloc(sizeof(T)*dataSize*2);
	for(int i=0; i<dataSize; i++)
	{
		place[i]=data[i];
	}
	maxSize=dataSize*2;
	size=dataSize;
 }
template<class T>
void 					Vector<T>::add			(const T& e, const unsigned int index)
{
	if(index>size+1){
		throw Exception::OUTOFINDEX;	
	}else
	{
		size++;
		if(size>maxSize)
		{
			maxSize=size*2;
			T* newPlace=(T*)malloc(sizeof(T)*maxSize*2);
			for(int i=0; i<index; i++)
			{
				newPlace[i]=data[i];
			}
			newPlace[index]=e;
			for(int i=index; i<size-1; i++)
			{
				newPlace[i+1]=data[i];
			}
			free(data);
			data=newPlace;
		}
		else{
			for(int i=size-1; i>index; i--)
			{
				data[i]=data[i-1];
			}
			data[index]=e;
		}
	}
}

template<class T>
void 					Vector<T>::remove			(const unsigned int index)
{
	if(index>=size)
	{
		throw Exception::OUTOFINDEX;
	}else
	{
		size--;
		for(int i=index; i<size; i++)
		{
			data[i]=data[i+1];
		}	
	}
}	
template<class T>
T&					Vector<T>::operator[]			(const unsigned int index)
{
	return data[index];
}	
