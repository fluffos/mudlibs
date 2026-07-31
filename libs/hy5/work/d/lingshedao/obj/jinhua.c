// tielianzi.c
#include "ansi.h" 
#include <weapon.h>
 
inherit THROWING;
 
void create()
{
	set_name(HIY"金花"NOR, ({ "jin hua", "jinhua", "hua" }) );
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "黄金打造的暗器。\n");
		set("unit", "把");
		set("value", 0);
		set("base_unit", "粒");
		set("base_weight", 1);
		set("base_value", 0);
		set("damage", 220);	//Here the damage=int_throwing, added by King
	}
	set_amount(50);
	init_throwing(220);
	setup();
}
