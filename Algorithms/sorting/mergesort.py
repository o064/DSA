
arr = [5,3,4,2,1]


def merge(left , right) :
    i = j = 0 
    merged=[]
    while i < len(left) and  j < len(right) : 
        if left[i] <= right[j]:
            merged.append(left[i])
            i +=1
        else :
            merged.append(right[j])
            j+=1
    # Append remaining elements (if any)
    merged.extend(left[i:])
    merged.extend(right[j:])
    
    return merged

def merge_sort(arr) : 
    n =len(arr)
    if len(arr) <= 1 :
        return arr 
    mid =  n // 2
    left = merge_sort(arr[:mid])
    right = merge_sort(arr[mid:])
    return merge(left,right) 




print(merge_sort(arr))

