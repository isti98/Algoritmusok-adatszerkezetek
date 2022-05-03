
#include<iostream>

//Rendezések

#ifndef SORT
#define SORT

//Sorable osztály , Absztrakt osztály
//class T	-	A rendezhető rekordok típusa
//class S	-	A rendezhető rekordok egyik mezője, ami alapján a rendezés definálva van.
template<class T, class S> 
class Sortable
{
	public:
					Sortable		(){}		
		virtual bool 		lesser			(const T& t1, const T& t2){return lessThan(sortBy(t1), sortBy(t2));}
		virtual		~Sortable		(){} 
		
	protected:
		virtual S 		sortBy			(const T& t)const=0;
		virtual bool 		lessThan		(const S& s1, const S& s2)const=0;
	private:
		
};

//Sorozatok absztrakt osztály
//class T	-	Sorozat elemeinek típusa 
//class S	-	A sorozat reprezentációjának típusa
//member()	-	Megadja sorozat i-edik elemét.
template<class T, class Se>
class Series 
{
	public:
					Series			(){}
		virtual T&		member			(const unsigned int index)=0;
		virtual unsigned int	getSize		()const=0;	
	protected:
		Se*			data;		
	private:
};

//class T	-	A sorozat elemeinek típusa
//class S	-	Sorozat elemeinek az a mezője vagy generált értéke ,amely alapján a sorozat rendezve lesz
//class Se	- 	A sorozat adatszerkezete, típusa
template<class T, class S, class Se>
class Sort
{
	public:
					Sort			(Sortable<T, S>* so, Series<T, Se>* se):sortable(so), series(se){}
		void			bubbleSort		();
		//void 		insertSort		();
		//void			quickSort		();
							
	protected:
		Sortable<T,S>*		sortable;
		Series<T,Se>*		series;
		
	private:

};

template< class T, class S , class Se>
void 		Sort<T, S ,Se>::bubbleSort		()
{
	for(unsigned int i=1; i<series->getSize(); i++)
	{
		unsigned int j=i;
		while(j>0 && sortable->lesser(series->member(j),series->member(j-1)))
		{
			T sgd=series->member(j-1);
			series->member(j-1)=series->member(j);
			series->member(j)=sgd;
			j--;
		}
	}
}



#endif