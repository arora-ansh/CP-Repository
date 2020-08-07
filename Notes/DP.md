## Dynamic Programming

It isn't really programming as in coding, but rather the storage of data dynamically as the running of the program progresses. 
The most basic example for its use is in fibonacci, where rather than calling functions over and over again, we can simply store information as and when it is processed and then if it is stored, call it up again. So rather than exponential, it reduces the time complexity to linear. DP, however, isn't limited to recursion, as it finds uses in iteration, where the storage of values can be used to our advantage again.

#### Notes - 

#### Common Questions - 
1. In the AlphaNode question, we solved the question using recursion first. But after that, to reduce the time complexity, we store the values in another array as and when we find the value for that. Here, for example, we had a code 234165. We first through recursion, form our recursive statements (2 + 34165 and 23 + 4165) and recurse this way till no more digits are left in the array. Now, to DP it, we store the value for each step (here each step will be one size difference) and then when we add another base case which returns the stored value if it has any. O(n) time.
2. In the largest bitonic array question, we simply find the lis and lds, and then for each number on the array, find the sum of lis+lds-1 and return the highest as the largest bitonic subarray. This is a DP problem since we still are storing data for each array element dynamically and making use of it later in the question.
