// 兰花扶穴手秘诀
#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(HIC"兰花拂穴手秘诀"NOR, ({"mijue"}));
	set_weight(200);
	set("unit", "册");
	set("value", 500);
	set("material", "paper");
	set("skill", ([
			"name":"fuxue-shou",//skill which will be increased
			"exp_required":	10000,	// minimum combat experience required
			"jing_cost": 20+random(15),// jing cost every time study this
			"difficulty":	25,	// the base int to learn this skill
			"max_skill":	101	// the maximum level you can learn
		      ]));
}
