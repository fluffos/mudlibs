// mgui.c 
//by dwolf

#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(RED"玫瑰花"NOR, ({ "meigui hua", "hua" }) );
	set_weight(250);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", RED"一束漂亮的玫瑰花,恋爱中的人可少不了喔。\n"NOR);
		set("unit", "束");
		set("value", 100);
	}
	setup();
}

