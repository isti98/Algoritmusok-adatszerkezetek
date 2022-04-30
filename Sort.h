
#include "Enumeration.h"

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
		virtual bool 		lesser			(const T& t1, const T& t2){return lesser(sortBy(t1), sortBy(t2));}
		virtual		~Sortable		(){} 
		
	protected:
		virtual S 		sortBy			(const T& t)const=0;
		virtual bool 		lesser			(const S& s1, const S& s2)=0;
	private:
		
};

//class T	-	A rendezhető rekordok típusa
//class S	-	A rendezhető rekordok egyik mezője, ami alapján a rendezés definálva van.
template<class T, class S>
class Sort
{
	public:
		void	 		SortInPlace		();		
	protected:
		Sortable<T,S>		sortable;
		Enumerator<T>		enor;
		
	private:

};

#endif
