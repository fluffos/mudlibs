// guanfu 官服 by zine aug 28 2010
#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
	set_name(HIR"朝廷官府"NOR, ({ "guan fu", "cloth", "chao fu" }) );
	set_weight(2000);
		if( clonep() )
			set_default_object(__FILE__);
        else 
			{
				set("unit", "件");
				set("material", "cloth");
				set("value", 1);
				set("long", "这是一件崭新的朝廷官服，整齐地叠好放着。\n");
				set("armor_prop/armor", 1);
			}
       setup();
}
