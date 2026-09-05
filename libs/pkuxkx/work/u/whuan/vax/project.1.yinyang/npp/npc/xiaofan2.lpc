// xiaofan2.c ?

inherit NPC;

inherit F_DEALER;
                      
 
void greeting(object);
void create()
{
	set_name("小贩", ({ "xiao fan", "fan" }));
	set("title","专收废物");  
        create_family("峨嵋派",7,"记名弟子");
	set("shen_type", 0);

	set("gender", "女性");
	set_max_encumbrance(100000000);
	set("age", 35);
	set("long",
		"一个外出讨生活的老妇人。\n");
	set("no_get_from", 1);

	set_skill("unarmed", 60);
	set_skill("dodge", 60);
	set_temp("apply/attack", 30);
	set_temp("apply/attack", 30);
	set_temp("apply/damage", 15);

	set("combat_exp", 50000);
	set("attitude", "friendly");
	
	setup();
}

void init()                         
{                                   
        object ob;
        ob = this_player();
        ::init();
        remove_call_out("greeting");
        call_out("greeting", 1, ob);

        add_action("do_list", "list");
        add_action("do_steal","steal");
        add_action("do_buy", "buy");
	add_action("do_sell", "sell");
	add_action("do_value", "value");
        add_action("do_beg", "beg");
}
void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        say( "小贩快活地说道：这位" + RANK_D->query_respect(ob)
            + "，我这儿专收购大家不用的费物。\n");
         
}
void die()
{
	message_vision("\n$N死了。\n", this_object());
	destruct(this_object());
}
int do_steal()
{
    message_vision("这么穷的人你也好意思偷？\n",this_object());
    return 1;
}
int do_beg()
{
        write("这里不能乞讨！\n");
        return 1;
}
