//strategy第四本
inherit ITEM;
void create()
{
	set_name( "「孙膑兵法」",({ "sunbin bingfa", "book"}));
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "本");
		set("long","这是一部战国时期杰出的军事家孙膑及其弟子撰写的兵书。\n");
		set("value", 5000);
		set("material", "paper");
		set("zijin",1); 
		set("skill", ([
	  	"name": "strategy",  //name of the skill
 		"exp_required": 15000 , //minimum combat experience required
		"jing_cost": 25 + random(30),// jing cost every time study this
		"difficulty":	28,	// the base int to learn this skill
		"max_skill":	119,	// the maximum level you can learn
		"min_skill":    90
		]) );
	}
}