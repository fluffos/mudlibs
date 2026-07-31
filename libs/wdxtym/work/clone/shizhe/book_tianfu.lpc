// jinsha.c

#include <ansi.h>
inherit COMBINED_ITEM;
string query_autoload() { return query_amount() + ""; }

void autoload(string param)
{
	int amt;

	if (sscanf(param, "%d", amt) == 1)
		set_amount(amt);
}

void setup()
{
	set_amount(1);
	::setup();
}

void create()
{
	set_name(HIM "天赋技能书" NOR, ({ "tianfu jineng shu" }));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "用来重置天赋技能的道具，有几率获得两个天赋技能和三个天赋技能。\n");
		set("unit", "本");
		set("base_unit", "本");
		set("base_value", 500);
		set("yuanbao", 20);
        set("no_sell", 1);
		set("only_do_effect", 1);
		set("base_weight", 1);
	}
	setup();
}

int do_effect(object me)
{
	if(me->query("combat_exp", 1) < 2) 
                return notify_fail("你没有实战基础，无法使用" + name() + "！\n");

	message_vision(CYN "$N" CYN "使用了一"+query("unit") + name() + CYN "，感觉获得了新生一般。"NOR"\n", me);

	UPDATE_D->born_player(me);
	add_amount(-1);

	return 1;
}
