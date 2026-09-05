// bing.c 官兵

inherit NPC;

void create()
{
	set_name("右金吾卫将军", ({ "jin wu", "jiang" }));
	set("age", 22);
	set("gender", "男性");
	set("long", "金吾卫的将军，负责巡逻长安，治理长安的职责。\n");
	set("attitude", "peaceful");
	set("changan_bing",1);

	set("str", 28);
	set("dex", 20);
	set("combat_exp", 10000000);
  set("shen_type",1);
 	set("max_qi", 10000);
 	set("max_jing", 10000);
 	set("neili", 10000);
 	set("max_neili", 10000);
 	set("jiali", 150);

	set_skill("unarmed", 450);
	set_skill("hand",450);
	set_skill("dodge", 450);
	set_skill("parry", 450);
	set_skill("blade", 450);
	set_skill("force", 450);
	set_skill("halberd",450);
	set_skill("bixue-xinfa", 450);
	set_skill("kuangfeng-dao", 450);
	set_skill("longfeng-xiang", 450);
	set_skill("huzhua-shou", 450);
	set_skill("lujia-ji", 450);
	map_skill("force", "bixue-xinfa");
	map_skill("dodge", "longfeng-xiang");
	map_skill("parry", "huzhua-shou");
	map_skill("hand", "huzhua-shou");
	map_skill("blade", "kuangfeng-dao");
	map_skill("halberd", "lujia-ji");
	
	prepare_skill("hand", "huzhua-shou");
	set_temp("apply/attack", 150);
	set_temp("apply/defense", 150);
	set_temp("apply/damage", 150);
	set_temp("apply/armor", 150);

	setup();
	carry_object("/clone/weapon/fangtianji")->wield();
	carry_object(__DIR__"obj/mingguang-jia")->wear();
}

void init()
{
	object ob;
	::init();
	if (interactive(ob = this_player()) && 
		(int)ob->query_condition("cakiller")) {
		remove_call_out("kill_ob");
		call_out("kill_ob", 1, ob);
	}
}

int accept_fight(object me)
{
	command("say 大爷我正想找人杀呐，今天算你倒霉。\n");
	me->apply_condition("cakiller", 60);
	kill_ob(me);
	return 1;
}

void kill_ob(object ob)
{
	object wshi,*inv;
	int lp,ws;
	
	if ( time() - query("killer/"+ob->query("id")) > 60 )
	{
	  set("killer/"+ob->query("id"),time());
	  inv=all_inventory(environment(this_object()));
	  ws=0;
	  for(lp=0;lp<sizeof(inv);lp++)
	  {
	  	if ( inv[lp]->query("id")=="jin wu" )
	  		ws++;
	  }
	  
	  if ( ws < 16 )
	  {
	    message_vision("$N从远方招来了几个卫士。\n", this_object());
	    for(lp=0;lp<4;lp++)
	    {
		    wshi=new(__DIR__"jinwu-1");
		    wshi->move(environment(ob));
		    wshi->kill_ob(ob);
	    }
	  }
	}
	::kill_ob(ob);
}