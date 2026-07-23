// reboot.c

#include <login.h>
#include <ansi.h>
#include <net/daemons.h>

inherit F_DBASE;

int main(object me, string arg)
{
	string wiz_status;
	object npc;

	if( me != this_player(1) ) return 0;
	
	wiz_status = SECURITY_D->get_status(me);
	if( wiz_status != "(admin)" && wiz_status != "(arch)" && wiz_status != "(wizard)" )
		return notify_fail("只有 (arch) 以上的巫师才能重新启动" + MUD_NAME + "\n");

        message("system",
                HIW     "\t\t【海洋II】将在五分钟后重新启动！请尽快存档(save)！\n\n" NOR,
                users() );
        call_out("countdown", 60, 5);

	return 1;
}

private void countdown(int min)
{
	min--;
	if( min ) {
		message("system",
                        HIR     "\t\t【海洋II】将在" + chinese_number(min) + "分钟后重新启动！请尽快存档(save)！\n\n"NOR,
			users() );
		call_out("countdown", 60, min);
	} else {
		message("system",
                        HIW "\t\t【海洋II】重新启动。。。请稍候再登陆！\n"NOR,
			users() );
		call_out("do_shutdown", 3+random(8));
	}
}

private void do_shutdown()
{
	int i,j;
	object *ob, link_ob;
	string id;
	j=0;
	seteuid(getuid());
/*	set("channel_id", "存盘精灵"); // 这段存盘的代码看上去就不大顺眼，肯定写的不太好，但太晚了我就不改它了
	ob=users();
	i=sizeof(ob);
	for( i=0;i<sizeof(ob);i++) {
	id = (string) ob[i]->query("id");
	if (!id) continue;
	if(!environment(ob[i]) )        continue;
	if( !objectp(link_ob = ob[i]->query_temp("link_ob")) ) continue;
	if( (int)link_ob->save() && (int)ob[i]->save() ) j = 1;
	else CHANNEL_D->do_channel( this_object(), "sys", ob[i]->query("name")+"档案自动存盘失败。");
	}
	CHANNEL_D->do_channel( this_object(), "sys", "档案自动存盘成功。");*/
	shutdown(0);
	return;
}

int help (object me)
{
        write(@HELP
指令格式: reboot
 
重新起动游戏, 系统会开始倒数计时, 五分钟後重新起动。
 
HELP
);
        return 1;
}
 
