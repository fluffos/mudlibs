// wucai_skirt.c

#include <armor.h>

inherit CLOTH;

void create()
{
        set_name("五彩绸裙", ({ "wucai skirt", "skirt" }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "浅红的的底料上绣着澄、黄、绿、蓝、紫五色大花，格外夺目。\n");
                set("unit", "件");
                set("value", 600);
                set("material", "cloth");
                set("armor_prop/armor", 1);
                set("armor_prop/personality", 3);
                set("female_only", 1);
        }
        setup();
}