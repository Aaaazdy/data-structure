Status judge(Stack *S)
{
    //进行表达式的输入和判断
    SElemType *p;
    char n;

    scanf("%c",&n);            //第一个括号的检测
    while(n!='(' && n!='[')        //忽略数字等其他符号，直到输入括号
    {
        if(n==')' || n==']' || n=='#')    return FALSE;    //若为')'或']'，则表明不匹配。'#'用于结束输入
        scanf("%c",&n);
    }

    if(n=='(' || n=='[')    Push(S,n);    //检测到左括号，进栈
    scanf("%c",&n);
    while(n!='#')    //'#'用于结束输入
    {
        if(n=='(' || n==')' || n=='[' || n==']')
        {
            p=S->top;
            Push(S,n);
            if(*(p-1)=='(')        //与前一个括号比较
            {
                if(*p==')')
                {
                    printf("%c\n",Pop(S));
                    printf("%c\n",Pop(S));
                }
                else if(*p==']')    return FALSE;
            }
            else if(*(p-1)=='[')
            {
                if(*p==']')
                {
                    printf("%c\n",Pop(S));
                    printf("%c\n",Pop(S));
                }
                else if(*p==')')    return FALSE;
            }
        }
        scanf("%c",&n);
    }
    if(S->top==S->base)    return TRUE; //栈内没有元素时，说明匹配
    else return FALSE;
}