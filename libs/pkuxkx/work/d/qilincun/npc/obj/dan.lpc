// shen_dan2.c 神丹
// Rewrote by iszt@pkuxkx, 2007-02-12

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(BLK"仙丹"NOR, ({"xian dan", "dan"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "颗");
		set("long", "这是一颗"BLK"仙丹"NOR"，不知道吃下去会有什么效果。\n");
		set("value", 50000);
		set("no_drop", "这东西不能扔。\n");
		set("no_steal", 1);
	}
	setup();
}

void init()
{
	add_action("do_eat", "eat");
}

int do_eat(string arg)
{
	object me = this_player();
	object ob = this_object();
	int pot, kar, spi, shen;

	if (!id(arg))
		return notify_fail("你要吃什么？\n");

	if(!me->query_temp("liquan/find_cuigu"))
	{
		message_vision(HIY"$N吃下一颗不知从哪里来的$n"HIY"，不过如同嚼蜡一般毫无效果。\n"NOR, me, ob);
		destruct(ob);
		return 1;
	}

	pot = me->query("neili");
	if(pot > me->query("max_neili")*2)
		pot = me->query("max_neili")*2;
        pot = random(pot/4);
	kar = random(100) - 98;
        if(kar < 0 || me->query("xiantian/kar/liquan"))
		kar = 0;
        spi = random(41) - 39;
        if(spi < 0 || me->query("xiantian/spi/liquan") >= 4)
		spi = 0;

	message_vision(HIY "$N吃下一颗$n"HIY"，只觉满身轻松，有如成仙一般...\n" NOR, me, ob);
	tell_object(me, HIW"你的潜能增加了"+chinese_number(pot)+"点！\n"NOR);
	me->add("potential", pot);
	me->add("pot/liquan", pot);
	tell_object(me, HIW"你的福缘增加了"+chinese_number(kar)+"点！\n"NOR);
	me->add("kar", kar);
        me->add("xiantian/kar/liquan", kar);
	tell_object(me, HIW"你的灵性增加了"+chinese_number(spi)+"点！\n"NOR);
	me->add("spi", spi);
	me->add("xiantian/spi/liquan", spi);

	destruct(ob);
	return 1;
}
