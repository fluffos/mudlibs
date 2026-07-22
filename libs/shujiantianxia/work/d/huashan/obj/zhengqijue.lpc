// ITEM: /d/huashan/obj/zhengqijue.c
// Date: Look 99/03/25

inherit ITEM;

void create()
{
	set_name( "正气诀要", ({ "shu", "book" }));
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "本");
		set("long", "这是一册华山派正气诀上册。上面画满了各种打坐吐呐的姿势。\n");
        set("value", 50);
		set("material", "paper");
		set("skill", ([
			"name":	"zhengqi-jue",	// name of the skill
			"exp_required":	0,	// minimum combat experience required
			"jing_cost":	10+random(20),	// jing cost every time study this
			"difficulty":	20,	// the base int to learn this skill
			"max_skill":	120	// the maximum level you can learn
		]) );
	}
}
