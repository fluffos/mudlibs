//strategy第三本
inherit ITEM;
void create()
{
	set_name( "「武经总要」",({ "wujing zongyao", "book"}));
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "本");
		set("long","武经总要是北宋名臣曾公亮所著。\n书中总结前朝的军事思想并大篇幅介绍的军器制造。\n");
		set("value", 3000);
		set("material", "paper");
		set("Strategy_Book_Series",3);  
		set("skill", ([
	  	"name": "strategy",  //name of the skill
 		"exp_required": 10000 , //minimum combat experience required
		"jing_cost": 20 + random(30),// jing cost every time study this
		"difficulty":	25,	// the base int to learn this skill
		"max_skill":	109,	// the maximum level you can learn
		"min_skill":    70
		]) );
	}
}