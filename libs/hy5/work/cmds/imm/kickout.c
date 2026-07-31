//  kickout.c
// by edward 

#include "/doc/help.h"
#include <ansi.h>

inherit F_CLEAN_UP;
inherit F_DBASE;

int main(object me, string arg)
{
        string name,q_name,q_id,q_ip;
        object obj;

        if( !arg ) return notify_fail("指令格式 : kickout <玩家名>\n" );

        seteuid(ROOT_UID);

    obj = LOGIN_D->find_body(arg);
        if( !obj || !userp(obj) ) return notify_fail("没有这个玩家....。\n");

//        name = obj->short(1);
//        q_name = obj->name();
        q_id = obj->query("id");
        q_ip = query_ip_name(obj);

        if( me == obj )
                return notify_fail("用 quit 这条指令好些 :) \n");

        if( (wiz_level(me) < wiz_level(obj)) || (wiz_level(me) == wiz_level(obj)) )
                return notify_fail("你不能赶级别比你高的巫师的下线！\n");

        tell_room( environment(obj), me->name() + "突然出现在你面前，并且说道：“"+q_name +
                        "！你这个" + RANK_D->query_rude(obj) + "，滚吧！\n" );
        obj->set("last_on", time());
        obj->save();
        catch(destruct(obj));
        if( obj )
                return notify_fail("你无法让这个玩家离线。\n");
        else {
                set("channel_id", me->name() );
        CHANNEL_D->do_channel(this_object(), "rumor", q_name + "被系统踢出了"+MUD_NAME+"。");
                CHANNEL_D->do_channel(this_object(), "sys", "我将"NOR + name + HIR"踢出了系统。");
                log_file("kickout",
                        sprintf("%s(%s) kickout %s(%s) on %s at %s.\n", me->name(), 
                        me->query("id"), q_name, q_id, q_ip, ctime(time()) ) );
        }
        return 1;
}

int help(object me)
{
        write(@HELP
指令格式 : kickout <玩家名>

此命令可以强迫恶意的玩家离线。

HELP );
        return 1;
}

