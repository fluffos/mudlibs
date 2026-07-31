// wushi.c

inherit NPC;
// inherit F_SKILL;

void create()
{
	set_name("武士", ({ "wu shi", "shi" }));
	set("gender", "男性");
	set("age", random(10) + 20);
	set("str", 25);
	set("dex", 16);
	set("long", "一个充满了傲气的武士。\n");
	set("combat_exp", 50000);
	set("shen_type", 1);
	set("attitude", "peaceful");

	set_skill("unarmed", 80);
	set_skill("force", 80);
	set_skill("blade", 80);
	set_skill("dodge", 80);
	set_skill("parry", 80);
	set("neili", 1000); 
	set("max_neili", 1000);
	set("jiali", 10);

	setup();
//	carry_object("/d/city/npc/obj/tiejia")->wear();
//	carry_object("/d/feitian/obj/wushidao")->wield();
}

