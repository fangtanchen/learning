1<<44;  这边的1是int型的，移位之后最大是int的数。 所以1<<62什么的都变成0了
- 要么把1强制变成long long int 类型
- 要么把目标的值向右移位
