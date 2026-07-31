//yupei.c
 
#include <armor.h>
 
inherit SHIELD;

void create()
{
	set_name(HIG"情场失意"NOR, ({ "qing yi" }) );
	set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "风流玉佩，洪荒时期，炸天玉女传奇送与度情信物，望其照福人间，却因度情荒淫无道，一次被抓，被群殴无意掉落的玉佩。\n");
		set("unit", "块");
		set("value", 5000000);
		set("no_drop", 1);
		set("no_give", 1);
		set("no_put", 1);
		set("no_steal", 1);
	set("armor_prop/unarmed_damage", 600);
	set("armor_prop/damage", 600);
	set("armor_prop/armor", 600);
	}
	setup();
}

int query_autoload() {return 1;}