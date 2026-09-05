#include <armor.h>
#include <ansi.h>

inherit BOOTS;

void create()
{
        set_name(WHT "皮靴" NOR, ({ "pi xue", "shoes" }));
        set_weight(2000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "双");
                set("value", 2000);
                set("long", "这是一双动物皮缝制的薄皮靴，保暖相当好。");
                set("material", "cloth");
                set("armor_prop/armor", 1);
        }
        setup();
}

