// guoba.c 锅巴肉片

#include <ansi.h>

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name(HIY "锅巴肉片" NOR, ({"rou pian", "rou"}));
	set_weight(200);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "“锅巴肉片”风味独特。
上此菜时，侍应一手端盛有金黄色炸好的锅巴菜盘置席上， 
一手持热汁汤碗，迅速将热汁浇在锅巴上，发出响声，妙趣横生。\n");
		set("unit", "盘");
		set("value", 120);
		set("food_remaining", 3);
		set("food_supply", 50);
	}
}