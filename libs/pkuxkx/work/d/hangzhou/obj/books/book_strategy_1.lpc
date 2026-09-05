//strategy第一本
inherit ITEM;
void create()
{
	set_name( "「孙子注」",({ "sunzi zhu", "book"}));
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "本");
		set("long","这是一部三国时期曹操注释的十三篇孙子兵法。\n");
		set("value", 1000);
		set("material", "paper");
		set("Strategy_Book_Series",1); 
		set("skill", ([
	  	"name": "strategy",  //name of the skill
 		"exp_required": 0 , //minimum combat experience required
		"jing_cost": 10 + random(20),// jing cost every time study this
		"difficulty":	20,	// the base int to learn this skill
		"max_skill":	29,	// the maximum level you can learn
		]) );
	}
}