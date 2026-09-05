// shutdown.c

#include <net/daemons.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	string wiz_status;
	
	if( me != this_player(1) ) return 0;
	
	wiz_status = SECURITY_D->get_status(me);
	if( wiz_status != "(admin)" && wiz_status != "(arch)" )
		return notify_fail("只有 (arch) 以上的巫师才能重新启动" + MUD_NAME + "\n");

	write("你确定要重启系统吗？(y/N)");
	input_to("get_confirm",0);
	return 1;
}

int get_confirm(string answer)
{
	object *user, link_ob;
	int i;

	if(answer != "y" && answer != "Y")
	{
		write("放弃。\n");
		return 1;
	}

	message( "system", "游戏重新启动，请稍候一分钟再 login 。\n", users() );
/*
	user = users();
	for(i=0; i<sizeof(user); i++) {
		if( !environment(user[i]) ) continue;
		user[i]->save();
		link_ob = user[i]->query_temp("link_ob");
		if( objectp(link_ob) ) link_ob->save();
	}
*/
	if( find_object(DNS_MASTER) ) DNS_MASTER->send_shutdown();

	shutdown(0);
	return 1;
}
int help (object me)
{
        write(@HELP
指令格式: shutdown
 
马上重新起动游戏。
 
HELP
);
        return 1;
}
 
