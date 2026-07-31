// Npc wife.c

#include <ansi.h>

inherit NPC;

void create()
{
	set_name("姬凤仪", ({
		"ji fengyi",
		"ji",
		"fengyi",
		}));
	set("long",
		"她就是包大人的夫人兼卫士,她曾在灵鹫宫习武.\n");
	set("gender", "御赐一品诰命夫人");
	set("age", 45);
	set("shen_type",1);
	set("attitude", "peaceful");

	set("str", 25);
	set("int", 25);
	set("con", 30);
	set("per", 30);
	set("dex", 30);

	set("qi", 5800);
	set("max_qi", 5800);
	set("jing", 5500);
	set("max_jing", 5500);
	set("neili", 2000);
	set("max_neili", 2000);
	set("jiali", 20);

	set("combat_exp", 500000);
	set("score", 10000);
	set_skill("force", 100);
	set_skill("unarmed", 100);
	set_skill("dodge", 100);
	set_skill("parry", 100);
	set_skill("hand",100);
	set_skill("strike", 100);

	set_skill("zhemei-shou",280);
	set_skill("liuyang-zhang",280);
   	set_skill("yueying-wubu",280);
	set_skill("bahuang-gong", 270);

	map_skill("force", "bahuang-gong");
	map_skill("strike","liuyang-zhang");
	map_skill("dodge", "yueying-wubu");
	map_skill("unarmed", "liuyang-zhang");
	map_skill("hand", "zhemei-shou");
	map_skill("parry", "liuyang-zhang");

	setup();
	carry_object("/d/lingjiu/obj/qingyi")->wear();
            carry_object("/d/lingjiu/obj/doupeng")->wear();
	add_money("silver",10);
}

