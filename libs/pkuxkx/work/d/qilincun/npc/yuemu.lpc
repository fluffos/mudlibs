// Rewrote by iszt@pkuxkx, 2007-02-12

inherit NPC;

void create()
{
	set_name("岳母", ({ "yue mu", "yue" }));
	set("gender", "女性");
	set("age", 41);
	set("long", "她是小岳飞的母亲，这不是一位平凡的母亲。\n");

	set("combat_exp", 2000);
	set("shen_type", 1);

	set("attitude", "peaceful");

	set_skill("unarmed", 20);
	set_skill("dodge", 20);
	set_temp("apply/attack", 10);
	set_temp("apply/defense", 10);
	set("inquiry", ([
		"岳飞" : "他到后山救王二愣的媳妇了。",
	]) );

	setup();
	carry_object("/clone/misc/cloth")->wear();
}