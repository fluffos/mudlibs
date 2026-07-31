// NPC :rong_ziju.c 容子矩
// By River 98/12
inherit NPC;
void create()
{
        set_name("容子矩", ({ "rong ziju", "rong", "ziju"}));
        set("title","无量剑东宗掌门师弟");              
        set("gender", "男性" );
        set("age", 46);
        set("str", 27);
        set("con", 23);
        set("dex", 26);
        set("int", 25);
        set("per", 20);
   	set("attitude", "friendly");

        set("max_qi", 18000);
        set("max_jing", 20000);
        set("eff_jingli", 20000);
        set("neili", 200-0);
	set("qi", 180-0);	
        set("max_neili", 20-00);
        set("jiali", 40);
        set("unique", 1);
        
        set("long","他是无量剑东宗的掌门的师弟。\n");
        set("combat_exp", 1350000);
        set("shen", 1000); 

        set_skill("parry", 220);
        set_skill("dodge", 200);
        set_skill("force", 200);
        set_skill("cuff", 200);
        set_skill("sword", 200);
        set_skill("kurong-changong", 200);   
        set_skill("xiaoyaoyou", 200);
        set_skill("wuliang-jian", 200);
        map_skill("dodge", "xiaoyaoyou");
        map_skill("parry", "wuliang-jian");
        map_skill("sword", "wuliang-jian");
        map_skill("force", "kurong-changong");         
        set("chat_chance_combat", 120);
        set("chat_msg_combat", ({
                (: perform_action, "sword.qian" :),
                (: exert_function, "powerup" :),
                (: exert_function, "recover" :),
        }) );
        setup();
        carry_object("/clone/weapon/gangjian")->wield();
        carry_object(__DIR__"obj/changpao")->wear();
}
