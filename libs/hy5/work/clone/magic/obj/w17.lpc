// 布伦希多神鞭
#include <ansi.h>
#include <weapon.h>
inherit SWORD;

void create()
{
        set_name(HIC"次元之剑"NOR, ({"magic sworde", "msworde"}));
        set_weight(15000);

        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", HIC"这是一把次元之剑,做工极其精致!\n"NOR);
                set("unique", 1);
                set("armor_prop/intelligence",15);
                set("value", 65000);
		set("armor_prop/armor",10);
        }
     init_sword(650);
        setup();
}       