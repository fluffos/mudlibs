//  /clone/npc/huyz 胡逸之
// by dubei
inherit NPC;
 
void create()
{
	set_name("胡逸之", ({ "hu yizhi", "hu" }));
	set("nickname", "百胜刀王");
	set("long", 
        "他就是百胜刀王胡逸之。\n");
	set("gender", "男性");
	set("age", 46);
	set("attitude", "peaceful");
	set("shen", -10000);
	set("str", 40);
	set("int", 35);
	set("con", 35);
	set("dex", 37);
	set("per",26);
            set("eff_jingli",3000);
	set("max_qi", 2500);
	set("max_jing", 2500);
	set("neili", 6000);
        set("max_neili", 6000+random(5000));
	set("jiali", 120);
	set("combat_exp", 2500000); 
            set("unique", 1);
	set("chat_chance", 30);
	set("chat_msg", ({
		(: random_move :)
	}) );
         set_skill("force", 200);
         set_skill("yijin-jing", 200);
         set_skill("dodge", 220);
         set_skill("tiyunzong", 200);
         set_skill("parry", 200);
        set_skill("blade", 200);
        set_skill("cuff", 200);
        set_skill("shandian-daofa", 200);
        set_skill("wenjia-quan", 200);
        set_skill("literate", 150);
 
        map_skill("force", "yijin-jing");
        map_skill("dodge", "tiyunzong");
        map_skill("cuff", "jingang-quan");
         map_skill("blade", "shandian-daofa");
  	map_skill("parry", "shandian-daofa");
  	prepare_skill("cuff", "jingang-quan");
 
        setup(); 
        carry_object("/clone/misc/cloth")->wear();
              carry_object("/clone/weapon/blade")->wield();
        add_money("gold", 1);
}
 
