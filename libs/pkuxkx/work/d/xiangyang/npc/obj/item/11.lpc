// flower_leaf.c
 
#include <weapon.h>
 
inherit THROWING;
 
void create()
{
	set_name("花瓣", ({ "flower leaf", "hua ban", "ban" }) );
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "新鲜的玫瑰花的花瓣，上面还挂这晶莹的露珠，在高手手中这甚至能当暗器使。\n");
		set("unit", "把");
		set("value", 0);
		set("base_unit", "片");
		set("base_weight", 1);
		set("base_value", 0);
		set("damage", 2);	//Here the damage=int_throwing, added by King
	}
	init_throwing(2);
	setup();
}
