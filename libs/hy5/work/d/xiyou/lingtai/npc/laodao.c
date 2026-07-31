// worker.c

inherit NPC;

void create()
{
        set_name("老道士", ({"laodao"}));
        set("gender", "男性" );
        set("age", 73);
        set("long", "一位老道士，眉毛和胡子都白了．\n");
        set("combat_exp", 20000);
	set("daoxing", 50000);

        set("attitude", "peaceful");
        set_skill("unarmed", 30);
   
        set("max_force", 300);
        set("force_factor", 2);
        setup();
        carry_object("/d/xiyou/lingtai/obj/cloth")->wear();
	carry_object("/d/obj/book/stickbook");
}

