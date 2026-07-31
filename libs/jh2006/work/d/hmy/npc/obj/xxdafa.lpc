// force_book.c 内功心法

inherit ITEM;

void create()
{
	set_name("吸星大法", ({ "xxdafa book","book"}));
	set_weight(600);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "本");
		set("long", "这是一本线装书，里面密密麻麻的画了不少打坐吐呐的姿势。\n");
		set("value", 500);
		set("material", "paper");
		set("skill", ([
			"name":	"xxdafa",	// name of the skill
			"exp_required":	10000,	// minimum combat experience required
			"jing_cost":	60,	// jing cost every time study this
			"difficulty":	10,	// the base int to learn this skill
			"max_skill":	200	// the maximum level you can learn

		]) );
	}
}
