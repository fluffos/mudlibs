
#include <ansi.h>
inherit ITEM;
void create()
{
        set_name( "便条", ({ "bian tiao", "tiao", "biantiao" }) );
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "张");
                set("long","这是出入郭靖帅府的信物。\n");
                set("value", 0);
                 }
        setup();
}

void init()
{
        call_out("dest", 2400);
}

void dest()
{
        destruct(this_object());
}
