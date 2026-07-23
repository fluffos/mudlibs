// /clone/drug/chantui.c

#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(HIB"蝉蜕"NOR, ({"chan tui"}));
        set_weight(200);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "支");
                set("value", 3500);
                set("medicine", "drug");
		set("make/drug", 1);
        }
	setup();
}
