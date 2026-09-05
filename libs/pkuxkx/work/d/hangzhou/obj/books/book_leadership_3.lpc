//leadership第三本
inherit ITEM;
void create()
{
	set_name( "「礼记」",({ "liji", "book"}));
	set_weight(1200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "本");
		set("long", "这是五经中的礼记。\n");
		set("value", 15000);
		set("material", "paper");
		set("zijin",1); 
		set("skill", ([
	  	"name": "leadership",  //name of the skill
 		"exp_required": 50000 , //minimum combat experience required
		"jing_cost": 30 + random(30),// jing cost every time study this
		"difficulty":	30,	// the base int to learn this skill
		"max_skill":	132,	// the maximum level you can learn
		"min_skill":    100
		]) );
	}
}
