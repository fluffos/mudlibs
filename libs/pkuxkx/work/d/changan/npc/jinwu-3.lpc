// bing.c 官兵

inherit NPC;

void create()
{
	set_name("右金吾卫郎将", ({ "jin wu", "jiang" }));
	set("age", 22);
	set("gender", "男性");
	set("long", "金吾卫的郎将，负责巡逻长安，治理长安的职责。\n");
	set("attitude", "peaceful");
	set("changan_bing",1);

	set("str", 28);
	set("dex", 20);
	set("combat_exp", 3000000);
  set("shen_type",1);
 	set("max_qi", 5000);
 	set("max_jing", 5000);
 	set("neili", 5000);
 	set("max_neili", 5000);
 	set("jiali", 100);

	set_skill("unarmed", 300);
	set_skill("hand",300);
	set_skill("dodge", 300);
	set_skill("parry", 300);
	set_skill("blade", 300);
	set_skill("force", 300);
	set_skill("halberd",300);
	set_skill("bixue-xinfa", 300);
	set_skill("kuangfeng-dao", 300);
	set_skill("longfeng-xiang", 300);
	set_skill("huzhua-shou", 300);
	set_skill("lujia-ji", 300);
	map_skill("force", "bixue-xinfa");
	map_skill("dodge", "longfeng-xiang");
	map_skill("parry", "huzhua-shou");
	map_skill("hand", "huzhua-shou");
	map_skill("blade", "kuangfeng-dao");
	map_skill("halberd", "lujia-ji");
	
	prepare_skill("hand", "huzhua-shou");
	set_temp("apply/attack", 100);
	set_temp("apply/defense", 100);
	set_temp("apply/damage", 100);
	set_temp("apply/armor", 100);

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
	    for(lp=0;lp<2;lp++)
	    {
		    wshi=new(__DIR__"jinwu-1");
		    wshi->move(environment(ob));
		    wshi->kill_ob(ob);
	    }
	  }
	}
	::kill_ob(ob);
}