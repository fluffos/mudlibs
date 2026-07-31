// kuai-huosan.c
// Modified by Venus Nov.1997

inherit NPC;
inherit F_MASTER;

#include "gaibang.h"

void create()
{
	set_name("快活三", ({"kuai huosan", "kuai", "huosan"}));
	set("title", "丐帮四袋弟子");
	set("gender", "男性");
	set("age", 18);
	set("long",
		"这是位丐帮四袋弟子，看来是个很有点霸气的人。\n");
	set("attitude", "peaceful");
	set("class", "beggar");
	set("str", 22);
	set("int", 20);
	set("con", 20);
	set("dex", 25);
	set("max_qi", 180);
	set("max_jing", 190);
	set("neili",700);
	set("max_neili", 700);
	set("jiali", 20);
	set("combat_exp", 80000);
	set_skill("force", 70);
	set_skill("jiaohua-neigong", 70);
	set_skill("unarmed", 60);
	set_skill("changquan", 60);
	set_skill("dodge", 60);
	set_skill("feiyan-zoubi", 60);
	set_skill("parry", 70);
	set_skill("begging", 40);
	set_skill("checking", 30);
	map_skill("force", "jiaohua-neigong");
	map_skill("unarmed", "changquan");
	map_skill("dodge", "feiyan-zoubi");
	create_family("丐帮", 20, "弟子");
	setup();
}
