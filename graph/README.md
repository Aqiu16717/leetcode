* 图(graph)的组成
  * 顶点(edge)
  * 边(vertex)

* 根据边是否具有方向
  * 有向图(directed graph)
  * 无向图(undirected graph)

* 根据所有顶点是否连通
  * 连通图(connected graph)
  * 非连通图(disconnected graph)

* 为边添加“权重”变量
  * 有权图
  * 无权图

* 邻接(adjacency)：两顶点之间存在边相连

* 路径(path)：从顶点 A 到顶点 B 经过的边构成的序列被称为从 A 到 B 的“路径”

* 度(degree)：一个顶点拥有的边数
  * 入度: 有向图中，指向该顶点的边的数量
  * 出度：有向图中，有多少条边从该顶点指出


* 图的表示
  * 邻接矩阵adjacenncy matrix
    * nxn的矩阵/二维数组： 从顶点的角度表示图
        * 可以快速判断两个顶点之间有没有边
        * 对于稀疏图空间利用率低，适合用于稠密图
  * 邻接表adjacency list：从边的角度表示图
    * n个链表
    * 适合稀疏图
    * 不便于判断两个顶点之间是否存在边

* 图的遍历
  * bfs
  * dfs