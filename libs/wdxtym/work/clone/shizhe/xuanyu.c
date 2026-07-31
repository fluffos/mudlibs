//yupei.c
 
#include <armor.h>
 
inherit SHIELD;

void create()
{
	set_name(HIY"玄冥玉"NOR, ({ "xuan yu" }) );
	set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", HIM"，根。\n没了，深情“哭”。\n完了完了。”。\n");
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