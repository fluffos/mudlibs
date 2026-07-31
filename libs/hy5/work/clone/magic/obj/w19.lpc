// 布伦希多神鞭
#include <ansi.h>
#include <weapon.h>
inherit CLUB;

void create()
{
        set_name(HIY"圣者之枪"NOR, ({"magic clube", "mclube"}));
        set_weight(15000);

        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", HIY"这是一把圣者之枪,做工极其精致!\n"NOR);
                set("unique", 1);
                set("armor_prop/constitution",15);
                set("value", 165000);
		set("armor_prop/armor",80);
        }
     init_club(800);
        setup();
}       