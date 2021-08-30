//万能版本
    int a[100];
	char c;
	int i=0;
	int k=1;
	int num=-1;
	do
	{
	    c=getchar();
		if((c==','&&k!=1)||(c=='\n'&&k!=1)||(c==EOF&&k!=1))
		{
			a[++num]=i;
			i=0;
			k=1;
		}
		else
		{
			i=c-'0'+i*10;
			k=0;
		}
	}
	while(c!='\n'&&c!=EOF);
//数组从0开始，到num为数组上限	
	
	

//逗号结尾版本
    int a[100];
    char c;
    int i=0;
    int num=-1;
    while((c=getchar())!='\n'&&c!=EOF)
	{
	    if(c==',') 
		{
		    a[++num]=i;
   		    i=0;
	    }
	    else
		{
   	        i=c-'0'+i*10;
	    }
    }
//数组从0开始，到num为数组上限	


//不以逗号结尾版本
    int a[100];
    char c;
    int i=0;
    int num=-1;
    while((c=getchar())!='\n'&&c!=EOF)
	{
	    if(c==',') 
		{
		    a[++num]=i;
   		    i=0;
	    }
	    else
		{
   	        i=c-'0'+i*10;
	    }
    }
    a[++num]=i;
//数组从0开始，到num为数组上限	