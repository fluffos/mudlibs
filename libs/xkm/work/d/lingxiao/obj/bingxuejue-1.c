//Cracked by Roath
// bingxuejue-i.c

inherit ITEM;

void create()
{
        set_name( "冰雪诀上册", ({ "bingxue jue", "book" ,"jue" }));
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "本");
                set("long", "这是一册提高冰雪心法初级入门的秘籍。\n");
		set("value", 200);
		set("material", "paper");
		set("skill", ([
                        "name": "bingxue-jue",       // name of the skill
			"exp_required":	0,	// minimum combat experience required
                        "jing_cost": 15+random(15),        // jing cost every time study this
			"difficulty":	20,	// the base int to learn this skill
			"max_skill":	50,	// the maximum level you can learn
		]) );
	}
}
