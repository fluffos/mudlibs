// shuiran_skirt.c

#include <armor.h>

inherit CLOTH;

void create()
{
        set_name("水染绿缎裙", ({ "shuiran skirt", "skirt" }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "像清脆的草地映着缕缕的白云，一片朦胧，引起人无限遐想。\n");
                set("unit", "件");
                set("value", 600);
                set("material", "cloth");
                set("armor_prop/armor", 1);
                set("armor_prop/personality", 3);
                set("female_only", 1);
        }
        setup();
}