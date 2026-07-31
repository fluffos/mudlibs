// ITEM: /d/huashan/obj/ziyin_book_2.c
// Date: Look 99/03/25

inherit ITEM;

void create()
{
	set_name("紫氤吟下册", ({ "ziyin yin", "book" }));
	set_weight(200);
	set("unit", "册");
	set("long", "这是一册紫氤吟下册，上面画满了各种打坐吐呐的姿势。\n");
//	set("treasure",1);
	set("value", 3000);
        set("unique", 1);
	set("material", "paper");
	set("skill", ([
			"name":	"ziyin-yin",	// name of the skill
			"exp_required":	1000,	// minimum combat experience required
			"jing_cost": 20+random(15),// jing cost every time study this
			"difficulty":	25,	// the base int to learn this skill
			"max_skill":	100	// the maximum level you can learn
		      ]) );
}
