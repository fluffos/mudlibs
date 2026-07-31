// taoshu.c 

#include <ansi.h>

inherit ITEM;

void create()
{
        set_name("小桃树", ({ "tao shu", "shu" }) );
        set_weight(30000);
        set_max_encumbrance(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "棵");
                set("long", "这是一棵结满果实的小桃树。\n");
                set("value", 1000);
                set("material", "wood");
                set("no_get",1);
                set("no_drop",1);
        }
        setup();
}

