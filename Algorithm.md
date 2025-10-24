#### 取消同步流，提高效率

在大规模数据下，关闭同步流可以提高效率

```c++
#define pp ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
void solve(){
    pp;
    ...
        ...
        	...
}
```

#### 类型转换static_cast<目标类型><int>

```c++
float a;
int b = static_cast<int>(a);
```



#### **二分法**

使用前提是有序数组

1、左闭右闭 [left , right]

```c++
left = 0;
right = nums.size() - 1;
while(left <= right)
{
	int mid = left + ((right - left) >> 1);
	if(nums[mid] > target) right = mid - 1;
	else if(nums[mid] < target) left = mid + 1;
	else return mid;
}
return -1;
```

2、左闭右开 [left , right) 

```c++
left = 0;
right = nums.size();
while(left < right)
{
	int mid = left + ((right - left) >> 1);
	if(nums[mid] > target) right = mid;
	else if(nums[mid] < target) left = mid + 1;
	else return mid;
}
return -1;
```

#### **gcd(最大公约数)和lcm(最小公倍数)**

```c++
int gcd(int a, int b) {
    int temp;
    while (b != 0) {  
        temp = a % b;
        a = b;
        b = temp;
    }
    return a;  
}

int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}
```

其中求解gcd可直接使用内置函数__gcd(a,b)

输入：

```
请输入两个整数: 12 18
```

输出：

```
最大公约数: 6
最小公倍数: 36
```

#### N皇后问题

###### 回溯法

```c++
vector<int> board(n, -1);
ll ans = 0;
bool isValid(int row, int col, vector<int>& board) {
    for (int i = 0; i < row; i++) {
        if (board[i] == col || abs(board[i] - col) == abs(i - row)) {
            return false;
        }
    }
    return true;
}

void solve(int row, vector<int>& board, int n) {
    if (row == n) {
        ans++;
        return;
    }

    for (int col = 0; col < n; col++) {
        if (isValid(row, col, board)) {
            board[row] = col;
            solve(row + 1, board, n); 
            board[row] = -1; // 回溯
        }
    }
}
```

###### 位运算法

```c++
#include <iostream>
using namespace std;
long Ans = 0; // 记录解的个数

// 递归函数，寻找可以放置皇后的位置
void test(long row, long ld, long rd) {
    if (row != upperlim) {
        // pos 表示当前行可以放置皇后的位置
        long pos = upperlim & (~(row | ld | rd));
        while (pos) {
            // 取出最右边的可以放皇后的位置
            long p = pos & (-pos);
            pos -= p; // 移除该位置并递归调用 test 过程

            // 更新限制条件
            long new_ld = (ld | p) << 1;// 左对角线
            long new_rd = (rd | p) >> 1;// 右对角线
            test(row | p, new_ld, new_rd);
        }
    } 
    else {
        ++Ans; // 找到一个解
    }
}
// 位运算解决N皇后问题
void solveNQueens(int n) {
    long upperlim = (1 << n) - 1; // 初始化，upperlim 表示 n 个皇后的所有列都已放置好
    // 调用参数
    test(0, 0, 0);
    cout << "共有 " << Ans << " 种排列" << endl;
}
 
int main() {
    int n; 
    solveNQueens(n);
    return 0;
}
```

#### Dijkstra单源最短路算法

```c++
typedef pair<int, int> pii; // pair<distance, node>

void dijkstra(int n, vector<vector<pii>>& graph, int source) {
    // 最短路径数组，初始化为无穷大
    vector<int> dist(n, INT_MAX);
    dist[source] = 0;

    // 优先队列，存储当前节点的 (距离, 节点编号)
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, source}); // 起点距离为 0

    while (!pq.empty()) {
        int u = pq.top().second; // 当前节点
        int d = pq.top().first;  // 当前节点的最短距离
        pq.pop();

        // 如果当前距离大于已知最短距离，跳过
        if (d > dist[u]) continue;
        // if (vis[u]) continue;  也可以使用访问标记数组，保证每个顶点只会被处理一次
        // vis[u] = true;

        // 遍历所有邻接节点
        for (auto& edge : graph[u]) {
            int v = edge.first;   // 邻接节点
            int weight = edge.second; // 边的权重

            // 如果通过当前节点u到达v的路径更短，更新dist[v]
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v}); // 将新路径加入队列
            }
        }
    }
}
int main(){
    int n, m;// n: 节点数, m: 边数
    vector<vector<pii>> graph(n);

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w}); // u -> v (w)
        graph[v].push_back({u, w}); // 如果是无向图的话
    }
    dijkstra(n, graph, source);
}
```

#### 并查集

文章链接https://serein.blog.csdn.net/article/details/105126583?fromshare=blogdetail&sharetype=blogdetail&sharerId=105126583&sharerefer=PC&sharesource=m0_74316503&sharefrom=from_link

