// cloth.c
//
// This is the basic equip for players just login.


#include <armor.h>
#include <ansi.h>

inherit HEAD;

void create()
{
        set_name(HIR "鸠工巾" NOR, ({ "jiugong jin","jin", "head" }));
        set_weight(500);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "条");
                set("material", "cloth");
                set("armor_prop/armor", 1);
        }
        setup();
}
