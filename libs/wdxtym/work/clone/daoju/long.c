//yupei.c
 
#include <armor.h>
 
inherit SHIELD;

void create()
{
	set_name(HIY"Áú·ï³ÊÏé"NOR, ({ "long fong" }) );
	set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "ÉÏ¹Å¾íÖá£¬³¯¸èÒ¹ÏÒ´óÕ½Õê×ÓÎŞÒâµôÂäµÄÓñÅå¡£\n");
		set("unit", "¿é");
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