//yupei.c
 
#include <armor.h>
 
inherit SHIELD;

void create()
{
	set_name(HIY"无玉"NOR, ({ "w yu" }) );
	set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", HIM"，落叶归根。\n风流倜傥，深情“风”。\n雷。”。\n");
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