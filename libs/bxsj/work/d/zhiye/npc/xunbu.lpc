// xunbu.c 巡捕
// by augx@sj 9/11/2001

#include <ansi.h>
inherit NPC;

void create()
{
	set_name("巡捕", ({ "xun bu", "xunbu"}));
	set("gender", "男性");
	set("age", random(10) + 30);
	set("str", 25);
	set("dex", 25);
	set("long", "他站在那里，的确有说不出的威风。\n");
	set("combat_exp", 300000);
	set("shen_type", 1);
	set("no_quest", 1);
	set("attitude", "peaceful");

	set_skill("unarmed", 140);
	set_skill("blade", 140);
	set_skill("force", 140);
	set_skill("sword", 140);
	set_skill("dodge", 140);
	set_skill("parry", 140);

	set_temp("apply/attack", 40);
	set_temp("apply/defense", 40);
	set_temp("apply/armor", 40);
	set_temp("apply/damage", 40);

	set("neili", 3000);
	set("max_qi", 1500);
	set("max_jing", 1200);
	set("eff_jingli", 1000);
	set("max_neili", 3000);
	set("jiali", 40);

	setup();
	carry_object(BINGQI_D("gangdao"))->wield();
	carry_object(ARMOR_D("yayifu"))->wear();
}
