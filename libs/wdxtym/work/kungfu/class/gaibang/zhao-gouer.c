// zhao-gouer.c
// Modified by Venus Nov.1997
inherit NPC;

#include "gaibang.h"

void create()								   
{
	set_name("赵狗儿", ({"zhao gouer", "zhao", "gouer"}));
	set("title", "丐帮一袋弟子");
	set("gender", "男性");
	set("age", 15);
	set("long",
		"这是位地痞似的丐帮一袋弟子，看来是个小地痞。\n");
	set("attitude", "peaceful");
	set("class", "beggar");
	set("str", 18);
	set("int", 20);
	set("con", 20);
	set("dex", 23);
	set("max_qi", 150);
	set("max_jing", 120);
	set("neili", 250);
	set("max_neili", 250);
	set("jiali", 5);
	set("combat_exp", 2500);
	set_skill("force", 30);
	set_skill("jiaohua-neigong", 30);
	set_skill("unarmed", 30);
	set_skill("changquan", 30);
	set_skill("dodge", 30);
	set_skill("feiyan-zoubi", 30);
	set_skill("parry", 30);
	set_skill("begging", 30);
	set_skill("checking", 30);
	map_skill("force", "jiaohua-neigong");
	map_skill("unarmed", "changquan");
	map_skill("dodge", "feiyan-zoubi");
	create_family("丐帮", 20, "弟子");
	setup();
}
