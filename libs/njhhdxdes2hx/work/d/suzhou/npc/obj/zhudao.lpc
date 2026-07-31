//OBJECT:/d/suzhou/npc/obj/zhudao.c 
//by dwolf
//9711.5
        
#include <ansi.h>
#include <weapon.h>
inherit BLADE;

void create()
{
	set_name(RED"竹刀"NOR, ({ "zhu dao", "dao" }));
	set_weight(7000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "柄");
		set("long","这是一柄竹刀，镖局弟子的练习武器。\n");
		set("value", 10);
		set("material", "wood");
		set("wield_msg", "$N「唰」的一声抽出一柄$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n插回刀鞘。\n");
	}
	init_blade(2);
	setup();
}
