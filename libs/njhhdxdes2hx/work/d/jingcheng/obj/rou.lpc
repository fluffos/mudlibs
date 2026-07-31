// dumpling.c 包子  

#include <ansi.h>

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name(RED"老鼠肉"NOR, ({"laoshu rou", "rou","meet"}));
	set_weight(120);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", RED"一块恶心的老鼠肉,散发着阵阵臭气. \n NOR");
		set("unit", "块");
  set("value", 12000)
;
		set("food_remaining",20);
		set("food_supply", 100);
	}
}
