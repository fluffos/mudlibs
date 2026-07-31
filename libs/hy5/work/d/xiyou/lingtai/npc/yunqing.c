// worker.c

inherit NPC;
inherit F_MASTER;
void create()
{
        set_name("云清", ({"yun qing", "yun"}));
        set("gender", "男性" );
        set("age", 33);
        set("long",
"方寸山三星洞第三代弟子中的杰出人物．\n虽不是很聪明，但师祖却很看重他．\n");
	set("int", 25);
	set("class", "taoist");
        set("combat_exp", 80000);
	set("daoxing", 100000);

        set("attitude", "peaceful");
        create_family("方寸山三星洞", 3, "弟子");

        set("eff_dx", 30000);
        set("nkgain", 200);

      

	set("str", 30);
        set("per", 30);
        set("max_kee", 400);
        set("max_gin", 400);
        set("max_sen", 400);
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
