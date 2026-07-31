//JHY BY 02/8/29
// /d/changbai/shoushi.c 首饰

inherit ITEM;
#include <ansi.h>

void create()
{
        set_name(HIY"首饰"NOR, ({"shoushi", "shi"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "件");
                set("long", "这是一件精美女性头饰。\n");
                set("value", 10000000);
                set("medicine", 1);
        }
        setup();
}
