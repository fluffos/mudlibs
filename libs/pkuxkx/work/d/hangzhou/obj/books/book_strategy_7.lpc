//strategy第七本
inherit ITEM;
void create()
{
	set_name( "「神机制敌太白阴经」",({ "shenji jing", "book"}));
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "本");
		set("long","这是一部唐代宗时河东节度使都虞候李筌撰写的兵书。\n");
		set("value", 3000);
		set("material", "paper");
		set("Strategy_Book_Series",7); 
		set("skill", ([
	  	"name": "strategy",  //name of the skill
 		"exp_required": 20000 , //minimum combat experience required
		"jing_cost": 30 + random(30),// jing cost every time study this
		"difficulty":	30,	// the base int to learn this skill
		"max_skill":	199,	// the maximum level you can learn
		"min_skill":    160
		]) );
	}
}