//strategy第六本
inherit ITEM;
void create()
{
	set_name( "「诸葛亮兵法」",({ "zhugeliang bingfa", "book"}));
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "本");
		set("long","这是一部记录诸葛武侯一生用兵之道的兵书。\n");
		set("value", 3000);
		set("material", "paper");
		set("Strategy_Book_Series",6);  
		set("no_fullme_no_get","这本书还是留待有缘人来取吧。");
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