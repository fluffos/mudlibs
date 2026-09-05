//danxinjue丹心诀
#include <ansi.h>
inherit ITEM;
void create()
{
	set_name( HIR"「丹心诀」"NOR,({ "danxin jue", "book"}));
	set_weight(5000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "本");
		set("long","一本岳王墓里挖到的书，记载了一些内功心法。\n");
		set("value", 10000);
		set("material", "paper");
		set("skill", ([
	  	"name": "bixue-xinfa",  //name of the skill
 		"exp_required": 800000 , //minimum combat experience required
		"jing_cost": 80 + random(120),// jing cost every time study this
		"difficulty":	45,	// the base int to learn this skill
		"max_skill":	349,	// the maximum level you can learn
		"min_skill":    200
		]) );
	}
}