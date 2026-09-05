// 包袱,Zine 4/7/2011

inherit ITEM;
#include <ansi.h>
void create()
{
        set_name("包袱", ({"bao fu", "bao", "bag"}));
        set_weight(3500);
        set_max_encumbrance(30000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "个");
                set("long", "这是一个粗布做的大包袱，里面可以装很多东西。\n");
                set("no_store",1);
                set("no_pawn", 1);
                set("value", 1000);
        }
		
}

