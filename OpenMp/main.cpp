#include <iostream>
#include"parallelSum.h"


int main() {

   parallelSum<int> parallel_o;

   parallelSum<int> :: result res1;
   parallelSum<int> :: result res2;
   parallelSum<int> :: result res3;

    int size = 1000;
    int array[size];
    int num_threads;
    for (int i = 0; i < size;i++){
        array[i] = i;
    }

    for (int j = 1; j <= 16;j++){
        res1 = parallel_o.parallel_sum_std(array,size,j);

        std::cout << "Parallel Reduction :"<< j << "\n";
        std::cout << "The sum is :"<< res1.sum <<"\n";
        std::cout << "The time is :"<< res1.time <<"\n";
        std::cout << "******************************************"<< "\n";
    }

   for (int m = 1; m <= 16; m++){
       res2 = parallel_o.parallel_sum_omp1(array,size,m);

       std::cout << "OpenMP Custom Parallel Reduction :"<< m <<"\n";
       std::cout << "The sum is :"<< res2.sum <<"\n";
       std::cout << "The time is :"<< res2.time <<"\n";
       std::cout << "******************************************"<< "\n";
   }

    for (int n = 1; n <= 16; n++){
        res3 = parallel_o.parallel_sum_omp_builtin(array,size,n);

        std::cout << "OpenMP Built-in Reduction :"<< n <<"\n";
        std::cout << "The sum is :"<< res3.sum <<"\n";
        std::cout << "The time is :"<< res3.time <<"\n";
        std::cout << "******************************************"<< "\n";
    }

}
