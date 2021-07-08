# 二分归并排序

# ----------算法思想----------
"""
二分归并排序是一种分治算法。
这个算法不断地将一个数组分为两部分，
分别对左子数组和右子数组排序，
然后将两个数组合并为新的有序数组。
在合并的过程中需要额外的内存空间
"""

# -------------伪码描述----------

"""
MergeSort(A,p,r):
输入:数组A[p,r] 1<=p<=r<=n
输出：从A[p] 到 A[r] 按照递增的顺序排序 
    if p<r
        then q = (p+r)/2
    MergeSort(A,p,q)
    MergeSort(A,q+1,r)
    Merge(A,p,q,r) #将排好序的数组合并
"""

"""
Merge(A,p,q,r):
输入：按照递增顺序排好队的数组 A[p....q] 和 A[q+1....r]
输出按照赠序排序的数组A[p,r]
    x = q - p +1 #左边数组元素个数
    y = r - q #右边数组元素个数
    将A[p,q] 复制到数组B[1,x] ,将A[q+1,r] 复制到数组 C[1,y]
    i = 1,j = 1, k =  p
    while(i <= x and j <= y):
        if(B[i] <= C[j]) #B的首元素小，放到新数组中
            A[k] = B[i]
            i++
        else 
            A[k] = C [j]
            j++
        k++
    if i > x 
        将C[j,y] 的元素复制到 A[k,r] # B已经是空数组
    else:
        将 B[i,x] 的 元素复制到 A[k,r] # B已经是空数组
"""

# ----------具体实现-------

def MergeSort(listA):
    if len(listA) <=1: #递归结束条件
        return listA

    midle = len(listA) //2
    left = MergeSort(listA[:midle]) #左数组归并排序
    right = MergeSort(listA[midle:]) #右数组归并排序
    sort_listA = Merge(left,right)
    return sort_listA

# 合并操作
def Merge(left,right):
    l = 0
    r = 0
    result = []
    while l<len(left) and r<len(right):
        if left[l] < right[r]:
            result.append(left[l])
            l+=1
        else:
            result.append(right[r])
            r+=1
    result += left[l:]
    result += right[r:]
    return result

listA = [5,4,3,2,1]
sort_listA = MergeSort(listA)
print(listA)
print("--------------------")
print(sort_listA)