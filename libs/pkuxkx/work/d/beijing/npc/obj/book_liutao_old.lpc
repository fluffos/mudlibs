//strategy第二本
inherit ITEM;
void create()
{
	set_name( "「六韬」",({ "liu tao", "book"}));
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "本");
		set("long","此书有文韬、武韬、龙韬、虎韬、豹韬、犬韬六卷，总结了先秦兵学和诸子论兵的精华。\n");
		set("value", 2000);
		set("material", "paper");
		set("zijin",1); 
		set("skill", ([
	  	"name": "strategy",  //name of the skill
 		"exp_required": 5000 , //minimum combat experience required
		"jing_cost": 10 + random(30),// jing cost every time study this
		"difficulty":	22,	// the base int to learn this skill
		"max_skill":	59,	// the maximum level you can learn
		"min_skill":    30
		]) );
	}
}