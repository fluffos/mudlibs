// daodejing.c

inherit ITEM;

void create()
{
	set_name( "手法精要", ({ "handshu", "book" }));
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("treasure",1);set("unit", "本");
		set("long", "这是一册手法精要。\n");
		set("value", 500);
		set("material", "paper");
		set("skill", ([
			"name":	"hand",	// name of the skill
			"exp_required":	1000,	// minimum combat experience required
			"jing_cost":    20+random(20),// jing cost every time study this
			"difficulty":	20,	// the base int to learn this skill
			"max_skill":	120	// the maximum level you can learn
		]) );
	}
}
