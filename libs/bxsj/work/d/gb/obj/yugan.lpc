// yugan.c

#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(YEL"鱼竿"NOR, ({ "yu gan", "yugan", "gan" }) );
        set_weight(1500);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "根");
		set("no_drop", 1);
                set("value", 200);
                set("long", "这是一把鱼竿。\n");
        }
        setup();
}

