// Room: /d/dzd/caocong.c

#include <ansi.h>
#define OUT_DOWN __DIR__"caodi2" 
inherit __DIR__"dzd_room";

int do_kill(string arg);
int do_zuan(string arg);
string look_out();

void create()
{
	set("short","草丛");
	set("long",@LONG
大片的荒草掩没了你的身影，从草丛的缝隙(out)可以完全看到蜿蜒于草地中小路上的动静。
一阵微风吹过，你只觉有隐隐的腥气飘来。手碰到一个硬硬的东西，一看差点惊呼出来：原
来是一根人的腿骨。
LONG
	);
	set("outdoors","大智岛");
	set("item_desc",([
		"out" : (: look_out :),
	]));
	setup();
}

void init()
{
	object room,*ob;
	object me = this_player();
	object here = this_object();
	int i;
	
	::init();
	add_action("do_kill","kill");
	add_action("do_kill","ansuan");
	add_action("do_kill","touxi");
	add_action("do_zuan","zuan");

	if(userp(me) && !wizardp(me)) {
		if(!room=find_object(OUT_DOWN))
			room=load_object(OUT_DOWN)	;
		ob = all_inventory(here);
		for(i=0;i < sizeof(ob);i++) {
			if(userp(ob[i]) && !wizardp(ob[i]) && ob[i] != me) {
				tell_object(me,HIW"你突然发现"+ob[i]->name()+"也在草丛中,不禁大吃一惊！\n"NOR);
				message_vision(HIW"$n看到$N发现了$n，大吼一声，向$N扑了过来!\n"NOR,me,ob[i]);
				me->kill_ob(ob[i]);
				ob[i]->kill_ob(me);
				return;
			}
		}
	}
	"/cmds/std/look.c"->look_room(me,here);
}

int do_zuan(string arg)
{
	object me = this_player();
	if(me->is_busy() || me->is_fighting())
		return notify_fail("你正忙着呢。\n");
	if(!arg || arg != "out")
		return notify_fail("你要钻到哪儿？\n");
	message_vision(HIY"$N双手一撑地，身子已箭一般的窜了出去。\n"NOR,me);
	me->move(OUT_DOWN);
	message("vision",HIY""+me->name()+"从草丛中钻了出来。\n"NOR,OUT_DOWN,me);
	return 1;
}

string look_out()
{
	object room;
	if(!room = find_object(OUT_DOWN))
		room = load_object(OUT_DOWN);
	"/cmds/std/look.c"->look_room(this_player(),room);
	return """";
}

int do_kill(string arg)
{
	object ob,room;
	object me = this_player();
	if(me->is_busy() || me->is_fighting())
		return notify_fail("你正忙着呢。\n");
	if(!arg || !(room = find_object(OUT_DOWN)))
		return notify_fail("你要偷袭谁？\n");
	if(!(ob = present(arg,room)))
		return notify_fail("你要偷袭谁？\n");
	if(!ob->is_character() || ob->is_corpse())
		return notify_fail("看清楚一点！\n");
	if(!userp(ob))
		return notify_fail("偷袭npc? ……\n");
	if(wiz_level(me) < wiz_level(ob))
		return notify_fail("你不能偷袭巫师等级比你高的对手。\n");
	message_vision(HIW"$N从草丛中一跃而出，气势如虹，直取"+ob->name()+"！\n"NOR,me);
	message_vision(HIW"忽然一股杀气袭来，$N抬头望去，只见一个人影挟着剑气飞掠而出！！\n"NOR,ob);
	me->move(room);
	if(!random(10)) {
		message_vision(HIY"却见$N早有准备，身子轻轻一侧让过来势，趁机对$n发动攻击。\n"NOR,ob,me);
		me->start_busy(3);
	} else if(!random(5)) {
			message_vision(HIW"$N大吃一惊，匆忙将身子向后一仰，$n堪堪擦着$N的鼻尖掠过！\n"NOR,ob,me);
		} else {
			message_vision(HIR"$N只觉一股凌厉刺骨的杀气袭来，不及回避，已被$n一击而中！！\n"NOR,ob,me);
			ob->start_busy(3);
			}
	me->kill_ob(ob);
	if(!userp(ob))
		ob->kill_ob(me);
	else {	
		ob->fight_ob(me);
		if(userp(me))
			tell_object(ob,HIR"如果你要和" + me->name() + "性命相搏，请你也对这个人下一次kill指令。\n"NOR);
		}

	return 1;	 
}
