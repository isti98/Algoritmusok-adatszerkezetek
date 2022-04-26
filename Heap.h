
#include "Tree.h"

//HEAP KUPAC ADATSZERKEZET


//TÖMBÖS IMPLEMENTÁCIÓ

// BINEÁRIS FÁS IMPLEMENTÁCIÓ
template<class T>
class Heap : public Tree<T>
{
	public:
					Heap			(){}
					Heap			(const T& k, Heap<T>* const l, Heap<T>* const r, Heap<T>* const p): Tree<T>::parent(p), Tree<T>::left(l), Tree<T>::right(r), Tree<T>::key(k){}
		
		Tree<T>*		next			()const override;
		Tree<T>*		max			()const override;
		Tree<T>*		min			()const override;
		Tree<T>*		search_iter		(const T& k)const;
		void 			insert			(const T& k) override;
		Tree<T>*		search			(const T& k)const override;
		void			remove			() override;
		
					~Heap			(){};
	protected:
	
	private:
};


