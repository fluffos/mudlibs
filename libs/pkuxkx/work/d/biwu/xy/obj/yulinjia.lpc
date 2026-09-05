// yulinjia.c 鱼鳞甲
//created by zine 25 aug 2010
#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
	set_name(WHT"鱼鳞甲"NOR, ({ "yulin jia", "armor", "jia" }) );
    set_weight(18000);
	if( clonep() )
		set_default_object(__FILE__);
    else 
		{
			set("unit", "件");
			set("material", "steel");
			set("value", 1);
			set("long", "一片片鱼鳞状钢片镶缀而成的战甲。\n");
			set("armor_prop/armor", 800);
        }
	setup();
}
