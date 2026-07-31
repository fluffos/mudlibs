// hai.c 海公公
#include <ansi.h>
inherit NPC;
string ask_for_zigong();
string ask_for_jingong();
int do_pretend ( string arg );

void create()
{
	set_name("海大富", ({"hai gonggong", "hai", "gonggong"}));
	set("title", "大内高手");
	set("long",
		"他是东厂大太监海大富，大内高手。。\n"
	);

	set("gender", "无性");
	set("rank_info/respect", "公公");

	set("attitude", "heroism");
	set("class", "eunach");



	set("age", 60);
	set("shen_type", -1);
	set("str", 25);
	set("int", 20);
	set("con", 20);
	set("dex", 25);
	set("max_qi", 15000);
	set("max_jing", 15000);
	set("neili", 25000);
	set("max_neili", 25000);
	set("jiali", 100);
	set("combat_exp", 3875000);
	set("score", 5000);
	set("apply/attack",  130);
	set("apply/defense", 130);

	set_skill("force", 250);
	set_skill("unarmed", 250);
	set_skill("sword", 250);
	set_skill("dodge", 250);
	set_skill("parry", 250);
	set_skill("kuihua-xinfa", 250);
	set_skill("pixie-jian", 250);
map_skill("force", "kuihua-xinfa");
	map_skill("dodge", "pixie-jian");
	map_skill("sword", "pixie-jian");
	map_skill("parry", "pixie-jian");
        set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
                (: perform_action, "sword.cimu" :),
                (: perform_action, "sword.huanying" :),
                (: perform_action, "sword.sanlianci" :),
                (: exert_function, "powerup" :),
                (: exert_function, "recover" :)
        }) );
	setup();
	set("chat_chance", 15);

	carry_object("/clone/misc/cloth")->wear();
	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/d/city/obj/jiudai");
	carry_object("/d/beijing/obj/yaofen");
	//add_money("silver", 50);
}

