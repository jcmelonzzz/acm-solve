## A - 确定比赛名次

#### 题目大意

#### 只有比赛成绩，形式如P1 P2，这种意思就说明P1赢了P2，请为他们排序且小序号排在大序号前面

#### 首先先想一下它跟图的关系，这道题有一个特点，没比过的队伍该怎么排？输出要求提示了小在大的前面，只有参与了比赛的两只队才有彼此的输赢关系，那就可以构造一个有向图，赢指向输，那么就可以联系拓扑排序，即后面的点不会指向它前面的那个点，那么就解决一部分的问题，其次就是排序问题，上课也有讲过利用优先队列自带的排序功能，便可以达到要求，首先就是构造有向图，其次利用拓扑排序和优先队列解决问题，但题目有个没注意到的地方（~~其实是眼瞎了~~），就是最开始要求多组数据，那么就要有循环语句，导致两次wa


### 拓扑排序模板
```
queue<int> q
//或者使用优先队列（看题目是否有要求排序）priority_queue<int,vector<int>,greater<int> > q
vector<int> mp[maxn];
int in[maxn];//表示入度，也就是说一个点被指向的次数
for(int i = 1;i <= n;i++)if(!in[i])q.push(i);
while(!q.empty()){
    int cnt = q.top();
    q.pop();
    if(!q.empty())printf("%d ",cnt);
    else printf("%d\n",cnt);
    for(int i=0;i<mp[cnt].size();i++){
        int cmp = mp[cnt][i];
        in[cmp] --;
        if(!in[cmp])q.push(i);
    }
}
```


## B - 图的遍历

#### 题目大意

#### 给n个点，m条路径，寻找每个点可以到的最大点

#### 最开始用dfs搜索，从小到大，一个一个遍历，知道找到最大的点，询问的点打上标记避免重复询问，但是这样子会导致超时，原因是每个点会有可能重复后面点的dfs，看了一下题解后了解反向建图，从大的开始，那么大的能到的点也就说明那个点可以到达大的点，给他赋值，至此解决问题
```
//注意用来装有向图的一般用vector
vector<int> a[amxn];
```


## C - 产生冠军

#### 题目大意

#### 游戏规则：如果A赢B，B赢C，A与C没打比赛，那么A一定赢C；如果A赢B，B赢C，C赢A，那么没有冠军，有n个比赛，比赛结果为前者战胜后者，判断是否冠军

#### 第一眼看，大抵跟有向图有关，联系一下前面做的两道题，大概就是入度为0的是比赛第一名，但要考虑是否有多个入度为0的选手，还有就是这次不同的是字符串，而不是数字，那么就应用map，标记选手，如果是第一次出场，则输入vector，如果不是，则要看是否赢得比赛进行判断，那就用1标记一直赢比赛的选手，其他就依次加1，最后来依次找出为1的选手，再看数量，同样要注意是多组数据


## D - 逃生

#### 题目大意

#### 有n个人，1最富，依次类推，富的在前（~~有关系~~），然后有m对关系，例如a b，a必须在b前面，求排序

#### 根据题意大概可以知道是拓扑排序，先根据关系来排序，接着小的在大的前面，最开始还用了map去重，但是后面出来的答案是不对的，这样子是错的，因为可能存在如下情况，比如说三个数，a,b,c，其中a>b>c，但是题目要求c在a前面，b又跟第一名有关系，那么这样子按照原来那样子来排序，会有可能排成bac，而正确答案是cab，所以这个时候利用B题所使用的反图，因为是书的大小关系发生了问题，那么我尝试一下从大到小，是否可以？事实上是可以的，也试着去推演一遍，是可以的


## E - 繁忙的都市

#### 题目大意

#### 一座城市，n个交叉路口，有m条需要修的路，需要修多少条且最小总花费中最大花费是多少

#### 要求最小总值，形成一个无向图，也就是权值之和最小，那么就是最小生成树，那么怎么写呢，利用Kruskal算法，来进行求解，利用并查集来回溯是否连接或者是否成环，并依次累加求路线总数和最小权值之和中最大的值，模板如下

### Kruskal算法模板/最小生成树
```
int lu_sum = 0;//路线总数
int lu_all = 0;//权值综合
int id[maxn];//序号
struct lu
{
    int u,v;
    int cost;
    //bool operator <(const lu& t)const{
    //    return cost < t.cost;
    //}
}p[maxn];
bool cmp(lu a,lu b){
    return a.cost < b.cost;
}//也可以用重载运算符
int find(int x){
    if(id[x] != x)id[x] = find(id[x]);
    return id[x];
}
void solve(){
    sort(p+1,p+1+m);
    for(int i=1;i<=n;i++)id[i] = i;
    for(int i=1;i<=m;i++){
        if(find(p[i].u)!=find(p[i].v)){
            id[find(p[i].u)] = find(p[i].v);
            lu_sum ++;
            lu_all += p[i].cost;
            if(lu_sum == n-1)break;
        }
    }
}
```


## F - 口袋的天空

#### 题目大意

#### 有n个云，m个关系，存在关系的两个云可以合成一个云，需要k个棉花糖，一个云合成一个棉花糖，那么花费的最小代价是多少

#### 主要思路是最小生成树，将sum的临界值改成n-k即可


## G - 买礼物

#### 题目大意

#### 买B样东西，每个东西价格为A，但是K-i,j表示买了第i样东西后买第j样的价格就是K-i,j，求最小价格总和

#### 求最小总和，每一样之间可能存在关系，那么就利用最小生成树，首先要注意数据范围（~~错在这里四次。。。~~）因为是矩阵，物品最多五百，那么下标至少是五百的阶乘，然后利用kruskal算法，去进行求解，然后就是矩阵中要收取有用的关系，比如价格比原价格还大的pass，为0也pass，j>i也可以pass，然后对这些数据进行排序即可


## H - 局域网

#### 有一些网络形成回路，保证n个点都是连通的情况下，删除价值较大的线路，求最大删除价值之和

#### 与前面的不一样，这是求最大了，但要求还是一样，保持连通，换个角度想，其实剩下来的也就是最小价值总和了，那么就可以使用最小生成树


## I - 部落划分

#### 题目大意

#### n个居住点，划分成k个部落，要求最近的部落的距离最远

#### 要求最近的部落的距离最远，那么就得先求出每个居住点的距离，这样子就可以进行排序，然后就利用最小生成树，把那些距离近的居住点合并在一起，合并数量达到n-m个时，下一个距离长度即为最近部落的最远距离


## J - Explorer

#### 题目大意

#### 