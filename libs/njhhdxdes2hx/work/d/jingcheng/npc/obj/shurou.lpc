// shurou.c 
//by dwolf
#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name(YEL"老鼠肉"NOR, ({ "shu rou", "rou" }) );
	set_weight(350);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", RED"一头血淋淋的死老鼠。据说老鼠肉好吃喔。\n"NOR);
		set("unit", "头");
		set("value", 80);
		set("food_remaining", 4);
		set("food_supply", 10);
	}
	setup();
}

