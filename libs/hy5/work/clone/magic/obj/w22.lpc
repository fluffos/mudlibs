// 布伦希多神鞭
#include <ansi.h>
#include <weapon.h>
inherit STAFF;

void create()
{
        set_name(HIB"暗云神枪"NOR, ({"magic stafff", "mstafff"}));
        set_weight(15000);

        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", HIB"这是一把暗云神枪,做工极其精致!\n"NOR);
                set("unique", 1);
                set("armor_prop/strength",15);
                set("value", 165000);
		set("armor_prop/armor",100);
        }
     init_staff(800);
        setup();
}       