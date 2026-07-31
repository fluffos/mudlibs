//yupei.c
 
#include <armor.h>
 
inherit SHIELD;

void create()
{
	set_name(HBMAG"如梦令"NOR, ({ "ru hua" }) );
	set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", HIM"昨夜雨疏风骤，浓睡不消残酒。\n试问卷帘人，却道“海棠依旧”。\n“知否？知否？应是绿肥红瘦。”。\n");
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