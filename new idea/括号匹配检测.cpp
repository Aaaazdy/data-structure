Status judge(Stack *S)
{
    //���б��ʽ��������ж�
    SElemType *p;
    char n;

    scanf("%c",&n);            //��һ�����ŵļ��
    while(n!='(' && n!='[')        //�������ֵ��������ţ�ֱ����������
    {
        if(n==')' || n==']' || n=='#')    return FALSE;    //��Ϊ')'��']'���������ƥ�䡣'#'���ڽ�������
        scanf("%c",&n);
    }

    if(n=='(' || n=='[')    Push(S,n);    //��⵽�����ţ���ջ
    scanf("%c",&n);
    while(n!='#')    //'#'���ڽ�������
    {
        if(n=='(' || n==')' || n=='[' || n==']')
        {
            p=S->top;
            Push(S,n);
            if(*(p-1)=='(')        //��ǰһ�����űȽ�
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
    if(S->top==S->base)    return TRUE; //ջ��û��Ԫ��ʱ��˵��ƥ��
    else return FALSE;
}