9.10-a


typedef struct adjmat{
	int dist[7], a[7][7], miniumpath[7];
	char data[7], path[7];
}adjmat;
typedef struct queue{
	int front, rear, data[7];
}queue;
adjmat g;
queue q;
void Dijkstra(adjmat g, queue q)
{
	while( !(q.front == q.rear))
	{
		i = q.data[q.front++];
		for( j = 0; j < 7; j++)
		{
			if( g.a[i][j] > 0)
			{
				if( g.dist[i]+g.a[i][j] < g.dist[j])
				{
					g.dist[j] = g.dist[i]+g.a[i][j];
					g.path[j] = g.data[i];
					q.data[q.rear++] = j;
                    g.miniumpath[j] = 1;
				}
                if( g.dist[i]+g.a[i][j] == g.dist[j])
                {
					g.miniumpath[j] += 1;
				}
			}
		}
	}
}

9.10-b

typedef struct adjmat{
	int dist[7], a[7][7], edge[7];
	char data[7], path[7];
}adjmat;
typedef struct queue{
	int front, rear, data[7];
}queue;
adjmat g;
queue q;
void Dijkstra(adjmat g, queue q)
{
	while( !(q.front == q.rear))
	{
		i = q.data[q.front++];
		for( j = 0; j < 7; j++)
		{
			if( g.a[i][j] > 0)
			{
				if( g.dist[i]+g.a[i][j] < g.dist[j])
				{
					g.dist[j] = g.dist[i]+g.a[i][j];
					g.path[j] = g.data[i];
					q.data[q.rear++] = j;
                    g.edge[j] = g.edge[i] + 1;
				}
                if( g.dist[i]+g.a[i][j] == g.dist[j])
                {
					if(g.edge[i] + 1 < g.edge[j])
                    {
                        g.edge[j] = g.edge[i] + 1;
                        g.path[j] = g.data[i];
                    }
				}
			}
		}
	}
}