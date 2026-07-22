// forcebook.c

inherit ITEM;

void create()
{
	set_name( "内功入门", ({ "force book", "book" }));
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "本");
		set("long", "这是一册内功入门，上面记载着初浅的内功心法。\n");
		set("value", 5000);
		set("material", "paper");
		set("skill", ([
			"name":	"force",	// name of the skill
			"exp_required":	0,	// minimum combat experience required
			"jing_cost": 20, 	// jing cost every time study this
			"difficulty":	20,	// the base int to learn this skill
			"max_skill":	30,	// the maximum level you can learn
		]) );
	}
}
