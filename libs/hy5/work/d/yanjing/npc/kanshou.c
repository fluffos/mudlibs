inherit NPC;
void create()
{
   set_name("王府看守",({"kan shou"}));
   set("gender","男性");
        set("shen_type",-1);
	set("combat_exp",50000);
   
   set("age",46);
   set("qi",5800);
   set("max_qi",5800);
   set("food",250);
   set("water",250);
   set("neili",5800);
   set("max_neili",5800);
   set("force_factor",20);

set("qi", 15200); 
        set("max_qi", 15200); 
        set("jing", 13500); 
        set("max_jing", 13500); 
        set("neili", 16500); 
        set("max_neili", 16500); 
        set("jiali", 180); 
        set("combat_exp", 5000000); 
        set("level", 50);
        set("score", 20000); 
        
        set_skill("force", 140); 
        set_skill("lengyue-shengong", 240); 
        set_skill("blade", 260); 
        set_skill("baisheng-daofa", 260); 
        set_skill("hujia-daofa", 180); 
        set_skill("dodge", 260); 
        set_skill("sixiang-bufa", 260); 
        set_skill("taxue-wuhen", 160);
        set_skill("parry", 240); 
        set_skill("throwing", 260); 

        set_skill("strike", 240); 
        set_skill("tianchang-strike", 240); 
        set_skill("cuff", 240); 
        set_skill("hujia-quan", 240); 
        set_skill("literate", 180); 
        set_skill("martial-cognize", 140); 

        map_skill("force", "lengyue-shengong"); 
        map_skill("blade", "hujia-daofa"); 
        map_skill("dodge", "sixiang-bufa"); 
        map_skill("parry", "hujia-daofa"); 
        map_skill("strike", "tianchang-strike"); 
        map_skill("cuff", "hujia-quan"); 
           
        prepare_skill("strike", "tianchang-strike"); 
        prepare_skill("cuff",   "hujia-quan"); 
        
        

        
        set_temp("apply/attack", 120);
        set_temp("apply/defense", 120);
        set_temp("apply/armor", 120);
        set_temp("apply/damage", 520);
        
        set("chat_chance_combat", 120); 
        set("chat_msg_combat", ({ 
                (: perform_action, "blade.huanying" :),
               	(: perform_action, "blade.lian" :),
                (: perform_action, "blade.xian" :), 
                (: perform_action, "blade.zhui" :), 
                (: perform_action, "blade.cang" :), 
                (: perform_action, "cuff.kuai" :), 
                (: perform_action, "strike.jian" :), 
                (: perform_action, "dodge.fei" :), 
                (: exert_function, "recover" :), 
                (: exert_function, "powerup" :), 
        })); 
 
   setup();
   add_money("silver",2);
carry_object(__DIR__"obj/pijia")->wear();
carry_object(__DIR__"obj/blade")->wield();
}
