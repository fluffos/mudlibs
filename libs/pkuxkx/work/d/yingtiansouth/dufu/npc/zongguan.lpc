inherit NPC;


void create()
{
	set_name("总管", ({ "zong guan","guan","zong" }));
	set("gender", "男性");
	set("age", 60);
	set("str", 10);
	set("dex", 10);
	set("long", "他是都府里的总管，大事小情都需要他来拿个主意。\n");
	set("combat_exp", 12000);
	set("shen_type", 1);
	set("attitude", "peaceful");

	set_skill("unarmed", 15);
	set_skill("force", 30);
	set_skill("dodge", 10);
	set_skill("parry", 10);

	setup();
	carry_object(__DIR__"obj/cloth_zongguan")->wear();
}
