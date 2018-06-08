#include <cmath>
#include <cstdio>
#include <vector>
#include <limits>
#include <iostream>
#include <algorithm>
using namespace std;

class MinHeap {
    private:
        int heap_size;
        vector<int> hp;

        void min_heapify(int i) {
            int l = 2*i + 1, r = 2*i + 2, smallest = i;
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
            for(int i = floor(this->heap_size/2); i >= 0; i--)
                this->min_heapify(i);
        }
    
        void decrease_key(int key, int val) {
            this->hp[key] = val;
            for(int i = key; i >= 0; i = (i-1)/2) {
                if(hp[i] < hp[(i-1)/2])
                    swap(hp[i], hp[(i-1)/2]);
                else
                    return;
            }
        }
        
        string do_padding (unsigned index, unsigned mlength){
            string padding;
            if (int((index-1)/2) != 0){
                return (int((index-1)/2) % 2 == 0) ?
                (do_padding(int((index-1)/2),mlength) + string(mlength+4,' ') + " ")  :
                (do_padding(int((index-1)/2),mlength) + string(mlength+3,' ') + " |") ;
            }
            return padding;
        }


        void printer (unsigned index, unsigned mlength){
            auto last  = heap_size - 1 ;
            auto left  = 2 * index + 1 ;
            auto right = 2 * index + 2 ;
            cout << " " << this->hp[index] << " ";
            if (left <= last){
                auto llength = to_string(this->hp[left]).size();
                cout << "---" << string(mlength - llength,'-');
                printer(left,mlength);
                if (right <= last) {
                    auto rlength = std::to_string(this->hp[right]).size();
                    cout << "\n" << do_padding(right,mlength) << string(mlength+ 3,' ') << " | ";
                    cout << "\n" << do_padding(right,mlength) << string(mlength+ 3,' ') << " └" <<
                    string(mlength - rlength,'-');
                    printer(right,mlength);
                }
            }
        }

    public:
        MinHeap(const vector<int> &vec) {
            this->heap_size = vec.size();
            this->hp = vec;
            this->build_heap();
        }
        
        void insert(int val) {
            if(this->heap_size < this->hp.size())
                this->hp[heap_size] = numeric_limits<int>::max();
            else
                this->hp.push_back(numeric_limits<int>::max());
            this->decrease_key(heap_size++, val);
        }

        void remove(int key) {
            int i = 0;
            do {
                if(this->hp[i] == key)
                    break;
                i++;
            } while(i < heap_size);
            if(i != this->heap_size) {
                swap(this->hp[i], this->hp[--heap_size]);
                this->min_heapify(i);
            }
        }
    
        void print_min() {
            cout<<this->hp[0]<<endl;
        }
        void print (){
            cout<<"\n";
            unsigned mlength = 0;
            for (int &element : this->hp){
                auto clength = to_string(element).size();
                if (clength > mlength) {
                    mlength = to_string(element).size();
                }
            }
            cout <<  string(mlength - to_string(this->hp[0]).size(),' ');
            printer(0,mlength);
        }
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int q, choice, num, itr = 0;
    cin>>q;
    int arr[q][2];
    vector<int> vec;
    while(q--) {
        cin>>choice;
        if(choice != 3) {
            cin>>num;
            arr[itr][0] = choice;
            arr[itr][1] = num;
        } else {
            arr[itr][0] = 3;
            arr[itr][1] = -1;
        }
        itr++;
    }
    int i;
    for(i = 0; arr[i][0] == 1; i++)
        vec.push_back(arr[i][1]);
    MinHeap heap(vec);
    for(int j = i; j < itr; j++) {
        // heap.print();
        if(arr[j][0] == 1) {
            heap.insert(arr[j][1]);
        } else if(arr[j][0] == 2) {
            heap.remove(arr[j][1]);
        } else {
            heap.print_min();
        }
    }
    return 0;
}

