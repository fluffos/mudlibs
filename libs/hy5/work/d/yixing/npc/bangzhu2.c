// /d/yixing/npc/bangzhu2.c
// Last Modified by winder on Jul. 12 2002



inherit NPC;

#include <ansi.h>




void create()
{
	set_name("草上飞", ({ "bangzhu" }));
	set("gender", "男性");
	set("age", 30);
	set("long", "一个魁梧之极的大汉，脸庞极尽苍桑，精神却甚矍铄。\n");
	set("attitude", "friendly");
	set("shen_type", -1);

	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);

	set("combat_exp", 60000);

	set("max_qi", 300);
	set("max_jing", 200);
	set("max_qi", 600);
	set("max_neili", 200);
	set("neili", 200);

	set_skill("dodge", 80);
	set_skill("force", 80);
	set_skill("parry", 80);
	set_skill("cuff", 80);
/*
	set_skill("ding-force", 80);
	map_skill("force", "ding-force");

	set_skill("wuxingbu", 80);
	map_skill("dodge", "wuxingbu");
*/
	set("no_get", "帮主太重了");

	setup();

	call_out("come_attacker", 10);
}

