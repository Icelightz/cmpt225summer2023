#include "a4_base.h"
#include "a4_sort_implementations.h"
#include <cassert>

using namespace std;

void test_is_sorted_int() {
    vector<int> v;
    v={};
    cout << is_sorted(v) << endl;
    v={1};
    cout << v.size() << endl;
    cout << is_sorted(v) << endl;
    v={2,1};
    cout << is_sorted(v) << endl;
    v={1,2};
    cout << is_sorted(v) << endl;
    v={1,2,3};
    cout << is_sorted(v) << endl;
    v={1,3,2};
    cout << is_sorted(v) << endl;
    v={2,1,3};
    cout << is_sorted(v) << endl;
    v={2,3,1};
    cout << is_sorted(v) << endl;
    v={3,1,2};
    cout << is_sorted(v) << endl;
    v={3,2,1};
    cout << is_sorted(v) << endl;
    v={-100,-2,-3,10,20};
    cout << is_sorted(v) << endl;
    v={-100,-2,-3,-29};
    cout << is_sorted(v) << endl;
}

void test_is_sorted_string() {
    vector<string> v;
    v={"hi","ha"};
    cout << is_sorted(v) << endl;
    v={"a","b","c"};
    cout << is_sorted(v) << endl;
    v={"c","b","a"};
    cout << is_sorted(v) << endl;
}

void print_stats() {
    vector<int> v;
    v={3,1,2,5,4,6,7,8,9,11,12,13,14};
    SortStats s = bubble_sort(v);
    cout << s << endl;
    cout << s.to_csv() << endl;
    for (int i = 0; i < 10; i++)
    {
        vector<int> v;
        v=rand_vec(10,-10,10);
        SortStats s = bubble_sort(v);
        cout << s << endl;
        cout << s.to_csv() << endl;
    }
    
}

void test_rand_vec() {

    // 10 tests
    for (int i = 0; i < 10; i++)
    {
        cout << rand_vec(3,3,5)<< endl;
    }
    
}

void test_bubble_sort() {
    vector<int> v;
    v={};
    bubble_sort(v);
    cout << is_sorted(v) << endl;
    v={1};
    bubble_sort(v);
    cout << is_sorted(v) << endl;
    v={2,1};
    bubble_sort(v);
    cout << is_sorted(v) << endl;
    v={1,2};
    bubble_sort(v);
    cout << is_sorted(v) << endl;
    v={1,2,3};
    insertion_sort(v);
    cout << is_sorted(v) << endl;
    v={1,3,2};
    bubble_sort(v);
    cout << is_sorted(v) << endl;
    v={2,1,3};
    bubble_sort(v);
    cout << is_sorted(v) << endl;
    v={2,3,1};
    bubble_sort(v);
    cout << is_sorted(v) << endl;
    v={3,1,2};
    bubble_sort(v);
    cout << is_sorted(v) << endl;
    v={3,2,1};
    bubble_sort(v);
    cout << is_sorted(v) << endl;
    v={-100,-2,-3,10,20};
    bubble_sort(v);
    cout << is_sorted(v) << endl;
    v={-100,-2,-3,-29};
    bubble_sort(v);
    cout << is_sorted(v) << endl;
}

void test_insertion_sort() {
    vector<int> v;

    v={};
    insertion_sort(v);
    cout << v << endl;
    cout << is_sorted(v) << endl;

    v={1};
    insertion_sort(v);
    cout << v << endl;
    cout << is_sorted(v) << endl;

    v={2,1};
    insertion_sort(v);
    cout << v << endl;
    cout << is_sorted(v) << endl;

    v={1,2};
    insertion_sort(v);
    cout << is_sorted(v) << endl;

    v={1,2,3};
    insertion_sort(v);
    cout << v << endl;
    cout << is_sorted(v) << endl;

    v={1,3,2};
    insertion_sort(v);
    cout << v << endl;
    cout << is_sorted(v) << endl;

    v={2,1,3};
    insertion_sort(v);
    cout << v << endl;
    cout << is_sorted(v) << endl;

    v={2,3,1};
    insertion_sort(v);
    cout << v << endl;
    cout << is_sorted(v) << endl;

    v={3,1,2};
    insertion_sort(v);
    cout << v << endl;
    cout << is_sorted(v) << endl;

    v={3,2,1};
    insertion_sort(v);
    cout << v << endl;
    cout << is_sorted(v) << endl;

    v={-100,-2,-3,10,20};
    insertion_sort(v);
    cout << v << endl;
    cout << is_sorted(v) << endl;

    v={-100,-2,-3,-29};
    insertion_sort(v);
    cout << v << endl;
    cout << is_sorted(v) << endl;
}

