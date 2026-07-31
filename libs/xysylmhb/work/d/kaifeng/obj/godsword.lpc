// godsword.c LOTS 1998.10.16

#include <weapon.h>
inherit SWORD;

void create()
{
	set_name("尚方宝剑", ({ "godsword", "jian", "sword" }));
	set_weight(100);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "柄");
		set("long", "这是一把尚方宝剑,它可以先斩后奏.\n");
		set("value", 50000);
		set("material", "gold");
		set("wield_msg", "$N「唰」的一声抽出一柄$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n插回剑鞘。\n");
	}
	init_sword(400);
	set("no_drop",1);
	set("no_get",1);
        set("no_steal",1);
        setup();

}
void owner_is_killed() { destruct(this_object()); }
