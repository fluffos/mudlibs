inherit NPC;


void create()
{
	set_name("客卿", ({ "ke qing","ke","qing" }));
	set("gender", "男性");
	set("age", 30+random(10));
	set("str", 10);
	set("dex", 10);
	set("long", "他是一位不得志的读书人，希望在都府能被赏识。\n");
	set("combat_exp", 4000);
	set("shen_type", 1);
	set("attitude", "peaceful");

	set_skill("unarmed", 15);
	set_skill("force", 10);
	set_skill("dodge", 10);
	set_skill("parry", 10);

	setup();
	carry_object(__DIR__"obj/cloth_zhangfang")->wear();
}
