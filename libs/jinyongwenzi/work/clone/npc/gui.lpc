// /clone/npc/guishuxin
// by dubei

inherit NPC;
 
void create()
{           
        set_name("归辛树", ({ "gui xinshu", "gui" }));
        set("long",@LONG
他就是名震天下的归辛树，样子似乎很平常，似乎看不出什么特别的来。
LONG
        ); 
        set("gender", "男性");
        set("nickname", "神拳无敌");
        set("age", 72);
        set("attitude", "friendly");
        set("shen", -9500);
        set("str", 35);
        set("int", 30);
        set("con", 30);
        set("dex", 30);
        set("max_qi", 6000);
        set("eff_jingli", 3500);
              set("unique", 1);
        set("max_jing", 2500);
        set("neili", 7000);
        set("max_neili", 7000);
        set("jiali", 150);
        set("combat_exp", 3000000); 
              set("per",16);
        set("chat_chance_combat", 40);
        set("chat_msg_combat", ({
                (: perform_action, "strike.tiangang" :)
            }));
           set("chat_chance", 10);
	set("chat_msg", ({
		(: random_move :)
	}) );
        set_skill("strike", 220);
        set_skill("sword", 220);
        set_skill("dodge", 220);
        set_skill("parry", 220);
        set_skill("xiantian-gong", 220);
        set_skill("tiangang-zhang",220);
        set_skill("quanzhen-jianfa", 200);
        set_skill("jinyan-gong",200);             
        set_skill("literate", 100);
        set_skill("force", 200);
        
        map_skill("force", "xiantian-gong");
        map_skill("dodge", "jinyan-gong");
        map_skill("strike","tiangang-zhang");
        map_skill("parry", "tiangang-zhang");
        map_skill("sword", "quanzhen-jianfa");
        prepare_skill("strike", "tiangang-zhang");
 
        create_family("华山派", 10, "弟子");
 
        setup();
        carry_object("/clone/armor/cloth")->wear();
 
}
 