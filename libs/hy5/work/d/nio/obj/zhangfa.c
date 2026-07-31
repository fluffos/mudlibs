// zhangfa.c 落英神剑掌法

inherit ITEM;

void create()
{
	set_name("落英神剑掌图解", ({ "zhangfa tujie", "tujie", "shu", "book" }));
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("treasure", 1);
		set("unit", "本");
		set("long", "这本掌法中详细地画着黄药师所创的落英神剑掌的图解，虽然对你来说略显艰深，但用它来领悟基本掌法的诀窍却是可以的。\n");
		set("value", 30);
		set("material", "paper");
		set("skill", ([
			"name":	"strike",	// name of the skill
			"exp_required":	100,	// minimum combat experience required
			"jing_cost":	15,	// jing cost every time study this
			"difficulty":	25,	// the base int to learn this skill
			"max_skill":	30	// the maximum level you can learn
		]) );
	}
}
