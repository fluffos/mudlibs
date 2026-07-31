// OBJ: xuantie.c
// Date: Look 99/04/25

#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(HIB "墨纹玄铁" NOR, ({"mowen xuantie", "xuantie", "tie"}));
        set_weight(50);
        if (clonep())
                set_default_object(__FILE__);
        else {
              set("unit", "块");
              set("long", HIY "这是一块千年罕见的墨纹玄铁，入手极重，如果铸成剑的话，恐怕其锋无剑可比。\n");
              set("value", 10000);
              set("unique", 1);
	      set("treasure",1);
//              set("no_drop", 1);
              set("no_get", 1);
        }
        setup();
}

