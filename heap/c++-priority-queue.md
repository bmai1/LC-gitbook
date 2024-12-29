# ©️ c++ priority queue

```cpp
priority_queue<int> pq; // max-heap (return max first)
priority_queue<int, vector<int>, greater<int>> pq; // min-heap

// Methods
pq.push(1);
int top = pq.top();
pq.pop();
```

Example implementation:

```cpp
class MaxHeap {
private:
    std::vector<int> heap;

    void percolate_up(int index) {
        while (index > 0) {
            int parent = (index - 1) / 2;
            if (heap[index] <= heap[parent]) {
                break;
            }
            std::swap(heap[index], heap[parent]);
            index = parent;
        }
    }

    void percolate_down(int index) {
        int size = heap.size();
        while (true) {
            int left = 2 * index + 1;
            int right = 2 * index + 2;
            int largest = index;

            if (left < size && heap[left] > heap[largest]) {
                largest = left;
            }
            if (right < size && heap[right] > heap[largest]) {
                largest = right;
            }
            if (largest == index) {
                break;
            }
            std::swap(heap[index], heap[largest]);
            index = largest;
        }
    }

public:
    void push(int val) {
        heap.push_back(val);
        percolate_up(heap.size() - 1);
    }

    int top() const {
        if (heap.empty()) {
           return -1;
        }
        return heap[0];
    }

    int pop() {
        if (heap.empty()) {
            return -1;
        }
        int max = heap[0];
        if (heap.size() > 1) {
            heap[0] = heap.back();
            heap.pop_back();
            percolate_down(0);
        } 
        else {
            heap.pop_back();
        }
        return max;
    }
};
```