主要作用：求连通分支数（如果一个图中所有点都存在可达关系（直接或间接相连），则此[图的连通分支](https://so.csdn.net/so/search?q=图的连通分支&spm=1001.2101.3001.7020)数为 1；如果此图有两大子图各自全部可达，则此图的连通分支数为2……）

```c++
// 定义并查集（DSU）数据结构
class DSU {
    vector<int> pre, rank;
public:
    DSU(int n) {
        pre.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; ++i) {
            pre[i] = i; // 初始化每个顶点的父节点为自己
        }
    }

    // 查找根节点（路径压缩）
    int find(int x) {
        if (pre[x] != x) {
            pre[x] = find(pre[x]);
        }
        return pre[x];
    }

    // 合并两个集合（按秩合并）
    void unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            if (rank[rootX] < rank[rootY]) {
                pre[rootX] = rootY;
            } else if (rank[rootX] > rank[rootY]) {
                pre[rootY] = rootX;
            } else {
                pre[rootY] = rootX;
                rank[rootX]++;
            }
        }
    }
};
```

#### 最小生成树

需要利用上面的并查集

```c++
// 定义边的结构体
struct Edge {
    int src, dest, weight;
};
// Kruskal算法实现
vector<Edge> kruskal(vector<Edge>& edges, int V) {
    // 按边的权重从小到大排序
    sort(edges.begin(), edges.end(), [](const Edge& a, const Edge& b) {
        return a.weight < b.weight;
    });

    DSU dsu(V); // 初始化并查集
    vector<Edge> result; // 存放最小生成树的边

    for (const Edge& edge : edges) {
        int srcRoot = dsu.find(edge.src);
        int destRoot = dsu.find(edge.dest);

        // 如果两个顶点不在同一个集合中，则加入最小生成树
        if (srcRoot != destRoot) {
            result.emplace_back(edge);
            dsu.unite(srcRoot, destRoot);
        }
    }

    return result;
}
```

#### DFS和BFS

```c++
void dfs(int start, vector<vector<int>>& graph, vector<bool>& visited) {
    stack<int> s;
    s.push(start);
    visited[start] = true;

    while (!s.empty()) {
        int node = s.top();
        s.pop();
        for (int neighbor : graph[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                s.push(neighbor);
            }
        }
    }
}
/ ***********************************************************************
void bfs(int start, vector<vector<int>>& graph, vector<bool>& visited) {
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        for (int neighbor : graph[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}


```

#### 前缀和

前缀和是一种常用的预处理技术，用于快速计算数组中任意区间的和。在这个代码中，前缀和数组 `a` 被定义为：

```c++
for(int i=1;i<=n;i++){
    cin>>a[i];
    a[i]+=a[i-1];
}    
```

这里 `a[i]` 存储的是原数组从第1个元素到第 `i` 个元素的和。通过前缀和，我们可以快速计算任意区间 `[i, j]` 的和，公式为 `a[j] - a[i-1]`。

#### 矩阵乘法

```c++
#include <iostream>
#include <vector>
using namespace std;

// 矩阵相加
vector<vector<int>> addMatrix(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int n = A.size();
    vector<vector<int>> C(n, vector<int>(n, 0));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            C[i][j] = A[i][j] + B[i][j];
    return C;
}

// 分治法矩阵乘法
vector<vector<int>> multiplyMatrix(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int n = A.size();
    vector<vector<int>> C(n, vector<int>(n, 0));
    
    if (n == 1) {
        C[0][0] = A[0][0] * B[0][0];
        return C;
    }
    
    int mid = n / 2;
    vector<vector<int>> A11(mid, vector<int>(mid)), A12(mid, vector<int>(mid)), A21(mid, vector<int>(mid)), A22(mid, vector<int>(mid));
    vector<vector<int>> B11(mid, vector<int>(mid)), B12(mid, vector<int>(mid)), B21(mid, vector<int>(mid)), B22(mid, vector<int>(mid));
    
    for (int i = 0; i < mid; ++i) {
        for (int j = 0; j < mid; ++j) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + mid];
            A21[i][j] = A[i + mid][j];
            A22[i][j] = A[i + mid][j + mid];
            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + mid];
            B21[i][j] = B[i + mid][j];
            B22[i][j] = B[i + mid][j + mid];
        }
    }
    
    vector<vector<int>> C11 = addMatrix(multiplyMatrix(A11, B11), multiplyMatrix(A12, B21));
    vector<vector<int>> C12 = addMatrix(multiplyMatrix(A11, B12), multiplyMatrix(A12, B22));
    vector<vector<int>> C21 = addMatrix(multiplyMatrix(A21, B11), multiplyMatrix(A22, B21));
    vector<vector<int>> C22 = addMatrix(multiplyMatrix(A21, B12), multiplyMatrix(A22, B22));
    
    for (int i = 0; i < mid; ++i) {
        for (int j = 0; j < mid; ++j) {
            C[i][j] = C11[i][j];
            C[i][j + mid] = C12[i][j];
            C[i + mid][j] = C21[i][j];
            C[i + mid][j + mid] = C22[i][j];
        }
    }
    
    return C;
}

int main() {
    int n;
    cin >> n;
    
    vector<vector<int>> X(n, vector<int>(n)), Y(n, vector<int>(n));
    
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> X[i][j];
    
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> Y[i][j];
    
    vector<vector<int>> result = multiplyMatrix(X, Y);
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}
```

