
#include <armor.h>


inherit WAIST;

void create()
{
	set_name("丝绸肚兜", ({ "silk underwear", "underwear" }) );
	set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "这是一件大红丝绸做成的肚兜，上面绣着鸳鸯戏水，闻起来还有一股淡香。\n");
		set("unit", "件");
		set("value", 1200);
		set("material", "cloth");
		set("armor_prop/armor", 11);
		set("armor_prop/personality", 13);
		set("female_only", 1);
	}
	setup();
}

