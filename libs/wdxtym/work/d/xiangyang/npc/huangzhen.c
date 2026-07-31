// huangzhen.c

inherit NPC;
inherit F_BANKER;

#include <ansi.h>

void create()
{
	set_name("黄真", ({"huang zhen", "zhen", "huang"}));
	set("nickname", HIY"铜笔铁算盘"NOR);
	set("gender", "男性");

	set("age", 59);
	set("long",
		"黄真是神剑仙猿穆人清的开门大弟子，也是这个钱庄的"
		"老板，管理襄阳军饷。\n");
	set("attitude", "peaceful");
	set("per", 21);
	set("str", 26);
	set("con", 30);
	set("dex", 30);
	set("int", 30);

	set("max_qi", 3500);
	set("max_jing", 1800);
	set("neili", 36000);
	set("max_neili", 3600);
	set("jiali", 40);

	set("combat_exp", 500000);
	set("shen_type", 1);

	set("chat_chance_combat", 80);
	set("chat_msg_combat", ({
		(: exert_function, "powerup" :),
		(: exert_function, "recover" :)
	}) );

	set_skill("strike", 140);
	set_skill("cuff", 140);
	set_skill("sword", 140);
	set_skill("force", 140);
	set_skill("parry", 140);
	set_skill("dodge", 140);
	set_skill("literate", 60);

	set_skill("huashan-sword", 140);
	set_skill("huashan-xinfa", 140);
	set_skill("poyu-quan", 140);
	set_skill("hunyuan-zhang", 140);
	set_skill("feiyan-huixiang", 140);

	map_skill("sword", "huashan-sword");
	map_skill("parry", "huashan-sword");
	map_skill("force", "huashan-xinfa");
	map_skill("cuff", "poyu-quan");
	map_skill("strike", "hunyuan-zhang");
	map_skill("dodge", "feiyan-huixiang");
	prepare_skill("cuff", "poyu-quan");
	prepare_skill("strike", "hunyuan-zhang");

	create_family("华山派", 21, "弟子");

	setup();

	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/clone/misc/cloth")->wear();
	add_money("silver", 5);

}
void init()
{
	add_action("do_check", "check");
	add_action("do_convert", "duihuan");
	add_action("do_deposit", "cun");
	add_action("do_withdraw", "qu");
	delete_temp("busy");
}
