

inherit ITEM;



void create()

{

set_name( "丹心剑谱「上册」",({ "danxin jianpu", "jianpu", "shu", "book"}));

	set_weight(200);

	if( clonep() )

		set_default_object(__FILE__);

	else {

		set("unit", "本");

		set("long","这是一本碧血丹心剑总诀，封皮上一条长龙在云中若隐若现。\n");

		set("value", 1000);

		set("material", "paper");

		set("skill", ([

  		"name": "danxin-jian",  //name of the skill

 		"exp_required": 10000 , //minimum combat experience required

		"jing_cost": 20+random(20),// jing cost every time study this

		"difficulty":	30,	// the base int to learn this skill

		"max_skill":	70	// the maximum level you can learn

		]) );

	}

}

