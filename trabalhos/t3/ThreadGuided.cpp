#include <algorithm>
#include <iostream>
#include <string>
#include <thread>
#include <omp.h>

class SharedArray
{
    private:
        char *array;
        int index;
        int size;

    public:
        SharedArray(int n) : size(n), index(0)
        {
            array = new char[size];
            std::fill(array, array + size, '-');
        }

        ~SharedArray()
        {
            delete[] array;
        }

        void VaiAlahVonte(char c)
        {
            array[index] = c;
            spendSomeTime();
            index++;
        }


        void Carrega(char c)
        {
            #pragma omp critical
            {
                array[index] = c;
                spendSomeTime();
                index++;
            }
        }

        int countOccurrences(char c)
        {
            return std::count(array, array + size, c);
        }

        std::string toString()
        {
            return std::string(array, size);
        }

    private:
        void spendSomeTime()
        {
            for (int i = 0; i < 10000; i++)
                for (int j = 0; j < 1000; j++);
        }
};

class ArrayFiller
{
    private:
        static const int nThreads = 3;
        static const int nTimes = 20;
        SharedArray *array;

    public:
        ArrayFiller()
        {
            array = new SharedArray(nThreads * nTimes);
        }

        void fillArrayConcurrently(int op)
        {   
            int i;
            
                
                    #pragma omp parallel for schedule(guided) num_threads(nThreads) private(i)
                    for (i = 0; i < nTimes*nThreads; i++)
                        array->Carrega('A' + omp_get_thread_num());
                    
            
        }

        void printStats()
        {
            std::cout << array->toString() << std::endl;
            for (int i = 0; i < nThreads; ++i)
                std::cout << (char)('A' + i) << "="
                        << array->countOccurrences('A' + i) << " ";
            std::cout << std::endl;
        }

        ~ArrayFiller()
        {
            delete array;
        }
};

int main()
{
    std::cout << "Each thread should add its char to the array n times (n=20)" << std::endl;
    std::cout << "Correct results should total exactly nThreads*nTimes chars" << std::endl;

    std::cout << "\nCom tratamento de mutex e  scheduling Guided" << std::endl;
    ArrayFiller c1;
    c1.fillArrayConcurrently(0);
    c1.printStats();

}