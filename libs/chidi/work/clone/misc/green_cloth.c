// pink_cloth.c

#include <armor.h>
#include <ansi.h>

inherit CLOTH;

void create()
{
	set_name(GRN "绿罗裙" NOR, ({ "green cloth", "cloth" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "这件绿色的绸裙上面绣着几朵绿色的小花，闻起来还有一股淡香。\n");
		set("unit", "件");
		set("material", "cloth");
		set("armor_prop/armor", 1);
		set("armor_prop/personality", 3);
		set("female_only", 1);
	}
	setup();
}

