inherit F_CLEAN_UP;
int main(object me,string arg)
{
    object* all = users();
    if (!arg) return notify_fail("指令格式 : findplayer 玩家中文名 \n");
    
    for(int i =0;i<sizeof(all);i++)
    {
        if(objectp(all[i]) && userp(all[i]))
        {
            if(stringp(all[i]->query("name")))
            {
                if(strcmp(all[i]->query("name"),arg) == 0)
                {
                    write(all[i]->query("id")+"\n");
                }
            }
        }
    }
    return 1;
}


int help(object me)
{
write(@HELP
指令格式 : findplayer 玩家中文名

此指令可让你根据在线玩家中文名查找ID。
HELP
    );
    return 1;
}
