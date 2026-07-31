// 狂风杖
#include <ansi.h>
#include <weapon.h>
inherit STAFF;

void create()
{
        set_name(HIC"狂风杖"NOR, ({"magic staffd", "mstaffd"}));
        set_weight(15000);

        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", HIC"这是一把狂风杖,做工极其精致!\n"NOR);
                set("unique", 1);
                set("value", 15000);
		set("armor_prop/armor",100);
        }
     init_staff(500);
        setup();
}       