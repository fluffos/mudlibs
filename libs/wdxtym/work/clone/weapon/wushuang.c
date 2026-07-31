// wushuang.c 无双
 
#include <armor.h>
 
inherit SHIELD;

void create()
{
	set_name(HIR"无双"NOR, ({ "wu shuang" }) );
	set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "华山之巅，群雄争锋，天下无双，舍我其谁。\n");
		set("unit", "块");
		set("value", 1);
		set("no_drop", 1);
		set("no_give", 1);
		set("no_put", 1);
		set("no_steal", 1);
	set("armor_prop/unarmed_damage", 100);
	set("armor_prop/damage", 100);
	set("armor_prop/skills", 100);
	set("armor_prop/armor", 100);
	}
	setup();
}
