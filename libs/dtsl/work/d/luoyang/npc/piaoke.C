
inherit NPC;

void create()
{
   set_name("嫖客",({ "piao ke","piao","ke" }) );
        set("gender", "男性" );
        set("age", 30);
   set("long", "这是一个雄性激素分泌过剩的哺乳动物。\n");
       
   set("combat_exp", 50);
   set("str", 10);
   set("per", 0);
   set("attitude", "friendly");
   setup();
   carry_object(__DIR__"obj/cloth")->wear();
  
}

void init()
{
	object ob;
	ob=this_player();
	
	if(!ob||is_fighting()) return;
	remove_call_out("welcome");
	call_out("welcome",1,ob);
	
}

void welcome(object ob)
{
   if(!ob) return;
   if(environment(ob)!=environment(this_object()))
   return;
	switch(random(2))
	{
	case 0:
	command("say 不愧是曼清院服务一流啊。");
	break;
	
	case 1:
	command("say 要是能一亲秀芳大家的芳泽就是杀了我也愿意！");
	}
	
}
