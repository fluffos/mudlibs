// yugan.c  渔竿
//Jay 4/8/96

#include <ansi.h>

inherit ITEM;

void create()
{
        set_name("渔竿", ({"yu gan", "gan"}));
        set_weight(800);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "这是一根你自制的渔竿，可以用来钓鱼。\n");
                set("unit", "根");
                set("material", "clud");
        }
        setup();
}

