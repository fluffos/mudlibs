// quit.c

#include <command.h>
#include <config.h>

inherit F_DBASE;
inherit F_CLEAN_UP;

void create() 
{
	seteuid(getuid());
	set("name", "离线指令");
	set("id", "quit");
	set("channel_id", "离线");
}

int main(object me, string arg)
{
	int i;
	int doing;
	object *inv, link_ob;

	if (LOGIN_D->get_madlock()) 
		return notify_fail("时空已经封闭，没有人能够退出这个时空了。\n");

	if (me->is_busy() && ! me->query("doing"))
		return notify_fail("你现在正忙着做其他事，不能退出游戏！\n");

	if (me->query_condition("killer"))
		return notify_fail("你现在正在被通缉，不能正常退出游戏！\n");

	if (me->is_fighting())
		return notify_fail("你现在正在打架，怎么能说走就走？\n");

	if (me->query_competitor())
		return notify_fail("好家伙，你正在和人比武，怎么能开溜？\n");

	if (me->dps_count() > 0)
		return notify_fail("好家伙，你打晕了别人就想开溜？\n");

//	if (me->over_encumbranced())
//		return notify_fail("你身上背的东西太多了，无法离开这个世界。\n");

	if (me->run_override("quit"))
		return 1;

	link_ob = me->query_temp("link_ob");

	if (objectp(link_ob))
	{
		// Are we possessing in others body ?
		if (link_ob->is_character())
		{
			write("你的魂魄回到" + link_ob->name(1) + "的身上。\n");
			exec(link_ob, me);
			link_ob->setup();
			link_ob->write_prompt();
			return 1;
		}

		if (link_ob->query_temp("ip_number"))
		{
			link_ob->set("last_on", time());
			link_ob->set("last_from",
				     link_ob->query_temp("ip_number"));
			link_ob->set("registered",
				     me->query("registered"));
			link_ob->save();
		}
		destruct(link_ob);
	}

	if (me->query("doing")||(environment(me)&&environment(me)->query("close_room")||me->query("guaji")||me->query_temp("pending/afk")))
	{
		if (! interactive(me))
			return 1;

		write("你暂时离线，人物不退出...\n");
		message("vision", me->name() + "离线了。\n",environment(me), ({ me }));
		me->save();
		link_ob = new(LOGIN_OB);
		exec(link_ob, me);
		destruct(link_ob);
		return 1;
	}

#if INSTALL_EXAMINE
	EXAMINE_D->examine_player(me);
#endif

	me->log_command("quit");
	me->force_me("unset sign1");
	me->force_me("team dismiss");
	write("欢迎下次再来！\n");
	if (environment(me))
	{
		if(environment(me)->query("out_room"))
		{
			environment(me)->no_die(me);
			me->move(environment(me)->query("out_room"));
		}
		message("vision", me->name() + "离开游戏。\n",environment(me), ({ me }));
	}

	CHANNEL_D->do_channel(this_object(), "sys",me->name() + "[" + me->query("id") + "]离开游戏了。");


	log_file("stat", sprintf("%-8s %-10s %-18s %-18s %-15s.\n",
				 me->name(1), me->query("id"),
				 ctime(me->query_temp("logon_time")),
				 ctime(time()),
				 interactive(me) ? query_ip_number(me) : "unknow"));

	me->save();
	me->set_magic_move();
	me->end_log();
	destruct(me);
	return 1;
}

int force_quit(object me)
{
	if (previous_object() != me ||
	    ! playerp(me))
		return notify_fail("你不能摧毁这个对象。\n");

	seteuid(getuid());
	me->save();
	if (environment(me) != find_object(VOID_OB))
		me->move(VOID_OB, 1);
	destruct(me);
	return 1;
}

int help(object me)
{
	write(@HELP
指令格式 : quit | exit

当你(你)想暂时离开时, 可利用此一指令。
HELP );
    return 1;
}

