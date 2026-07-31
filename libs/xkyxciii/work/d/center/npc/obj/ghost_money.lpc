#include <ansi.h>

inherit ITEM;
void create()
{
        set_name(HIW "纸花" NOR, ({ "ghost flower", "flower"}) );
        set_weight(50);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "串");
                set("long", "一串纸花\n");
                set("value", 1000);
        }
}



