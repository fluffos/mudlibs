//leadership第二本(无金叶)
inherit ITEM;
void create()
{
	set_name( "「尚书」",({ "shangshu", "book"}));
	set_weight(1200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "本");
		set("long", "这是五经中的尚书。\n");
		set("value", 10000);
		set("material", "paper");
		set("zijin",1); 
		set("skill", ([
	  	"name": "leadership",  //name of the skill
 		"exp_required": 10000 , //minimum combat experience required
		"jing_cost": 20 + random(20),// jing cost every time study this
		"difficulty":	25,	// the base int to learn this skill
		"max_skill":	99,	// the maximum level you can learn
		"min_skill":    50
		]) );
	}
}
