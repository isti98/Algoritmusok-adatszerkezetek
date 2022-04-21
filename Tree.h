
//Fa adatszerekezetek deklarációja

#ifndef TREE_H
#define TREE_H


//Absztrakt osztály 
template<class T>
class Tree
{
	public:					
						
						Tree			(){}
		typedef enum Exception{EMPTYTREE,NULLPTR}Exception;
		
		T				getKey			()const{return key;}
		Tree<T>*			getParent		()const{return parent;}
		Tree<T>*			getLeft		()const{return left;}
		Tree<T>*			getRight		()const{return right;}
		void				setKey			(const T& k){key=k;}
		void				setParent		(Tree<T>* const p){parent=p;}
		void 				setLeft		(Tree<T>* const l){left=l;}
		void 				setRight		(Tree<T>* const r){right=r;}
		void 				set			(const Tree<T>* const t1);
		
		virtual Tree<T>*		root			()const=0;
		virtual Tree<T>*		next			()const=0;
		virtual Tree<T>*		max			()const=0;
		virtual Tree<T>*		min			()const=0;
		virtual void 			insert			(const T& k)=0;
		virtual Tree<T>*		search			(const T& k)const=0;
		virtual Tree<T>*		search_iter		(const T& k)const=0;
		virtual void			remove			()=0;	
		virtual void			inorder		()const=0;
		virtual void			preorder		()const=0;
		virtual void			postorder		()const=0;
		
		virtual 			~Tree			(){};		
	protected:
		T	 			key;
		Tree<T>*			parent;
		Tree<T>* 			left;
		Tree<T>* 			right;	
};

template<class T>
void			Tree<T>::set		(const Tree<T>* const  t1)
{
	if(t1!=nullptr)
	{
		setRight(t1->getRight());
		setLeft(t1->getLeft());
		setParent(t1->getParent());
		setKey(t1->getKey()); 
	}else{
		throw Exception::NULLPTR;
	}
}

template<class T>
class SearchTree : public Tree<T>
{
	public:
					SearchTree		(){Tree<T>::setLeft(nullptr); Tree<T>::setRight(nullptr); Tree<T>::setParent(nullptr);}
					SearchTree		(const T& k, Tree<T>* const l, Tree<T>* const r, Tree<T>* const p){Tree<T>::setKey(k); Tree<T>::setLeft(l); Tree<T>::setRight(r); Tree<T>::setParent(p);}
					//SearchTree		(const T& k, Tree<T>* const l, Tree<T>* const r, Tree<T>* const p): Tree<T>::parent(p), Tree<T>::left(l), Tree<T>::right(r), Tree<T>::key(k){}
		
		Tree<T>*		root			()const override;
		Tree<T>*		next			()const override;
		Tree<T>*		max			()const override;
		Tree<T>*		min			()const override;
		Tree<T>*		search_iter		(const T& k)const;
		void 			insert			(const T& k) override;
		Tree<T>*		search			(const T& k)const override;
		void			remove			() override;
		void			inorder		()const override;
		void			preorder		()const override;
		void			postorder		()const override;
		
		
		 			~SearchTree		(){};
	protected:
	
	private:
};

template<class T>
class Heap : public Tree<T>
{
	public:
					Heap			(){}
					Heap			(const T& k, Heap<T>* l, Heap<T>* r, Heap<T>* p): Tree<T>::parent(p), Tree<T>::left(l), Tree<T>::right(r), Tree<T>::key(k){}
		
		Tree<T>*		root			()const override;
		Tree<T>*		next			()const override;
		Tree<T>*		max			()const override;
		Tree<T>*		min			()const override;
		Tree<T>*		search_iter		(const T& k)const;
		void 			insert			(const T& k) override;
		Tree<T>*		search			(const T& k)const override;
		void			remove			() override;
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
						RaceTree		(){}
						RaceTree		(const T& k, RaceTree<T>* l, RaceTree<T>* r, RaceTree<T>* p): Tree<T>::parent(p), Tree<T>::left(l), Tree<T>::right(r), Tree<T>::key(k){}

		Tree<T>*		root			()const override;
		Tree<T>*		next			()const override;
		Tree<T>*		max			()const override;
		Tree<T>*		min			()const override;
		Tree<T>*		search_iter		(const T& k)const;
		void 			insert			(const T& k) override;
		Tree<T>*		search			(const T& k)const override;
		void 			remove			() override;
		void			inorder		()const override;
		void			preorder		()const override;
		void			postorder		()const override;
		
					~RaceTree		(){};
	
	private:	

};

#endif


