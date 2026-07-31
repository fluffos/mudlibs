// worker.c

inherit NPC;
void create()
{
        set_name("慧琉", ({"hui liu"}));
        set("gender", "男性" );
        set("age", 33);
        set("long", "一个相貌堂堂的道士．");
	set("title", "道长");
	set("class", "taoist");
        set("combat_exp", 45000);
	set("daoxing", 60000);

        set("attitude", "peaceful");
        create_family("方寸山三星洞", 4, "弟子");
        set_skill("unarmed", 50);


        set("per", 30);
        set("max_kee", 500);
        set("max_sen", 300);
        set("force", 450);
        set("max_force", 300);
        set("force_factor", 5);
        setup();
        carry_object("/d/xiyou/lingtai/obj/cloth")->wear();
}