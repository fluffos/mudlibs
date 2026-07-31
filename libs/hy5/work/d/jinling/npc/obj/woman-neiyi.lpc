
#include <armor.h>

inherit CLOTH;

void create()
{
	set_name("红布肚兜", ({ "red underwear", "underwear" }) );
	set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "这是一件大红棉布做成的肚兜，上面绣着几朵黄花，闻起来还有一股淡香。\n");
		set("unit", "件");
		set("value", 0);
		set("material", "cloth");
		set("armor_prop/armor", 1);
		set("armor_prop/personality", 3);
		set("female_only", 1);
	}
	setup();
}

