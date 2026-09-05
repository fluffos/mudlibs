// kickout.c
// modified by olives@indeed
#include <ansi.h>
#include <command.h>
inherit F_CLEAN_UP;
int main(object me, string arg)
{
        object ob;
        int    block_time,cur_time;
        string name;

        if( me!=this_player(1) ) return 0;
        if( !arg )
                return notify_fail(MAG"踢错了,不羞!\n"NOR);

        if( sscanf(arg, "%s for %d", name,block_time)!=2 )
        {
                if( sscanf(arg, "%s", name)!=1 )
                        return notify_fail(MAG"踢错了,不羞!\n"NOR);
        }
        ob = LOGIN_D->find_body(name);
		if(living(ob) && (wiz_level(me) < wiz_level(ob)))
			return notify_fail("你的巫师等级必须比对方高才能踢他出去。\n");
        if (!ob) return notify_fail("咦... 有这个人吗?\n");
/*
				if (    !living(ob)
                ||      !ob->is_character()
                ||      ob==me )
                        return notify_fail("ob error!\n");
*/
        if( !(int)(block_time) || block_time < 0 )
                block_time = 0;
        if( block_time > 1440 ) //一天
                return notify_fail("既然如此，不如直接purge了呢。:) \n");

        message_vision( HIW "\n$N一个大脚把$n给踢了出去\n\n" NOR, me,ob);
        seteuid(ROOT_UID);
        if( block_time )
        {
                cur_time = time();
                ob->set("block_login",cur_time+block_time*60);
        }
        log_file("kickout_player",sprintf("%s(%s) kickouts %s(%s) on %s and deny
s his relogin for %d minutes.\n",
                me->name(1), geteuid(me), ob->name(1), geteuid(ob),ctime(time())
,block_time ) );
//        ob->save_autoload();
//        ob->save();
        destruct(ob);
        
        seteuid(getuid());
        return 1;
}
int help(object me)
{
write(@HELP
指令格式 : kickout <某人> [for <时间>] (时间的单位为分)

大概的时间速查：
24小时 = 1440                                                                  
三天   = 4320
一周   = 10080
封更长的时间可能容易造成难于处理的情况，因此限制为一周以内。

HELP
    );
    return 1;
}                                                                              
