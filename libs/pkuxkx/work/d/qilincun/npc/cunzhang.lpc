// Rewrote by iszt@pkuxkx, 2007-02-12

inherit NPC;

void create()
{
	string weapon;
	set_name("村长", ({ "cun zhang"}));
	set("gender", "男性");
	set("age", random(20) + 55);
	set("str", 30);
	set("con", 26);
	set("int", 20);
	set("dex", 23);
	set("long", "他就是这里的村长。\n");
	set("combat_exp", 80000 + random(40000));
	set("attitude", "friendly");
	set_skill("force", 50);
	set_skill("literate", 50);
	set_skill("dodge", 50);
	set_skill("parry", 50);
	set_skill("blade", 50);

	set("max_qi", 650);
	set("eff_jingli", 400);
	set("neili", 700);
	set("max_neili", 700);
	set("jiali", 30);

	set("shen_type",1);set("score",200);setup();
	add_money("silver", random(200));
	carry_object("/clone/misc/cloth")->wear();
}