void stat_insertion_sort() {
    vector<int> v;
    SortStats s;

    v=rand_vec(100000,-1000,1000);
    s=insertion_sort(v);
    cout << s << endl;
}

/*
void test_selection_sort() {
    vector<int> v;

    v={};
    selection_sort(v);
    cout << v << endl;
    cout << is_sorted(v) << endl;

    v={1};
    selection_sort(v);
    cout << v << endl;
    cout << is_sorted(v) << endl;

    v={2,1};
    selection_sort(v);
    cout << v << endl;
    cout << is_sorted(v) << endl;

    v={1,2};
    selection_sort(v);
    cout << v << endl;
    cout << is_sorted(v) << endl;

    v={1,2,3};
    selection_sort(v);
    cout << v << endl;
    cout << is_sorted(v) << endl;

    v={1,3,2};
    selection_sort(v);
    cout << v << endl;
    cout << is_sorted(v) << endl;

    v={2,1,3};
    selection_sort(v);
    cout << v << endl;
    cout << is_sorted(v) << endl;

    v={2,3,1};
    selection_sort(v);
    cout << v << endl;
    cout << is_sorted(v) << endl;

    v={3,1,2};
    selection_sort(v);
    cout << v << endl;
    cout << is_sorted(v) << endl;

    v={3,2,1};
    selection_sort(v);
    cout << v << endl;
    cout << is_sorted(v) << endl;

    v={-100,-2,-3,10,20};
    selection_sort(v);
    cout << v << endl;
    cout << is_sorted(v) << endl;

    v={-100,-2,-3,-29};
    selection_sort(v);
    cout << v << endl;
    cout << is_sorted(v) << endl;

}
*/

/*
void test_merge_sort_recur() {
    vector<int> v;
    int num_comps = 0;

    v={5,4,3,2,1};
    cout << v << endl;
    merge_sort_recur(v,0,v.size()-1,int& num_comps);
    cout << v << endl;

    v={5,4,3,2,1,0};
    cout << v << endl;
    merge_sort_recur(v,0,v.size()-1,int& num_comps);
    cout << v << endl;

    v={5,4,3,2,1,0,-1,-2};
    cout << v << endl;
    merge_sort_recur(v,0,v.size()-1,int& num_comps);
    cout << v << endl;
    
}
*/

/*
void test_merge() {
    vector<int> v;

    v={1,3,5,2,4,6};
    cout << v << endl;
    merge(v,0,2,5);
    cout << v << endl;

    v={};
    cout << v << endl;
    merge(v,0,0,0);
    cout << v << endl;

    v={1};
    cout << v << endl;
    merge(v,0,0,0);
    cout << v << endl;

    v={1,2};
    cout << v << endl;
    merge(v,0,0,1);
    cout << v << endl;

    v={2,-1};
    cout << v << endl;
    merge(v,0,0,1);
    cout << v << endl;

    v={-1,5, 1,3,5,2,4,6, 21,-10};
    cout << v << endl;
    merge(v,2,4,7);
    cout << v << endl;

    /*
    // broken test
    for (int j = 1; j < 10; j++) {
        for (size_t i = 0; i < 20; i++)
        {
            v=rand_vec(i,-10,10);
            cout << v << endl;
            merge(v,0,(i-1)/2,i-1);
            cout << v << endl;
        }
    }
    
    
}*/

