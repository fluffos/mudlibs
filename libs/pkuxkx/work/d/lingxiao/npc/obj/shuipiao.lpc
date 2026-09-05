//shuipiao.c 

#include <ansi.h>
#include <weapon.h>

inherit HAMMER;

void create()
{
	set_name("水瓢", ({ "shui piao", "piao", "hammer" }));
	set_weight(500);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", "这是一个用老葫芦劈开做成的瓢，普通百姓的日常务农用品。\n");
		set("value", 50);
		set("material", "steel");
		set("wield_msg", "$N拿出一个$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n插在腰上。\n");
	}
	init_hammer(4);
	setup();
}

void init()
{
	add_action("do_yao", "yao");
}

int do_yao(string arg)
{
	object me = this_player();
	object room = environment(me);

	if(arg != "雪")
		return notify_fail("你想舀什么？\n");
	if(me->query_temp("lingxiao/fantang_job") != "取水")
		return notify_fail("没人让你来取水罢？\n");
	if(me->query_temp("lingxiao/fantang_ok"))
		return notify_fail("桌椅已经整理好了，快去覆命罢。\n");
	if(me->is_busy())
		return notify_fail("你正忙着呢。\n");
	if(me->is_fighting())
		return notify_fail("先把眼前的敌人解决掉吧。\n");

	if(!room->query("outdoors"))
		return notify_fail("屋里哪来的雪？\n");
	if(room->query("snow_got"))
		return notify_fail("这里的雪已经被踩过了，不能舀来化水。\n");
	if(room->query("outdoors") != "凌霄城")
		return notify_fail("这里没有干净的雪，不能舀来化水，还是快回到雪山上吧。\n");
	message_vision(HIW"$N选了一片干净的积雪，从中舀了一瓢。\n"NOR, me);
	set("snow_got", 1);
	room->set("snow_got", 1);
	set("long", "这是一个用老葫芦劈开做成的瓢，里面满满装了雪。\n");
	return 1;
}