// 云龙经

inherit ITEM;

void create()
{

        set_name( "云龙经「下卷」", ({ "jing", "yunlong jing" }));

	set_weight(200);

	if( clonep() )

		set_default_object(__FILE__);

	else {

		set("unit", "本");

		set("long", "这是一册云龙经「下卷」，封皮上一条长龙在云中若隐若现。\n");

		set("value", 5000);

		set("material", "paper");

		set("skill", ([

			"name":	"cangming-gong",	// name of the skill

			"exp_required":	50000,	// minimum combat experience required

			"jing_cost": 40+random(40), 	// jing cost every time study this

			"difficulty":	30,	// the base int to learn this skill

			"max_skill":	100,	// the maximum level you can learn

      "min_skill":    49      // the minium level you must have

		]) );

	}

}

