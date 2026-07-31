//yupei.c
 
#include <armor.h>
 
inherit SHIELD;

void create()
{
	set_name(HIY"风花雪月"NOR, ({ "feng hua" }) );
	set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "你是我的小呀小苹果，怎么爱你都不嫌多，大手一辉大苹果丢下了他的随身的玉佩！听说拥有它会极丑无比。\n");
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