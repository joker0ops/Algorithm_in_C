/****************************************************************************

图G由顶点集V和边集E组成，记为G=(V,E)，V(G)表示图G中顶点的有限非空集，E(G)表示图G中顶点之间的关系。
使用|V|表示图G中顶点的个数，也称图的阶，|V|>=1，V一定是非空集
E={(u,v)|u∈V, v∈V}，这里(u,v)表示无向边，<u,v>表示u到v的有向边，|E|表示图G中边的条数

邻接矩阵存储无权图：
#define MaxVertexNum 100
// 定义顶点的最大数目
typedef struct{
    char Vex[MaxVertexNum];
    // 顶点表，存储顶点字母
    int Edge[MaxVertexNum][MaxVertexNum];
    // 邻接表，若是无权图，也可直接用bool类型或枚举类型表示边
    int vexnum,arcnum;
    // 图的当前顶点数和边数/弧数
} MGraph;

邻接矩阵存储带权图（网）：
#define MaxVertexNum 100
#define INFINITY 最大的int值
typedef char VertexType;
// 定义顶点数据类型
typedef int EdgeType;
// 定义边权值的数据类型
typedef struct{
    VertexType Vex[MaxVertexNum];
    // 定义顶点
    EdgeType Edge[MaxVertexNum][MaxVertexNum];
    // 邻接矩阵存储边的值
    int vexnum,arcnum;
    // 当前图的顶点数和弧数
} MGraph;

邻接表法（类似树的孩子表示法）
    data   *first                   (data域存储与顶点相关的一些信息, first域指向与该顶点相连的第一条边)
0   A       ->(1, )->(2, )->(3, )   // 表示与顶点A直接相连的结点有B,C,D
1   B       ->(0, )->(4, )->(5, )
2   C       ->(0, )->(4, )
3   D       ->(0, )->(5, )
4   E       ->(1, )->(2, )
5   F       ->(1, )->(3, )

// 边
typedef struct ArcNode{
    int adjvex;
    // 边所指向的结点的序号，标识边指向哪个结点
    struct ArcNode *next;
    // 指向下一条边的指针
    // InfoType info;
    // 边权值
} ArcNode;

// 顶点
typedef struct VNode{
    VertexType data;
    // 顶点信息
    ArcNode *first;
    // 第一条边，哪条边是第一条并不重要，有多种表示方法
}VNode,AdjList[MaxVertexNum];

// 用邻接表存储的图
typedef struct{
    AdjList vertices;
    int vexnum,arcnum;
}ALGraph;

图的基本操作：
Adjacent(G,x,y);            // 判断图G是否存在边<x,y>或(x,y)
Neighbors(G,x);             // 列出图G中与结点x相邻的边
InsertVertex(G,x);          // 在图G中插入顶点x
DeleteVertex(G,x);          // 从图G中删除顶点x
AddEdge(G,x,y);             // 若边(x,y)或<x,y>不存在则添加
RemoveEdge(G,x,y);          // 若边(x,y)或<x,y>存在则删除
FirstNeighbor(G,x);         // 求图G中顶点x的第一个邻接点，若有则返回邻接点号，若图中无x或x无邻接点则返回-1
NextNeighbor(G,x,y);        // 假设G中顶点y是x的一个邻接点，则返回除y之外x的下一个邻接点号，若y是x的最后一个邻接点则返回-1
Get_edge_value(G,x,y);      // 获取图G中边(x,y)或<x,y>对应的权值
Set_edge_value(G,x,y,v);    // 设置图G中边(x,y)或<x,y>的权值为v

BFS：
bool visited[MAX_VERTEX_NUM]={false};
void BFS(Graph G,int v);
void BFSTraverse(Graph G){
    InitQueue(Q);
    // 初始化队列
    for(i=0;i<G.vexnum;++i)
        if(!visited[i])
        // 从第一个未访问的结点开始进行BFS，防止非连通图出现没有访问的结点
            BFS(G,i);
}
void BFS(Graph G,int v){
    visit(v);
    visited[v]=true;
    EnQueue(Q, v);
    // 将该顶点序号v入队
    while(!isEmpty(Q)){
        DeQueue(Q, v);
        // 从队列中取出一个顶点序号并把该顶点序号存入v
        for(w=FirstNeighbor(G,v);w>=0;W=NextNeighbor(G,v,w)){
            if(!visited[w]){
                visited(w);
                visited[w]=true;
                Enqueue(Q,w);
            }
        }
    }
}
[分析]图的操作并不是直接对结点操作，在操作过程中调用的是顶点的序号，以上过程是先访问，然后再将该顶点入队，
在访问它的邻接结点时先将其出队，再访问其邻接结点，也可先入队再出队访问。具体流程如下：
EnQueue(v);
while(!isEmpty(Q)){
    DeQueue(Q,v);
    visit(v);
    visited[v]=true;
    for(w=FirstNeighbor(G,v);w>=0;w=NextNeighbor(G,v,w)){
        Enqueuw(Q,w);
    }
}

DFS:
bool visited[MAX_VERTEX_NUM]={false};
void DFS(Graph G,int v);
void DFSTraverse(Graph G){
    InitQueue(Q);
    // 初始化队列
    for(i=0;i<G.vexnum;++i)
        if(!visited[i])
        // 从第一个未访问的结点开始进行BFS，防止非连通图出现没有访问的结点
            DFS(G,i);
}
void DFS(Graph G, int v){
    visit(v);
    visited[v]=true;
    for(w=FirstNeighbor(G,v);w>=0;w=NextNeighbor(G,v,w))
        if(!visited[w])
            DFS(G,w);
}

BFS求无权图的单源最短路径
// 需要三个数组
// d[]用来保存从u到各个顶点的最短路径
// path[]用来保存该最短路径上该顶点的直接前驱
// visited[]用来保存顶点的访问状态
void BFS_MIN_Distance(Graph G, int u){
    for(i=0; i<G.vexnum; i++){
        d[i]=∞;
        path[i]=-1;
    }
    d[u]=0;
    visited[u]=true;
    EnQueue(Q,u);
    while(!isEmpty(Q)){
        DeQueue(Q,u);
        for(w=FirstNeighbor(G,u);w>=0;w=NextNeighbor(G,u,w)){
            if(!visited[w]){
                // 访问邻接顶点w，更新三个数组信息
                d[w]=d[u]+1;    // 注意这里一定是d[u]+1，在原路径长度的基础上叠加
                path[w]=u;
                visited[w]=true;
                EnQueue(Q,w);
            }
        }
    }
}
BFS寻无权图单源最短路径的实现仅仅需要该BFS算法的visit部分。
其生成树一定是以源点为根的树，每个顶点所在层数就是该顶点距源点的最短距离。
仅适用于求无权图

Dijkstra算法：
// 可求无权/有权图，有向/无向图（无向图就是双向有向图）
// 需要三个数组
// final[]标记各顶点是否已经找到最短路径
// dist[]最短路径长度
// path[]路径上的前驱

Floyd算法：
// 可求带权/无权图，有向/无向图的各顶点间最短路径
// 需要两个数组，A(x)用来存储当前以x作为中转点的邻接二维矩阵，其中存储的是顶点两两之间以x作为中转点时的最短路径
// path(x)用来标识两个顶点之间的中转点
// 初始时，不存在直接路径的最短路径长度为∞，中转点全为-1
步骤：
1、若A(k-1)[i][j]>A(k-1)[i][k]+A(k-1)[k][j]
2、则A(k)[i][j]=A(k-1)[i][k]+A(k-1)[k][j]
    path(k)[i][j]=k
3、否则A(k)和path(K)保持原值
实现：
// ......省略矩阵的初始化工作
for(int k=0;k<n;k++){   // 考虑以k作为中转点
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
        // 遍历整个A矩阵
            if(A[i][j]>A[i][k]+A[k][j]){    // 以k作为中转点的路径更短
                A[i][j]=A[i][k]+A[k][j];    // 更新路径长度
                path[i][j]=k;               // 更新中转点
            }
        }
    }
}
通过递归寻找完整的最短路径
void search(int path[][], int i, int j){
    if(path[i][j]==-1){
        printf(i->j);
        return ;
    }
    else if(path[i][j]!=-1){
        search(path, i, path[i][j]);
        search(path, path[i][j], j);
    }
}
****************************************************************************/