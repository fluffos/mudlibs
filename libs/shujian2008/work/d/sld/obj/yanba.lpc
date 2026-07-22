//Yanqi 08/11/2k
#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(HIY"盐巴"NOR, ({ "yan ba", "yan", "ba" }) );
        set_weight(10000);
        set("unit", "包");
        if (clonep())
                set_default_object(__FILE__);
        else {
        set("long", "这是一包从海路贩运来的盐巴。\n");
        set("no_give",1);
	}
	setup();
}
