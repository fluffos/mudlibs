// stone.c
#include <ansi.h>

inherit ITEM;

void create()
{
        set_name("石块", ({ "stone" }) );
        set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "块");
                set("long", "一块普通的石头。\n");
                set("value", 1);
                set("material", "stone");
        }
        setup();
}
