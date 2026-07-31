// 银色长枪
#include <ansi.h>
#include <weapon.h>
inherit AXE;

void create()
{
        set_name(HIB"月神斧"NOR, ({"water axe", "watersting"}));
        set_weight(15000);

        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", HIB"这是一把月神斧,做工极其精致!\n"NOR);
                set("unique", 1);
                set("value", 15000);
		set("armor_prop/armor",10);
        }
     init_axe(550);
        setup();
}       