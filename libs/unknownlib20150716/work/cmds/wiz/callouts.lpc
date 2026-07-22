// callouts.c
inherit F_CLEAN_UP;

int main(object me, string arg)
{
mixed *info;
int i,flag=0;
string output;

output = sprintf("%-20s %-6s %s\n", "函数", "延迟","物件");

if ( !arg )
        info = call_out_info();
else if ( sscanf(arg,"-d %s",arg)!=1 )
        info = filter_array(call_out_info(), (: $1[1]==$2 :), arg);
else    {
        info = filter_array(call_out_info(), (: $1[1]==$2 :), arg);
        flag = 1;
        }
write(sprintf("arg=%s(%d)\n",arg,flag));        
for(i=0; i<sizeof(info); i++) 
        {
        if ( flag && info[i][1]==arg )
                {
                output+= sprintf("%O 清除 %s函数 调用成功。\n", info[i][0],arg);                        
                destruct(info[i][0]);
                }
        else    {               
                if ( sizeof(info[i]) == 4)
                        output += sprintf("%-20s %-6d %O %O\n",info[i][1],info[i][2],info[i][0],info[i][3]);
                else    output += sprintf("%-20s %-6d %O\n", info[i][1],info[i][2],info[i][0]);
                }
        }
me->start_more(output);
return 1;
}

int help()
{
    write(@LONG
指令格式：callouts [-d] [<函数名称>]

查询或删除暂存的呼叫函数
LONG
    );
    return 1;
}

