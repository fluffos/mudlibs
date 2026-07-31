// shishugang.c史叔刚

inherit NPC;
 
void create()
{
        set_name("史叔刚", ({ "shi shugang","shi","shugang" }));
        set("nickname", "金甲狮王");
        set("long", 
        "他就万兽山庄五兄弟的老三，脸色略微发黄，似是久病初愈的样子。\n"
        "据说曾得异人传授一身精湛的功夫。\n");
        set("gender", "男性");
        set("age", 29);
        set("attitude", "friendly");
        set("shen", 6500);
        set("str", 32);
        set("int", 20);
        set("con", 23);
        set("dex", 23);
        set("eff_jingli",2000);
        set("max_qi", 1200);
        set("max_jing", 1500);
        set("neili", 2600);
        set("max_neili", 2600);
        set("jiali", 120);
        set("combat_exp", 650000);
    
        set("chat_chance_combat", 60);
        set("chat_msg_combat", ({
                (: perform_action, "sword.sanqing" :)
            }));

         
        set_skill("strike", 140);
        set_skill("sword", 140);
        set_skill("dodge", 140);
        set_skill("parry", 140);
        set_skill("xiantian-qigong", 160);
//        set_skill("tiangang-zhang",150);
        set_skill("quanzhen-jian", 140);
        set_skill("jinyan-gong",140);             
        set_skill("literate", 140);
        set_skill("force",140);
        map_skill("force", "xiantian-gong");
        map_skill("dodge", "jinyan-gong");
//        map_skill("strike","tiangang-zhang");
        map_skill("parry", "tiangang-zhang");
        map_skill("sword", "quanzhen-jian");
        prepare_skill("strike", "tiangang-zhang");

         set("inquiry", ([
                "神雕侠" : "全仗他老人家我的内伤才得以康复。",
                "霍都" : "再要见到那个狗贼，一定要杀了他。",
                "御兽": "此技为我们兄弟祖传之术，武功若无小成，学习甚是危险。",
                
        ]) );
        
        setup();
carry_object("/clone/weapon/changjian")->wield();
        carry_object("/clone/misc/cloth")->wear();
//        add_money("gold", 10);
}