// dumpling.c 包子
#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

mapping *data=({
(["name":"糌粑",	"id":"bread",	"mw":-1,	]),
(["name":"绵羊肉",	"id":"bread",	"mw":-1,	]),
(["name":"耗牛肉",	"id":"bread",	"mw":-1,	]),
(["name":"烤面饼",	"id":"bread",	"mw":-1,	]),				
(["name":"青稞面",	"id":"bread",	"mw":-1,	]),				
(["name":"青稞面",	"id":"bread",	"mw":-1,	]),				
});

void create()
{
	mapping npc;

	npc=data[random(sizeof(data))];
	set_name(npc["name"],({ npc["id"] }));
	set_weight(80);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "一块香喷喷的"+query("name")+"。\n");
		set("unit", "块");
		set("value", 50);
		set("food_remaining", 5);
		set("food_supply", 50);
	}
}
