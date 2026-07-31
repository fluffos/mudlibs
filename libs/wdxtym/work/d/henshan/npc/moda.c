// moda.c
inherit NPC;
inherit F_MASTER;
#include <ansi.h>;
void create()
{
	set_name("莫大", ({ "mo da", "mo" }) );
	set("title", HIR"衡山派第十三掌门"NOR);
	set("nickname", "潇湘夜雨");
	set("gender", "男性");
	set("class", "swordsman");
	set("age", 55);
	set("attitude", "peaceful");
	set("per", 22);
	set("str", 26);
	set("con", 30);
	set("dex", 30);
	set("int", 28);

	set("neili", 2400);
	set("max_neili", 2400);
	set("jiali", 30);
	set("max_qi",2000);
	set("max_jing",1200);
	set("combat_exp", 1200000);
	set("shen_type", 1);

	set_skill("unarmed", 150);
	set_skill("sword", 150);
	set_skill("force", 150);
	set_skill("parry", 150);
	set_skill("dodge", 150);
	set_skill("hengshan-sword", 150);
	set_skill("lingxu-bu", 150);

	map_skill("sword", "hengshan-sword");
	map_skill("parry", "hengshan-sword");
	map_skill("dodge", "lingxu-bu");

	create_family("衡山派", 13, "掌门");
	setup();

	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/clone/cloth/cloth")->wear();
}

