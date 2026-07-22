#include <ansi.h>

inherit ITEM;
void create()
{
        set_name(HIW "纸钱" NOR, ({ "ghost money", "money" }) );
        set_weight(50);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "串");
                set("long", "一串纸钱\n");
                set("value", 1000);
        }
}



