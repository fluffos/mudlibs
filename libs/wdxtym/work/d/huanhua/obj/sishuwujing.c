inherit ITEM;

void create()
{
        set_name( "四书五经", ({ "book","shu" }));
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "本");
                set("long", "这是一本四书五经，是读书识字的初级课本。\n");
		set("value", 500);
		set("material", "paper");
		set("skill", ([
			"name":	"literate",	
                        "exp_required": 0,     // minimum combat experience required
			"jing_cost": 5, 	// jing cost every time study this
			"difficulty":	20,	// the base int to learn this skill
                        "max_skill":    30,     // the maximum level you can learn
		]) );
	}
}
