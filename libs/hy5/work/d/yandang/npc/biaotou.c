// biaotou.c 财主管家

inherit NPC;

void create()
{
	set_name("镖头", ({ "biao tou", "biao" }));
	set("gender", "男性");
	set("age", 35);

	set("combat_exp", 50000);
	set("shen_type", 1);

	set_skill("unarmed", 100);
	set_skill("blade", 100);
	set_skill("parry", 100);
	set_skill("dodge", 100);
	
	set_temp("apply/attack", 15);
	set_temp("apply/defense", 15);
	set_temp("apply/damage", 20);

	setup();
	carry_object("/clone/weapon/gangdao")->wield();
	carry_object("/clone/misc/cloth")->wear();
}
void init()
{
	::init();
	add_action("do_get","get");
	add_action("do_steal","steal");
}
int do_get(string arg)
{
	object me,obj;
	string from,item;
	me=this_player();
	if(!arg)	return 0;
	if(sscanf(arg, "%s from %s", arg, from)==2)
	{
		if(from=="biaoche"||from=="che"||from=="biao")	{
		command("say 大胆强盗,光天化日之下,竟敢拦路抢劫！\n");
                      call_out("kill_ob", 1, me); 
		return 1;
		}
	return 0;
  }
return 0;
}
int do_steal(string arg)
{
	object me;
	string from;
	me=this_player();
	if(!arg)	return 0;
	if(sscanf(arg,"%s from %s",arg,from)==2)	{
		if(from=="biaoche"||from=="che"||from=="biao")	{
		command("say 大胆恶贼,居然老虎嘴边拔毛,我看你活得不耐烦了！\n");
        call_out("kill_ob", 1, me); 
return 1;
	}
return 0;
   }
	return 0;
}
	
