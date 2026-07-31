
inherit ITEM;

void create()
{
	set_name("禅刀精义", ({ "chandao", "shu", "book" }));
	set_weight(50);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "本");
		set("long",
			"这是一本佛家刀法秘籍\n"
			"是一本旧卷，上面密密麻麻绘有不少僧人手执戒刀扑击腾挪的场面。\n");
//          set("treasure", 1);
		set("value", 200);		set("material", "paper");
		set("skill", ([
			"name":	"blade",	// name of the skill
			"exp_required":	1000,	// minimum combat experience required
			"jing_cost":	20,	// jing cost every time study this
			"difficulty":	20,	// the base int to learn this skill
			"max_skill":	50	// the maximum level you can learn
		]) );
	}
}
