#include <ansi.h>
inherit F_CLEAN_UP;
int main(object me, string arg)
{
	string msg;
        if(!me->query_temp("boss_screen"))
                return notify_fail("你老板什么时候来的？\n");
	me->delete_temp("block_msg/all");
        if(time() - me->query_temp("boss_screen") < 60)
        {
                write("等老板走远点……\n");
                me->set_temp("block_msg/all",1);
                return 1;
        }
	write(CLR);
	write("侠客行告诉你：运气如何？被抓住了吗？哈哈！\n");
        message("channel:chat", HIG"【警铃】" + me->name(1) + "得意洋洋地打开屏幕，看着老板在门外消失：拜拜了您哪。\n"NOR, users());
        me->delete_temp("boss_screen");
	return 1;
}

int help(object me)
{
     write(@HELP
指令格式: bossgone  

这个指令让你(玩家)在老板走后恢复正常侠客行游戏。

有关指令：bosscome
HELP
    );
    return 1;
}
