//By Zine 各地美食

inherit ITEM;
inherit F_FOOD;
#include <ansi.h>

void create()
{
	set_name(WHT"君山银针"NOR, ({"junshan yinzhen","yinzhen"}));
	set_weight(700);
	
            set("long", "这是一盘君山银针，让人垂涎欲滴。\n");
            set("unit", "盘");
            set("value", 170);
            set("food_remaining", 4);
            set("food_supply", 50);
            set("notfresh",0);
    
    setup();
    remove_call_out("gofresh");
    call_out("gofresh",45);
}

int gofresh()
{
    this_object()->set("notfresh",1);
    return 1;
}

