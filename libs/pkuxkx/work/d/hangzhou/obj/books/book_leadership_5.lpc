//leadership第五本
inherit ITEM;
void create()
{
	set_name( "「春秋」",({ "chunqiu", "book"}));
	set_weight(1200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "本");
		set("long", "这是五经中的春秋。\n");
		set("value", 15000);
		set("material", "paper");
		set("zijin",1); 
		set("skill", ([
	  	"name": "leadership",  //name of the skill
 		"exp_required": 100000 , //minimum combat experience required
		"jing_cost": 35 + random(35),// jing cost every time study this
		"difficulty":	35,	// the base int to learn this skill
		"max_skill":	199,	// the maximum level you can learn
		"min_skill":    166
		]) );
	}
}
