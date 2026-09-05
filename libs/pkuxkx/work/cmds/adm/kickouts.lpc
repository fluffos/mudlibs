// kickout.c
#include <ansi.h>
#include <command.h>
inherit F_CLEAN_UP;
int main(object me, string arg)
{
        object ob;
        string tmpstr;
        if( me!=this_player(1) ) return 0;
        if( !arg || sscanf(arg, "%s", arg)!=1 )
                return notify_fail("指令格式 : kickout <某人>\n");
        if(!wizardp(me))
                return 0;
        ob = LOGIN_D->find_body(arg);
        if (!ob) return notify_fail("咦... 没有这个人?\n");
/*                 if (    !living(ob)
                ||      !ob->is_character())
                        return notify_fail("搞错了吧，这个怎么能踢呢？\n");%/
                        return notify_fail("搞错了吧，这个怎么能踢呢？\n");*/
        message_vision( HIW "\n$N一个大脚把$n给踢了出去\n\n" NOR, me,ob);
        seteuid(ROOT_UID);
        ob->save();
        destruct(ob);
        seteuid(getuid());
        return 1;
}
int help(object me)
{
write(@HELP
指令格式 : kickout <某人>
HELP
    );
    return 1;
}
