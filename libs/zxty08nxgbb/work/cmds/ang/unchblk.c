// channel unblock command..

inherit F_CLEAN_UP;
int main(object me, string arg)
{
        object ob;
        
    if (!arg)
        return  notify_fail("命令格式: unchblk <玩家id>\n");
    
        ob = LOGIN_D->find_body(arg);
        if (!ob) return notify_fail("这个人不在！\n");
        if (time()- ob->query("chblk_channel")>3600)
                tell_object(me,(string)ob->query("name")+"的聊天频道是打开的。\n");
        else{
                ob->delete("chblk_channel");
                tell_object(me, (string)ob->query("name")+"的所有频道被打开了。\n");
        }
        return 1;
}
int help(object me)
{
write(@HELP
指令格式 : unchblk <某人>

       此命令将打开某人的交谈频道。
HELP
    );
    return 1;
}

