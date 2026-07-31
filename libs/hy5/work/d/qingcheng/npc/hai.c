// yu.c

inherit NPC;
//inherit F_SKILL;

void create()
{
        set_name("余沧海", ({ "yu canghai", "yu", "canghai" }));
        set("gender", "男性");
        set("age", 52);
        set("long", "他身形矮小，可是神情凝重，俨然一派大宗师气。\n");
        set("class", "taoist");

        set("combat_exp", 6800000);
        set("shen_type", -1);
set("pubmaster",1);
        set("max_qi", 3500);
        set("jing", 2000);
        set("max_jing", 2000);
        set("neili", 3500);
        set("max_neili", 3500);
        set("jingli", 2000);
        set("max_jingli", 1000);

        set_skill("sword", 280);
        set_skill("pixie-sword", 280);
        set_skill("unarmed", 180);
        set_skill("dodge", 180);
        set_skill("parry", 180);
        set_skill("blade", 180);
        set("neili", 12000);
        set("max_neili", 12000);
        set("jiali", 30);
        set("max_qi",12000);
        set("max_jing",11200);
        set("combat_exp", 6000000);
        set_skill("unarmed", 220);
        set_skill("sword", 220);
        set_skill("force", 220);
        set_skill("parry", 220);
        set_skill("dodge", 220);
        set_skill("lingxu-bu", 220);
	set_temp("apply/attack", 200);
	set_temp("apply/defense", 200);
	set_temp("apply/armor", 200);
	set_temp("apply/damage", 200);        
        set_skill("liuhe-dao", 300);
        map_skill("parry", "liuhe-dao");
        map_skill("blade", "liuhe-dao");
 set("chat_chance_combat", 40);
        set("chat_msg_combat", ({
    (: perform_action, "blade.lianhuan" :),
    (: perform_action, "blade.lianhuan" :),
 }) );

        create_family("青城派", 7, "掌门");
        setup();
        carry_object("/clone/weapon/gangdao")->wield();
        carry_object("/d/wudang/obj/bluecloth")->wear();
}


int accept_object(object who, object ob)
{
	int i;

	if (!(int)who->query_temp("learn_timeb"))      
		who->set_temp("learn_timeb", 0);

	if( !ob->query("money_id") )
		return 0;		


	if(who->query_skill("liuhe-dao",1)<30)
		i=ob->value() / 50;
	else
	{
		if(who->query_skill("liuhe-dao",1)<60)
			i=ob->value() / 100;
		else
		{
			if(who->query_skill("liuhe-dao",1)<100)
				i=ob->value() / 150;
			else
				i=ob->value() / 300;
		}
	}
	who->add_temp("learn_timeb",i);

      message_vision("余沧海对$N说道：既然你诚心想学我的武功，我就成全成全你吧。\n",who);

	return 1;
}

int recognize_apprentice(object ob)
{
	if( ob->query_temp("learn_timeb") <= 0) return 0;
else         
ob->add_temp("learn_timeb",-1);
return 1;
}
