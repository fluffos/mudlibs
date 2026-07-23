// 长柄战斧
#include <ansi.h>
#include <weapon.h>
inherit AXE;

void create()
{
        set_name(RED"长柄战斧"NOR, ({"lang axe", "langaxe"}));
        set_weight(15000);

        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", RED"这是一把长柄战斧,做工极其精致!\n"NOR);
                set("unique", 1);
                set("value", 15000);
		set("armor_prop/armor",10);
        }
     init_axe(450);
        setup();
}       