#include <iostream>
#include "MagicalContainer.hpp"

namespace ariel{

    MagicalContainer::MagicalContainer(MagicalContainer &other){
        container = other.container;
    }

    MagicalContainer& MagicalContainer::operator=(const MagicalContainer &other){
        if (this == &other)
            return *this;
        container = other.container;
        return *this;
    }



    void MagicalContainer::addElement(int elem){

    }

    int MagicalContainer::size(){
        return 0;
    }

    void MagicalContainer::removeElement(int elem){

    }

    MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::begin() const 
    {   
        return AscendingIterator(container);
    }

    MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::end() const {
        return AscendingIterator(container);
    }



    MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::begin() const
    {
        return SideCrossIterator(*this);
    }

    MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::end() const {
        return SideCrossIterator(*this);
    }


    MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::begin() const
    {
        return PrimeIterator(*this);
    }

    MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::end()const {
        return PrimeIterator(*this);
    }



}
