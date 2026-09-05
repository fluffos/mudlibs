// tianyi.c 天衣
//created by zine 25 aug 2010
#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{	
	set_name("天衣"NOR, ({ "tian yi", "armor", "cloth" }) );
    set_weight(1800);
	if( clonep() )
		set_default_object(__FILE__);
    else 
		{
			set("unit", "件");
			set("value", 1);
			set("long", "一件毫不显眼的服饰。\n");
			set("armor_prop/armor", 1800);
        }
	setup();
}
