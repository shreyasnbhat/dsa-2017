# Enter your code here. Read input from STDIN. Print output to STDOUT
cases = int(raw_input().strip())

for i in range(cases):
    
    n = int(raw_input().strip())
    arr = map(int,raw_input().strip().split())
    
    max_sum_till_now = arr[0]
    max_sum = arr[0]
    
    all_neg = 0
    
    max_arr = max(arr)
    
    non_con_sum = 0
    
    if arr[0] > 0 :
        non_con_sum+=arr[0]
    else :
        all_neg = 1
    
    for k in xrange(1,len(arr)):
        max_sum_till_now = max(max_sum_till_now + arr[k] , arr[k])
        max_sum = max(max_sum,max_sum_till_now)
        if arr[k] > 0 :
            non_con_sum += arr[k]
        else :
            all_neg +=1
    
    if all_neg < len(arr):
        print max_sum , non_con_sum
    else:
        print max_arr , max_arr
