// wineskin.c  酒袋
#include <ansi.h>
inherit ITEM;
inherit F_LIQUID;

mapping *data=({
(["name":"青稞酒",	"id":"drink",	"mw":-1,	]),
(["name":"酥油",	"id":"drink",	"mw":-1,	]),
(["name":"酸奶",	"id":"drink",	"mw":-1,	]),
(["name":"奶渣",	"id":"drink",	"mw":-1,	]),				
(["name":"酥油茶",	"id":"drink",	"mw":-1,	]),				
(["name":"清水",	"id":"drink",	"mw":-1,	]),				
(["name":"牛皮囊",	"id":"drink",	"mw":-1,	]),				

});

void create()
{
	mapping npc;

	npc=data[random(sizeof(data))];
	set_name(npc["name"],({ npc["id"] }));
	set_weight(700);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "一个用来装"+query("name")+"的大碗，大概装得八、九升的酒。\n");
		set("unit", "碗");
		set("value", 100);
		set("max_liquid", 15);
	}

	// because a container can contain different liquid
	// we set it to contain wine at the beginning
	set("liquid", ([
		"type": "alcohol",
		"name": "米酒",
		"remaining": 25,
		"drunk_apply": 3,
	]));
}
