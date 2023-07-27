// a4_sort_implementations.h

/////////////////////////////////////////////////////////////////////////
//
// Student Info
// ------------
//
// Name : <put your full name here!>
// St.# : <put your full SFU student number here>
// Email: <put your SFU email address here>
//
//
// Statement of Originality
// ------------------------
//
// All the code and comments below are my own original work. For any non-
// original work, I have provided citations in the comments with enough
// detail so that someone can see the exact source and extent of the
// borrowed work.
//
// In addition, I have not shared this work with anyone else, and I have
// not seen solutions from other students, tutors, websites, books,
// etc.
//
/////////////////////////////////////////////////////////////////////////

#pragma once

#include "a4_base.h"

using namespace std;

//
// Put the implementations of all the functions listed in a4_base.h here.
//
//
// Returns true if v[0] <= v[1] <= ... <= v[n-1], and false otherwise.
// Returns true if v is empty, i.e. an empty vector is considered sorted.
//
template <typename T>
bool is_sorted(vector<T> &v)
{
    ulong size = v.size();
    if (size < 2) {
        return true;
    }
    // case non-empty
    // check for out of place values
    for (int i = 0; i < size-1; i++) {
        if (v[i] > v[i+1]) {
            return false;   // out of order value found.
        }
    }

    // no value out of place. vector is sorted
    return true;
}

//
// Sorting algorithm headers. Each algorithm implements the named algorithm as
// described in the textbook (iquick sort is decribed in the assignment), and
// returns a SortStats object containing statistics about the run.
//
//
/*
    string sort_name;
    size_t vector_size = 0;
    ulong num_comparisons = 0;
    double cpu_running_time_sec = 0.0;
*/
template <typename T>
SortStats bubble_sort(vector<T> &v)
{
    // Note: when size=0 or 1, there's really no sorting done,
    // but I chose to still use the timer for code simplicity.

    size_t size = v.size();
    ulong num_comps = 0;
    clock_t start = clock();
    
    // if size = 0 or 1, then vector is sorted
        // do not use the below loop in this case, since operations between signed
        // and unsigned will result in overflow from the left for case size=0
    //else :
    if (size >= 2) {
        for (size_t i = 0; i < size - 1; i++)   // use size_t to handle large input
        {
            for (size_t j = 0; j < size - i - 1; j++)
            {
                num_comps++;
                if (v[j] > v[j + 1])
                {
                    swap(v[j], v[j + 1]);   // std::swap
                }
            }
        }
    }

    clock_t end = clock();
    double elapsed_cpu_time_sec = double(end - start) / CLOCKS_PER_SEC;

    return SortStats{"Bubble sort",
                     size,
                     num_comps,
                     elapsed_cpu_time_sec};
}

template <typename T>
SortStats insertion_sort(vector<T> &v)
{
    size_t size = v.size();
    ulong num_comps = 0;
    clock_t start = clock();
    
    // if size = 0 or 1, then vector is sorted
    //else :

    if (size >= 2) {

        for (size_t i = 1; i < size; i++)   // use size_t to handle large input
        {
            // insert key into correct position in sorted part of vector

            int j = i; // j keep track of where v[i] has been moved to

            // interpret comparison as between values in the vector,
            // so not counting other things such as boundary checks
 
            while ( j>0 ){   //left boundary check, then compare
                num_comps++;
                if ( v[j-1] > v[j] ) {
                    // Be careful swapping. if using a variable to store the key,
                    // make sure to update the variable since the key keeps moving left.
                    // to make things more efficient, a variable is not used here.
                    swap(v[j], v[j-1]);   // std::swap
                }
                else {
                    break;
                }

                j--;
            }
            
        }
        
    }

    clock_t end = clock();
    double elapsed_cpu_time_sec = double(end - start) / CLOCKS_PER_SEC;

    return SortStats{"Insertion sort",
                     size,
                     num_comps,
                     elapsed_cpu_time_sec};
}

