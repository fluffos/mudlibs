//OBJECT:/d/suzhou/npc/obj/zhujian.c 
//by dwolf
//97.11.5

#include <ansi.h>
#include <weapon.h>
inherit SWORD;

void create()
{
	set_name(MAG"竹剑"NOR, ({ "zhu jian", "jian" }));
	set_weight(5000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "柄");
		set("long", "这是一柄普通的竹剑,供弟子练习用。\n");
		set("value", 10);
		set("material", "bamboo");
		set("wield_msg", "$N「唰」的一声抽出一柄$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n插回剑鞘。\n");
	}
	init_sword(2);
	setup();
}
