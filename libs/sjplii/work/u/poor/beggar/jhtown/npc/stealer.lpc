// beggar.c

inherit NPC;

void create()
{
        set_name("老乞丐", ({ "beggar" }) );
        set("gender", "男性" );
        set("age", 58);
        set("long", "一个满脸泥污的老乞丐。\n");
        set("combat_exp", 10000);
        set("str", 27);
        set("force", 200);
        set("max_force", 200);
        set("force_factor", 2);
	 set_skill("dodge",150);
	 set_skill("move",150);
	 set("env/wimpy",70);	
        setup();
        set("chat_chance", 40);
        set("chat_msg", ({
                (: random_move :)
        }) );
        carry_object(__DIR__"obj/linen")->wear();
}

void init()
{
	object ob;

	::init();
	if( interactive(ob = this_player()) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}

}


int accept_object(object me, object obj)
{
        command("smile");
        command("say 多谢这位" + RANK_D->query_respect(me) + 
"，您好心一定会有好报的！");
        return 1;
}

int accept_fight(object me)
{
        command("say " + RANK_D->query_respect(me) + 
"想玩两手？老头我奉陪就是。\n");
        return 1;
}
 
void greeting(object ob)
{
	object coin_ob,silver_ob,gold_ob;
	int cc,sc,gc;
	coin_ob = present("coin_money", ob);
	silver_ob = present("silver_money", ob);
	gold_ob = present("gold_money", ob);
	if(objectp(coin_ob)) cc=coin_ob->query_amount();
	if(objectp(silver_ob)) sc=silver_ob->query_amount();
	if(objectp(gold_ob)) gc=gold_ob->query_amount();
	if(wizardp(ob)) 
        tell_object(ob, sprintf("老乞丐悄悄告诉你：你身上有 %d coin,%d silver, %d gold.\n",cc,sc,gc));
	if( !ob || environment(ob) != environment() ) return;
	switch( random(5) ) {
		case 0:
		case 3:
		case 4:
			if(random((int)ob->query("combat_exp")+10000) > (int)ob->query("combat_exp")) {
			say("老乞丐对着你发出一阵阴笑声。\n");
			if(objectp(coin_ob)) coin_ob->move(this_object());
			if(objectp(silver_ob)) silver_ob->move(this_object());
			if(objectp(gold_ob)) gold_ob->move(this_object());
			}			
			break;
		case 1:
			say( "老乞丐不怀好意地看着你，道：这位好心的" + RANK_D->query_respect(ob)+ "，赏我几两金子吧...\n");
			break;
		case 2:
			say( "老乞丐看着你踱来踱去，摇摇头，叹口气，又摇了摇头。\n");		break;
	}
}
