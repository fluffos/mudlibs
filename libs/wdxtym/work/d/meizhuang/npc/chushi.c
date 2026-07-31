// chushi.c

inherit NPC;

void create()
{
	set_name("厨师", ({ "chu shi", "chu" }));
	set("title", "梅庄");
	set("long",
		"梅庄的一名厨师，笑眯眯地看着你，看来很和善的样子。\n");
	set("gender", "男性");
	set("age", 34);
	set("attitude", "peaceful");
	set("shen_type", 1);

	set("max_qi", 200);
	set("max_jing", 50);
	set("combat_exp", 500);
	set_skill("force", 10);
	set_skill("dodge", 10);
	set_skill("cuff", 10);
	set_skill("parry", 10);

	setup();
}
