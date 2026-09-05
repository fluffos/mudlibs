//leadership第一本
inherit ITEM;
void create()
{
	set_name( "「大清律例」",({ "daqing lvli", "book"}));
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "本");
		set("long","这是一本朝廷官员的必备手册。\n");
		set("value", 5000);
		set("material", "paper");
		set("zijin",1); 
		set("skill", ([
	  	"name": "leadership",  //name of the skill
 		"exp_required": 0 , //minimum combat experience required
		"jing_cost": 10 + random(20),// jing cost every time study this
		"difficulty":	20,	// the base int to learn this skill
		"max_skill":	49	// the maximum level you can learn
		]) );
	}
}

