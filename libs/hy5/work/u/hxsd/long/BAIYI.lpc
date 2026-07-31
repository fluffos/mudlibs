// pink_cloth.c

#include <armor.h>

inherit CLOTH;

void create()
{
        set_name("白丝绸衫", ({ "pink cloth", "cloth" }) );
        set_weight(10);
	if( clonep() )
		set_default_object(__FILE__);
	else {
                set("long", "这件雪白的绸衫上面洁白无比，闻起来还有一股淡香。\n");
		set("unit", "件");
		set("value", 600);
		set("material", "cloth");
		set("armor_prop/armor", 1);
		set("armor_prop/personality", 3);
		set("female_only", 1);
	}
	setup();
}

