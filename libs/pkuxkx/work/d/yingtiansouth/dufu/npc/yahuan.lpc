inherit NPC;


void create()
{
	set_name("丫鬟", ({ "ya huan", "ya","huan" }));
	set("gender", "女性");
	set("age", random(15) + 10);
	set("str", 10);
	set("dex", 10);
	set("long", "她是一名都府里的丫鬟，内府的打扫由她负责。\n");
	set("combat_exp", 6000);
	set("shen_type", 1);
	set("attitude", "peaceful");

	set_skill("unarmed", 10);
	set_skill("force", 10);
	set_skill("dodge", 10);
	set_skill("parry", 10);

	setup();
	carry_object(__DIR__"obj/cloth_yahuan")->wear();
}
