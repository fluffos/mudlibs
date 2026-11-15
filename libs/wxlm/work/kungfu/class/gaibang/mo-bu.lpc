// mo-bu.c
// Modified By Venus. Nov.1997

inherit NPC;
inherit F_MASTER;

#include "gaibang.h"

void create()
{
	set_name("莫不收", ({"mo bushou", "mo", "bushou"}));
	set("title", "丐帮三袋弟子");
	set("gender", "男性");
	set("age", 17);
	set("long",
		"这是位丐帮三袋弟子，看来是个很吃得开的一方霸主。\n");
	set("attitude", "peaceful");
	set("class", "beggar");
	set("str", 21);
	set("int", 20);
	set("con", 20);
	set("dex", 23);
	set("max_qi", 180);
	set("max_jing", 160);
	set("neili", 500);
	set("max_neili", 500);
	set("jiali", 15);
	set("combat_exp", 25000);
	set_skill("force", 60);
	set_skill("jiaohua-neigong", 60);
	set_skill("unarmed", 40);
	set_skill("changquan", 40);
	set_skill("dodge", 40);
	set_skill("feiyan-zoubi", 40);
	set_skill("parry", 40);
	set_skill("begging", 40);
	set_skill("checking", 40);
	map_skill("force", "jiaohua-neigong");
	map_skill("unarmed", "changquan");
	map_skill("dodge", "feiyan-zoubi");

	create_family("丐帮", 20, "弟子");
	setup();
}
