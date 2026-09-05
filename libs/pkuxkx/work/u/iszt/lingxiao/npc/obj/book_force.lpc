// force book

inherit ITEM;

void create()
{
	set_name("内功入门", ({ "force book", "shu", "book" }));
	set_weight(100);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "本");
		set("long", "这是一本凌霄城编制的小册子，专门用来指导弟子练习内功。\n");
		set("value", 500);
		set("material", "paper");
		set("skill", ([
			"name":	"force",	// name of the skill
			"exp_required":	0,	// minimum combat experience required
			"jing_cost":	10,	// jing cost every time study this
			"difficulty":	10,	// the base int to learn this skill
			"max_skill":	14	// the maximum level you can learn
		]) );
	}
}
