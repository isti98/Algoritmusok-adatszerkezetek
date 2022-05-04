//Riszterer István
//2022.03.31
//Algoritmusok és adatszerkezetek


#include <iostream>
//Adatszerkezetek
#include "List.h"
#include "Stack.h"
#include "Queue.h"
#include "PrQueue.h"
#include "TwoWayList.h"
#include "Vector.h"
//#include "Heap.h"
#include "HeapArray.h"
#include "SearchTree.h"
//#include "Map.h"
#include <map>
#include "Sort.h"


using namespace std;

#define NORMALMODE
#ifdef NORMALMODE

using namespace std;	

class City
{
	public:
		City(const int p, const string& i):pop(p),ID(i){}
		unsigned int pop;
		string ID;
	
		friend ostream& 		operator<<		(ostream& os, const City& c){os<<c.pop<<c.ID; return os;}
		friend bool 			operator<		(const City& c1, const City& c2){return c1.pop<c2.pop;}
		friend bool 			operator>		(const City& c1, const City& c2){return c1.pop>c2.pop;}
};

class CitySortable : public Sortable<City, unsigned int>
{
	public:	
					CitySortable		(){}	
	protected:
		unsigned int  		sortBy			(const City& t)const override
								{return t.pop;}
		bool 			lessThan		(const unsigned int& s1, const unsigned int& s2)const override
								{return s1<s2;}
};
class CitySeries : public Series<City, Vector<City>>
{
	public:
					CitySeries		(Vector<City>* d)
					{ Series<City, Vector<City>>::data=d;}
		City&			member			(const unsigned int index)override
					{return (*Series<City, Vector<City>>::data)[index];}
		unsigned int		getSize		()const override
					{return Series<City, Vector<City>>::data->getSize();}	
}; 

class Matrix{
	public:
		Matrix(int i, string j){x=i; y=j;}
		int x;
		string y;
};

int main()
{	
	Vector<City> cities;
	
	City m1(15,"a");
	City m2(14,"b");
	City m3(13,"c");
	City m4(12,"d");
	City m5(11,"aa");
	City m6(10,"bb");
	City m7(9,"cc");
	City m8(8,"dd");
	City m9(7,"aaa");
	City m10(6,"bbb");
	City m11(5,"ccc");
	City m12(4,"ddd");
	City m13(3,"aaaa");
	City m14(2,"bbbb");
	City m15(1,"cccc");
	cities.add(m1,cities.getSize());
	cities.add(m2,cities.getSize());
	cities.add(m3,cities.getSize());
	cities.add(m4,cities.getSize());
	cities.add(m5,cities.getSize());
	cities.add(m6,cities.getSize());
	cities.add(m7,cities.getSize());
	cities.add(m8,cities.getSize());
	cities.add(m9,cities.getSize());
	cities.add(m10,cities.getSize());
	cities.add(m11,cities.getSize());
	cities.add(m12,cities.getSize());
	cities.add(m13,cities.getSize());
	cities.add(m14,cities.getSize());
	cities.add(m15,cities.getSize());

	for(int i=0; i<cities.getSize(); i++)
	{
		cout<<cities[i].pop<<" "<<cities[i].ID<<" ";
	}
	cout<<endl;
	
	CitySortable c_so;
	CitySeries c_se(&cities);
	Sort<City, unsigned int, Vector<City>> sorting(&c_so, &c_se);
	//sorting.bubbleSort();
	//sorting.insertSort();
	//sorting.quickSort(0,cities.getSize()-1);
	//sorting.heapSort();
	
	
	for(int i=0; i<cities.getSize(); i++)
	{
		cout<<cities[i].pop<<" "<<cities[i].ID<<" ";
	}
	cout<<endl;
/*	
	HeapArray<City> ha;
	for(int i=0; i<cities.getSize() ; i++)
	{
		ha.insert(cities[i]);
	}
*/		
	//TODO
}

#else
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

//SEARCHTREE TESTING

TEST_CASE("SEARCHTREE")
{
	SECTION("set")
	{
		SECTION("not nullptr")
		{
			SearchTree<int> t1(10,nullptr, nullptr ,nullptr);
			SearchTree<int> t2(0, &t1, &t1 , &t1);
			t1.set(&t2);
			CHECK(t1.getRight()==&t1);
			CHECK(t1.getLeft()==&t1);
			CHECK(t1.getParent()==&t1);
			CHECK(t1.getKey()==0);
		}
		SECTION("nullptr")
		{
			SearchTree<int> t1(10,nullptr, nullptr ,nullptr);
			SearchTree<int>* t2=nullptr;
			CHECK_THROWS(t1.set(t2));
		}
	}
	
	int lista[] =  {5, 3, 10, 2, 7, 6, 9, 1, 4, 0, 8};
	SearchTree<int> st;
	
	for(int i=0; i<sizeof(lista)/sizeof(int); i++)
	{
		st.insert(lista[i]);
	}
	SECTION("high")
	{	
		SearchTree<int> st1;
		SearchTree<int> st2(0,nullptr, nullptr , nullptr);
		CHECK_THROWS(st1.Tree<int>::high());
		CHECK(st2.Tree<int>::high()==0);
		CHECK(st.Tree<int>::high()==4);
	}
	SECTION("insert + search + search_iter")
	{
		int result[] = {5,5,3,10,7,7,2,3,1,7};
		bool leftChild[] = {true , false , true , true , true , false , true , false , true , false};
		
		for(int i=0; i<<sizeof(lista)/sizeof(int); i++)
		{
			Tree<int>* found =st.search(lista[i]);
			CHECK(found->getParent()->getKey()==result[i]);
			if(leftChild[i]){
				CHECK(found->getParent()->getLeft() == found);
			}else{
				CHECK(found->getParent()->getRight() == found);
			}
		}
		for(int i=0; i<<sizeof(lista)/sizeof(int); i++)
		{
			Tree<int>* found =st.search_iter(lista[i]);
			CHECK(found->getParent()->getKey()==result[i]);
			if(leftChild[i]){
				CHECK(found->getParent()->getLeft() == found);
			}else{
				CHECK(found->getParent()->getRight() == found);
			}
		}
	}
	SECTION("min")
	{
		CHECK(st.min()->getKey()==0);
	}
	SECTION("max")
	{
		CHECK(st.max()->getKey()==10);
	}
	SECTION("root")
	{
		CHECK(st.min()->root()->getKey()==5);
		CHECK(st.max()->root()->getKey()==5);
	}
	SECTION("next")
	{
		for(int i=0; i<sizeof(lista)/sizeof(int)-1; i++)
		{
			CHECK(st.search(i)->next()->getKey()==i+1);
		}
	}
	SECTION("remove")
	{
		st.inorder();
		cout<<endl;
		for(int i=0; !st.isEmpty(); i++ )
		{
			cout<<"removed item: "<<lista[i]<<endl;
			st.search(lista[i])->remove();
			st.inorder();
			cout<<endl;
		}
	}
}



