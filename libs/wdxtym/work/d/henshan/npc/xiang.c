// xiang.c
inherit NPC;
inherit F_MASTER;
#include <ansi.h>;
void create()
{
	set_name("向大年", ({ "xiang danian", "xiang", "danian" }) );
	set("gender", "男性");
	set("class", "swordsman");
	set("age", 25);
	set("attitude", "peaceful");
	set("str", 26);
	set("con", 30);
	set("dex", 30);
	set("int", 28);
	set("per", 20);

	set("neili", 1400);
	set("max_neili", 1400);
	set("jiali", 30);
	set("max_qi",1500);
	set("max_jing",800);
	set("combat_exp", 300000);
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

	create_family("衡山派", 14, "弟子");
	setup();

	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/clone/cloth/cloth")->wear();
}

