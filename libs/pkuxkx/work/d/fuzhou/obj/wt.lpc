// cloth.c
//
// This is the basic equip for players just login.

#include <armor.h>

inherit CLOTH;

int do_swim(string arj);


void create()
{
        set_name("水靠", ({ "shui kao" }) );
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
                set("material", "cloth");
                set("armor_prop/armor", 1);
        }
        setup();
}
/*
 void init()
{
	add_action("do_swim","swim");
}  
int do_swim(string arj)
  {this_player()->move("/d/quanzhou/hole");
  return 1;
}
*/





