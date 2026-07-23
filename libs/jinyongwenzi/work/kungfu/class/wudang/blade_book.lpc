// blade_book.c

inherit ITEM;

void create()
{
	set_name("刀法概要", ({ "blade book", "book" }));
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "本");
		set("long",
"封这是一本讲述基本刀法要领的书籍。\n");
		set("value", 100);
		set("material", "paper");
		set("skill", ([
			"name": 		"blade",		// name of the skill
			"exp_required":	1000,			// minimum combat experience required
											// to learn this skill.
			"jing_cost":		20,				// jing cost every time study this
			"difficulty":	20,				// the base int to learn this skill
											// modify is jing_cost's (difficulty - int)*5%
			"max_skill":	35				// the maximum level you can learn
											// from this object.
		]) );
	}
}
