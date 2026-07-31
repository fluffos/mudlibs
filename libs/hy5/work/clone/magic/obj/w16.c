// 布伦希多神鞭
#include <ansi.h>
#include <weapon.h>
inherit WHIP;

void create()
{
        set_name(HIC"布伦希多神鞭"NOR, ({"magic whipd", "mwhipd"}));
        set_weight(15000);

        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", HIC"这是一把布伦希多神鞭,做工极其精致!\n"NOR);
                set("unique", 1);
                set("value", 15000);
		set("armor_prop/armor",10);
        }
     init_whip(600);
        setup();
}       