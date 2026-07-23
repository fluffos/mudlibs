// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.

#include <ansi.h> 


inherit NPC; 
inherit F_MASTER; 




void create() 
{ 
        object ob; 
        set_name("苗人凤", ({ "miao renfeng", "miao", "renfeng" })); 
        set("gender", "男性"); 
        set("nickname", YEL "金面佛" NOR); 
        set("title", "打遍天下无敌手"); 
        set("age", 48); 
        set("long", @LONG 
他就是号称打遍天下无敌手的「金面佛」苗人 
凤。只见他脸色透黄，似乎蒙上了一层淡淡的 
金纸。他身材高大魁梧，四肢修长，却是全然 
不修篇幅，令人称奇。 
LONG ); 
        set("attitude", "friendly"); 
        set("shen_type", 1); 
        set("str", 32); 
        set("int", 31); 
        set("con", 33); 
        set("dex", 31); 
        
        set("qi", 25500); 
        set("max_qi", 25500); 
        set("jing", 24000); 
        set("max_jing", 24000); 
        set("neili", 26800); 
        set("max_neili", 26800); 
        set("jiali", 200); 
        set("level", 50);
        set("combat_exp", 9500000); 
        set("score", 20000); 
        
        set_skill("force", 260); 
        set_skill("lengyue-shengong", 380); 
        set_skill("dodge", 240); 
        set_skill("sixiang-bufa", 380); 
        set_skill("sword", 260); 
        set_skill("miaojia-jian", 380); 
        set_skill("baisheng-daofa", 380);
        set_skill("blade", 240); 
        set_skill("hujia-daofa", 380); 
        set_skill("strike", 260); 
        set_skill("cuff", 260); 
        set_skill("tianchang-strike", 380); 
        set_skill("parry", 360); 
        set_skill("literate", 300); 
        set_skill("martial-cognize", 380); 

        set_skill("daojian-guizhen", 380); 
        set_skill("hujia-quan", 380); 
        

        map_skill("force", "lengyue-shengong"); 
        map_skill("dodge", "sixiang-bufa"); 
        map_skill("sword", "miaojia-jian"); 
        map_skill("blade", "hujia-daofa"); 
        map_skill("parry", "miaojia-jian"); 
        map_skill("strike", "tianchang-strike"); 
        map_skill("cuff", "hujia-quan"); 
        
        prepare_skill("strike", "tianchang-strike"); 
        prepare_skill("cuff", "hujia-quan"); 
           

         
        //create_family("中原苗家", 6, "传人"); 
        create_family("关外胡家", 7, "友人"); 
        set("inquiry", ([ 

                "胡家刀法" : "胡家刀法乃是我当年从胡世兄处习得，当真精妙无比。", 
                "胡一刀"   : "当年我中了奸人毒计杀害了他，令我遗憾终生！", 
        ])); 
        
        set("chat_chance_combat", 99); 
        set("chat_msg_combat", ({ 
                (: perform_action, "sword.zhai" :), 
                (: perform_action, "sword.zhu" :), 
                (: perform_action, "sword.jian" :), 
                (: perform_action, "sword.gan" :), 
                	(: perform_action, "sword.lian" :), 
                (: perform_action, "strike.dan" :), 
                	(: perform_action, "dodge.fei" :), 
                (: perform_action, "strike.duo" :), 
                	(: perform_action, "strike.huang" :), 
                (: perform_action, "cuff.kuai" :), 		
                (: exert_function, "recover" :), 
                (: exert_function, "powerup" :), 
        })); 
if (random(3)==0)
{
	        set("isok",1);
	        map_skill("sword", "daojian-guizhen"); 
        map_skill("blade", "daojian-guizhen"); 
        map_skill("parry", "daojian-guizhen"); 
        set("chat_chance_combat", 99); 
        set("chat_msg_combat", ({ 
                (: perform_action, "sword.feidao" :), 
                (: perform_action, "sword.feng" :), 
                (: perform_action, "sword.guizhen" :), 
                (: perform_action, "sword.hujia" :), 
                	(: perform_action, "sword.tian" :), 
                	(: perform_action, "sword.wolf" :),                 		
                	(: perform_action, "sword.xue" :),                 		                		
                (: perform_action, "strike.dan" :), 
                	(: perform_action, "dodge.fei" :), 
                (: perform_action, "strike.duo" :), 
                	(: perform_action, "strike.huang" :), 
                (: perform_action, "cuff.kuai" :), 		
                (: exert_function, "recover" :), 
                (: exert_function, "powerup" :), 
        })); 
 }       
        set_temp("apply/damage", 100); 
        set_temp("apply/unarmed_damage", 100); 
        set_temp("apply/armor", 200); 
	set_temp("apply/attack",190);
	set_temp("apply/defense",190);
	set_temp("apply/armor",1800);
	set_temp("apply/damage",800);        
        set("master_ob",5);
	setup(); 
        
        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/clone/cloth/cloth")->wear(); 
if (query("isok")==1)
{
        carry_object("/d/zhongzhou/npc/obj/jundao"); 

}
} 
        
void attempt_apprentice(object ob) 
{


        
        if (ob->name(1) == "苗人凤") 
        { 
                command("hmm"); 
                command("say 你怎么也取这个名字？"); 
                return; 
        } 
        
        if (ob->name(1) == "苗若兰") 
        { 
                command("hmm"); 
                command("say 你就不能换个别的名字？"); 
                return; 
        } 
        
        if (ob->name(1) == "苗鬼凤" || ob->name(1) == "苗人龙") 
        { 
                command("hmm"); 
                command("say 你安心要和我作对是不是？"); 
                return; 
        } 
        
        command("sigh"); 
        command("recruit " + ob->query("id")); 
        command("say 我本已打算不收徒弟，让我田家与胡、苗、范三家的纷争得以平息。"); 
        command("say 可是这祖传三十七势苗家剑就在我处失传，未免太过不孝。"); 
        return; 
} 
 
int recognize_apprentice(object me, string skill) 
{

        
        if ((int)me->query("shen") < 0) 
        {
                command("sigh"); 
                command("say 你怎能走上邪路？我可不能教你苗家剑。"); 
                return -1; 
        }
        
        if (me->query("combat_exp",1)<=400000)
        {
                command("say 你此时功力太浅，还是先打好基础再说吧。");
                return -1;
        }

        if (skill != "miaojia-jian" && skill != "sword")
        {
                command("say 我只教你基本剑法和苗家剑法，别的就不要来烦我了！"); 
                return -1;
        }

        if (me->query_skill(skill, 1) >= 400) 
        {
               command("say 够了！我就教你到这里吧，武功还是" 
                       "要靠自己多研究才是！"); 
               return -1; 
        }
        
        command("say 看在当年我中了奸人毒计杀害了胡一刀，令我遗憾终生的事上，我就传你苗家剑法。"); 
        return 1;
}
        
