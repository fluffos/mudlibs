// 银色长枪
#include <ansi.h>
#include <weapon.h>
inherit CLUB;

void create()
{
        set_name(RED"火神战戟"NOR, ({"fire sting", "firesting"}));
        set_weight(15000);

        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "杆");
                set("long", RED"这是一杆火神战戟,做工极其精致!\n"NOR);
                set("unique", 1);
                set("value", 15000);
		set("armor_prop/armor",10);
        }
     init_club(450);
        setup();
}       