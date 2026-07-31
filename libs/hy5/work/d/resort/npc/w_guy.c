 inherit NPC;
void create()
{
        set_name("黑袍公", ({ "oldguy" }) );
        set("gender", "男性" );
        set("class","legend");
        set("reward_npc", 1);
        set("difficulty", 15);
        
        set("age", 65);
        set("str", 46);
        set("cor", 24);
        set("cps", 11);
        set("per", 27);
        set("int", 27); 
        set("attitude", "peaceful"); 
        set("max_atman", 500);
        set("atman", 500);
        set("max_neili", 50000);
        set("force", 50000);
        set("max_mana", 500);
        set("mana", 500);
        set("force_factor", 50);
        set("fly_target",1); 
        set("long",     "黑袍公除了下棋，什么也不做\n");  
        set("combat_exp", 999999); 
        set_skill("unarmed", 100);
        set_skill("throwing", 250);
        set_skill("dodge", 100);
        set_skill("force", 130);
        set_skill("literate", 70); 
        set_skill("qidaoforce", 100);
        set_skill("meihua-shou", 91);
        set_skill("fall-steps", 10); 
        map_skill("unarmed", "meihua-shou");
        map_skill("dodge", "fall-steps");
        map_skill("force","qidaoforce"); 
        set("chat_chance", 1);
        set("chat_msg", ({
               (: exert_function, "juqi" :),
        }) );        
        set("chat_chance_combat", 30);
        set("chat_msg_combat", ({
                (: perform_action, "unarmed.meihai" :),
        }) );
        
        setup(); 
        carry_object(__DIR__"obj/wqi")->wield();
        carry_object(__DIR__"obj/bcloth")->wear();
}
void init()
{
        ::init();
        set_temp("qidaoforce_juqi",1);
}       
  
