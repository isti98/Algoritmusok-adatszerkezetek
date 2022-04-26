
#include "Tree.h"

template<class T>
class RaceTree : public Tree<T>
{
	public:
					RaceTree		(){}
					RaceTree		(const T& k, RaceTree<T>* const l, RaceTree<T>* const r, RaceTree<T>* const p): Tree<T>::parent(p), Tree<T>::left(l), Tree<T>::right(r), Tree<T>::key(k){}

		Tree<T>*		next			()const override;
		Tree<T>*		max			()const override;
		Tree<T>*		min			()const override;
		Tree<T>*		search_iter		(const T& k)const;
		void 			insert			(const T& k) override;
		Tree<T>*		search			(const T& k)const override;
		void 			remove			() override;
		
					~RaceTree		(){};
	protected:	
	
	private:	

};
