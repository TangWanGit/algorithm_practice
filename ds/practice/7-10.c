//
// Created by zhaoxiaoli on 2019-09-16.
//
/**
 * @desc: 
 * @author zhaoxiaoli
 * @date 2019-09-16
 */


void Prim()
{
    MST = {s};
    while(1){
        V = 未收录顶点中dist最小者;
        if(这样的V不存在)
            break;
        将V收录进MST;
        dist[V] = 0;
        for(V 的每个邻接点 W)
            if(dist[W] != 0)
                if(E(v,w) < dist[W]) {
                    dist[W] = E(v,w);
                    parent[W] = V;
                }
    }
    if( MST 中收的顶点不到V个)
        ERROR("生成树不存在");
}