// worker.c

inherit NPC;
inherit F_MASTER;
void create()
{
        set_name("云静", ({"yun jing", "yun"}));
        set("gender", "男性" );
        set("age", 33);
        set("long", "方寸山三星洞第三代弟子中的杰出人物．\n");
        set("combat_exp", 70000);
	set("daoxing", 100000);

        set("attitude", "peaceful");
	set("int", 25);
	set("class", "taoist");
        create_family("方寸山三星洞", 3, "弟子");
	
        set("eff_dx", 30000);
        set("nkgain", 200);

        set_skill("unarmed", 40);
        set_skill("dodge", 40);
        set_skill("parry", 40);
        set_skill("spells", 40);  
  

        set("per", 30);
        set("max_kee", 500);
        set("max_gin", 500);
        set("max_sen", 500);
        set("force", 450);
        set("max_force", 300);
        set("force_factor", 10);
        set("mana", 450);
        set("max_mana", 300);
        set("mana_factor", 5);

        setup();
	carry_object("/d/xiyou/lingtai/obj/daoguanq")->wear();
        carry_object("/d/xiyou/lingtai/obj/cloth")->wear();
        carry_object("/d/xiyou/lingtai/obj/bang")->wield();
}
