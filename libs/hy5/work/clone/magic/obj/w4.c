// 银色长枪
#include <ansi.h>
#include <weapon.h>
inherit BLADE;

void create()
{
        set_name(RED"炎龙刀"NOR, ({"f blade", "fblade"}));
        set_weight(15000);

        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", RED"这是一把炎龙刀,做工极其精致!\n"NOR);
                set("unique", 1);
                set("value", 15000);
		set("armor_prop/armor",10);
        }
     init_blade(450);
        setup();
}       