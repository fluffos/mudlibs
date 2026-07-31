// moda.c
inherit NPC;
inherit F_MASTER;
#include <ansi.h>;
void create()
{
        set_name("莫大", ({ "mo da", "mo" }) );
        set("title", HIR"衡山派第十三掌门"NOR);
        set("nickname", "潇湘夜雨");
        set("gender", "男性");
        set("class", "swordsman");
        set("age", 55);
set("pubmaster",1);
        set("attitude", "peaceful");
        set("per", 22);
        set("str", 26);
        set("con", 30);
        set("dex", 30);
        set("int", 28);

        set("max_qi", 3500);
        set("jing", 2000);
        set("max_jing", 2000);
        set("neili", 3500);
        set("max_neili", 3500);
        set("jingli", 2000);
        set("max_jingli", 1000);
        set("combat_exp", 1200000);
        set("shen_type", 1);

        set_skill("unarmed", 150);
        set_skill("sword", 150);
        set_skill("force", 150);
        set_skill("parry", 150);
        set_skill("dodge", 150);
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
        set_skill("luoyan-jian", 320);
        set_skill("hengshan-sword", 320);
        set_skill("lingxu-bu", 320);

        map_skill("sword", "luoyan-jian");
        map_skill("parry", "luoyan-jian");
        map_skill("dodge", "lingxu-bu");
set("chat_chance_combat", 40);
        set("chat_msg_combat", ({
    (: perform_action, "sword.yunwu" :),
    (: perform_action, "blade.yunwu" :),
 }) );
        create_family("衡山派", 13, "掌门");
        setup();

        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/clone/cloth/cloth")->wear();
}

int accept_object(object who, object ob)
{
	int i;

	if (!(int)who->query_temp("learn_timec"))      
		who->set_temp("learn_timec", 0);

	if( !ob->query("money_id") )
		return 0;		


	if(who->query_skill("luoyan-jian",1)<30)
		i=ob->value() / 50;
	else
	{
		if(who->query_skill("luoyan-jian",1)<60)
			i=ob->value() / 100;
		else
		{
			if(who->query_skill("luoyan-jian",1)<100)
				i=ob->value() / 150;
			else
				i=ob->value() / 300;
		}
	}
	who->add_temp("learn_timec",i);

      message_vision("莫大对$N说道：既然你诚心想学我的武功，我就成全成全你吧。\n",who);

	return 1;
}

int recognize_apprentice(object ob)
{
	if( ob->query_temp("learn_timec") <= 0) return 0;
else         
ob->add_temp("learn_timec",-1);
return 1;
}
