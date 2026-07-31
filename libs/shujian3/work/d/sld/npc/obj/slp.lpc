// slp.c

#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
        set_name(HIW"神龙袍"NOR, ({"shenlong pao", "pao"}));
        set_weight(1000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "件");
                set("long", "这是一件用五彩神龙皮织成的长袍。\n");
                set("value", 10000);
                set("material", "fur");
                set("armor_prop/armor", 50);
        }
        setup();
}

