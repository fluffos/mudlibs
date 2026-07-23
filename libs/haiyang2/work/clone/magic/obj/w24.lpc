// 布伦希多神鞭
#include <ansi.h>
#include <weapon.h>
inherit THROWING;

void create()
{
        set_name(BLU"灭世之暗器"NOR, ({"magic throwingf", "mthrowingf"}));
        set_weight(15000);

        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "支");
                set("long", BLU"这是一把灭世之暗器,做工极其精致!\n"NOR);
                set("unique", 1);
                 set("armor_prop/intelligence",15);
                set("value", 200);
		set("armor_prop/armor",200);
        }
         set_amount(100);
     init_throwing(500);
        setup();
}       