// stone.c
// By River 98.10
#include <ansi.h>
inherit ITEM;
void create()
{
        set_name("石块", ({"shi kuai", "shi", "stone"}));
        set_weight(5000);
        if (clonep())
               set_default_object(__FILE__);
        else {
               set("long", "这是一块普普通通的石头。\n");
               set("unit", "块");
        }
        setup();
}
