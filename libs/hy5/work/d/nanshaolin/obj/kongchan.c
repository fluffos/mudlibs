// Obj: /d/nanshaolin/obj/kongchan.c
// Last Modified by winder on May. 29 2001

inherit NPC;
void create()
{
	set_name("空禅石人", ({ "kongchan shiren", "kongchan", "shiren" }));
	set("long", "年代久远已无法看清他当年之相貌，\n"
		"他身材魁梧高大挺拔，让人觉的精力四射。\n");
	set("gender", "男性");
	set("attitude", "friendly");
	set("class", "bonze");
	set("age", 100);
	set("shen_type", 1);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
	set("max_qi", 1200);
	set("max_jing", 1000);
	set("neili", 2000);
	set("max_neili", 2000);
	set("jiali", 50);
	set("combat_exp", 1200000);
	set("score", 200);
	set_skill("force", 140);
	set_skill("yijinjing",140);
	set_skill("damo-jian", 140);
	set_skill("dodge", 140);
	set_skill("shaolin-shenfa", 140);
	set_skill("leg", 140);
	set_skill("parry", 140);
	set_skill("buddhism", 140);
	map_skill("force", "yijinjing");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("leg", "damo-jian");
	map_skill("parry", "damo-jian");
	prepare_skill("leg", "damo-jian");
	setup();
}
#include "chan.h"
