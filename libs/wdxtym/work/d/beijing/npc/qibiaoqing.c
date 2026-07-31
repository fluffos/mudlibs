// qibiaoqing.c

#include <ansi.h>

inherit NPC;
inherit F_UNIQUE;
inherit F_MASTER;

void create()
{
	set_name("祁彪清", ({ "qi biaoqing", "qi" }));
	set("title", HIR "天地会"HIG"青木堂"NOR"会众"); 
	set("shen_type", 1);
	set("gender", "男性");
	set("age", 35);
	set("long", "一个脾气火暴的壮汉。\n");

	set_skill("unarmed", 60);
	set_skill("dodge", 70);
	set_skill("parry", 70);
	set_skill("sword", 80);
	set_skill("force", 70);
	set_skill("huashan-xinfa", 50);
	set_skill("huashan-sword", 70);
	set_skill("huashan-shenfa",60);
	map_skill("dodge", "huashan-shenfa");
	map_skill("parry", "huashan-sword");
	map_skill("sword", "huashan-sword");
	map_skill("force", "huashan-xinfa");

	set_temp("apply/attack", 35);
	set_temp("apply/attack", 35);
	set_temp("apply/damage", 25);

	set("combat_exp", 50000);
	set("attitude", "friendly");

	set("inquiry", ([
		"陈近南" : "想见总舵主可不容易啊。",
		"天地会" : "只要是英雄好汉，都可以入我天地会。",
		"反清复明" : "去棺材店和回春堂仔细瞧瞧吧！",
		"暗号" : "敲三下！",
		"切口" : "敲三下！",
	]));

	setup();
	carry_object("/clone/misc/cloth")->wear();
	carry_object("/clone/weapon/changjian")->wield();
}
