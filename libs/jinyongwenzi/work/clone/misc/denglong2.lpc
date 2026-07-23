// item: denglong.c
// by snowman@SJ , 01/05/1999.
#include <ansi.h>
inherit FIRE_ITEM;
void create()
{
        set_name(HIR"大花灯笼"NOR, ({"dahua denglong", "dahua" "denglong", "light"}));
        set_weight(1400);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "这是一盏纸敷的大花灯笼，到了黑暗的地方就用(light)得着了。\n");
                set("unit", "盏");
                set("value", 1500);
                set("light/time", 360);
        }
        setup();
}


