#include <bits/stdc++.h>

using namespace std;

class MinHeap {
    private:
        long long int heap_size;
        vector<long long int> hp;

        void min_heapify(long long int i) {
            long long int l = 2*i + 1, r = 2*i + 2, smallest = i;
            if(l < this->heap_size && hp[i] > hp[l])
                smallest = l;
            if(r < this->heap_size && hp[smallest] > hp[r])
                smallest = r;
            if(smallest != i) {
                swap(this->hp[i], this->hp[smallest]);
                this->min_heapify(smallest);
            }
        }
        
        void build_heap() {
            for(long long int i = floor(this->heap_size/2); i >= 0; i--)
                this->min_heapify(i);
        }

        void decrease_key(long long int key, long long int val) {
            this->hp[key] = val;
            for(long long int i = key; i >= 0; i /= 2) {
                if(this->hp[i] < this->hp[(i-1)/2])
                    swap(this->hp[i], this->hp[(i-1)/2]);
                else
                    return;
            }
        }

        void increase_key(long long int key, long long int val) {
            this->hp[key] = val;
            this->min_heapify(key);
        }

    public:
        MinHeap(const vector<long long int> &vec) {
            this->heap_size = vec.size();
            this->hp = vec;
            this->build_heap();
        }

        long long int extractMin() {
            swap(this->hp[0], this->hp[--heap_size]);
            min_heapify(0);
            return this->hp[heap_size];
        }

        void insert(long long int val) {
            if(this->hp.size() > this->heap_size)
                this->hp[heap_size] = numeric_limits<long long int>::max();
            else
                this->hp.push_back(numeric_limits<long long int>::max());
            this->decrease_key(this->heap_size++, val);
        }

        void print_as_array() {
            for(long long int i = 0; i < heap_size; i++)
                cout<<this->hp[i]<<" ";
            cout<<endl;
        }
    
        long long int cookie(long long int sweet) {
                long long int count = 0;
                while(true) {
                    if(this->hp[0] < sweet){
                    long long int a = this->extractMin();
                    if(heap_size == 0)
                        return -1;
                    long long int b = this->extractMin();
                    insert(a + 2*b);
                    count++;
                    } else {
                        return count;
                    }
                }
        }
};
/*
 * Complete the cookies function below.
 */
long long int cookies(long long int k, vector<long long int> &A) {
    /*
     * Write your code here.
     */
    MinHeap heap(A);
    return heap.cookie(k);
}

int main(){
    long long int n, k;
    cin>>n>>k;
    vector<long long int> vec(n);
    for(long long int i = 0; i < n; i++)
        cin>>vec[i];
    cout<<cookies(k, vec);
    return 0;
}


// someone else's solution passed all cases(mine only 22/25(still dunno why??))
/*
int main() {
    int n,k;
    cin >> n >> k;
    
    // enter values
    priority_queue <int,vector<int>,greater<int>> q;
    for (int i=0;i<n;i++) {
        int x;
        cin >> x;
        q.push(x);
    }
    
    // process
    int count=0;
    while(true){
        int x;
        if ((x=q.top())<k) {
            q.pop(); // remove 1st
            if (q.empty()) { // nothing left, can't proceed
                cout << -1;
                break;
            }
            int y=2*q.top(); 
            q.pop(); // remove 2nd
            q.push(x+y); // create new
            count++; // completed 1 op
        }
        else {
            cout << count; // print ans
            break;
        }
    }
        
    return 0;
    }
*?
