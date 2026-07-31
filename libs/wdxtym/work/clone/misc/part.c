// part.c 身体某部位

#include <ansi.h>

inherit ITEM;
inherit F_FOOD;
inherit F_CUTABLE;
inherit F_SILENTDEST;

void eat_effect();
int is_body_part() { return 1; }

void create()
{
	set_name(RED "残肢" NOR, ({ "body part"}));
	set_weight(500);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "块");
		set("value", 0);
		set("food_supply", 1);
		//set("food_remaining", 4);
	}
}

string long() { return ::long() + extra_desc(); }

void eat_effect()
{
	object me;

	me = this_player();
	me->add("combat/eatman", 1);
	if (me->query("shen") > -1000)
		me->set("shen", -1000);
}
