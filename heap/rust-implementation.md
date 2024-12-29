# 🦀 rust implementation

(Max) heaps can be represented as complete binary trees in array form.

```rust
struct MaxHeap {
    heap: Vec<i32>,
}

impl MaxHeap {
    fn new() -> MaxHeap {
        MaxHeap { heap: Vec::new() }
    }

    // Move node up tree (swap with parents until correct position)
    fn percolate_up(&mut self, mut node_index: usize) {
        while node_index > 0 {
            let parent_index = (node_index - 1) / 2;
            if self.heap[node_index] > self.heap[parent_index] {
                self.heap.swap(node_index, parent_index);
                node_index = parent_index;
            }
            // Correct position in heap
            else {
                return;
            }
        }
    }

    // Move node down tree (swap with children until correct position)
    fn percolate_down(&mut self, mut node_index: usize) {
        while node_index < self.heap.len() {
            let left = 2 * node_index + 1;
            let right = 2 * node_index + 2;
            let mut largest = node_index;
            if left < self.heap.len() && self.heap[left] > self.heap[largest] {
                largest = left;
            }
            if right < self.heap.len() && self.heap[right] > self.heap[largest] {
                largest = right;
            }
            // Correct position in heap
            if largest == node_index {
                return;
            }
            self.heap.swap(node_index, largest);
            node_index = largest;
        }
    }

    // Push value then percolate up from end to restore heap order
    fn push(&mut self, val: i32) {
        self.heap.push(val);
        self.percolate_up(self.heap.len() - 1);
    }

    // Return the largest element without removing it
    fn top(&self) -> Option<i32> {
        if self.heap.is_empty() {
            None
        } 
        else {
            Some(self.heap[0])
        }
    }

    // Remove largest element and percolate down from start to restore heap order
    fn pop(&mut self) -> Option<i32> {
        if self.heap.is_empty() {
            return None;
        }
        let max = self.heap[0];
        if self.heap.len() > 1 {
            self.heap[0] = self.heap.pop().unwrap();
            self.percolate_down(0);
        } 
        else {
            self.heap.pop();
        }
        Some(max)
    }
}
```
