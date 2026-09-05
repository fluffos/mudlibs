// cloth.c
//
// This is the basic equip for players just login.


#include <armor.h>
#include <ansi.h>

inherit BOOTS;

void create()
{
        set_name(CYN "窥垣靴" NOR, ({ "kuiyuan xue","xue", "shoes" }));
        set_weight(800);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "双");
                set("material", "cloth");
                set("armor_prop/armor", 5);
        }
        setup();
}
