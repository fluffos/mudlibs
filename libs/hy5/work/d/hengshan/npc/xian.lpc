// xian.c
inherit NPC;
inherit F_MASTER;
#include <ansi.h>;
void create()
{
        set_name("定闲师太", ({ "dingxian shitai", "shitai", "dingxian" }) );
        set("gender", "女性");
        set("title", HIB"恒山派第十三代掌门"NOR);
        set("class", "bonze");
        set("age", 45);
        set("attitude", "peaceful");
        set("per", 24);
        set("str", 26);
        set("con", 30);
        set("dex", 30);
        set("int", 28);
set("pubmaster",1);
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
        set_skill("hengshan-jian", 320);


        map_skill("sword", "hengshan-jian");
        map_skill("parry", "hengshan-jian");
        map_skill("dodge", "lingxu-bu");
set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
    (: perform_action, "sword.shenfeng" :),
    (: perform_action, "sword.shenfeng" :),
 }) );

        create_family("恒山派", 13, "掌门");
        setup();

        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/d/shaolin/obj/xuan-cloth")->wear();
}

int accept_object(object who, object ob)
{
	int i;

	if (!(int)who->query_temp("learn_timef"))      
		who->set_temp("learn_timef", 0);

	if( !ob->query("money_id") )
		return 0;		


	if(who->query_skill("hengshan-jian",1)<30)
		i=ob->value() / 50;
	else
	{
		if(who->query_skill("hengshan-jian",1)<60)
			i=ob->value() / 100;
		else
		{
			if(who->query_skill("hengshan-jian",1)<100)
				i=ob->value() / 150;
			else
				i=ob->value() / 300;
		}
	}
	who->add_temp("learn_timef",i);

      message_vision("定闲师太对$N说道：既然你诚心想学我的武功，我就成全成全你吧。\n",who);

	return 1;
}

int recognize_apprentice(object ob)
{
	if( ob->query_temp("learn_timef") <= 0) return 0;
else         
ob->add_temp("learn_timef",-1);
return 1;
}
