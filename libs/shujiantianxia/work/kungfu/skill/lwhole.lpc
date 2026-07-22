// add wd quest 剑诀 by Lane@SJ 2005.7.11
// Room: lwhole.c

#include <ansi.h>;

inherit ROOM;

string wall(object me);

void create()
{
	set("short", HIB"石壁岩洞"NOR);
	set("long", @LONG
这是一天然石洞，不是很深，当太阳升起时能直射全洞。象是有人在此住
过，正面有一石床，左边放有一些石碗，右面的石壁(wall)十分平整。
LONG
	);

	set("exits", ([
		"out" : __DIR__"wanniansong",
	]));    

	set("item_desc", ([
		"wall" : (: wall :)
	]));

	setup();
}

void init()
{
	add_action("do_study", "study");
}

int do_study(string arg)
{
	object me;
	me = this_player();

	if( !living(me) ) return 0;

	if( (int)me->query_skill("literate", 1) < 10 )
		return notify_fail("你字也不认识几个,如何研读无上心法。\n");

	if( me->is_busy() || me->is_fighting() )
		return notify_fail("你正忙着呢。\n");
         
	if( arg == "wall" ) {
		if( me->query_temp("wudang/jianjue") ) {
			message_vision("$N慢慢的琢磨着石壁上的小字。\n", me);
			tell_object(me, HIW"\t\t老道年已过百，想我武当能人不多，虽有善心，终不得其用。晚年闭关新创两门绝技\n"+
			"\t「"RED"太极拳"HIW"」和「"RED"太极剑"HIW"」，望能够留传后世，造福万民，来此昔日故地，留字以待，了却心愿 ...

			"HIY"冲虚自然，以慢打快，以静制动，後发制人。
			"HIG"无极而生，阴阳之母。阴阳相济，方为懂劲。
			"RED"纯以意行，形神合一，圆转贯串，滔滔不绝。
			"HIC"气之所至，意之所动，内外双修，无我无招。

				\t\t\t"WHT"张三丰\n"NOR);
		write(HIW"你静心研习石壁上的小子，大有感触，对「太极」的领会又更深入了一个层次。\n"NOR);
		tell_object(me, BMAG"恭喜你，你于" + NATURE_D->game_time() + "加深对「太极」的理解。\n"NOR);
		me->delete_temp("wudang/jianjue");
		me->set("wudang/jianjue", 1);
		return 1;
		}

		if( (int)me->query("jing") < 30 )
			return notify_fail("你太累了，还是歇会再研读吧！\n");
		if( (int)me->query_skill("yinyun-ziqi", 1) >= 41 )
			return notify_fail("你对着石壁研习一会，只觉所述早已尽藏心胸。\n");

		message_vision("$N开始面壁琢磨。\n", me);
		write("你静心研习石壁上的秘籍，对内功心法有些领悟。\n");
		me->receive_damage("jing", 40);
		me->receive_damage("jingli", 15);
		me->improve_skill("yinyun-ziqi", (int)me->query("int"));
		return 1;
	}
	return notify_fail("什么？\n");
}

string wall(object me)
{
	int exp, time;

	if( me->query("family/family_name") != "武当派" )
		return  HIW" ......彼之力方碍我之皮毛，我之意已入彼骨里。双手支撑，一气贯通。\n"+
			"左重则左虚，而右已去，右重则右虚，而左已去......\n"NOR;

	if( me->query_skill("yinyun-ziqi", 1) < 450 )
		return  HIW" ......彼之力方碍我之皮毛，我之意已入彼骨里。双手支撑，一气贯通。\n"+
			"左重则左虚，而右已去，右重则右虚，而左已去......\n"NOR;

	if( me->query_skill("taiji-jian", 1) < 450 )
		return  HIW" ......彼之力方碍我之皮毛，我之意已入彼骨里。双手支撑，一气贯通。\n"+
			"左重则左虚，而右已去，右重则右虚，而左已去......\n"NOR;

	if( me->query("wudang/jianjue") )
		return  HIW" ......彼之力方碍我之皮毛，我之意已入彼骨里。双手支撑，一气贯通。\n"+
			"左重则左虚，而右已去，右重则右虚，而左已去......\n"+
			"\t\t\t石壁顶部的几句太极口诀依稀可见 ...\n"NOR;

	time = time() - me->query("wd_jianjue/time");
	if( me->query("wd_jianjue/time") && time < 86400 && !wizardp(me) )
		return  HIW" ......彼之力方碍我之皮毛，我之意已入彼骨里。双手支撑，一气贯通。\n"+
			"左重则左虚，而右已去，右重则右虚，而左已去......\n"+
			"\t\t\t你近来已经看了好几遍了，早已熟记于心 ...\n"NOR;

	exp = me->query("combat_exp") - me->query("wd_jianjue/exp");
	if( me->query("wd_jianjue/exp") && exp < 100000 && !wizardp(me) )
		return  HIW" ......彼之力方碍我之皮毛，我之意已入彼骨里。双手支撑，一气贯通。\n"+
			"左重则左虚，而右已去，右重则右虚，而左已去......\n"+
			"\t\t\t你近来已经看了好几遍了，早已熟记于心 ...\n"NOR;

	me->set("wd_jianjue/time", time());
	me->set("wd_jianjue/exp", me->query("combat_exp"));
	message_vision(HIY"$N仔细的打量着石壁，其实这几句口诀你早已牢记于心.........\n"NOR, me);

	if( random(2) && random(me->query_int()) > 15 && random(me->query("kar")) > 15 ) {
		message_vision(HIR"$N突然发现石壁顶部似乎刻有小子，$N自言自语：“会是什么呢？”\n"NOR, me);
		me->set_temp("wudang/jianjue", 1);
	} else {
		message_vision(HIW"$N环顾四周结果什么也没发现 ...\n"NOR, me);
	}
	me->set("wd_jianjue/time", time());
	me->set("wd_jianjue/exp", me->query("combat_exp"));
	return  HIW" ......彼之力方碍我之皮毛，我之意已入彼骨里。双手支撑，一气贯通。\n"+
		"左重则左虚，而右已去，右重则右虚，而左已去......\n"NOR;

}
