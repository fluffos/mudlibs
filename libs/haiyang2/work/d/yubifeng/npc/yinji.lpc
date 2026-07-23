// yinji.c 殷吉

#include <ansi.h>
inherit NPC;

void create()
{
	set_name("殷吉", ({ "yin ji", "ji", "yin" }) );
	set("gender", "男性");
	set("title", "辽东天龙门南宗第六代掌门人");
	set("nickname", "威震天南");
	set("age", 43);
	set("attitude", "friendly");
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	set("combat_exp", 1300000);
	set_skill("dodge", 50);
	set_skill("force", 50);
	set_skill("cuff", 50);
	set_skill("hand", 50);
	set_skill("sword", 50);
	set_skill("liehuo-jian", 350);
	set_skill("changquan", 350);

	map_skill("sword", "liehuo-jian");
	map_skill("parry", "liehuo-jian");
	map_skill("cuff", "changquan");

	prepare_skill("cuff", "changquan");


	setup();
	carry_object("/clone/misc/cloth")->wear();
	carry_object("/clone/weapon/changjian")->wield();
}
