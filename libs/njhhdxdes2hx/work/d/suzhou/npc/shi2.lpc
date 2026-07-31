//NPC: /d/suzhou/npc/shi2.c
// by dwolf
//97.11.4

#include <ansi.h>

inherit NPC;
inherit F_VENDOR;

void create()
{
	set_name("史守财", ({"shi shoucai", "shi"}));
	set("title", HIM "钱庄" NOR + YEL "老板" NOR);
	set("nickname", MAG "铁" NOR + BLK "公鸡" NOR);
	set("gender", "男性");
	set("age", 40);

	set("str", 22);
	set("int", 24);
	set("dex", 28);
	set("con", 28);

	set("kee", 500); 
	set("max_kee", 500);
	set("gin", 150);
	set("max_gin", 150);
	set("shen", 1);

	set("combat_exp", 100000);
	set("shen_type", 1);
	set("attitude", "friendly");
	set("env/wimpy", 50);
	set("chat_chance", 2);
	set("chat_msg", ({
	HIW"史守财骄傲的说道：本银号已经有几百年的历史，在全国可以说是第一家。\n"NOR,
 	HIW"史守财呵呵笑道：在本店存钱无利息，取钱收十分之一手续费，客官您看着办吧。\n"NOR
	}));
	set_skill("unarmed", 80);
	set_skill("dodge", 80);
	set_temp("apply/attack", 100);
	set_temp("apply/defense", 100);
	set_temp("apply/damage", 45);

	setup();
	add_money("gold", 3);
}
