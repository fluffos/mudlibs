// 星尘杖
#include <ansi.h>
#include <weapon.h>
inherit STAFF;

void create()
{
        set_name(HIC"星尘杖"NOR, ({"magic staffe", "mstaffe"}));
        set_weight(15000);

        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", HIC"这是一把星尘杖,做工极其精致!\n"NOR);
                set("unique", 1);
                set("armor_prop/intelligence",20);
                set("value", 165000);
		set("armor_prop/armor",50);
        }
     init_staff(600);
        setup();
}       