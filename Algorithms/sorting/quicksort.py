arr = [2,8,7,1,3,5,6,4]
def partition(arr,p,r):
    i=p-1
    for j in range(p,r):
        if arr[j] <= arr[r]:
            i +=1
            arr[j],arr[i]=arr[i],arr[j]
    arr[i+1],arr[r]=arr[r],arr[i+1]
    return i+1
def quickSort(arr,p,r):
    if p < r : 
        q = partition(arr,p,r)
        quickSort(arr,p,q-1)
        quickSort(arr,q+1,p)
    return arr


print(quickSort(arr, 0, len(arr)-1))

























def partition(arr, p, r) : 
    i = p-1
    for j in range(p ,r) : 
        if   arr[j] <= arr[r]:
            i +=1
            arr[i] , arr[j] = arr[j] ,arr[i]
    arr[i+1],arr[r]=arr[r],arr[i+1]
    return i+1
def quickSort(arr ,p ,r):
    if p < r : 
        q = partition(arr ,p,r)
        quickSort(arr,p,q-1)
        quickSort(arr,q+1,r)
quickSort(arr,0,len(arr)-1)