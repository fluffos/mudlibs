// ruanshizhong.c 阮士中

#include <ansi.h>
inherit NPC;

void create()
{
	set_name("阮士中", ({ "ruan shizhong", "shizhong", "ruan" }) );
	set("gender", "男性");
	set("title", "辽东天龙门北宗第五代弟子");
	set("nickname", "七星手");
	set("age", 43);
	set("attitude", "friendly");
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	set("combat_exp", 400000);
	set_skill("dodge", 60);
	set_skill("force", 60);
	set_skill("cuff", 60);
	set_skill("hand", 60);
	set_skill("sword", 60);
	set_skill("liehuo-jian", 60);
	set_skill("changquan", 50);
	map_skill("sword", "liehuo-jian");
	map_skill("parry", "liehuo-jian");
	map_skill("sword", "liehuo-jian");
	map_skill("cuff", "changquan");

	prepare_skill("cuff", "changquan");


	setup();
	carry_object("/clone/misc/cloth")->wear();
	carry_object("/clone/weapon/changjian")->wield();
}
