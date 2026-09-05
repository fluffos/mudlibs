//leadership第四本
inherit ITEM;
void create()
{
	set_name( "「周易」",({ "zhouyi", "book"}));
	set_weight(1200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "本");
		set("long", "这是五经中的周易。\n");
		set("value", 15000);
		set("material", "paper");
		set("zijin",1); 
		set("skill", ([
	  	"name": "leadership",  //name of the skill
 		"exp_required": 80000 , //minimum combat experience required
		"jing_cost": 32 + random(32),// jing cost every time study this
		"difficulty":	32,	// the base int to learn this skill
		"max_skill":	165,	// the maximum level you can learn
		"min_skill":    133
		]) );
	}
}
