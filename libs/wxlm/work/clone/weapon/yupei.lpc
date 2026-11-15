//yupei.c
 
#include <armor.h>
 
inherit SHIELD;

void create()
{
	set_name(HIW"瑾墨青花"NOR, ({ "jinmo qinghua" }) );
	set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "传闻少康给微笑的定情信物。\n");
		set("unit", "块");
		set("value", 1);
		set("no_drop", 1);
		set("no_give", 1);
		set("no_put", 1);
		set("no_steal", 1);
		set("armor_prop/unarmed_damage", 100);
		set("armor_prop/damage", 100);
		set("armor_prop/armor", 100);
	}
	setup();
}

int query_autoload() {return 1;}