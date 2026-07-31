// lu.c
inherit NPC;
inherit F_MASTER;
#include <ansi.h>;
void create()
{
	set_name("Â³Á¬ÈÙ", ({ "lu lianrong", "lu", "lianrong" }) );
	set("nickname", HIY"½ðÑÛµñ"NOR);
	set("gender", "ÄÐÐÔ");
	set("class", "swordsman");
	set("age", 45);
	set("attitude", "peaceful");
	set("per", 13);
	set("str", 26);
	set("con", 30);
	set("dex", 30);
	set("int", 28);

	set("neili", 1400);
	set("max_neili", 1400);
	set("jiali", 30);
	set("max_qi",1500);
	set("max_jing",800);
	set("combat_exp", 600000);
	set("shen_type", 1);

	set_skill("unarmed", 80);
	set_skill("sword", 80);
	set_skill("force", 80);
	set_skill("parry", 80);
	set_skill("dodge", 80);
	set_skill("hengshan-sword", 80);
	set_skill("lingxu-bu", 80);

	map_skill("sword", "hengshan-sword");
	map_skill("parry", "hengshan-sword");
	map_skill("dodge", "lingxu-bu");

	create_family("ºâÉ½ÅÉ", 13, "µÜ×Ó");
	setup();

	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/clone/cloth/cloth")->wear();
}

