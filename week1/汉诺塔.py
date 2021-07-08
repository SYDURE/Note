# 汉诺塔

"""

Hanoi(A,C,n):
if n = 1 then move(A,C)  //将最大的盘子移动到C上
else Hanoi(A,B,n-1)  //以C为中间柱,将n-1 个盘子移动到B上
    move(A,C)         //将当前最大的盘子移动到C上
    Hanoi(B,C,n-1)   //以A为中间柱，将n-1 个 盘子移动到C上

"""

# ----------------实现-----------------

def Hanoi(A,C,B,n):   #开始 结束 中间柱
    if n == 1:
        print(A,"-->",C)
    else:
        Hanoi(A,B,C,n-1) #//以C为中间柱,将n-1 个盘子移动到B上
        print(A, "-->", C)
        Hanoi(B,C,A,n-1)

if __name__ == '__main__':
    Hanoi("A","B","C",3)

