// user list
// modify by chui
#include <ansi.h>
inherit F_CLEAN_UP;
int main(object me, string arg)
{
    object *ob;
    int i;  
    ob=users();
    i = sizeof(ob);
    if (!arg)
    {
        while (i--) 
        {
            if ( this_player()->visible(ob[i]) )
                write(sprintf(HIY"%10s(%10s) : "+HIC"%24s\n"NOR,ob[i]->query("name"),ob[i]->query("id"), file_name(ob[i])));
        } 	
    }
    else 
    {
        while (i--) 
        {
            if ( arg == COLOR_D->uncolor(ob[i]->query("name")) )
            {
                if ( this_player()->visible(ob[i]) ) 
                    write(sprintf(HIM"%10s(%10s) : "+HIG"%24s\n"NOR,ob[i]->query("name"),ob[i]->query("id"), file_name(ob[i])));
            }
        } 	
    }
    return 1;
}

int help(object me)
{
write(@HELP
指令格式 : ulist

将线上所有玩家的/obj/user number 显示出来。
HELP
    );
    return 1;
}
