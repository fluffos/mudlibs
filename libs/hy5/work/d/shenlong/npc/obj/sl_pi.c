// sl_cloth.c

#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
        set_name(HIW"神龙皮"NOR, ({"shenlong pi", "pi", "cloth"}));
        set_weight(1000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "张");
                set("long", "这是一张五彩神龙的皮。\n");
                set("value", 80);
                set("material", "fur");
                set("armor_prop/armor", 40);
        }
        setup();
}