void test_merge_sort() {
    vector<int> v;
    SortStats s;

    v={};
    cout << v << endl;
    merge_sort(v);
    cout << v << endl;
    cout << is_sorted(v) << endl;
    s = merge_sort(v);
    cout << s << endl;

    v={1};
    cout << v << endl;
    merge_sort(v);
    cout << v << endl;
    cout << is_sorted(v) << endl;
    s = merge_sort(v);
    cout << s << endl;

    v={2,1};
    cout << v << endl;
    merge_sort(v);
    cout << v << endl;
    cout << is_sorted(v) << endl;
    s = merge_sort(v);
    cout << s << endl;

    v={1,2};
    cout << v << endl;
    merge_sort(v);
    cout << v << endl;
    cout << is_sorted(v) << endl;
    s = merge_sort(v);
    cout << s << endl;

    v={1,2,3};
    cout << v << endl;
    merge_sort(v);
    cout << v << endl;
    cout << is_sorted(v) << endl;
    s = merge_sort(v);
    cout << s << endl;

    v={1,3,2};
    cout << v << endl;
    merge_sort(v);
    cout << v << endl;
    cout << is_sorted(v) << endl;
    s = merge_sort(v);
    cout << s << endl;

    v={2,1,3};
    cout << v << endl;
    merge_sort(v);
    cout << v << endl;
    cout << is_sorted(v) << endl;
    s = merge_sort(v);
    cout << s << endl;

    v={2,3,1};
    cout << v << endl;
    merge_sort(v);
    cout << v << endl;
    cout << is_sorted(v) << endl;
    s = merge_sort(v);
    cout << s << endl;

    v={3,1,2};
    cout << v << endl;
    merge_sort(v);
    cout << v << endl;
    cout << is_sorted(v) << endl;
    s = merge_sort(v);
    cout << s << endl;

    v={3,2,1};
    cout << v << endl;
    merge_sort(v);
    cout << v << endl;
    cout << is_sorted(v) << endl;
    s = merge_sort(v);
    cout << s << endl;

    v={-100,-2,-3,10,20};
    cout << v << endl;
    merge_sort(v);
    cout << v << endl;
    cout << is_sorted(v) << endl;
    s = merge_sort(v);
    cout << s << endl;

    v={-100,-2,-3,-29};
    cout << v << endl;
    merge_sort(v);
    cout << v << endl;
    cout << is_sorted(v) << endl;
    s = merge_sort(v);
    cout << s << endl;
}

void stat_merge_sort() {
    vector<int> v;
    SortStats s;

    v=rand_vec(10000000,-1000,1000);
    s=merge_sort(v);
    cout << s << endl;
}
/*
void test_quick_sort_arrange() {
    vector<int> v;
    v={0};
    cout << v << endl;
    quick_sort_arrange(v,0,1);
    cout << v << endl;

    v={1,2};
    cout << v << endl;
    quick_sort_arrange(v,0,v.size()-1);
    cout << v << endl;

    v={2,1};
    cout << v << endl;
    quick_sort_arrange(v,0,v.size()-1);
    cout << v << endl;

    v={1,2,3};
    cout << v << endl;
    quick_sort_arrange(v,0,v.size()-1);
    cout << v << endl;

    v={1,3,2};
    cout << v << endl;
    quick_sort_arrange(v,0,v.size()-1);
    cout << v << endl;

    v={2,3,1};
    cout << v << endl;
    quick_sort_arrange(v,0,v.size()-1);
    cout << v << endl;

    v={2,1,3};
    cout << v << endl;
    quick_sort_arrange(v,0,v.size()-1);
    cout << v << endl;

    v={3,1,2};
    cout << v << endl;
    quick_sort_arrange(v,0,v.size()-1);
    cout << v << endl;

    v={3,2,1};
    cout << v << endl;
    quick_sort_arrange(v,0,v.size()-1);
    cout << v << endl;
    
    v={1,4,3,5,2,3};
    quick_sort_arrange(v,0,v.size()-1);
    cout << v << endl;

    v={1,4,3,5,2,3,1};
    quick_sort_arrange(v,0,v.size()-1);
    cout << v << endl;
    
}
*/

/*
void test_quick_sort_recur() {
    vector<int> v;
    v={0};
    cout << v << endl;
    quick_sort_recur(v,0,v.size()-1);
    cout << v << endl;

    v={1,2};
    cout << v << endl;
    quick_sort_recur(v,0,v.size()-1);
    cout << v << endl;

    v={2,1};
    cout << v << endl;
    quick_sort_recur(v,0,v.size()-1);
    cout << v << endl;

    v={1,2,3};
    cout << v << endl;
    quick_sort_recur(v,0,v.size()-1);
    cout << v << endl;

    v={1,3,2};
    cout << v << endl;
    quick_sort_recur(v,0,v.size()-1);
    cout << v << endl;

    v={2,1,3};
    cout << v << endl;
    quick_sort_recur(v,0,v.size()-1);
    cout << v << endl;

    v={2,3,1};
    cout << v << endl;
    quick_sort_recur(v,0,v.size()-1);
    cout << v << endl;

    v={3,1,2};
    cout << v << endl;
    quick_sort_recur(v,0,v.size()-1);
    cout << v << endl;

    v={3,2,1};
    cout << v << endl;
    quick_sort_recur(v,0,v.size()-1);
    cout << v << endl;

    v={1,4,3,5};
    cout << v << endl;
    quick_sort_recur(v,0,v.size()-1);
    cout << v << endl;

    v={1,4,3,5,2,3,1};
    cout << v << endl;
    quick_sort_recur(v,0,v.size()-1);
    cout << v << endl;
}
*/

void stat_quick_sort() {
    vector<int> v;
    SortStats s;

    v=rand_vec(100000,-1000,1000);
    s=quick_sort(v);
    cout << s << endl;
}

