//一个可以指导崆峒弟子武功的NPC，可以看作是神仙的化身。
//行踪无定，而且很少出现。
// Qyz

inherit F_UNIQUE;
inherit NPC;



void create()
{
        set_name("无名高手", ({ "gao shou","gaoshou" }) );
        set("title","");
        set("gender", "男性" );
        set("age", 110);
        set("cor", 40);
        set("cps", 40);
        set("per", 40);
        set("int", 40);
        set("chat_chance", 10);
        set("chat_msg", ({
                    (: random_move :)
                    }) );

        set("attitude", "friendly");
        set("can_teach",1); 
   set("combat_exp", 1000000);
        set("str", 55);
        set("max_qi",5000);
        set("max_jing",5000);
        set("max_sen",5000);
        set("neili", 10000);
        set("max_neili", 10000);
        set("atman", 10000);
        set("max_atman", 50000);
        set("mana", 50000);
        set("max_mana", 50000);
        set("force_factor", 350);




set_skill("jinshe-jian",250);
set_skill("liancheng-jian",250);
set_skill("hujia-daofa",250);
set_skill("demon-strike",250);
set_skill("nine-moon-claw",250);
set_skill("ill-quan",250);
set_skill("doomstrike",250);
set_skill("luoriquan",250);
set_skill("qinnashou",250);
set_skill("taixuan-gong",250);

        set_temp("apply/attack", 200);
        set_temp("apply/defense", 200);
        set_temp("apply/armor", 600);
        set_temp("apply/damage", 650);
        set_skill("jingyiforce",250);
        set_skill("demon-blade",280);
        set_skill("literate",250);
        set_skill("unarmed",250);
        set_skill("dodge",290);
        set_skill("parry",250);
	set_skill("force",250);
	set_skill("blade",250);
	set_skill("changquan",250);
        //set_skill("doomsword",250);
        //set_skill("chilian-shenzhang",250);
        //set_skill("softsword",280);
        //set_skill("nine-moon-sword",250);
        set_skill("luohua-jian",250);
        set_skill("sword",250);
        set_skill("feixian-sword",250);
        set_skill("bat-blade",250);
        set_skill("fengyu-piaoxiang",390);

        map_skill("unarmed","changquan");
        map_skill("sword","jinshe-jian");
        map_skill("force","taixuan-gong");
        map_skill("dodge","fengyu-piaoxiang");
        map_skill("parry","liancheng-jian");
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: exert_function, "hun" :),
                (: exert_function, "jing" :),
                (: exert_function, "po" :),
                (: exert_function, "taixuan" :),		
                (: exert_function, "xuan" :),			
                (: perform_action, "unarmed.yuhuan" :),
                (: perform_action, "sword.kuangwu" :),
                (: perform_action, "sword.wan" :),
                (: perform_action, "sword.kun" :),	
                (: perform_action, "sword.shi" :),	
                (: perform_action, "sword.suo" :),	                	
                (: perform_action, "parry.ci" :),
                (: perform_action, "parry.erguang" :),
(: perform_action, "parry.gan" :),
(: perform_action, "parry.qian" :),
(: perform_action, "parry.qu" :),		             
(: perform_action, "parry.zhai" :),		             
(: perform_action, "parry.zhu" :),		             	             
(: perform_action, "dodge.zonghengsihai" :),		             	             
(: perform_action, "dodge.zonghengsihai" :),		             	              
        }) );
        set("force", 10000);
        set("force_factor",1000);



        set("combat_exp", 5999999);


        set("positive_score",10000);
        setup();

        carry_object("/clone/misc/cloth")->wear();
        carry_object("/clone/weapon/gangjian")->wield();
}


