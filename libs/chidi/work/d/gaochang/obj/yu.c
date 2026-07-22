// book4.c
inherit ITEM;
void create()
{
    set_name("玉简", ({ "yu", "yu jian"}));
    set_weight(500);
    if( clonep() )
        set_default_object(__FILE__);
    else {
        set("unit", "块");
        set("long",
            "                   玉简\n\n"
            "这是一块刻满线条的玉简。\n");
        set("value", 500);
        set("material", "stone");
        set("no_sell",1);
        set("skill", ([
            "name": "axe",  // name of the skill
            "exp_required": 0,  // minimum combat experience required
            "jing_cost":    10, // jing cost every time study this
            "difficulty":   20, // the base int to learn this skill
            "max_skill":    49  // the maximum level you can learn
        ]) );
    }
}
void init()
{
    add_action("do_break","break");
}
int do_break(string arg)
{
     object ob,me;
     me = this_player();
	if( !arg || !id(arg) )
        return notify_fail("你想摔什么？\n");
        if (environment()==this_player()){
      		message_vision("$N将玉简往地上一摔。\n", this_player());
	  	ob=new("/d/gaochang/obj/suiyu");
	  	ob->move(environment(environment()));
	  	me->set_temp("break_suiyu",1);
		destruct(this_object());
		return 1;
    	}else
       	return notify_fail("玉简不在你身上怎么摔呀。\n");
	
}
