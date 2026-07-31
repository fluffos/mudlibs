// sxh.c 
//by dwolf

#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(HIW"水仙花"NOR, ({ "shuixian hua", "hua" }) );
	set_weight(250);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", HIW"一束漂亮的水仙花。\n"NOR);
		set("unit", "束");
		set("value", 80);
	}
	setup();
}

