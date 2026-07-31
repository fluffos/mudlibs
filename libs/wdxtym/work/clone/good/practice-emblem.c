#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(MAG "紫金练习勋章" NOR, ({ "practice emblem", "emblem" }));
        set_weight(3000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", MAG "带在身上可以提升练习最大次数三百次。\n" NOR);
                set("unit", "块");
                set("can_summon", 1);
                set("value", 500000);
        }
        setup();
}

int query_autoload()
{
        return 1;
}
