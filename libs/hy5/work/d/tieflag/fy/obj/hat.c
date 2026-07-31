 // hat.c
#include <armor.h> 
inherit HEAD; 
void create()
{
        set_name("ÖñóÒ", ({ "hat" }) );
        set_weight(300);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "¶¥");
                set("value", 100);
                set("material", "wood");
                set("armor_prop/armor", 4);
                set("armor_prop/spirituality",3);
                set("armor_prop/intelligence",12);
		set("skill", ([
			"name":	      "force",	// name of the skill
			"exp_required":	0,	// minimum combat experience required
			"jing_cost":	30,	// jing cost every time study this
			"difficulty":	20,	// the base int to learn this skill
			"max_skill":	59,	// the maximum level you can learn
			"min_skill":	100	// the maximum level you can learn
		]) );              
        }
        setup();
} 
