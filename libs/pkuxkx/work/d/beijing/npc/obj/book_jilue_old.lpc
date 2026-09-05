//leadership第二本(无金叶)
inherit ITEM;
void create()
{
	set_name( "「明书辑略」",({ "mingshu jilue", "book"}));
	set_weight(1200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "本");
		set("long", "据说此书为“湖州三宝”之一，想必读来大有益处。\n");
		set("value", 10000);
		set("material", "paper");
		set("zijin",1); 
		set("skill", ([
	  	"name": "leadership",  //name of the skill
 		"exp_required": 10000 , //minimum combat experience required
		"jing_cost": 20 + random(20),// jing cost every time study this
		"difficulty":	25,	// the base int to learn this skill
		"max_skill":	99,	// the maximum level you can learn
		"min_skill":    50
		]) );
	}
}
void init()
{
        add_action("do_shake", "shake");
        add_action("do_shake", "doudong");
}
int do_shake(string arg)
{
	object me = this_player();
        if( !arg || arg=="" ) return 0;
        if( arg == "book" || arg == "mingshu jilue") 	
	tell_object(me, "不管你怎么抖，再没金叶了。\n");
	return 1;
}
