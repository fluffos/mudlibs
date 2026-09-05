// guanfu 官服 by zine aug 28 2010
#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
	set_name(RED"朝廷官府"NOR, ({ "guanfu", "cloth", "chao fu" }) );
	set_weight(2000);
		if( clonep() )
			set_default_object(__FILE__);
        else 
			{
				set("unit", "件");
				set("material", "cloth");
				set("value", 1);
				set("long", "这是一件皱巴巴的朝廷官服，被随便丢在一边。\n");
				set("armor_prop/armor", 1);
			}
       setup();
}
