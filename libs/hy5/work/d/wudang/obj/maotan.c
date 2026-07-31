// maotan.c

#include <armor.h>

inherit CLOTH;

void create()
{
        set_name("毛毯", ({ "mao tan","tan" }) );
        set_weight(600);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "张");
                set("long", "一张由纯羊毛织成的毛毯。毛线细密十分保暖。\n");
                set("material", "cloth");
                set("armor_prop/armor", 1);
        }
        setup();
}
