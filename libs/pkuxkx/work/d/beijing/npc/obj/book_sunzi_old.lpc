//strategy第七本
inherit ITEM;
void create()
{
	set_name( "「孙子兵法」",({ "sunzi bingfa", "book"}));
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "本");
		set("long","这就是被誉为“兵经”的伟大著作，其作者孙武被誉为“兵圣”。\n");
		set("value", 50000);
		set("material", "paper");
		set("zijin",1); 
		set("skill", ([
	  	"name": "strategy",  //name of the skill
 		"exp_required": 100000 , //minimum combat experience required
		"jing_cost": 50 + random(50),// jing cost every time study this
		"difficulty":	40,	// the base int to learn this skill
		"max_skill":	199,	// the maximum level you can learn
		"min_skill":    170
		]) );
	}
}