# 最大公约数

# --------------伪码-------
"""
输入： 非负整数m,n，其中m 与 n 不全为0
输出： m与 n的最大公约数
// 使用r代表余数

while n>0 do:
    r = m mod n
    m = n
    n = r
return m

"""

# --------------实现-------

def Euclid(m,n):
    while n != 0:
        r = m % n
        m = n
        n = r
    return m

m = Euclid(10,3)
print(m)
