// /d/city/npc/dadao.c

inherit NPC;

void create()
{
	set_name("客商", ({"ke shang", "ke", "shang"}));
	set("long", "他是一个在河北一带做生意的客商。\n");

	set("gender", "男性");
	set("attitude", "heroism");

	set("age", 40);
	set("shen_type", -1);
	set("str", 28);
	set("int", 23);
	set("con", 23);
	set("dex", 28);
	set("combat_exp", 30000);

	set_skill("force", 30);
	set_skill("dodge", 30);
	set_skill("unarmed", 30);
	set_skill("parry", 30);

	setup();
	add_money("silver", 30);
	carry_object("/clone/misc/cloth")->wear();
}
