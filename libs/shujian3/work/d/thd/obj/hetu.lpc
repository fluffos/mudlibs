#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(HIG"河图"NOR, ({ "he tu","he","tu" }));
	set_weight(300);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "本");
		set("value", 5000);
		set("treasure",1);
		set("unique",1);
		set("newbie", 1);
		set("material", "paper");
		set("skill", ([
			"name": "qimen-bagua",  
			"jing_cost":    40,     
			"exp_required":	60000,	// minimum combat experience required
			"difficulty":   20,     
			"min_skill":	50,
			"max_skill":    100,
		]) );
	}
}
