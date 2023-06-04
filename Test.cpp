#include "doctest.h"
#include "sources/MagicalContainer.hpp"
#include <stdexcept>

using namespace std;
using namespace ariel;

TEST_CASE("basics function"){
    
    MagicalContainer container;
    CHECK_EQ(container.size() , 0);
    CHECK_THROWS(container.removeElement(0));
    
    for(int i=0 ; i<10 ; i++){
        CHECK_NOTHROW(container.addElement(i));
        CHECK_EQ(container.size(),i+1);
    }
    for(int i=9 ; i>=0 ; i--){
        CHECK_NOTHROW(container.removeElement(i));
        CHECK_EQ(container.size() , i);
    }

    container.addElement(1);
    container.removeElement(2);
    CHECK_EQ(container.size() , 1);

}

TEST_CASE("AscendingIterator"){
    MagicalContainer container;
    container.addElement(1);
    container.addElement(5);
    container.addElement(2);
    container.addElement(4);
    container.addElement(3);
    container.addElement(6);

    
    SUBCASE("basic"){
        MagicalContainer::AscendingIterator it (container);
        auto begin_it = it.begin();
        auto end_it = it.end();
        CHECK_NE(*begin_it , *end_it);
    
        CHECK_EQ(*begin_it , 1);
        ++begin_it;
        CHECK_EQ(*begin_it , 2);
        ++begin_it;
        CHECK_EQ(*begin_it , 3);
        ++begin_it;
        CHECK_EQ(*begin_it , 4);
        ++begin_it;
        CHECK_EQ(*begin_it , 5);
        ++begin_it;
        CHECK_EQ(*begin_it , 6);
        CHECK_EQ(*begin_it , *end_it);
    }

    SUBCASE("2 iterators on the same container"){
        container.addElement(0);
        MagicalContainer::AscendingIterator it1 (container);
        MagicalContainer::AscendingIterator it2 (container);
        auto it_begin1 = it1.begin();
        auto it_begin2 = it2.begin();
        CHECK_EQ(*it_begin1 , 0);
        CHECK_EQ(*it_begin1 , *it_begin2);
        ++it_begin1;
        CHECK_EQ(*it_begin1 , 1);
        CHECK_EQ(*it_begin2 , 0);
        ++it_begin1;
        ++it_begin2;
        CHECK_EQ(*it_begin1 , 2);
        CHECK_EQ(*it_begin2 , 1);
        ++it_begin2;
        CHECK_EQ(*it_begin1 , *it_begin2);
    }
}

TEST_CASE("SideCrossIterator"){
    MagicalContainer container;
    container.addElement(1);
    container.addElement(2);
    container.addElement(3);
    container.addElement(4);
    container.addElement(5);
    container.addElement(6);

    SUBCASE("basic"){
        MagicalContainer::SideCrossIterator it(container);
        auto begin_it = it.begin();
        auto end_it = it.end();
        CHECK_NE(*begin_it , *end_it);
        CHECK_EQ(*begin_it , 1);
        CHECK_EQ(*end_it , 4);
        ++begin_it;
        CHECK_EQ(*begin_it , 6);
        ++begin_it;
        CHECK_EQ(*begin_it , 2);
        ++begin_it;
        CHECK_EQ(*begin_it , 5);
        ++begin_it;
        CHECK_EQ(*begin_it , 3);
        ++begin_it;
        CHECK_EQ(*begin_it , 4);
        CHECK_EQ(*begin_it , *end_it);
    }

    SUBCASE("2 iterators on the same container"){
        MagicalContainer::SideCrossIterator iter(container);
        MagicalContainer::SideCrossIterator iter2(container);
        auto it1 = iter.begin();
        auto it2 = iter2.begin();
        CHECK_EQ(*it1 , *it2);
        ++it1;
        CHECK_EQ(*it1 , 6);
        CHECK_EQ(*it2 , 1);
        ++it1;
        ++it2;
        CHECK_EQ(*it1 , 2);
        CHECK_EQ(*it2 , 6);
        ++it2;
        CHECK_EQ(*it1 , *it2);
    }
}

TEST_CASE("PrimeIterator"){
    MagicalContainer container;
    container.addElement(2);
    container.addElement(3);
    container.addElement(5);
    container.addElement(6);
    container.addElement(7);

    SUBCASE("basic"){
        MagicalContainer::PrimeIterator it(container);
        auto it1 = it.begin();
        auto it2 = it.end();
        CHECK_NE(*it1 , *it2);
        CHECK_EQ(*it1 , 2);
        CHECK_EQ(*it2 , 7);
        ++it1;
        CHECK_EQ(*it1 , 3);
        ++it1;
        CHECK_EQ(*it1 , 5);
        ++it1;
        CHECK_EQ(*it1 , 7);
        CHECK_EQ(*it1 , *it2);
    }

    SUBCASE("2 iterators on the same container"){
        MagicalContainer::PrimeIterator iter(container);
        MagicalContainer::PrimeIterator iter2(container);
        auto it1 = iter.begin();
        auto it2 = iter2.begin();
        CHECK_EQ(*it1 , *it2);
        ++it1;
        CHECK_EQ(*it1 , 3);
        CHECK_EQ(*it2 , 2);
        ++it1;
        ++it2;
        CHECK_EQ(*it1 , 5);
        CHECK_EQ(*it2 , 3);
        ++it1;
        ++it2;
        CHECK_EQ(*it1 , 7);
        CHECK_EQ(*it2 , 5);
        ++iter2;
        CHECK_EQ(*it1 , *it2);
    }
}





