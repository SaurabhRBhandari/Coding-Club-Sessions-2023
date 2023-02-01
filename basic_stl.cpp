#include <bits/stdc++.h>
using namespace std;
#define int long long
bool cmp(int a,int b)
{
    return a%2>b%2;
}

void vector_functions() {
    vector <int> v = {1, 2, 10, 5, 2, 5, 10, 4};
    vector <int> v;
    v.push_back(1);
    // Find length of vector
    int n = (int)v.size();
    // for(int i = 0; i < (int)v.size(); i++) {
        // cout << v[i] << " ";
    // }
    // for-each loop
    for(auto i : v) {
        cout << i << " ";
    }
    cout << '\n';
    sort(v.begin(), v.end()); // sort
    // sort(v.begin(), v.end(), greater<int>()); // sort in reverse
    // sort(v.begin(), v.end(), comp);

    cout << is_sorted(v.begin(), v.end()) << '\n';

    cout << accumulate(v.begin(), v.end(), 0ll) << '\n';

    vector <int> w(10,-1);
    // 0, 1, 2, 3, 4, ....
    iota(w.begin(), w.end(), 0ll);
    for(auto i : w) cout << i << " ";

    // reverse(v.begin(), v.end());
    reverse(v.begin() + 2, v.end());
    reverse(v.begin() + 3, v.begin() + 5);

    int x = *max_element(v.begin(), v.end());
    int x_ind = max_element(v.begin(), v.end()) - v.begin();
}

void map_functions()
{

    //key-value pair
    map<int,int>mp;

    vector <int> v={5,5,4,4,4,3,3,3,3,2,2,2,2,2,1};
    
    //calculate the frequency of each element
    for(int x:v)
    {
        mp[x]++;
    }

    //iterate over the map
    for(auto x:mp)
    {
        int key=x.first;
        int value=x.second;
        // cout<<key<<" "<<value<<endl;
    }
    for(auto it=mp.begin();it!=mp.end();it++)
    {
        int key=it->first;
        int value=it->second;
        // cout<<key<<" "<<value<<endl;
    }

    //size of map
    // cout<<mp.size()<<endl;

    //erase an element
    mp.erase(5);

    int t=4;
    //find an element
    cout<<(mp.count(t)?"found":"not found")<<endl;

    //empty the map
    mp.clear();
}

void set_functions()
{
    //set stores only unique elements
    set<int>st;

    //insert an element
    st.insert(5);

    //insert multiple elements
    st.insert({1,2,3,4,5});

    //erase an element
    st.erase(5);

    //find an element
    int t=4;
    // cout<<(st.count(t)?"found":"not found")<<endl;

    //empty the set
    st.clear();

    //to calculate number of distinct elements in a vector
    vector <int> v={5,5,4,4,4,3,3,3,3,2,2,2,2,2,1};
    st.insert(v.begin(),v.end());

    // iterate over the set
    for(auto x:st)
    {
        // cout<<x<<" ";
    }
    // cout<<endl;
    for(auto it=st.begin();it!=st.end();it++)
    {
        // cout<<*it<<" ";
    }
    // cout<<endl;

    int x=3;

    //find the smallest element greater than or equal to a given number
    auto it=st.lower_bound(x);
    cout<<(it==st.end()?-1:*it)<<endl;

    //find the smallest element greater than a given number
    it=st.upper_bound(x);
    cout<<(it==st.end()?-1:*it)<<endl;

    //find the largest element less than or equal to a given number
    it=st.upper_bound(x);
    cout<<(it==st.begin()?-1:*(--it))<<endl;

    //find the largest element less than a given number
    it=st.lower_bound(x);
    cout<<(it==st.begin()?-1:*(--it))<<endl;

    //get the iterator of any element.
    it=st.find(x);

    //multiset
    multiset<int> st1;
    st1.insert(1);
    st1.insert(1);
    st1.insert({2,2,3,4,5});

    //to get count
    cout<<st.count(x)<<endl;

    //to erase the first occurence only
    st.erase(st.find(x));

    //to erase all occurences
    st.erase(x);

    //minimum and maximum element
    cout<<*st.begin()<<" "<<*st.rbegin()<<endl;

    //using custom comparator
    set<int,decltype(&cmp)> st2(cmp);
    st2.insert({1,2,3,4,5});
    for(auto x:st2)
    {
        // cout<<x<<" ";
    }

    st.clear();
    st.insert({1,2,3,4,5});
    //to get the kth smallest element
    int k=3;
    it=st.begin();
    advance(it,k-1);
    // cout<<*it<<endl;

    //to get the number of elements less than or equal to a given number
    t=4;
    it=st.upper_bound(t);
    cout<<(it==st.begin()?0:distance(st.begin(),it))<<endl;

    //to get the number of elements less than a given number
    it=st.lower_bound(t);
    cout<<(it==st.begin()?0:distance(st.begin(),it))<<endl;

    //to get the number of elements greater than or equal to a given number
    it=st.lower_bound(t);
    // cout<<(it==st.end()?0:distance(it,st.end()))<<endl;

    //to get the number of elements greater than a given number
    it=st.upper_bound(t);
    // cout<<(it==st.end()?0:distance(it,st.end()))<<endl;

    //to get the number of elements in a given range [l,r]
    int l=2,r=4;
    it=st.lower_bound(l);
    auto it1=st.upper_bound(r);
    // cout<<(it==st.end()?0:distance(it,it1))<<endl;

    //to get the kth smallest element in a given range [l,r]
    k=2;
    it=st.lower_bound(l);
    it1=st.upper_bound(r);
    advance(it,k-1);
    // cout<<*it<<endl;
}

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

void misc()
{
    //when elements in map/set need not be sorted use unordered.
    unordered_map<int,int> mp;
    unordered_set<int> st;

    //average time complexity-O(1), worst case-O(N)
    
    //to avoid hacks/FST use custom hash functions
    unordered_map<int,int,custom_hash> mp1;
    unordered_set<int,custom_hash> st1;
}


int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    vector_functions();
    map_functions();
    set_functions();
    misc();

    return 0;
}