template <typename T>
SortStats selection_sort(vector<T> &v)
{
    size_t size = v.size();
    ulong num_comps = 0;
    clock_t start = clock();
    
    // if size = 0 or 1, then vector is sorted
        // do not use the below loop if size=0, since operations between signed
        // and unsigned will result in overflow from the left
    //else :
    if (size >= 2) {

        int min; // index of min value

        for (size_t i = 0; i < size; i++)   // use size_t to handle large input
        {
            min = i; // starting minimal value.

            // find minimal value in unsorted vector
            for (size_t j = i+1; j < size; j++)
            {
                num_comps++;
                if (v[j] < v[min])   
                {
                    min = j; // found new min
                }
            }

            swap(v[i], v[min]);   // std::swap
        }

    }

    clock_t end = clock();
    double elapsed_cpu_time_sec = double(end - start) / CLOCKS_PER_SEC;

    return SortStats{"Selection sort",
                     size,
                     num_comps,
                     elapsed_cpu_time_sec};
}


//merge_sort helper 1
template <typename T>
void merge( vector<T> &v, int start, int mid, int end , ulong& num_comps) {
    // it's like putting 2 types of paint on a canvas, choosing the right one each time :)
    vector<T> canvas(end-start+1);
    //2 indexes to keep track of position in each part
    int id1 = start;
    int id2 = mid+1;
    
    for (size_t i = 0; i < end-start+1; i++)
    {   
        if (id1>mid) {  //left part reached end
            while(!(id2>end)) {
                canvas[i]=v[id2];
                i++;
                id2++;
                num_comps++;// successful comparison
            }
            num_comps++;// 1 extra comp for failed loop condition

            //put merged vector on canvas back to vector v
            for (int j = start; j < end + 1; j++) {
                v[j]=canvas[j-start];
            }
            return;// everything sorted
        }
        if (id2>end) {  //right part reached end
            while(!(id1>mid)) {
                canvas[i]=v[id1];
                i++;
                id1++;
                num_comps++;
            }
            num_comps++; // failed comp

            //put merged vector on canvas back to vector v
            for (int j = start; j < end + 1; j++) {
                v[j]=canvas[j-start];
            }
            return;// everything sorted
        }
        num_comps++;
        if (v[id1]<v[id2]) {
            canvas[i] = v[id1];
            id1++;
        }
        else if (v[id2]<v[id1]) {
            num_comps++;
            canvas[i] = v[id2];
            id2++;
        }
        else {
            num_comps++;//catch comp of else if... in case if fails
        }
    }
    
}

// merge_sort recursive function
// problem is marked by start and end indexes
template <typename T>
void merge_sort_recur( vector<T> &v, int start, int end, ulong& num_comps) {

    // base cases
    if (end-start == 1) { // size 2 problem
        if (v[start] > v[end]) {
            swap(v[start], v[end]);
        }
        return;
    }
    else if (start == end) { // size 1
        return;
    }

    // decompose into more recursive parts
    int mid = ((start+end)/2); // divide from approximate middle
    //divide into 2 parts
    merge_sort_recur(v, start, mid, num_comps);
    merge_sort_recur(v, mid+1, end, num_comps);
    
    // now both parts are sorted. merge them.

    // the 2 parts are next to each other, so mid gives info about both
    // the end of left part and start of right part
    merge(v, start, mid, end, num_comps); 

}

template <typename T>
SortStats merge_sort(vector<T> &v)
{
    size_t size = v.size();
    ulong num_comps = 0;
    clock_t start = clock();
    
    // if size = 0 or 1, then vector is sorted
        // do not use the below loop in this case, since operations between signed
        // and unsigned will result in overflow from the left for case size=0
    //else :
    if (size >= 2) {

        merge_sort_recur(v, 0, v.size() - 1, num_comps);

    }

    clock_t end = clock();
    double elapsed_cpu_time_sec = double(end - start) / CLOCKS_PER_SEC;

    return SortStats{"Merge sort",
                     size,
                     num_comps,
                     elapsed_cpu_time_sec};
}


template <typename T>
int quick_sort_arrange(vector<T> &v, int start, int end, ulong& num_comps) {
    // arranges vector and returns index of pivot
    // assume: v.size() >=2

    // Let X be element 1 index left of pivot.
    // If v[index] > pivot, insert it behind pivot.
    // This is done by swapping pivot with X, then swapping X with v[index]

    // if v[index] <= pivot, then it's already in place. So index++.
    // else a swap is done, and the new v[index] needs to be compared with pivot again.
    //      so index stays same.
    
    int index = start;
    int pivot = end;    // using index of pivot, since it's easier when swapping
    while( pivot-index >= 2) {
        if (v[index] > v[pivot]) {
            swap(v[pivot],v[pivot-1]);  // swap v[index] with pivot
            swap(v[index],v[pivot]);    // swap X with v[index]
            pivot--;    // correct pivot position
        }
        else {  // v[index] <= v[pivot]
            index++;
        }
        num_comps++;
    }

    if (v[index] > v[pivot]) {  // case size = 2
        swap(v[index], v[pivot]);
        pivot--;
    }
    num_comps++;
    return pivot;
    
}

