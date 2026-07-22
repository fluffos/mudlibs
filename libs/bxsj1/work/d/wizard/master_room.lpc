// 会客室

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"休息室"NOR);
	set("long", @LONG
这里是管理员的休息室，是让管理员用来休息的地方。室内窗明几净，陈设简
单，管理员平常都是在那里休息，墙上有一纸说明(shuoming)。
LONG);

	set("no_fight", 1);
	set("sleep_room", 1);
	set("no_sleep_room", 1);
	set("no_death", 1);
	set("item_desc", ([
		"shuoming" : "在此房间可使用下列命令：\n"+
		"\t1、full：	自己状态全满。\n"+
		"\t2、unchblk：	打开自己所有频道。\n\n",
	]));

	setup();
}

void init()
{
	object me= this_player();

	if ( getuid(me) != "mastera" && !wizardp(me))
		me->move("/d/city/chmiao", 1);
	else {
		me->delete("enter_wuguan");
		me->reincarnate();
		me->set("combat_exp", 300000);
		if ( !me->query("family"))
			me->set("family/family_name", "在线服务");
		add_action("do_full", "full");
		add_action("do_open", "unchblk");
	}
}

int do_full()
{
	object me = this_player();

	me->reincarnate();
	tell_object(me, "你的状态恢复完毕！\n");
	return 1;
}

int do_open()
{
	object me= this_player();

	me->delete("chblk_on");
	me->delete("chblk_rumor");
	me->delete("chblk_chat");
	me->delete("chblk_party");
	me->delete("chblk_sj");
	me->clear_condition();
	tell_object(me, "你的频道被打开了。\n");
	return 1;
}
