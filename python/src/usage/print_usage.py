#!/usr/bin/python3
#Python中print函数的各种用法
print("python中print函数的用法 : ")
print("1.使用print函数完成重定向到文件")
with open("./output.txt","w") as f:
    for num in range(1,11):
        print(num,sep=" ",end=" ",file=f)

print("2.使用f-string格式化输出到显示器")
data=[1,2,3,4,5]
print(f"data的内容为: {data}")
print("3.使用'%'完成字符串格式化")
print("整数: %d | 浮点数: %f | 字符串: %s" % (1,2.3,"hello world"))
print("4.使用字符串的format方法")
print("整数: {} | 浮点数: {} | 字符串: {} | 列表: {}".format(1,2.3,"hello world",data))