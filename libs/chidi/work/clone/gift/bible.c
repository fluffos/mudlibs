#pragma save_binary
 
// bible.c

inherit ITEM;
#include <ansi.h>
void create()
{
	set_name(YEL"圣经"NOR, ({ "bible"}));
	set_weight(600);
	set("task",1);
	set("owner","教父");
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "本");
		set("long",
			"这是一本圣经，上面写了一些教义。\n"
			);
		set("value", 1000);
		set("material", "paper");
set("no_give", 1);
set("no_drop", 1);
set("no_put", 1);

		set("skill", ([
			"name":	"literate",		// name of the skill
			"exp_required":	0,		// minimum combat experience required
			"literate_required":10,								// to learn this skill.
			"sen_cost":30,			// gin cost every time study this
			"difficulty":10,		// the base int to learn this skill
							// modify is gin_cost's (difficulty - int)*5%
			"max_skill":2000			// the maximum level you can learn
							// from this object.
		]) );
	}
	setup();
}
void owner_is_killed() { destruct(this_object()); }