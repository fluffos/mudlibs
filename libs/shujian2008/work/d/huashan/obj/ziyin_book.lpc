// ITEM: /d/huashan/obj/ziyin_book_1.c
// Date: Look 99/03/25

inherit ITEM;

void create()
{
    set_name("紫氤吟", ({ "ziyin yin", "book", "ziyin" }));
	set_weight(200);
	set("unit", "册");
	set("long", "这是一册紫氤吟，上面画满了各种打坐吐呐的姿势。\n");
//	set("treasure",1);
    set("value", 50);
	set("material", "paper");
	set("skill", ([
			"name":	"ziyin-yin",	// name of the skill
			"exp_required":	5000,	// minimum combat experience required
            "jing_cost": 30+random(25),// jing cost every time study this
			"difficulty":   20, // the base int to learn this skill
			"max_skill":	120	// the maximum level you can learn
		      ]) );
}
