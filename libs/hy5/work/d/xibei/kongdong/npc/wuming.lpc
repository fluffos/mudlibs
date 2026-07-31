//一个可以指导崆峒弟子武功的NPC，可以看作是神仙的化身。
//行踪无定，而且很少出现。
// Qyz

inherit F_UNIQUE;
inherit NPC;



void create()
{
        set_name("无名老者", ({ "lao zhe","zhe", "old" }) );
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




set_skill("jinshe-jian",380);
set_skill("liancheng-jian",380);
set_skill("hujia-daofa",380);
set_skill("demon-strike",380);
set_skill("nine-moon-claw",380);
set_skill("ill-quan",380);
set_skill("doomstrike",380);
set_skill("luoriquan",380);
set_skill("qinnashou",380);
set_skill("taixuan-gong",380);

        set_temp("apply/attack", 200);
        set_temp("apply/defense", 200);
        set_temp("apply/armor", 600);
        set_temp("apply/damage", 650);
        set_skill("jingyiforce",380);
        set_skill("demon-blade",280);
        set_skill("literate",380);
        set_skill("unarmed",380);
        set_skill("dodge",290);
        set_skill("parry",280);
	set_skill("force",380);
	set_skill("blade",280);
	set_skill("changquan",380);
        //set_skill("doomsword",380);
        //set_skill("chilian-shenzhang",380);
        //set_skill("softsword",280);
        //set_skill("nine-moon-sword",380);
        set_skill("luohua-jian",380);
        set_skill("sword",380);
        set_skill("feixian-sword",380);
        set_skill("bat-blade",380);
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

        set("long",     "这是一位仙风道骨的老道人，长得慈眉善目，极是可亲。\n");
        set("chat_chance_combat", 20);      
        set("chat_msg_combat", ({
        (: SKILL_D("hujia-daofa")->perform_action(this_object(), "weizhen-bafang") :),
           }) );  

        set("combat_exp", 99999999);


        set("positive_score",10000);
        setup();

        carry_object(__DIR__"obj/cloth1")->wear();
        carry_object(__DIR__"obj/bidao")->wield();
}

int valid_teach( object ppl, string skill )
{
	
   
    if (ppl->query("family/family_name") != "崆峒派")      //如果没有学功夫的标记
    {
        command( "say “呵呵，好久没人和老夫说话啦！”" );
        return 0;
    }
   
    if (ppl->query("marks/kongdong/zhou") != 1) 
    {
        command( "say “你见过周真人么？”" );
        return 0;
    }
     
     
    if( ppl->query("class_score/崆峒派") < 500 )
        {
        command( "say “我在崆峒山住几十年了，怎么不曾见过你？”" );
        return 0;
           
        }
    if( skill=="kongdong-xinfa")
    return 1;   
    if( skill=="hujia-daofa"&&random( (int)ppl->query("kar") ) < 20 &&ppl->query_jibie("hujia-daofa")<1) 
     {
        command( "say “你这人看起来心术不正，我不能教你！”" );
        ppl->add("gin",-20);
        return 0;
    }
       if(skill=="hujia-daofa"&& ppl->query_xiuwei_by_type("blade")<1500)
     {
        command( "say “可惜你修为不够，领悟不了我家传的胡家刀法！”" );
        return 0;
    }  
    command( "say “终于找到一个可以发扬我胡家刀法的后辈了。”" );
    command( "haaa" );
    return 1; 

}


int zhongcheng( object ppl, string skill )  //不检查忠诚度
{
    return 1;
}

