//strategy第八本
inherit ITEM;
void create()
{
	set_name( "「守城录」",({ "shoucheng lu", "book"}));
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "本");
		set("long","这是一部宋初陈规、汤璹编写的侧重城邑防御的专著。\n");
		set("value", 3000);
		set("material", "paper");
		set("Strategy_Book_Series",8); 
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