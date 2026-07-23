// /d/city/npc/dangpu_boss.c  created by Baiwt
#include <ansi.h>

inherit NPC;
void create()
{
set_name("夏天", ({ "xia tian","xia","boss" }) );
	set("gender", "男性" );
	set("age", 39);
set("nickname", "天马当铺老板");
	set("long",
       "他是金陵最大的当铺的老板，十分精明。\n");
	set("combat_exp", 50000);
	set("attitude", "friendly");
	set("per",30);
	set("no_arrest",1);
	set_skill("unarmed",200);
	set_skill("dodge",200);
	setup();
	carry_object("/clone/misc/cloth")->wear();
}

int accept_object(object who, object ob)
{
	message_vision("$N对$n说到：谢赏！！\n",this_object(),who);
		return 1;
}
	

