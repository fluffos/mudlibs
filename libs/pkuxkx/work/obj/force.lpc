#pragma save_binary
// order.c
inherit F_CLEAN_UP;

int main(object me,string arg)
{
        int res;
        object ob;
        string who,cmd,verb,path;


        if( me != this_player(1) ) return 0;

        if( !arg || arg==""|| sscanf(arg, "%s to %s", who, cmd)!=2 )

                return notify_fail("你要命令谁做什麽事？\n");
       ob = present(who,environment(me));
        if( !ob || !ob->is_character())
        return notify_fail("这里没有这个人。\n");

           res = ob->force_me(cmd);
        seteuid(getuid());
        return res;

}
