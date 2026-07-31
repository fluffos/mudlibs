// duantiande.c

inherit NPC;

void create()
{
	set_name("段天德", ({ "duan tiande", "duan" }));
	set("gender", "男性");
	set("title", "大宋兵马指挥使");
	set("age", 45);
	set("per", 15);
	set("long", "他是大宋临安兵马指挥使。\n");

        set_skill("dodge", 20);
        set_skill("unarmed", 20);
        set_temp("apply/attack",  20);
        set_temp("apply/defense", 20);
	set("shen_type", -1);


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

	//add_money("gold",3);
	carry_object("/clone/weapon/gangdao")->wield();
	carry_object("/d/city/npc/obj/junfu")->wear();
}