void test_shell_sort() {
    vector<int> v;

    v={};
    shell_sort(v);
    cout << v << endl;
    cout << is_sorted(v) << endl;

    v={1};
    shell_sort(v);
    cout << v << endl;
    cout << is_sorted(v) << endl;

    v={2,1};
    shell_sort(v);
    cout << v << endl;
    cout << is_sorted(v) << endl;

    v={1,2};
    shell_sort(v);
    cout << is_sorted(v) << endl;

    v={1,2,3};
    shell_sort(v);
    cout << v << endl;
    cout << is_sorted(v) << endl;

    v={1,3,2};
    shell_sort(v);
    cout << v << endl;
    cout << is_sorted(v) << endl;

    v={2,1,3};
    shell_sort(v);
    cout << v << endl;
    cout << is_sorted(v) << endl;

    v={2,3,1};
    shell_sort(v);
    cout << v << endl;
    cout << is_sorted(v) << endl;

    v={3,1,2};
    shell_sort(v);
    cout << v << endl;
    cout << is_sorted(v) << endl;

    v={3,2,1};
    shell_sort(v);
    cout << v << endl;
    cout << is_sorted(v) << endl;

    v={-100,-2,-3,10,20};
    shell_sort(v);
    cout << v << endl;
    cout << is_sorted(v) << endl;

    v={-100,-2,-3,-29};
    shell_sort(v);
    cout << v << endl;
    cout << is_sorted(v) << endl;
}

void test_shell_insertion() {
    vector<int> v;
    ulong x = 0;

    v={};
    shell_insertion(v,0,v.size()-1,x);
    cout << v << endl;
    cout << is_sorted(v) << endl;

    v={1};
    shell_insertion(v,0,v.size()-1,x);
    cout << v << endl;
    cout << is_sorted(v) << endl;

    v={2,1};
    shell_insertion(v,0,v.size()-1,x);
    cout << v << endl;
    cout << is_sorted(v) << endl;

    v={1,2};
    shell_insertion(v,0,v.size()-1,x);
    cout << is_sorted(v) << endl;

    v={1,2,3};
    shell_insertion(v,0,v.size()-1,x);
    cout << v << endl;
    cout << is_sorted(v) << endl;

    v={1,3,2};
    shell_insertion(v,0,v.size()-1,x);
    cout << v << endl;
    cout << is_sorted(v) << endl;

    v={2,1,3};
    shell_insertion(v,0,v.size()-1,x);
    cout << v << endl;
    cout << is_sorted(v) << endl;

    v={2,3,1};
    shell_insertion(v,0,v.size()-1,x);
    cout << v << endl;
    cout << is_sorted(v) << endl;

    v={3,1,2};
    shell_insertion(v,0,v.size()-1,x);
    cout << v << endl;
    cout << is_sorted(v) << endl;

    v={3,2,1};
    shell_insertion(v,0,v.size()-1,x);
    cout << v << endl;
    cout << is_sorted(v) << endl;

    v={-100,-2,-3,10,20};
    shell_insertion(v,0,v.size()-1,x);
    cout << v << endl;
    cout << is_sorted(v) << endl;

    v={-100,-2,-3,-29};
    shell_insertion(v,0,v.size()-1,x);
    cout << v << endl;
    cout << is_sorted(v) << endl;
}

void test_threshold_iquick_sort() {
    vector<int> v;
    SortStats s;
    for (int i = 0; i < 1000; i+=100) {
        v=rand_vec(i,1,i);
        s=quick_sort(v);
        cout << s.to_csv() << endl;

        v=rand_vec(i,1,i);
        s=insertion_sort(v);
        cout << s.to_csv() << endl;
    }

    
}

void print_all_stats() {
    vector<int> v;
    SortStats s;
    for (ulong i = 2000; i < 26*2000; i+=2000)
    {
        v=rand_vec(i,1,i);
        s=iquick_sort(v);
        cout << s.to_csv() << endl;
    }
    

}

int main() {
    
    //test_is_sorted_int();
    //test_is_sorted_string();

    //print_stats();

    //test_rand_vec();
    
    //test_bubble_sort();

    //test_insertion_sort();

    //stat_insertion_sort();

    //test_selection_sort();

    //test_merge();

    //test_merge_sort_recur();

    //test_merge_sort();

    //stat_merge_sort();

    //test_quick_sort_arrange();

    //test_quick_sort_recur();

    //stat_quick_sort();

    //test_shell_insertion();

    //test_shell_sort();

    print_all_stats();

    //test_threshold_iquick_sort();

    return EXIT_SUCCESS;
}