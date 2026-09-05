#include <armor.h>
#include <ansi.h>
inherit CLOTH;

void create()
{
	set_name(HIB"青花布衫"NOR, ({"bu shan", "cloth", "shan"}) );
    set_weight(3200);
    if( clonep() )
       set_default_object(__FILE__);
    else {
        set("unit", "件");
		set("long", "一件青花布织的衣衫。\n");
        set("material", "cloth");
        set("armor_prop/armor", 1);
    }
    setup();
}
