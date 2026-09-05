// female1-cloth.c

#include <armor.h>
#include <ansi.h>
inherit CLOTH;

void create()
{
        set_name(HIW"短袖"NOR, ({ "cloth" }) );
        set_weight(1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "这件白色的短袖就是普通夏天穿的短袖。\n");
                set("unit", "件");
                set("value", 0);
                set("material", "cloth");
                set("armor_prop/armor", 1);
                set("armor_prop/personality", 3);
                set("female_only", 1);
        }
        setup();
}
