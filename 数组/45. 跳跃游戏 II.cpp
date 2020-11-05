45. 跳跃游戏 II

给定一个非负整数数组，你最初位于数组的第一个位置。

数组中的每个元素代表你在该位置可以跳跃的最大长度。

你的目标是使用最少的跳跃次数到达数组的最后一个位置。

示例:

输入: [2,3,1,1,4]
输出: 2
解释: 跳到最后一个位置的最小跳跃数是 2。
     从下标为 0 跳到下标为 1 的位置，跳 1 步，然后跳 3 步到达数组的最后一个位置。

说明:

假设你总是可以到达数组的最后一个位置。

https://leetcode.com/problems/jump-game-ii/discuss/18014/Concise-O(n)-one-loop-JAVA-solution-based-on-Greedy

The main idea is based on greedy. Let's say the range of the current jump is [curBegin, curEnd], 
curFarthest is the farthest point that all points in [curBegin, curEnd] can reach.
Once the current point reaches curEnd, then trigger another jump, and set the new curEnd with curFarthest, 
then keep the above steps, as the following:

class Solution {
public:
    int jump(vector<int>& nums) {
        int jump = 0, curEnd = 0, curFarthest = 0;
        for (int i = 0; i < nums.size() - 1; ++i) {
            curFarthest = max(curFarthest, i + nums[i]);
            if (i == curEnd) {
                ++jump;
                curEnd = curFarthest;
            }
        }
        return jump;
    }
};
