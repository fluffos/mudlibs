// gui_nu.c

inherit NPC;

void create()
{
	set_name("龟奴", ({ "gui nu" }) );
	set("gender", "男性" );
	set("age", 38);
	set("long",
		"他是畅春园护场子的龟奴。\n");
	set("combat_exp", 100);
	set("attitude", "friendly");
	set("class","jiyuan");

	set("per",20);
	set("str",30);
	set("con",30);
	set("max_force",1000);
	set("force",1000);
	set("force_factor",5);
	set("max_atman",2000);
	set("atman",2000);
	set("max_mana",2000);
	set("mana",2000);
	set("max_kee",1200);
	set("max_gin",1000);
	set("max_sen",1000);

	set_skill("force",20);
	set_skill("dodge",20);
	set_skill("parry",20);
	set_skill("unarmed",200);
	setup();
	carry_object("/clone/misc/cloth")->wear();
}

void init()
{	
	object ob;

	::init();
	if( interactive(ob = this_player()) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
//	add_action("do_killing","kill");
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;

	if(ob->query("gender") == "男性") {
		if(ob->query_temp("jiyuan/order"))
			message_vision( "龟奴冲着$N点头哈腰：这位爷到我们这来保证爽透。\n",ob);
		else
			message_vision( "龟奴冲着$N点头哈腰：这位爷不摆一桌花酒好好玩玩？\n",ob);
	}
	if(ob->query("gender") == "女性" ){
		if(ob->query("age") <= 22)
			message_vision( "龟奴对$N微笑道：这位" + RANK_D->query_respect(ob)
				+ "想到我们这里铺床铺吗？我们这生意最好了。\n",ob);
		else
			message_vision( "龟奴冲着$N笑道：用不用请个小生陪陪您？\n",ob);
	}
}
/*
int do_killing(string arg)
{
	object obj,player = this_player();
	if(objectp(obj = present(arg,environment())) && living(obj))
	{
		if(obj->query("class") == "jiyuan")
			{
			message_vision("$N喊道：敢跑这来撒野，难道不想活了！！\n",this_object());
			set("combat_exp",2000000);
			set_skill("force",200);
			set_skill("dodge",200);
			set_skill("parry",200);
			set_skill("unarmed",200);
			set("force_factor",100);
			player->delete_temp("jiyuan");
			this_object()->kill_ob(player);
			player->kill_ob(this_object());
			if(obj = present("m_boss",find_object("/d/tianshui/jiyuan2")))
				obj->delete_temp("have_full");
			return 0;
			}
		return 0;
	}
	return 0;
}

int heal_up()
{
	if( environment() && !is_fighting() )
	{
		set("combat_exp",100);
		set_skill("force",20);
		set_skill("dodge",20);
		set_skill("parry",20);
		set_skill("unarmed",20);
		set("force_factor",5);
		return 1;
	}
	return ::heal_up() + 1;
}
*/