//TWO WAY NODE TESTING
TEST_CASE("TwoWayNode")
{
	TwoWayNode<int> twn1(10,nullptr,nullptr);
	TwoWayNode<int> twn2(20,nullptr,nullptr);
	TwoWayNode<int> twn3(30,nullptr,nullptr);
	
	SECTION("getValue")
	{
        	CHECK(twn1.getValue()==10);
        	CHECK(twn2.getValue()==20);
        	CHECK(twn3.getValue()==30);
	}
	SECTION("setValue")
	{
		twn1.setValue(1);
		twn2.setValue(2);
		twn3.setValue(3);
        	CHECK(twn1.getValue()==1);
        	CHECK(twn2.getValue()==2);
        	CHECK(twn3.getValue()==3);
	}
	SECTION("getPrev")
	{
        	CHECK(twn1.getPrev()==nullptr);
        	CHECK(twn2.getPrev()==nullptr);
        	CHECK(twn3.getPrev()==nullptr);
	}
	SECTION("setPrev")
	{
		twn1.setPrev(nullptr);
		twn2.setPrev(&twn1);
		twn3.setPrev(&twn2);
        	CHECK(twn1.getPrev()==nullptr);
        	CHECK(twn2.getPrev()==&twn1);
        	CHECK(twn3.getPrev()==&twn2);
	}
	SECTION("getNext")
	{
        	CHECK(twn1.getNext()==nullptr);
        	CHECK(twn2.getNext()==nullptr);
        	CHECK(twn3.getNext()==nullptr);
	}
	SECTION("setNext")
	{
		twn1.setNext(&twn2);
		twn2.setNext(&twn3);
		twn3.setNext(nullptr);
		CHECK(twn1.getNext()==&twn2);
        	CHECK(twn2.getNext()==&twn3);
        	CHECK(twn3.getNext()==nullptr);
	}
}

TEST_CASE("TwoWayList")
{
	TwoWayList<int>* twl=new TwoWayList<int>();
		
	SECTION("getNode")
	{
		SECTION("Expections")
		{
			CHECK_THROWS(twl->getNode(0));
			CHECK_THROWS(twl->getNode(1));
			CHECK_THROWS(twl->getNode(-1));
		}
		
		delete twl;
		int lista[]={1,2,3,4,5,6,7,8,9,10};
		TwoWayList<int>* twl = new TwoWayList<int>(lista, 10);
		SECTION("Within range")
		{
			CHECK(twl->getNode(0)->getValue()==1);
			CHECK(twl->getNode(3)->getValue()==4);
			CHECK(twl->getNode(6)->getValue()==7);
			CHECK(twl->getNode(9)->getValue()==10);
		}
	}
	delete twl;
	int lista[]={1,2,3,4,5,6,7,8,9,10};
	twl = new TwoWayList<int>(lista, 10);
	SECTION("get")
	{
		CHECK(twl->get(0)==1);
		CHECK(twl->get(2)==3);
		CHECK(twl->get(9)==10);
	}
	SECTION("insert")
	{
		twl->insert(0,0);
		CHECK(twl->get(0)==0);
		twl->insert(11,10);
		CHECK(twl->get(10)==11);
		twl->insert(12,2);
		CHECK(twl->get(2)==12);
		twl->insert(13,9);
		CHECK(twl->get(9)==13);
	}
	SECTION("erase")
	{
		int current=twl->get(1);
		twl->erase(0);
		CHECK(twl->get(0)==current);	
		
		current=twl->get(twl->getLength()-2);
		twl->erase(twl->getLength()-1);
		CHECK(twl->get(twl->getLength()-1)==current);
		
		current=twl->get(5);
		twl->erase(4);
		CHECK(twl->get(4)==current);
		
		current=twl->get(3);
		twl->erase(2);
		CHECK(twl->get(2)==current);
		
		CHECK_THROWS(twl->erase(100));
	}
	SECTION("setEmpty")
	{
		twl->setEmpty();
		CHECK(twl->getLength()==0);
		CHECK_THROWS(twl->get(0));
	}
	SECTION("sort")
	{
		CHECK(0==0);
	}
}
#endif
