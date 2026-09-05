#include <ansi.h>
inherit ITEM;
void create()
{
        set_name("装备部件"+NOR, ({"zhuangbei bujian", "bujian","parts"}));
        set_weight(600);
        set("long", "这是一堆装备的部件。\n");
        set("unit", "堆");
		set("value",0);
		set("no_store",1);
		set("no_sell",1);
		set("no_pawn",1);
		set("no_sell_in_playershop",1);
		setup();
}

int is_parts()
{
	return 1;
}