// 地狱鬼斧
#include <ansi.h>
#include <weapon.h>
inherit STAFF;

void create()
{
        set_name(HIR"方天戟"NOR, ({"magic staffc", "mstaffc"}));
        set_weight(15000);

        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", HIR"这是一把方天戟,做工极其精致!\n"NOR);
                set("unique", 1);
                set("value", 15000);
		set("armor_prop/armor",10);
        }
     init_staff(500);
        setup();
}       