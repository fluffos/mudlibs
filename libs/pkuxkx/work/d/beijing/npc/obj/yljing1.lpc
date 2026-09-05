// 云龙经

inherit ITEM;

void create()
{

	set_name( "云龙经「上卷」", ({"yunlong jing" , "jing"}));

	set_weight(200);

	if( clonep() )

		set_default_object(__FILE__);

	else {

		set("unit", "本");

		set("long", "这是一册云龙经「上卷」，封皮上一条长龙在云中若隐若现。\n");

		set("value", 5000);

		set("material", "paper");

		set("skill", ([

			"name":	"cangming-gong",

			"exp_required":	10000,	// minimum combat experience required

			"jing_cost": 20 + random(30), 	// jing cost every time study this

			"difficulty":	25,	// the base int to learn this skill

			"max_skill":	50,	// the maximum level you can learn
      
      "min_skill":    25,     // the min level you can learn

		]) );

	}

}

