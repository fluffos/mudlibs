//strategy第二本
inherit ITEM;
void create()
{
	set_name( "「三十六计」",({ "sanshiliu ji", "book"}));
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "本");
		set("long","三十六计是我国兵法大家们的经验总结。\n共分胜战计、敌战计、攻战计、混战计、并战计、败战计。\n");
		set("value", 25000);
		set("material", "paper");
		set("Strategy_Book_Series",2); 
		set("skill", ([
	  	"name": "strategy",  //name of the skill
 		"exp_required": 5000 , //minimum combat experience required
		"jing_cost": 10 + random(30),// jing cost every time study this
		"difficulty":	22,	// the base int to learn this skill
		"max_skill":	69,	// the maximum level you can learn
		"min_skill":    30
		]) );
	}
}