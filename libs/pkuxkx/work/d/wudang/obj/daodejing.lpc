// daodejing.c

inherit ITEM;

void create()
{
	set_name( "玄机直讲", ({ "shu", "book" }));
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "本");
		set("long", "这是张三丰的著作『玄机直讲』。\n");
		set("value", 500);
		set("material", "paper");
		set("skill", ([
			"name":	"taoism",	// name of the skill
			"exp_required":	0,	// minimum combat experience required
			"jing_cost": 20+random(20),// jing cost every time study this
			"difficulty":	20,	// the base int to learn this skill
			"max_skill":	100	// the maximum level you can learn
		]) );
	}
}
