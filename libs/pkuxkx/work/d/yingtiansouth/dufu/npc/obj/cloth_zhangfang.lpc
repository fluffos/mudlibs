#include <armor.h>
#include <ansi.h>
inherit CLOTH;

void create()
{
	set_name(CYN"青色长衫"NOR, ({"chang shan", "cloth", "shan"}) );
    set_weight(3000);
    if( clonep() )
       set_default_object(__FILE__);
    else {
        set("unit", "件");
		set("long", "一件天青色的长衫，读书人多穿着如此。\n");
        set("material", "cloth");
        set("armor_prop/armor", 1);
		set("value",30);
    }
    setup();
}
