#include <armor.h>
#include <ansi.h>
inherit CLOTH;

void create()
{
	set_name(WHT"玄色绸衫"NOR, ({"chou shan", "cloth", "shan"}) );
    set_weight(3000);
    if( clonep() )
       set_default_object(__FILE__);
    else {
        set("unit", "件");
		set("long", "一件玄色的绸衫。\n");
        set("material", "cloth");
        set("armor_prop/armor", 1);
		set("value",30);
    }
    setup();
}
