// sword_book.c



inherit ITEM;



void create()

{

          set_name("浣花剑谱", ({ "sword book", "book" }));
	set_weight(600);

	if( clonep() )

		set_default_object(__FILE__);

	else {

		set("unit", "本");

                set("long", "这是一本浣花剑派的剑谱，书的封面已经发黄了，看起来已经保存了很多年了。\n");
		set("value", 0);

		set("material", "paper");

		set("skill", ([

"name":                 "huanhua-jian",          

			"exp_required":	1000,			// minimum combat experience required

											// to learn this skill.

			"jing_cost":		20,				// jing cost every time study this

			"difficulty":	20,				// the base int to learn this skill

											// modify is jing_cost's (difficulty - int)*5%

                          "max_skill":    30                              // the maximum level you can learn
											// from this object.

		]) );

	}

}

