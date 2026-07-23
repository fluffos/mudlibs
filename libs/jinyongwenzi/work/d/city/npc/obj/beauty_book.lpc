// sword_book.c

inherit ITEM;

void create()
{
	set_name("长春经", ({ "beauty book", "book" }));
	set_weight(600);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "本");
		set("long",
"封面上写着「长春经」\n");
		set("value", 10000);
		set("material", "paper");
		set("skill", ([
			"name": 	"beauty",		// name of the skill
			"exp_required":	0,			// minimum combat experience required
								// to learn this skill.
			"jing_cost":	30,			// jing cost every time study this
			"difficulty":	20,			// the base int to learn this skill
								// modify is jing_cost's (difficulty - int)*5%
            "max_skill":    41         // the maximum level you can learn
								// from this object.
		]) );
	}
}
