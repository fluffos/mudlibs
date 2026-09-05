// suozijia.c 锁子甲 by zine aug 28 2010
#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
	set_name(HIW"锁子甲"NOR, ({ "suozi jia", "armor", "jia" }) );
	set_weight(20000);
		if( clonep() )
			set_default_object(__FILE__);
        else 
			{
				set("unit", "件");
				set("material", "steel");
				set("value", 1);
				set("long", "一件由铁环套扣缀合，每环与另四个环相套扣，形如网锁的战甲。\n");
				set("armor_prop/armor", 600);
			}
       setup();
}
