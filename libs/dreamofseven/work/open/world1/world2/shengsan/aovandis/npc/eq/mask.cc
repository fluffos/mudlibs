#include <armor.h>
#include <ansi.h>
inherit MASK;
void create()
{
	set_name("面具", ({ "mask" }) );
	set("long",@LONG
這是一副面具。
LONG
);
	set_weight(2100);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "副");
		set("material", "silk");
	}
	set("auto_set",2);
	setup();
}

//int query_autoload() { return 1; }
