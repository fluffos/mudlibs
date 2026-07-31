// master2.c

inherit NPC;
inherit F_MASTER;

void create()
{
        int i=random(2);
        set_name("林月光", ({ "master yue", "master", "yue" }) );
        set("class","jinghai");
        create_family("靖海派", 1, "创始人");

        set("gender", "女性" );
        set("age", 45);
        set("attitude", "peaceful");

        set("long", "这是一位眉清幕秀的中年女子，她就是靖
海派的创始人之一，靖海公的夫人。\n");

        set("combat_exp", 6500000);
        set("per", 29);
        set("str", 35);
        set("max_qi",35000);
        set("max_jing",35000);
        set("max_sen",35000);
        set("neili", 50000);
        set("max_neili", 50000);
        set("atman", 50000);
        set("max_atman", 50000);
        set("mana", 50000);
        set("max_mana", 50000);
        set("force_factor", 350);








        set_temp("apply/attack", 200);
        set_temp("apply/defense", 200);
        set_temp("apply/armor", 600);
        set_temp("apply/damage", 650);


        set_skill("demon-blade",380);
        set_skill("literate",380);
        set_skill("unarmed",380);
        set_skill("dodge",380);
        set_skill("parry",380);
	set_skill("force",380);
	set_skill("blade",380);
	set_skill("hand",380);
	set_skill("strike",380);
	set_skill("changquan",380);
 set_skill("sword",380);
        set_skill("luohua-jian",380);
        set_skill("feixian-sword",380);
        set_skill("bat-blade",380);
        set_skill("fengyu-piaoxiang",390);
set_skill("siqi-sword",380);
set_skill("sharen-sword",380);
set_skill("qinnashou",380);
set_skill("jingyiforce",380);
set_skill("jinghai-force",380);
set_skill("lingxiao-shou",380);
set_skill("panheng-zhang",380);
set_skill("xian-steps",380);
set_skill("longjiao-blade",380);
set_skill("bibo-sword",380);
set_skill("unarmed",380);
set_skill("dragonfight",380);
set_skill("club",380);
set_skill("fengbo-cha",380);

       map_skill("strike","panheng-zhang");
        map_skill("hand","lingxiao-shou");
        //map_skill("sword","bibo-sword");
if (i=0)
{       
        map_skill("blade","longjiao-blade");
}
else
{
 map_skill("club","fengbo-cha");
}

        map_skill("force","jinghai-force");
        map_skill("dodge","xian-steps");
        map_skill("parry","bibo-sword");
	//prepare_skill("strike", "panheng-zhang");
	//prepare_skill("hand", "lingxiao-shou");

map_skill("unarmed","dragonfight");
        set("chat_chance_combat", 99);
        set("chat_msg_combat", ({
                (: exert_function, "shield" :),
                (: exert_function, "powerup" :),
                (: exert_function, "roar" :),
                (: perform_action, "club.bibo" :),
                (: perform_action, "club.fengbo" :),
                (: perform_action, "club.yinhua" :),                     	
                (: perform_action, "blade.daoshen" :),
                (: perform_action, "blade.gobankiri" :),
                (: perform_action, "blade.jiu" :),	
                (: perform_action, "blade.longlianda" :),	
                (: perform_action, "blade.shiwanshenmo" :),	                	
                (: perform_action, "blade.suodi" :),	                	             	             
                    	
(: perform_action, "unarmed.jiuxian" :),	               
	(: perform_action, "unarmed.leidong" :),	               
(: perform_action, "unarmed.luanwu" :),	               
(: perform_action, "unarmed.sheshen" :),	               			
(: perform_action, "dodge.xian" :),	 
        }) );  

        setup();
if (i=0)
{ 
        carry_object("/d/feitian/npc/blackblade")->wield();
}
else
{
        carry_object(__DIR__"obj/jh_cha")->wield();	
}
 
        carry_object("/clone/misc/cloth")->wear();
carry_object("/d/jinghai/obj/key1");
}

void attempt_apprentice(object ob)
{
	if(ob->query("class") != "jinghai")
		return;

        if(ob->query("gender") == "男性")
        {
                command("say 妾身不收男弟子，去问问我相公吧。");
                return;
        }

	if(ob->query_skill("jingyiforce",1) < 200)
	{
		command("say 你的本门内功火候不够，回去练练再说吧。");
		return;
	}

        else
        {
                command("smile");
                command("say 很好，" + RANK_D->query_respect(ob) + "多加努力，他日必定有成。\n");
                command("recruit " + ob->query("id") );
        }
}

int recruit_apprentice(object ob)
{
        ::recruit_apprentice(ob);
        ob->set("class", "jinghai");
        return 1;
}

