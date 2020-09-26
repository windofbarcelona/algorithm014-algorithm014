学习笔记
本周总结：
1.周二算是结束了项目的一期，先补了一下上周的dp，做了四道实战例题，发现最困难的是dp方程的推导，但是只要能写出dp方程，后续代码的编写会相对容易一些，开始学的时候总是搞不懂什么自顶向下还是自顶向上，后面就干脆根据dp方程去确定 base case的值
如果dp方程最后出来是 dp[i] = dp[i+1]之类的，可以从边界的最大值开始初始化，如果是dp[i]=dp[i-1]之类的，一般是从0初始化，现在对于滚动数组理解不深，主要是因为还没有深入去复习上周的课程，不过感觉dp很有意思，接下来会挤时间补课
2.对于本周的课程是从周五开始看的，还是第一次听说字典树这个东西，题目大多是之前的题目，但是换了不同的做法，由于时间关系本周练习程度不够，后面都会练到
3.双向bfs模板
quefisrst.push(firstNode);
quelast.push(laseNode);
while (!quefisrst.empty() && !quelast.empty()) {
    if (quefisrst.size() < quelast.size())
        swap(quefirst, quesecond);
    int size = quelast.size();
    while (size--) {
        //按照bfs的方式，遍历node有关的节点，逐个入队，然后使用set进行去重，两端进行逼近
        auto node = quelast.front();
        quelast.pop();
    }
}
