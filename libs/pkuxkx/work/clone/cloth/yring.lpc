// cloth.c
//
// This is the basic equip for players just login.


#include <armor.h>
#include <ansi.h>

inherit FINGER;

void create()
{
        set_name(RED "橘井星" NOR, ({ "jujing xing","xing", "ring" }));
        set_weight(800);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "只");
				set("no_drop",1);
				set("no_give",1);
                set("material", "gold");
                set("armor_prop/armor", 1);
        }
        setup();
}
