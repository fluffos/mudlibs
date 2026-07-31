
#include <ansi.h>

inherit ITEM;

void create()
{
	set_name( "大乘涅磐经", ({ "jing", "dacheng jing" }));
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "本");
		set("long","这是一本普通的大乘涅磐经。\n");                                    
		set("value", 500);
		set("material", "paper");
		set("skill", ([
			"name":	"mahayana",	// name of the skill
			"exp_required":	0,	// minimum combat experience required
			"jing_cost": 10, 	// jing cost every time study this
			"difficulty":	15,	// the base int to learn this skill
			"max_skill":	50,	// the maximum level you can learn
		]) );
	}
}
