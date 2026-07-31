// suihua_skirt.c

#include <armor.h>

inherit CLOTH;

void create()
{
        set_name("黄绸碎花裙", ({ "suihua skirt", "skirt" }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "鹅黄的绸缎上点缀着小花。\n");
                set("unit", "件");
                set("value", 600);
                set("material", "cloth");
                set("armor_prop/armor", 1);
                set("armor_prop/personality", 3);
                set("female_only", 1);
        }
        setup();
}