// Room: /d/huijiang/npc/dizi.c
// Last Modified by winder on Sep. 12 2001

inherit NPC;

void create()
{
	set_name("红花会弟子", ({ "di zi", "dizi" }));
	set("long", "一名普普通通的红花会弟子\n他好像二十岁了！\n");
	set("gender", "男性");
	set("age", 20);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("str", 21);
	set("int", 22);
	set("con", 20);
	set("dex", 20);
	set("max_qi", 2800);
	set("max_jing", 2000);
	set("neili", 2000);
	set("max_neili", 2000);
	set("combat_exp", 200000);
	set_skill("force", 145);
	set_skill("dodge", 145);
	set_skill("unarmed", 140);
	set_skill("parry",150);
	set_skill("sword",150);
	set_skill("blade",150);

	create_family("红花会",3, "弟子");

	setup();
	carry_object("/d/city2/obj/jinduan")->wear();
	carry_object("/clone/weapon/gangdao")->wield();
}
