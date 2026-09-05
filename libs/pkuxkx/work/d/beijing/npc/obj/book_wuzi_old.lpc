//strategy第六本
inherit ITEM;
void create()
{
	set_name( "「吴子兵法」",({ "wuzi bingfa", "book"}));
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "本");
		set("long","全书分为图国、料敌、治兵、论将、应变、励士六篇，被兵家奉为经典。\n");
		set("value", 20000);
		set("material", "paper");
		set("zijin",1); 
		set("skill", ([
	  	"name": "strategy",  //name of the skill
 		"exp_required": 50000 , //minimum combat experience required
		"jing_cost": 30 + random(50),// jing cost every time study this
		"difficulty":	35,	// the base int to learn this skill
		"max_skill":	170,	// the maximum level you can learn
		"min_skill":    140
		]) );
	}
}