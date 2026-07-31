// Room: /u/xdd/gumu/gmbedroom.c
// Modify By River 98/08/29
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short",HIC"休息室"NOR);
	set("long", @LONG
这里是古墓弟子的休息室，房中空空洞洞，一如古墓无异。一块长条青石
作床，床上铺了张草席，一幅白布当作薄被，此外除了一根人高的绳索横过室
中，别无他物。
LONG        );

	set("exits", ([
		"north" : __DIR__"gmht",
	]));

	set("objects", ([
		__DIR__"obj/bed" : 1,
	]));

	set("sleep_room", 1);
	set("no_fight", 1);

	create_door("north", "石门", "south", DOOR_CLOSED);
	setup();
}

void init()
{
	add_action("do_zuo", "zuo");
	add_action("do_liao", "liao");
	add_action("do_liaodu", "liaodu");
}

int do_zuo(string arg)
{
	mapping fam;
	object me = this_player();
	if (me->is_busy() || me->is_fighting())
		return notify_fail("你正忙着哪！\n");
	if (!(fam = me->query("family")) || fam["family_name"] != "古墓派")
		return notify_fail("你不是古墓传人，如何能领悟古墓武功？\n");
	if (arg == "bed"){
		if (me->query("jing") < 20 )
			return notify_fail("你的精太少，无法抵御严寒。\n");
		if (me->query("potential", 1) < 1)
			return notify_fail("你的潜能没了，不能再继续修习了\n");
		write(HIC"你长吸一口气，往寒玉床上盘腿而坐。\n"NOR);
		if (me->query_skill("force", 1) < 10) {
			message_vision(HIR"$N还未坐稳,就怪叫一声, 从床上跳了下来，想必是受不了千年古玉之寒气。\n"NOR, me);
			return 1;
		}
		if (me->query_skill("yunu-xinjing", 1) > 50)
			return notify_fail("你的玉女心经已有相当火厚,寒玉床不能再助你修习内功了。\n");
		me->receive_damage("jing", 150 / (int)me->query("int"));
		me->add("potential", -1);
		write("借着寒玉床之天然神效，真气自然流动，你开始修习内功心法，当真灵验无比。 \n"NOR);
		me->improve_skill("yunu-xinjing", me->query_int() + random(me->query_int() * 5 / 6));
		return 1;
	}
	return notify_fail("你要坐在哪里? \n");
}

int do_liao(string arg)
{
	mapping fam;
	object me = this_player();

	if (me->is_fighting() || me->is_busy())
		return notify_fail("你正忙着呢。\n");

	if (!(fam = me->query("family")) || fam["family_name"] != "古墓派")
		return notify_fail("你不是古墓传人，如何能使用古墓的寒玉床？\n");

	if ((int)me->query("eff_qi") == (int)me->query("max_qi"))
		return notify_fail("你现在身上没有受到任何伤害！\n");

	if (arg == "bed"){
		message_vision(HIC"$N爬上寒玉床, 要借千年寒玉疗伤. \n"NOR, me);
		if ((int)me->query_condition("marks_bed") > 0 ){
			me->set_temp("last_damage_from", "无法抵抗寒玉床之奇寒而");
			me->receive_wound("qi", 50);
			message_vision(HIR"$N突然只觉一阵奇寒侵入身体，想是两次疗伤时隔太短，身子尚未复原之故。\n"NOR, me);
			me->unconcious();
			return 1;
		}
		if (me->query_skill("yunu-xinjing", 1) < 40)
			return notify_fail("寒玉床疗伤需以纯熟的玉女心经内功相辅, 否则无法外疗. \n");

		me->set("eff_qi", me->query("max_qi"));
		tell_object(me,HIW"\n不一会儿，你只觉得神采奕奕，伤口已然痊愈。\n"NOR);
		me->add_condition("marks_bed", 20);
		return 1;
	}
	return notify_fail("你要在哪疗伤? \n");
}

int do_liaodu(string arg)
{
	mapping fam;
	object me = this_player();
	
	if (me->is_fighting() || me->is_busy())
		return notify_fail("你正忙着呢。\n");

	if (!(fam = me->query("family")) || fam["family_name"] != "古墓派")
		return notify_fail("你不是古墓传人，如何能使用古墓的寒玉床？\n");
	
	if (!me->query_conditions_by_type("poison"))
		return notify_fail("你好象没有中毒吧？\n");

	if( arg == "bed"){
		message_vision(HIC"$N爬上寒玉床, 要借千年寒玉疗毒。\n"NOR, me);
		if ((int)me->query_condition("marks_bed") > 0 ){
			me->set_temp("last_damage_from", "无法抵抗寒玉床之奇寒而");
			me->receive_wound("qi", 50);
			message_vision(HIR"$N突然只觉一阵奇寒侵入身体，想是两次疗伤时隔太短，身子尚未复原之故。\n"NOR, me);
			me->unconcious();
			return 1;
		}
		if (me->query_skill("yunu-xinjing", 1) < 40)
			return notify_fail("寒玉床疗毒需以纯熟的玉女心经内功相辅, 否则无法外疗. \n");

		me->set("eff_jing", me->query("max_jing"));
		tell_object(me,HIW"\n不一会儿，你只觉得出了一身大汗，毒伤已然减轻不少。\n"NOR);
                me->clear_conditions_by_type("poison");
		me->add_condition("marks_bed", 20);
		return 1;
	}
	return notify_fail("你要在哪疗毒? \n");
}
