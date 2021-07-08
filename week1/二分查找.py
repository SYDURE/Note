# 二分查找

# ---------------算法思想---------
"""
思想：基于分治思想的快速搜索算法
适用于有序序列
基本原理：
1.找到搜索区域内的中间元素，和目标元素进行比对：
2.如果相等，则成功找到目标元素，返回该元素所在的位置；
3.如果目标元素的值大于中间元素，
    表明目标元素位于中间元素的右侧，因此以中间元素的右侧区域作为新的搜索区域
4. 如果目标元素的值小于中间元素，表明目标元素位于中间元素的左侧，
    因此以中间元素的左侧区域作为新的搜索区域
"""

# ----------------=伪代码描述------------

"""
binary_search( arr , p , q , ele):                                      // [p,q] 指定搜索区域，ele 为要搜索的目标元素
    if p > q:                                                                     // [p,q] 不存在时，返回一个错误值（比如 -1）
        return -1
    mid <- ⌊p+(q-p)/2⌋                                                   // 找到 [p,q] 区域内中间元素所在位置的下标
    if ele == arr[mid]:                                                     // 递归的出口，即 ele 和中间元素的值相等
        return mid
    if ele ＜ arr[mid]:                                                     // 比较 ele 和中间元素的值，进一步缩小搜索区域
        return binary_search(arr , p , mid-1 , ele)
    else:
        return binary_search(arr , mid+1 , q , ele)
"""

#--------------------具体实现----------------------
def binary_search(alist,item):
    n=len(alist)
    if n>0:
        mid = n // 2 #找到中间值
        if alist[mid]==item:
            return True  #证明中间值就是要找的值
        elif alist[mid]<item:
            return binary_search(alist[mid+1:],item)  #在中间值的右侧是目标值，按照递归的思想进行调用函数
        else:
            return binary_search(alist[:mid],item)    #在中间值的左侧是目标值，按照递归的思想进行调用函数
    return False

print(binary_search([1,2,3,4,5],2))