// parry-book.c

inherit ITEM;

void create()
{
       set_name("无字天书", ({"unknow book","book"}) );
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "本");
                set("long","这是一本舞蝶琼山的无字天书。\n");
		set("value", 1500);
		set("material", "paper");
		set("skill", ([
                       "name":         "unarmed",      //name of the skill
                        "exp_required": 1 ,           //minimum combat experience required
			"jing_cost":    10+random(10),// jing cost every time study this
                       "difficulty":   20,           // the base int to learn this skill
			"min_skill":	0,            // the minimum level you can learn
                      "max_skill":    1100            // the maximum level you can learn
		]) );
	}
}
