// 长柄战斧
#include <ansi.h>
#include <weapon.h>
inherit STAFF;

void create()
{
        set_name(RED"矮灵权杖"NOR, ({"wl staff", "wlstaff"}));
        set_weight(15000);

        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", HIB"这是一把矮灵权杖,做工极其精致!\n"NOR);
                set("unique", 1);
                set("value", 15000);
		set("armor_prop/armor",10);
        }
     init_staff(450);
        setup();
}       