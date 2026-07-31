// liu.c
inherit NPC;
inherit F_MASTER;
#include <ansi.h>;
void create()
{
	set_name("刘正风", ({ "liu zhengfeng", "liu" }) );
	set("gender", "男性");
	set("class", "swordsman");
	set("long", "一个胖老者。恂恂有礼，便如一个财主乡绅，有些小小的
富贵之气，又有些土气，但有时突然显出勃勃英气，不失
高手风范。\n");
	set("age", 45);
	set("attitude", "peaceful");
	set("per", 19);
	set("str", 26);
	set("con", 30);
	set("dex", 30);
	set("int", 28);

	set("neili", 2000);
	set("max_neili", 2000);
	set("jiali", 30);
	set("max_qi",2000);
	set("max_jing",1200);
	set("combat_exp", 1000000);
	set("shen_type", 1);

	set_skill("unarmed", 120);
	set_skill("sword", 120);
	set_skill("force", 120);
	set_skill("parry", 120);
	set_skill("dodge", 120);
	set_skill("hengshan-sword", 120);
	set_skill("lingxu-bu", 120);

	map_skill("sword", "hengshan-sword");
	map_skill("parry", "hengshan-sword");
	map_skill("dodge", "lingxu-bu");

	create_family("衡山派", 13, "弟子");
	setup();

	carry_object("/clone/weapon/changjian")->wield();
	carry_object(__DIR__"obj/luo_cloth")->wear();
}

