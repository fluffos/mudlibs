// xueshan-jianfa book

inherit ITEM;

void create()
{
	set_name("雪山剑谱", ({ "xueshan jianpu", "shu", "book" }));
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "本");
		set("long",
			"雪山剑谱\n"
			"这是一本凌霄城编制的小册子，专门用来指导弟子练习雪山剑法。\n");
		set("value", 2500);
		set("material", "paper");
		set("skill", ([
			"name":	"xueshan-jianfa",	// name of the skill
			"exp_required":	0,	// minimum combat experience required
			"jing_cost":	10,	// jing cost every time study this
			"difficulty":	20,	// the base int to learn this skill
			"max_skill":	24	// the maximum level you can learn
		]) );
	}
}
