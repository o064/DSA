
arr = [5,3,4,2,1]

for i in range(1, len(arr)) :
    j = i
    while j>0  and arr[j] < arr[j-1] :  # <= is not good for stability
        arr[j] ,arr[j-1] =arr[j-1],arr[j]
        j -= 1

print(arr)

# incremental approach because for every iteration arr is sorted partially
# worst case n^2 
# best case n