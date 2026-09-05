#include <ansi.h>
inherit ITEM;
void create()
{
        set_name(HIM"玫瑰"NOR, ({ "rose", "mei gui", "flower" }) );
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "束");
                set("long", "这是一束玫瑰，代表着爱情，也许你可以把它送给你的心上人。\n");
                set("value", 2000);
                set("material", "wood");
             }
       setup();
}

