// tangmen_book.c  ÌÆÃÅ°µÆ÷
#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(MAG"ÌÆÃÅ°µÆ÷"NOR, ({ "tangmen_book" }));
	set_weight(600);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "±¾");
		set("no_sell",1);
		set("long",
			"Ñ§ÌÆÃÅ°µÆ÷¡£\n");
		set("value", 1000);
		set("material", "paper");
		set("skill", ([
			"name":	 "tangmen-throwing",       // name of the skill
			"exp_required": 100000,		 // minimum combat experience required
								// to learn this skill.
			"jing_cost" :   30,
			"difficulty":   30,		     // the base int to learn this skill
								// modify is gin_cost's (difficulty - int)*5%
			"max_skill":    119,		    // the maximum level you can learn
			"min_skill":    0		       // the maximum level you can learn
								// from this object.
		]) );
	}
}
