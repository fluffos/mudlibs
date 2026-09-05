// tea_leaf.c
 
#include <weapon.h>
 
inherit THROWING;
 
void create()
{
        set_name("茶叶", ({ "tea leaf", "tea" }) );
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "才采的新茶，发出一股淡淡的香气，在高手手中这甚至能当暗器使。\n");
                set("unit", "把");
                set("value", 0);
                set("base_unit", "片");
                set("base_weight", 1);
                set("base_value", 0);
		set("damage", 1);	//Here the damage=int_throwing, added by King
        }
        init_throwing(1);
        setup();
}
