// lu-liding.c

inherit NPC;

void create()
{
        set_name("陆立鼎", ({ "lu liding", "lu" }) );
	set("gender", "男性" );
        set("age", 35);
	set("long", "他就是陆展元之弟陆立鼎。\n"+
		 "一身武功都是兄长陆展元所传，生性淡泊，一生席丰履厚，从不到江湖上行走。\n");
	set("attitude", "friendly");
        set("str", 22);
        set("dex", 24);
        set("con", 20);
        set("int", 20);
        set("per", 26);
        set("shen_type", 1);

        set_skill("force", 80);
        set_skill("dodge", 80);
        set_skill("blade", 80);
        set("jiali", 20);

        set("combat_exp", 100000);

        set("max_qi", 300);
        set("max_jing", 200);
        set("neili", 300);
        set("max_neili", 300);
        set("max_jingli", 200);

        set("inquiry", ([
		"何沅君" : "是我嫂子。",
		"陆展元" : "正是在下兄长。",
	]));

	setup();

        carry_object(BINGQI_D("blade"))->wield();
        carry_object(ARMOR_D("cloth"))->wear();
}
