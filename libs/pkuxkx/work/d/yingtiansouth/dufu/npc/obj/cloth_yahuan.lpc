#include <armor.h>
#include <ansi.h>
inherit CLOTH;

void create()
{
	set_name("绸衫", ({"chou shan", "cloth", "shan"}) );
    set_weight(2000);
    if( clonep() )
       set_default_object(__FILE__);
    else {
        set("unit", "件");
		set("long", "一件最便宜的绸衫。\n");
        set("material", "cloth");
        set("armor_prop/armor", 1);
    }
    setup();
}
