#pragma once
#include <iostream>
#include <vector>

using namespace std;

namespace ariel{

    class MagicalContainer{

        private:
            vector <int> container;

        public:
            MagicalContainer() = default;
            MagicalContainer(MagicalContainer &other);
            ~MagicalContainer() = default;
            
            void addElement(int elem);
            void removeElement(int elem);
            int size();

            MagicalContainer& operator=(const MagicalContainer &other);
            
            MagicalContainer(MagicalContainer&&) = delete;

            // Disable move assignment operator
            MagicalContainer& operator=(MagicalContainer&&) = delete;

            
        class AscendingIterator{

            private:
                const MagicalContainer &container;
                size_t cur_index;

            public:
                AscendingIterator(const MagicalContainer &cont) : container(cont), cur_index(0){}
                AscendingIterator(const AscendingIterator &cont) : container(cont.container), cur_index(0){}
                ~AscendingIterator() = default;
                AscendingIterator &operator=(const AscendingIterator &other){return *this;}
                AscendingIterator& operator=(AscendingIterator&&) = delete;
                
                
                
                
                
                int operator*() const {return 0;}
                bool operator==(const AscendingIterator& other) const{ return false;}
                bool operator!=(const AscendingIterator& other) const{ return false;}
                bool operator>(const AscendingIterator& other) const{ return false;}
                bool operator<(const AscendingIterator& other) const{ return false;}
                AscendingIterator &operator++(){return *this;}
                AscendingIterator begin() const;
                AscendingIterator end() const;
        };

        class SideCrossIterator{

            private:
                const MagicalContainer &container;
                size_t cur_index;

            public:
                SideCrossIterator(const MagicalContainer& cont) : container(cont), cur_index(0){}
                SideCrossIterator(const SideCrossIterator& cont) : container(cont.container), cur_index(0){}
                
                SideCrossIterator &operator=(const SideCrossIterator &other){return *this;}
                SideCrossIterator& operator++(){return *this;}
                int operator*() const {return 0;}
                bool operator==(const SideCrossIterator& other)const{ return false;}
                bool operator!=(const SideCrossIterator& other)const { return false;}
                bool operator>(const SideCrossIterator& other)const{ return false;}
                bool operator<(const SideCrossIterator& other)const{ return false;}
                

                SideCrossIterator begin() const;
                SideCrossIterator end() const;

        };

        class PrimeIterator {
            private:
                const MagicalContainer& container;
                size_t cur_index;

            public:
                PrimeIterator(const MagicalContainer& cont) : container(cont), cur_index(0){}
                PrimeIterator(const PrimeIterator& cont) : container(cont.container), cur_index(0){}
                PrimeIterator &operator=(const PrimeIterator &other){return *this;}
                PrimeIterator& operator++(){return *this;}
                int operator*() const {return 0;}
                bool operator==(const PrimeIterator& other) const{ return false;}
                bool operator!=(const PrimeIterator& other) const{ return false;}
                bool operator>(const PrimeIterator& other) const{ return false;}
                bool operator<(const PrimeIterator& other) const{ return false;}
                
                static bool isPrime(int num){
                    return false;
                }
                

                PrimeIterator begin() const;
                PrimeIterator end() const;
        };


    };
}
