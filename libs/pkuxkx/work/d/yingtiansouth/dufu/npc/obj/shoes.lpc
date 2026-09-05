// cloth.c
//
// This is the basic equip for players just login.


#include <armor.h>
#include <ansi.h>

inherit BOOTS;

void create()
{
        set_name(HIW "官靴" NOR, ({ "guan xue","xue", "boots" }));
        set_weight(500);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "双");
                set("material", "cloth");
                set("armor_prop/armor", 10);
        }
        setup();
}
