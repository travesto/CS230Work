/*
STL -- Standard Template Libary
Easily extendable and scalable!
--Containers
    ->
--Algorithms
    ->Sort
Generally if we have n containers and m algorithms, we would need n*m containers but, STL has iterators
--Iterators
    ->Algorithms implement iterator
    ->Iterator operates on container data
    ->Can be used on any data type with any algorithm
Because of iterators, we need n+m containers

*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<int> v;
    v.push_back(4);
    v.push_back(2);
    v.push_back(9);
}