// NPC :xin_shuangqing.c 辛双清
// By River 98/12
inherit NPC;
void create()
{
        set_name("辛双清", ({ "xin shuangqing", "xin", "shuangqing"}));
        set("title","无量剑西宗掌门");              
        set("gender", "女性" );
        set("age", 42);
        set("str", 27);
        set("con", 23);
        set("dex", 26);
        set("int", 25);
        set("per", 20);
   	set("attitude", "friendly");

        set("max_qi", 18000);
        set("max_jing", 20000);
        set("eff_jingli", 20000);
        set("neili", 20000);
	set("qi", 18000);	
        set("max_neili", 20000);
        set("jiali", 40);
        set("unique", 1);
        
        set("long","她是无量剑西宗的掌门，铁青着脸，嘴唇紧闭。\n");
        set("combat_exp", 3500000);
        set("shen", 1000); 

        set_skill("parry", 220);
        set_skill("dodge", 200);
        set_skill("force", 200);
        set_skill("cuff", 200);
        set_skill("sword", 100);
        set_skill("kurong-changong", 200);   
        set_skill("xiaoyaoyou", 300);
        set_skill("wuliang-jian", 300);
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
        carry_object(__DIR__"obj/whiterobe")->wear();
}
