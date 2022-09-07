int* read_list(char** data_pointer,int* list)
{
    int* i=list;
    int k=read_int(data_pointer);
    while(k!=-1)
    {
        *i=k;
        i++;
        k=read_int(data_pointer);
    }
    return i;
}
void list_cat(int* list1,int** list1_end_pointer,int* list2,int* list2_end)
{
    int* i=list2;
    for(;i<list2_end;i++)
    {
        **list1_end_pointer=*i;
        (*list1_end_pointer)++;
    }
}
void clear_char(char** data_pointer,const char c)
{
    while(**data_pointer!=c) 
    ++*data_pointer;
    ++*data_pointer;
}
