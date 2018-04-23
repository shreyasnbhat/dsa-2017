# A Dynamic Programming solution for
# subset sum problem
 
# Returns true if there is a subset 
# of set[] with sun equal to given sum
def isSubsetSum(st, n, sm) :
   
    # The value of subset[i][j] will be
    # true if there is a subset of 
    # set[0..j-1] with sum equal to i
    subset=[[True] * (sm+1)] * (n+1)
   
    # If sum is 0, then answer is true
    for i in range(0, n+1) :
        subset[i][0] = True
   
    # If sum is not 0 and set is empty,
    # then answer is false
    for i in range(1, sm + 1) :
        subset[0][i] = False
   
    # Fill the subset table in botton 
    # up manner
    for i in range(1, n+1) :
        for j in range(1, sm+1) :
            if(j < st[i-1]) :
                subset[i][j] = subset[i-1][j]
            if (j >= st[i-1]) :
                subset[i][j] = subset[i-1][j] or subset[i - 1][j-st[i-1]]
   
    """uncomment this code to print table
    for i in range(0,n+1) :
        for j in range(0,sm+1) :
            print(subset[i][j],end="")
    print(" ")"""
   
    return subset[n][sm];
 
# Driver program to test above function
st = [1, 2, 3]
sm = 7
n = len(st)
if (isSubsetSum(st, n, sm) == True) :
    print("Found a subset with given sum")
else :
    print("No subset with given sum")
     
     
# This code is contributed by Nikita Tiwari.
