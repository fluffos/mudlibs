// parry book

inherit ITEM;

void create()
{
	set_name("招架入门", ({ "parry book", "shu", "book" }));
	set_weight(100);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "本");
		set("long",
			"招架入门\n"
			"这是一本凌霄城编制的小册子，专门用来指导弟子练习招架。\n");
		set("value", 500);
		set("material", "paper");
		set("skill", ([
			"name":	"parry",	// name of the skill
			"exp_required":	0,	// minimum combat experience required
			"jing_cost":	10,	// jing cost every time study this
			"difficulty":	20,	// the base int to learn this skill
			"max_skill":	24	// the maximum level you can learn
		]) );
	}
}
