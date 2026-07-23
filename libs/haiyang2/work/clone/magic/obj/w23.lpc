// 布伦希多神鞭
#include <ansi.h>
#include <weapon.h>
inherit SWORD;

void create()
{
        set_name(RED"死神之剑"NOR, ({"magic swordf", "mswordf"}));
        set_weight(15000);

        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", RED"这是一把死神之剑,做工极其精致!\n"NOR);
                set("unique", 1);
                set("armor_prop/dexterity",15);
                set("value", 165000);
		set("armor_prop/armor",50);
        }
     init_sword(800);
        setup();
}       