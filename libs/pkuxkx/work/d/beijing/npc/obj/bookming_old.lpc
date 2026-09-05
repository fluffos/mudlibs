//leadership第二本(有金叶)
inherit ITEM;
void init()
{
        add_action("do_shake", "shake");
        add_action("do_shake", "doudong");
}
void create()
{
        set_name("「明书辑略」", ({"mingshu jilue", "book"}));
        set_weight(1200);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "据说此书为“湖州三宝”之一，想必读来大有益处。\n");
                set("unit", "本");
		set("value", 10000);                
                set("material", "paper");
                set("no_store",1);
                set("no_pawn",1);
                set("no_sell",1);
                set("zijin",1); 
                set("leaf", 1 + random(3));
		set("skill", ([
	  	"name": "leadership",  //name of the skill
 		"exp_required": 10000 , //minimum combat experience required
		"jing_cost": 20 + random(20),// jing cost every time study this
		"difficulty":	25,	// the base int to learn this skill
		"max_skill":	99,	// the maximum level you can learn
		"min_skill":    50
		]) );                
        }
        setup();
}
int do_shake(string arg)
{
	object me,goldleaf,book;
	me = this_player();
        if( !arg || arg=="" ) return 0;
        if( arg == "book" || arg == "mingshu jilue") 
	{
		if(query("leaf"))
		{
		message("vision","突然，一片金叶从书中掉了出来，不知道书里还有没有更多的金叶。\n",environment(me));
                goldleaf = new(__DIR__"goldleaf");
                goldleaf->move(environment(me));
                add("leaf", -1);
        	}
        	if (!query("leaf"))
        	{
                book = new(__DIR__"book_jilue");
                book->move(me);
                destruct(this_object());
        	}
        }
	return 1;
}
