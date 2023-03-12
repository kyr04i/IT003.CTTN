# Experiment with sorting algorithms

> Project requirements: 
```
1. Create a dataset of 10 sequences, each with about 1 million real numbers (random); the first sequence is in ascending order, the second is in descending order, the remaining 8 sequences are in random order
2. Write programs to sort the array according to the QuickSort, HeapSort, MergeSort algorithms and call the C++ sort function
3. Test each of the programs written above with the generated data set, recording the execution time of each test
4. Write test report: test results in data table and chart form; comment on experimental results
5. Report submitted in PDF file
```
                                **Report: Đánh giá hiệu suất các thuật toán sắp xếp trên các bộ test khác nhau**

`Sinh viên: Nguyễn Viết Duy  -  MSSV: 22520336`

`Class: IT003.N21.CTTN`


*Sorting is one of the basic and important algorithms in the field of computer science. With the development of today's data storage technologies, organizing that data has become a necessity for many different applications. Therefore, studying and comparing the performance of sorting algorithms is an important research topic in the field of computer science*

# Experiment:

```
To compare the performance of sorting algorithms, I use 4 algorithms namely Heap Sort, Merge Sort, Quick Sort and C library Sort to sort 10 different test sets. Each test set contains 1 million numeric data, in which test 1 of ascending numbers, test 2 of descending numbers, and the remaining tests are random numeric data.
The algorithms are implemented in the C++ programming language and the execution time is measured using the <sys/time.h> library in C++. All tests are done by me on the same computer with 12th gen Intel Core i5 CPU configuration and 8GB RAM
```

# Result :

![data](https://github.com/w1n-gl0ry/Data_Structures_and_Algotithms/blob/1a19dbb3d7d69b0e3a2249a8e1c9aca32facc362/Project1/image/result.png)

**Sort time data table of 4 algorithms with 10 different sets of TEST**





 
![line](https://github.com/w1n-gl0ry/Data_Structures_and_Algotithms/blob/1a19dbb3d7d69b0e3a2249a8e1c9aca32facc362/Project1/image/line_graph.png)

**Line chart comparing sorting time of 4 algorithms**
 
 
 
 
 
 
 
![bar](https://github.com/w1n-gl0ry/Data_Structures_and_Algotithms/blob/1a19dbb3d7d69b0e3a2249a8e1c9aca32facc362/Project1/image/bar_graph.png)

**The bar graph shows the average time of the algorithms for each data set**


```
Experimental results show that Quick Sort is the fastest algorithm with an average execution
time of only about 0.013s. Merge Sort is the second fastest algorithm with an average execution
time of around 0.056s. Heap Sort is the third fastest algorithm with an average execution time of about 0.214s 
and C library Sort is the slowest with an average execution time of about 0.033s.

In addition, the experimental results also show that, in the random test sets, Quick Sort is the best performing
algorithm, while Merge Sort is the best algorithm in the increasing test sets and Heap Sort is the best algorithm. 
best in descending test suites.
```

# Analyzing:

```
From the above experimental results, we can see that among the compared sorting algorithms, Quick Sort is the fastest. The execution time of Quick Sort ranges from 0.012 to 0.015 seconds for all test suites, much faster than other algorithms.
Merge Sort is the second fastest sorting algorithm among these algorithms. Its execution time is between 0.054 and 0.061 seconds, which is relatively fast compared to Heap Sort and C library Sort.
The C library Sort is the second slowest of these sorting algorithms. Its execution time is between 0.026 and 0.036 seconds, which is relatively slow compared to Quick Sort and Merge Sort.
Heap Sort is the slowest of these sorting algorithms. Its execution time is from 0.210 to 0.226 seconds, much slower than other algorithms.
```

# Rate and comment:
```
Quick Sort is the fastest sorting algorithm among the compared algorithms. It is popular and widely used in practical applications, especially in applications that need fast processing times. However, it can be problematic for some worst cases, where the sequence of numbers to be sorted is almost already sorted.
Merge Sort is the second fastest sorting algorithm among these algorithms. It is a stable algorithm and is effective in most cases. However, it uses recursive memory for its performance, so it can be problematic when the amount of data is large.

C library Sort is the most commonly used algorithm in the sorting libraries of the C language. It is a generalized sorting algorithm, designed to work well with all types of data. However, for special cases like sorting previously sorted data or data already sorted in reverse order, Quick Sort gives better results. This can be explained by the fact that Quick Sort uses divide-and-conquer and swap data, which reduces the number of element comparisons and swaps, thus sorting data faster in special cases. this distinction.
```

*In addition, the Heap Sort and Merge Sort algorithms can be improved to optimize performance. For example, Heap Sort can be improved by using Heapify instead of sorting each element, and Merge Sort can be improved using insertion sort when the array size is less than a certain threshold.
In general, the choice of the appropriate sorting algorithm depends on the type of data to be sorted and the special conditions in the sorting process. Understanding the advantages and disadvantages of sorting algorithms will help developers choose and optimize the right algorithm for their application..*










