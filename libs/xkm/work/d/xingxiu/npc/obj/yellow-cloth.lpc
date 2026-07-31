//Cracked by Roath
// yellow-cloth.c

#include <armor.h>
#include <ansi.h>
inherit CLOTH;

void create()
{
        set_name(YEL"黄葛布衫"NOR, ({ "gebu shan", "cloth", "gebu", "shan" }) );
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
                set("material", "cloth");
                set("armor_prop/armor", 3);
        }
        setup();
}

