#include <ansi.h>
inherit ITEM;
void create()
{
	set_name( "掌法秘籍", ({ "zhangfa miji", "miji" }));
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "本");
		set("long", CYN"这是一本薄薄的书，书皮已经有点发黄了，打开一看，上面画满了人武对打的图形。\n"NOR);
		set("value", 500);
		set("material", "paper");
		set("skill", ([
			"name":	"strike",	// name of the skill
			"exp_required":	0,	// minimum combat experience required
			"jing_cost": 20, 	// jing cost every time study this
			"difficulty":	15,	// the base int to learn this skill
                        "max_skill":    59,     // the maximum level you can learn
		]) );
	}
}