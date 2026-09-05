//leadership第三本
inherit ITEM;
void create()
{
	set_name( "「厚黑学」",({ "houhei xue", "book"}));
	set_weight(2000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "本");
		set("long","一很薄的书，不知道有什么用。\n");
		set("value", 15000);
		set("zijin",1); 
		set("material", "paper");
		set("skill", ([
	  	"name": "leadership",  //name of the skill
 		"exp_required": 50000 , //minimum combat experience required
		"jing_cost": 30 + random(30),// jing cost every time study this
		"difficulty":	30,	// the base int to learn this skill
		"max_skill":	149,	// the maximum level you can learn
		"min_skill":    100
		]) );
	}
}