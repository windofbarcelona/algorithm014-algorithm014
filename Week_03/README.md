学习笔记(本周刷题的记录截图在仓库中，一起推了上来)

刷题心得：

1.在最开始做题的时候，对于树的递归算法，自己只是有一个大概的思路，还分析不出最根本的子问题，以至于代码写不出来，对于这种题目，本周进行了反复练习，最起码写了四到五遍，慢慢去理解思想

2.对于递归来说，已经养成了习惯，不管题会不会做，先把模板码出来

(1) 跳出条件

(2)处理当前层

(3)进入下一层  一般二和三可能会写在一起

(4)恢复一些变量，这里似乎在回溯的时候用的比较多一点

3.本周课程的最后一部分内容是回溯，这部分内容我之前是根本不会的，马上研二了根本不知道回溯算法是什么.......

在做78题子集的时候看到了大佬的题解，硬着头皮读完了，发现很有规律性，这里贴出get到的宝藏模板

`result = []
def backtrack(路径, 选择列表):
    if 满足结束条件:
        result.add(路径)
        return
    for 选择 in 选择列表:
        做选择
        backtrack(路径, 选择列表)
        撤销选择

作者：labuladong
链接：https://leetcode-cn.com/problems/subsets/solution/hui-su-si-xiang-tuan-mie-pai-lie-zu-he-zi-ji-wen-t/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。`

对于目前用回溯算法解决的题目：17,46,47,51,77,78 这个模板都可以完美解决，并且在经过前面的练习之后，自己独立完成17题，简直是欣喜若狂(说白了还是自己菜 哈哈哈)

4.回溯算法一般是结合剪枝进行，剪枝我觉得就是上课讲到的试错的过程，在发生错误之前，剪掉要走的路径，可以极大的加快程序的运行，但是现在还是考虑不到剪枝的条件需要在以后慢慢去练习



本周收获满满，尤其是在回溯算法方面！加油！！！

