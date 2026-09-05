// monkey.c 

inherit NPC;

void create()
{
	set_name("猴子", ({ "monkey" }) );
	set("gender", "男性");
	set("age", 25);
	set("long",
		"这只猴子好可爱啊。\n");
	set("combat_exp", 10000);
        set("shen_type", -1);
	set("attitude", "peaceful");
	
	set("water", 200);
	set("food", 200);

	set("apply/attack", 20);
	set("apply/defense", 20);

//	set("chat_chance", 30);
//	set("chat_msg", ({
//		"我家大王叫我来拿你这小子的臭命 !\n",
//	}) );

	set_skill("unarmed", 35);
	set_skill("parry", 35);
	set_skill("dodge", 35);

	setup();

}
         void init()
{	
	object ob;
	::init();
 	if(interactive(ob = this_player())&&(ob->query("race")!="野兽"))
        {
	command("say 竟敢闯入我们猴子的住地。\n");
	 remove_call_out("do_killing");
	 call_out("kill_ob",0,ob);}
}
	void do_killing(object ob)
{
	if(!ob||environment()!=environment(ob))
	{
	return;
	this_object()->kill_ob(ob);
	}
}

	
