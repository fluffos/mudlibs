// 银色长枪
#include <ansi.h>
#include <weapon.h>
inherit SWORD;

void create()
{
        set_name(HIB"幻影之剑"NOR, ({"hy sword", "hysword"}));
        set_weight(15000);

        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", HIB"这是一把幻影之剑,做工极其精致!\n"NOR);
                set("unique", 1);
                set("value", 15000);
		set("armor_prop/armor",50);
        }
     init_sword(450);
        setup();
}       