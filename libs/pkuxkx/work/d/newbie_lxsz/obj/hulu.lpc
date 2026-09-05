// D:\xkx\d\liuxiu-shanzhuang\obj\hulu.c葫芦
//labaz 2012/10/20

#include <ansi.h>

inherit ITEM;
inherit F_LIQUID;

void create()
{
	set_name(YEL"葫芦"NOR, ({"hu lu","hulu",}));
	set_weight(700);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "这是一个葫芦，看来可以用来盛溪水"+HBBLU"(fill hulu)"NOR+"和饮用"+HBBLU"(drink hulu)"NOR+"。\n你仔细一看，葫芦底部还刻着“"+HIY"柳秀山庄"NOR+"”四个字。\n");
		set("unit", "个");
		set("value", 90);
		set("max_liquid", 15);
		set("no_drop","这葫芦还有用，你不能丢弃掉。\n");
	}

	// because a container can contain different liquid
	// we set it to contain water at the beginning
	set("liquid", ([
		"type": "water",
		"name": "清水",
		"remaining": 0,
		"drunk_supply": 6,
	]));
}



