// 布伦希多神鞭
#include <ansi.h>
#include <weapon.h>
inherit DAGGER;

void create()
{
        set_name(GRN"水晶匕首"NOR, ({"magic sworde", "msworde"}));
        set_weight(15000);

        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", GRN"这是一把水晶匕首,做工极其精致!\n"NOR);
                set("unique", 1);
                set("armor_prop/strength",15);
                set("value", 165000);
		set("armor_prop/armor",200);
        }
     init_dagger(500);
        setup();
}       