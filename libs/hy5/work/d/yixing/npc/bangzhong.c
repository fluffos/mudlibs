// /d/yixing/npc/bangzhong.c
// Last Modified by winder on Jul. 12 2002
// skills and exp are set up by message_bangzhu.h file

#include <ansi.h>
inherit NPC;
//inherit F_SSERVER;


void create()
{
	set_name("帮众", ({ "bangzhong" }));
	set("gender", "男性");
	set("party/party_name", HIC"长乐帮"NOR);
	set("party/rank", "豹捷堂");
	set("age", 20 + random(10));
	set("long", "一名身材高大的壮汉，满脸杀气，一付凶神恶煞的模样。\n");
	set("attitude", "friendly");
	set("shen_type", -1);

	set("str", 24);
	set("int", 10);
	set("con", 24);
	set("dex", 24);

	set("combat_exp", 30000);


	setup();
}

