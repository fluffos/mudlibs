//leadership第四本
inherit ITEM;
void create()
{
	set_name( "「资治通鉴」",({ "zizhi tongjian", "book"}));
	set_weight(5000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "本");
		set("long","一很厚的书，据说古往今来的帝王将相都要研读此书。\n");
		set("value", 20000);
		set("material", "paper");
		set("zijin",1); 
		set("skill", ([
	  	"name": "leadership",  //name of the skill
 		"exp_required": 100000 , //minimum combat experience required
		"jing_cost": 40 + random(40),// jing cost every time study this
		"difficulty":	35,	// the base int to learn this skill
		"max_skill":	199,	// the maximum level you can learn
		"min_skill":    150
		]) );
	}
}