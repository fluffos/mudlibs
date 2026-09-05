//strategy第五本
inherit ITEM;
void create()
{
	set_name( "「尉缭子」",({ "weiliaozi", "book"}));
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "本");
		set("long","这是一部战国时期尉缭撰写的兵书，此书有两个重要的特色“兵形势家”和军事法规。\n");
		set("value", 10000);
		set("material", "paper");
		set("zijin",1); 
		set("skill", ([
	  	"name": "strategy",  //name of the skill
 		"exp_required": 20000 , //minimum combat experience required
		"jing_cost": 30 + random(30),// jing cost every time study this
		"difficulty":	30,	// the base int to learn this skill
		"max_skill":	139,	// the maximum level you can learn
		"min_skill":    120
		]) );
	}
}