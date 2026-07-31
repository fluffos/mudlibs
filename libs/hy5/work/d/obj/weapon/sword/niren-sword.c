
#include <ansi.h>
#include <weapon.h>
inherit SWORD;
inherit F_UNIQUE;

void create()
{
        set_name( HBWHT "逆刃刀" NOR , ({ "niren sword", "sword" }));
	set_weight(10);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "柄");
		set("long",  HIG "这是一把逆刃刀，此剑似乎有着个秘密。\n" NOR );
		set("material", "steel");
                set("unique", 1);
                set("treasure", 1);
		set("wield_msg", "$N「唰」的一声抽出一柄$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n插回剑鞘。\n");
                set("no_drop", "这样东西不能离开你。\n");
                set("no_give", "这样东西不能给人。\n");
                set("no_get", "这样东西捡不起来。\n");
                set("no_put", "这样东西不能乱放。\n");
	}
	init_sword(250);
	setup();
}