template <typename T>
void quick_sort_recur(vector<T> &v, int start, int end, ulong& num_comps) {
    // base case
    if (start>=end) {    // size = 1 or 0 or -1
        return; // already sorted
    }

    // decompose
    int split;
    split = quick_sort_arrange(v, start, end, num_comps);
    quick_sort_recur(v, start, split-1, num_comps);
    quick_sort_recur(v, split+1, end, num_comps);      

}

template <typename T>
SortStats quick_sort(vector<T> &v)
{
    size_t size = v.size();
    ulong num_comps = 0;
    clock_t start = clock();
    
    // if size = 0 or 1, then vector is sorted
        // do not use the below loop in this case, since operations between signed
        // and unsigned will result in overflow from the left for case size=0
    //else :
    if (size >= 2) {
    
        quick_sort_recur(v, 0, size-1, num_comps);

    }

    clock_t end = clock();
    double elapsed_cpu_time_sec = double(end - start) / CLOCKS_PER_SEC;

    return SortStats{"Quick sort",
                     size,
                     num_comps,
                     elapsed_cpu_time_sec};
}

template <typename T>
void shell_insertion(vector<T>& v, size_t start, size_t end, ulong& num_comps) {
    // insertion sort to be used in shell sort
    
        for (size_t i = start; i < end-start+1; i++)   // use size_t to handle large input
        {
            // insert key into correct position in sorted part of vector

            int j = i; // j keep track of where v[i] has been moved to

            // interpret comparison as between values in the vector,
            // so not counting other things such as boundary checks
 
            while ( j>0 ){   //left boundary check, then compare
                num_comps++;
                if ( v[j-1] > v[j] ) {
                    // Be careful swapping. if using a variable to store the key,
                    // make sure to update the variable since the key keeps moving left.
                    // to make things more efficient, a variable is not used here.
                    swap(v[j], v[j-1]);   // std::swap
                }
                else {
                    break;
                }

                j--;
            }
            
        }
}

template <typename T>
SortStats shell_sort(vector<T> &v)
{
    size_t size = v.size();
    ulong num_comps = 0;
    clock_t start = clock();
    
    // if size = 0 or 1, then vector is sorted
        // do not use the below loop in this case, since operations between signed
        // and unsigned will result in overflow from the left for case size=0
    //else :
    if (size >= 2) {

    // Below code is from Programiz and is modified
    // Link: https://www.programiz.com/dsa/shell-sort
    // Rearrange elements at each n/2, n/4, n/8, ... intervals
    for (int interval = size / 2; interval > 0; interval /= 2) {
        for (int i = interval; i < size; i ++) {
        T temp = v[i];
        int j;
        for (j = i; j >= interval && (v[j - interval] > temp); j -= interval) {
            num_comps++;
            v[j] = v[j - interval];
        }
        v[j] = temp;
        }
    }
    }
        

    clock_t end = clock();
    double elapsed_cpu_time_sec = double(end - start) / CLOCKS_PER_SEC;

    return SortStats{"Shell sort",
                     size,
                     num_comps,
                     elapsed_cpu_time_sec};
}

template <typename T>
SortStats iquick_sort(vector<T> &v)
{
    size_t size = v.size();
    ulong num_comps = 0;
    clock_t start = clock();

    SortStats s;    // get num_comps from the returned value of chosen sort

    // With the implementations done in this flie, quick_sort is almost always faster than
    // insertion_sort,even for small vector sizes
    ulong threshold = 1000;

    if (v.size()>threshold) {
        s = quick_sort(v);
    }
    else {
        s = insertion_sort(v);
    }
    num_comps = s.num_comparisons;

    clock_t end = clock();
    double elapsed_cpu_time_sec = double(end - start) / CLOCKS_PER_SEC;

    return SortStats{"Iquick sort",
                     size,
                     num_comps,
                     elapsed_cpu_time_sec};
}
// See description in assignment.

//
// Returns a vector of n randomly chosen ints, each <= max and >= min.
//
vector<int> rand_vec(int n, int min, int max)
{
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        // max-min+1 is length of range
        v[i] = (rand() % (max-min+1)) + min;    
    }
    return v;
}