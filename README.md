# Stability in Sorting Algorithms

Sorting algorithms are classified as stable or unstable based on whether they maintain the relative order of equal elements in the sorted output. Here’s a rundown of some common sorting algorithms, highlighting their stability and reasons:

## Stable Sorting Algorithms

- **Bubble Sort:** Stable  
  **Why?** Bubble Sort only swaps adjacent elements if they are out of order. This means if two elements have the same value, they won’t be swapped, and their original order is preserved.

- **Insertion Sort:** Stable  
  **Why?** During insertion, elements are only moved if they are strictly greater or lesser, so if two elements are equal, the original order between them is maintained.

- **Merge Sort:** Stable (if implemented carefully)  
  **Why?** Merge Sort merges elements from two halves in a way that retains their relative order from the input halves. By always picking the element from the left half when elements are equal, it can preserve the order of equal elements.

- **Tim Sort (used in Python and Java’s Arrays.sort):** Stable  
  **Why?** Tim Sort is a hybrid of Merge Sort and Insertion Sort, and it is specifically designed to maintain the order of equal elements. It’s efficient for real-world data, which may already be partially sorted.

- **Counting Sort:** Stable (with proper implementation)  
  **Why?** Counting Sort works by counting occurrences and placing elements in their correct position based on counts. By iterating from left to right, it preserves the order of elements with the same value.

- **Radix Sort:** Stable  
  **Why?** Radix Sort sorts elements by individual digits, using a stable sorting algorithm (typically Counting Sort) at each digit level, thus maintaining the relative order of elements with equal values at each stage.

## Unstable Sorting Algorithms

- **Quick Sort:** Not stable  
  **Why?** Quick Sort’s partitioning can change the order of equal elements because elements are swapped across the pivot in a way that doesn’t necessarily preserve their original order.

- **Heap Sort:** Not stable  
  **Why?** Heap Sort involves moving elements in and out of a heap structure, which disrupts the relative order of equal elements due to the way the heap property is maintained (i.e., repeatedly swapping elements).

- **Selection Sort:** Not stable  
  **Why?** Selection Sort selects the smallest element in each pass and places it in its correct position by swapping, which can disrupt the order of equal elements.

## Why Stability Matters

Stability is important in scenarios where records are sorted on multiple keys. For example, if you have a list of people sorted by age, and you want to sort it by name while keeping the order of ages for people with the same name, a stable sort will preserve the previous order of ages for each name.

In general:

- **Stable Sorts** are useful for multi-level sorting and preserving original data order.
- **Unstable Sorts** can be faster or use less memory, which might be preferred when stability isn’t needed.
