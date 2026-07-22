
inherit ITEM;

void create()
{
	set_name("洗髓经", ({ "xisui jing", "xisui", "shu", "book" }));
	set_weight(50);
	if( clonep() ) {
		call_out("dest", 1800);
		set_default_object(__FILE__);
	} else {
		set("unit", "卷");
		set("long",
			"这是一卷达摩洗髓经\n"
			"是一块暗红色的破布，里面密密麻麻的画了不少打坐吐呐的姿势。\n");
                set("treasure", 1);
		set("unique", 1);
		set("value", 500);		set("material", "cloth");
		set("skill", ([
			"name":	"force",	// name of the skill
			"exp_required":	0,	// minimum combat experience required
			"jing_cost":	10,	// jing cost every time study this
			"difficulty":	20,	// the base int to learn this skill
			"max_skill":	29	// the maximum level you can learn
		]) );
	}
}

void dest()
{
	destruct(this_object());
}
