// 布伦希多神鞭
#include <ansi.h>
#include <weapon.h>
inherit BLADE;

void create()
{
        set_name(BLU"死神镰刀"NOR, ({"magic bladef", "mbladef"}));
        set_weight(15000);

        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", BLU"这是一把死神镰刀,做工极其精致!\n"NOR);
                set("unique", 1);
                set("armor_prop/strength",15);
                set("value", 165000);
		set("armor_prop/armor",200);
        }
     init_blade(600);
        setup();
}       