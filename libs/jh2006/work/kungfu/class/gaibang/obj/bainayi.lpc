// cloth.c
// login cloth
// This is the basic equip for players just login.

#include <armor.h>
#include <ansi.h>
inherit CLOTH;

void create()
{
        set_name(YEL"百衲结衣"NOR, ({ "baina jieyi", "cloth" }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
                set("material", "cloth");
                 set("armor_prop/armor", 20);
        }
        setup();
}
