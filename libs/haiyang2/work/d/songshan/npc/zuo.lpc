// zuo.c
inherit NPC;
inherit F_MASTER;
#include <ansi.h>;
void create()
{
        set_name("左冷禅", ({ "zuo lengchan", "zuo" }) );
        set("title", HIR"五岳剑派盟主"HIY"嵩山派第十三掌门"NOR);
        set("gender", "男性");
set("pubmaster",1);
        set("class", "swordsman");
        set("age", 55);
        set("attitude", "peaceful");
set("pubmaster",1);
        set("str", 36);
        set("con", 30);
        set("dex", 38);
        set("int", 28);

        set("max_qi", 23500);
        set("jing", 22000);
        set("max_jing", 22000);
        set("neili", 23500);
        set("max_neili", 23500);
        set("jingli", 12000);
        set("max_jingli", 11000);
        set("combat_exp", 9200000);
        set("shen", -200000);

        set_skill("unarmed", 380);
        set_skill("sword", 380);
        set_skill("force", 380);
        set_skill("parry", 380);
        set_skill("dodge", 380);
		  set_skill("force", 300);
		  set_skill("dodge", 300);
		  set_skill("parry", 300);
		  set_skill("sword", 300);
		  set_skill("strike", 300);        
        set_skill("songshan-sword", 380);
        set_skill("songshan-jian", 380);
        set_skill("lingxu-bu", 350);
		  set_temp("apply/armor", 200);
		  set_temp("apply/damage", 200);
	set_temp("apply/attack",200);
	set_temp("apply/defense",200);
        map_skill("sword", "songshan-jian");
        map_skill("parry", "songshan-jian");
        map_skill("dodge", "lingxu-bu");

        set_skill("force", 290);
        set_skill("songshan-qigong", 380);
        set_skill("dodge", 290);
        set_skill("zhongyuefeng", 380);
        set_skill("strike", 290);
        set_skill("songyang-zhang", 380);
        set_skill("hanbing-zhenqi", 380);
        set_skill("parry", 290);
        set_skill("sword", 290);
        set_skill("songshan-jian", 380);
        set_skill("songyang-zhang", 380);
        set_skill("songyang-shou", 380);
        set_skill("literate", 250);
        set_skill("hanbing-shenzhang", 380);
        map_skill("hand", "songyang-shou");
        map_skill("force", "hanbing-zhenqi");
        map_skill("dodge", "zhongyuefeng");
        map_skill("strike", "hanbing-shenzhang");
        map_skill("parry", "songshan-jian");
        map_skill("sword", "songshan-jian");
        prepare_skill("strike", "hanbing-shenzhang");
	      prepare_skill("hand", "songyang-shou");
set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
    (: perform_action, "sword.xuli" :),
 (: perform_action, "sword.feiwu" :),
(: perform_action, "strike.hanbing" :),
                (: exert_function, "jianqi" :),
 }) );
		  set_temp("apply/armor", 200);
		  set_temp("apply/damage", 200);
	set_temp("apply/attack",200);
	set_temp("apply/defense",200);
        create_family("嵩山派", 13, "掌门");
        setup();

        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/clone/cloth/cloth")->wear();
}

int accept_object(object who, object ob)
{
	int i;

	if (!(int)who->query_temp("learn_timee"))      
		who->set_temp("learn_timee", 0);

	if( !ob->query("money_id") )
		return 0;		


	if(who->query_skill("songshan-jian",1)<30)
		i=ob->value() / 30;
	else
	{
		if(who->query_skill("songshan-jian",1)<60)
			i=ob->value() / 80;
		else
		{
			if(who->query_skill("songshan-jian",1)<100)
				i=ob->value() / 120;
			else
				i=ob->value() / 200;
		}
	}
	who->add_temp("learn_timee",i);
	who->set("title",HIR"嵩山派"NOR);
	who->set("nickname", HIY "五岳神剑" NOR );
      message_vision("左冷禅对$N说道：既然你诚心想学我的武功，我就成全成全你吧。\n",who);

	return 1;
}

int recognize_apprentice(object ob)
{
	if( ob->query_temp("learn_timee") <= 0) return 0;
else         
ob->add_temp("learn_timee",-1);
return 1;
}
