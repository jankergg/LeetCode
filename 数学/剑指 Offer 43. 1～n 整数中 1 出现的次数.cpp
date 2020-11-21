剑指 Offer 43. 1～n 整数中 1 出现的次数

输入一个整数 n ，求1～n这n个整数的十进制表示中1出现的次数。
例如，输入12，1～12这些整数中包含1 的数字有1、10、11和12，1一共出现了5次。


class Solution {
public:
    int countDigitOne(int n) {
        int ones = 0;
        for (long m = 1; m <= n; m *= 10)
            ones += (n / m + 8) / 10 * m + (n / m % 10 == 1 ? n % m + 1 : 0);
        return ones;
    }
};

题解出自：

https://blog.csdn.net/darlingwood2013/article/details/90477318

https://cloud.tencent.com/developer/article/1399281

以 51234这个数为例，我们可以先将 51234划分成 1~1234（去掉最高位）和 1235~51234两部分来求解。下面先分析 1235~51234这个区间的结果：

所有的数中，1在最高位（万位）出现的次数
对于 1235~51234，最高位为1时（即万位为1时）的数有 10000~19999这10000个数，
也就是说1在最高位（万位）出现的次数为10000，因此我们可以得出结论：
如果最高位大于1，那么在最高位上1出现的次数为最高位对应的单位（本例中为一万次）；
但如果最高位为1，比如 1235~11234，那么次数就为去掉最高位之后的数了， 11234去掉最高位后是 1234，即1在最高位上出现的次数为 1234

所有的数中，1在非最高位上出现的次数
我们可以进一步将 1235~51234按照最高位的单位划分成4个区间（能划分成几个区间由最高位上的数决定，这里最高位为5，所以能划分5个大小为一万子区间）：

1235~11234

11235~21234

21235~31234

31235~41234

41235~51234

而每个数不考虑万位（因为1在万位出现的总次数在步骤1中已统计好了），其余四位（个、十、百、千）取一位放1（比如千位），
剩下的3位从 0~9中任意选（ 10*10*10），那么仅统计1在千位上出现的次数之和就是： 5(子区间数)*10*10*10，还有百位、十位、个位，结果为： 4*10*10*10*5。
因此非高位上1出现的总次数的计算通式为： (n-1)*10^(n-2)*十进制最高位上的数（其中 n为十进制的总位数）
于是 1235~51234之间所有的数的所有的位上1出现的次数的综合我们就计算出来了

剩下 1~1234，你会发现这与 1~51234的问题是一样的，因此可以做递归处理，即子过程也会将 1~1234也分成 1~234和 235~1234两部分，并计算 235~1234而将 1~234又进行递归处理。

而递归的终止条件如下：

如果 1~n中的 n： 1<=n<=9，那么就可以直接返回1了，因为只有数1出现了一次1
如果 n==0，比如将 10000划分成的两部分是 0~0(10000去掉最高位后的结果)和 1~10000，那么就返回0

笔者曾纠结，对于一个四位数，每个位上出现1时都统计了一遍会不会有重复，比如 11111这个数在最高位为1时的 10000~19999统计了一遍，
在统计非最高位的其他位上为1时又统计了4次，总共被统计了5次，而这个数1出现的次数也确实是5次，因此没有重复。


