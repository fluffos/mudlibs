// mdan.c 
//by dwolf

#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(YEL"牡丹花"NOR, ({ "mudan hua", "hua" }) );
	set_weight(250);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", YEL"一束漂亮的牡丹花,人称花中皇后。\n"NOR);
		set("unit", "束");
		set("value", 180);
	}
	setup();
}

