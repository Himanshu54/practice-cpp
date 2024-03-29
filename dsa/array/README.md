[Original Resource](https://github.com/jwasham/coding-interview-university) by John Washam
<details>
<summary>Dynamic Array</summary>

- [Dyanamic Array Code](array.h)
- [Tests Code](test_array.cpp)
- Resource:
    - [Arrays (video)](https://www.coursera.org/learn/data-structures/lecture/OsBSF/arrays)
    - [UC Berkeley CS61B - Linear and Multi-Dim Arrays (video)](https://archive.org/details/ucberkeley_webcast_Wp8oiO_CZZE) (Start watching from 15m 32s)
    - [Basic Arrays (video)](https://archive.org/details/0102WhatYouShouldKnow/02_04-basicArrays.mp4)
    - [Multi-dim (video)](https://archive.org/details/0102WhatYouShouldKnow/02_05-multidimensionalArrays.mp4)
    - [Dynamic Arrays (video)](https://www.coursera.org/learn/data-structures/lecture/EwbnV/dynamic-arrays)
    - [Jagged Arrays (video)](https://www.youtube.com/watch?v=1jtrQqYpt7g)
    - [Jagged Arrays (video)](https://archive.org/details/0102WhatYouShouldKnow/02_06-jaggedArrays.mp4)
    - [Resizing arrays (video)](https://archive.org/details/0102WhatYouShouldKnow/03_01-resizableArrays.mp4)

- Checks:
    - [x] Implement a vector (mutable array with automatic resizing):
        - [x] Practice coding using arrays and pointers, and pointer math to jump to an index instead of using indexing.
        - [x] new raw data array with allocated memory
            - can allocate int array under the hood, just not use its features
            - start with 16, or if starting number is greater, use power of 2 - 16, 32, 64, 128
        - [x] size() - number of items
        - [x] capacity() - number of items it can hold
        - [x] is_empty()
        - [x] at(index) - returns item at given index, blows up if index out of bounds
        - [x] push(item)
        - [x] insert(index, item) - inserts item at index, shifts that index's value and trailing elements to the right
        - [x] prepend(item) - can use insert above at index 0
        - [x] pop() - remove from end, return value
        - [x] delete(index) - delete item at index, shifting all trailing elements left
        - [x] remove(item) - looks for value and removes index holding it (even if in multiple places)
        - [x] find(item) - looks for value and returns first index with that value, -1 if not found
        - [x] resize(new_capacity) // private function
            - when you reach capacity, resize to double the size
            - when popping an item, if size is 1/4 of capacity, resize to half
    - [x] Time
        - O(1) to add/remove at end (amortized for allocations for more space), index, or update
        - O(n) to insert/remove elsewhere
    - [x] Space
        - contiguous in memory, so proximity helps performance
        - space needed = (array capacity, which is >= n) * size of item, but even if 2n, still O(n)
</details>
<details>
<summary>Circular Array (aka Circular Buffer)</summary>

* FIFO 
- [Circular Array Code](circular_array.h)
- [Tests](test_circular_buffer.cpp)
- Resource:
    - [MathCS Website](http://www.mathcs.emory.edu/~cheung/Courses/171/Syllabus/8-List/array-queue2.html)
    - [eapbg YouTube](https://www.youtube.com/watch?v=GbBrp6K7IvM)
- Checks:
    - [x] Implement a fixed size circular buffer
    - [x] size() returns number of current items
    - [x] capacity() max items it can hold
    - [x] is_empty() 
    - [x] is_full()
    - [x] insert() insert an item
    - [x] pop() return and remove item
    - [x] peek() return item at top of buffer
    * Common Assumtion : Circular Buffer is full when there is one empty slot.

</details>

[Other Implementations]()
<details>
<summary>Minimum Stack</summary>
    
- [Minimum Stack](minimum_stack.h)
- [Tests](test_minimum_stack.cpp)
</details>
<details>
<summary>Minimum Queue using Minimum Stack</summary>
    
- [Minimum Queue](minimum_queue.h)
- [Tests](test_minimum_queue.cpp)
</details>
