
//Fa adatszerekezetek deklarációja

#ifndef TREE_H
#define TREE_H

template<class T>
class Tree
{
	public:
						Tree			(){};
	
		typedef enum Exception{EMPTYTREE}Exception;
		
		T				getKey			()const{return key;}
		Tree<T>*			getParent		()const{return parent;}
		Tree<T>*			getLeft		()const{return left;}
		Tree<T>*			getRight		()const{return right;}
		void				setKey			(const T& k){key=k;}
		void				setParent		(Tree<T>* p){parent=p;}
		void 				setLeft		(Tree<T>* l){left=l;}
		void 				setRight		(Tree<T>* r){right=r;}
		void 				operator=		(const Tree<T>& t1);
		
		virtual Tree<T>*		root			()const=0;
		virtual Tree<T>*		next			()const=0;
		virtual Tree<T>*		max			()const=0;
		virtual Tree<T>*		min			()const=0;
		virtual void 			insert			(const T& k)=0;
		virtual Tree<T>*		search			(const T& k)const=0;
		virtual void			remove			(const T& k)=0;	
		virtual void			inorder		()const=0;
		virtual void			preorder		()const=0;
		virtual void			postorder		()const=0;
		
		virtual 			~Tree			(){};		
	protected:
		T*	 			key;
		Tree<T>*			parent;
		Tree<T>* 			left;
		Tree<T>* 			right;	
	private:
};

template<class T>
void 				Tree<T>::operator=		(const Tree<T>& t1)
{
	setRight(t1->getRight());
	setLeft(t1->getLeft());
	setParent(t1->getParent());
	setKey(t1->getKey()); 
}

template<class T>
class SearchTree : public Tree<T>
{
	public:
					SearchTree		(const T& k, SearchTree<T>* l, SearchTree<T>* r, SearchTree<T>* p): Tree<T>::parent(p), Tree<T>::left(l), Tree<T>::right(r), Tree<T>::key(k){}
		
		SearchTree<T>*		root			()const override;
		SearchTree<T>*		next			()const override;;
		SearchTree<T>*		max			()const override;
		SearchTree<T>*		min			()const override;
		SearchTree<T>*		search_iter		(const T& k)const;
		void 			insert			(const T& k) override;
		SearchTree<T>*		search			(const T& k)const override;
		SearchTree<T>*		remove			() override;	
		void			inorder		()const override;
		void			preorder		()const override;
		void			postorder		()const override;
		
		
		 			~SearchTree		(){};
	
	private:
};

template<class T>
class Heap : public Tree<T>
{
	public:
					Heap			(const T& k, Heap<T>* l, Heap<T>* r, Heap<T>* p): Tree<T>::parent(p), Tree<T>::left(l), Tree<T>::right(r), Tree<T>::key(k){}
		
		Heap<T>*		root			()const override;
		Heap<T>*		next			()const override;
		Heap<T>*		max			()const override;
		Heap<T>*		min			()const override;
		void 			insert			(const T& k) override;
		Heap<T>*		search			(const T& k)const override;
		void			remove			(const T& k) override;	
		void			inorder		()const override;
		void			preorder		()const override;
		void			postorder		()const override;
		
					~Heap			(){};
	private:
		
};

template<class T>
class RaceTree : public Tree<T>
{
	public:
						RaceTree		(const T& k, RaceTree<T>* l, RaceTree<T>* r, RaceTree<T>* p): Tree<T>::parent(p), Tree<T>::left(l), Tree<T>::right(r), Tree<T>::key(k){}

		RaceTree<T>*		root			()const override;
		RaceTree<T>*		next			()const override;
		RaceTree<T>*		max			()const override;
		RaceTree<T>*		min			()const override;
		void 			insert			(const T& k) override;
		RaceTree<T>*		search			(const T& k)const override;
		void			remove			(const T& k) override;
		void			inorder		()const override;
		void			preorder		()const override;
		void			postorder		()const override;
		
					~RaceTree		(){};
	
	private:	

};

#endif


