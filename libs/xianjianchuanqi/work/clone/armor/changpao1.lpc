#include <ansi.h>
#include <armor.h>
inherit CLOTH;

void create()
{
        set_name(YEL"土黄色布袍"NOR, ({ "bu pao", "pao"}));
        set("long", "这是一件土黄色长袍。\n");
        set_weight(1000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("material", "cloth");
                set("unit", "件");
                set("armor_prop/armor", 2);
        }
        setup();
}

