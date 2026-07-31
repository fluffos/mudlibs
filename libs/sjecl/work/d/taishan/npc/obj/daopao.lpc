// daopao.c 青色道袍
// By XiaoYao

#include <armor.h>

inherit CLOTH;

void create()
{
	set_name("青色道袍", ({"qingse daopao", "cloth", "dao pao"}) );
	set_weight(1500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "件");
		set("long", "这是件洗了发白的青色道袍。\n");
		set("material", "cloth");
                set("armor_prop/armor", 10);
	}
	setup();
}
