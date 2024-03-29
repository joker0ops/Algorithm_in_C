/****************************************************************************
    常考考点：
    数据、数据对象、数据元素、数据项的关系（包含）
    定义了一个ADT也就定义了一个数据结构，ADT只关心数据的逻辑结构及其运算，与具体实现无关（不关心存储结构）
    
    数据结构包括：逻辑结构、存储结构和数据的运算
    其中：
    算法设计依赖于逻辑结构
    算法实现依赖于存储结构
    从计算机的角度出发，确定了一种存储结构才能确定逻辑结构并且一定会确定一种逻辑结构
    逻辑结构独立于存储结构，存储结构不同，运算的具体实现就不同

    逻辑结构表示数据之间的对应关系：是毫无关系还是一对一、一对多、多对多？
    存储结构表示数据结构在计算机中的表示：包括顺序存储、链式存储、索引存储、散列存储（又称哈希存储）
    示例：像栈、队列说的是一种抽象数据类型、是逻辑结构，但链栈（用链表实现的栈结构）或者循环队列（用顺序表实现的队列）
    就是一种数据结构，其中包含了存储结构

    数据的运算：运算的定义是针对逻辑结构的，运算的实现是针对存储结构的

    算法特性：
    有穷性
    确定性（相同输入—>相同输出）
    可行性
    输入
    输出

    算法目标：
    正确性
    可读性
    健壮性（处理非法数据）
    效率与低存储量要求

    加法规则：T(n) = T1(n) + T2(n) = O(f(n)) + O(g(n)) = O(max(f(n), g(n)))
    乘法规则：T(n) = T1(n)*T2(n) = O(f(n)*g(n))
    递归算法的时间复杂度可以用递推式求Tn=Tn-1+x或直接看递归嵌套次数与基本运算执行次数的关系

    空间复杂度： 如若输入数据所占空间与所使用的算法无关，则只分析额外空间
                对于递归程序，空间复杂度一般与递归深度相等

    同一个算法，实现语言的级别越高，执行效率越低
****************************************************************************/