// color_head.c

#include <armor.h>
#include <ansi.h>

inherit HEAD;

void create()
{
	set_name( HIR "红玫瑰" NOR , ({ "red rose" }) );
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "这是一朵美丽无比的红玫瑰。\n");
		set("unit", "朵");
		set("value", 2000);
		set("material", "rose");
		set("armor_prop/armor", 11);
//		set("armor_prop/personality", 0);
//		set("female_only", 1);
	}
	setup();
}

