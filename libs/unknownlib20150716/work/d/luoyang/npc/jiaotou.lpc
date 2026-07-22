inherit NPC;

void create()
{
        set_name("赵铁拳", ({"zhao tiequan", "zhao"}));
        set("age", 32);
        set_level(12);
        set("gender", "男性");
        set("long","一个精精瘦瘦的小个子，在练一套拳．\n");
	set("title", "武馆教头");
        set("attitude", "peaceful");

        set("shen_type", 1);
	set("force_factor", 5);
        set_skill("unarmed",120);
        set_skill("dodge",120);
	set_skill("force",120);
        set_skill("parry",120);
	setup();
        carry_object("/d/obj/cloth/linen")->wear();
}

int recognize_apprentice(object ob)
{
	return 1;
}
