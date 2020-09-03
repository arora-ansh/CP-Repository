# Segment Trees

- Used in problems where we have to answer in ranges
- Generally used in query questions, where the array changes between two return queries

> In general array traversal, the updation takes O(1) time, while the querying in a range takes O(n) time, which becomes unfavorable in the case of a lot of queries. In a more complex, sum-array like implementation, while the querying here will take O(1) time, the updation can take O(n) time. So the best way to deal with such problems are **Segment Trees**.

In segment trees we maintain a binary tree based on the given property. Here the updation and querying both happens in O(logn) time. The updation happens in the base and reflects in its upper nodes. Similarly, for a query, we start moving to the side of the tree where our answer may reside and end up querying in O(logn) time.
