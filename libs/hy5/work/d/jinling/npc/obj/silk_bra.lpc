// pink_cloth.c

#include <armor.h>

inherit CLOTH;

void create()
{
	set_name("真丝乳罩", ({ "silk-bra", "bra" }) );
	set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "这个粉红色的乳罩上面绣著两朵玫瑰，闻起来还有一股淡香。\n");
		set("unit", "个");
		set("value", 1000);
		set("material", "cloth");
		set("armor_prop/armor", 11);
		set("armor_prop/personality", 13);
		set("female_only", 11);
	}
	setup();
}

