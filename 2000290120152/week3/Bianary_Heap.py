# SHIVANSHU SINGH  2000290120152

# Binary Heap -> a complete binary tree (represented as array)
# root -> arr[0]
# for ith node ->
# Parent node : arr[(i-1)//2]     
# left : arr[(2*i)+1]
# right : arr[(2*i)+2]

# heap operations -> getMin(), extractMin(), decreaseKey(), insert(), delete()
# applications of heaps-> heapSort(), preorityQueue, graph(Dijkstra’s Shortest Path && Prim’s MST), Merge K Sorted Arrays like questions.


class BinaryHeap:
    
    def __init__(self):
        self.heap = []
    
    def parent(self, i):
        return (i-1)//2
    
    def left_child(self, i):
        return (2*i)+1
        
    def right_child(self, i):
        return (2*i)+2
    
    def swap(self, i, j):
        self.heap[i], self.heap[j] = self.heap[j], self.heap[i]

    def insert(self, x):
        self.heap.append(x)
        self._shift_up(len(self.heap) - 1)
        
    def extract_min(self):
        if not self.heap:
            return None
        min_ele = self.heap[0]
        last_ele = self.heap.pop()
        if self.heap:
            self.heap[0] = last_ele
            self._shift_down(0)
        return min_ele
        
    def decrease_key(self, i, new_val):
        if i >= len(self.heap):
            return
        if new_val < self.heap[i]:
            self.heap[i] = new_val
            self._shift_up(i)
            
    def delete(self, i):
        if i >= len(self.heap):
            print("Not found")
            return 
        last_ele = self.heap.pop()
        if i < len(self.heap):
            self. heap[i] = last_ele
            self._shift_down(i)
        
    def get_min(self):
        if not self.heap:
            return None
        return self.heap[0]
        
    def _shift_up(self, i):
        while i > 0 and self.heap[i] < self.heap[self.parent(i)]:
            self.swap(i, self.parent(i))
            i = self.parent(i)
    
    def _shift_down(self, i): # heapify (min-heap)
        size = len(self.heap)
        smallest = i
        left = self.left_child(i)
        right = self.right_child(i)
        
        if left<size and self.heap[left] < self.heap[smallest]:
            smallest = left
        
        if right<size and self.heap[right] < self.heap[smallest]:
            smallest = right
            
        if smallest != i:
            self.swap(i, smallest)
            self._shift_down(smallest)
     
    def display(self):
        print(self.heap)


heap = BinaryHeap()

heap.insert(5)
heap.insert(3)
heap.insert(8)
heap.insert(1)
heap.insert(10)

heap.display()

print(heap.get_min())  
print(heap.extract_min())  
print(heap.extract_min())  
print(heap.get_min())
heap.decrease_key(2, 2)
print(heap.get_min())  
heap.delete(1)
heap.delete(55)
print(heap.get_min())  
heap.display()
