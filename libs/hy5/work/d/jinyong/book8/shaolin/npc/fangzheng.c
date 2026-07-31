inherit NPC;
#include <ansi.h>
void create()
{
	set_name("方证大师", ({
		"fangzheng dashi",
		"fangzheng",
		"dashi",
	}));
	set("long",
		"他是一位白须白眉的老僧，身穿一袭金丝绣红袈裟。\n"
		"他身材略显佝偻，但却满面红光，目蕴慈笑，显得神完气足。\n"
	);

	set("nickname", "少林寺方丈");
	set("gender", "男性");
	set("attitude", "friendly");
	set("class", "bonze");

	set("age", 60);
	set("shen_type", 1);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
	set("max_qi", 100000);
	set("max_jing", 100000);
	set("neili", 100000);
	set("max_neili", 100000);
	set("jiali", 150);
	set("combat_exp", 10000000);
	set("score", 500000);

	set_skill("force", 450);
	set_skill("hunyuan-yiqi", 450);
	set_skill("dodge", 450);
	set_skill("shaolin-shenfa", 450);
	set_skill("finger", 450);
	set_skill("strike", 450);
	set_skill("hand", 450);
	set_skill("claw", 450);
	set_skill("parry", 450);
	set_skill("nianhua-zhi", 450);
	set_skill("sanhua-zhang", 450);
	set_skill("fengyun-shou", 450);
	set_skill("longzhua-gong", 450);
	set_skill("buddhism", 500);
	set_skill("literate", 300);
	set_skill("weituo-zhang", 450);
	set_skill("shaolin-tantui", 450);
	set_skill("jingang-zhang", 450);
	set_skill("jimie-zhua", 450);
	set_skill("duoluoye-zhi", 450);
	set_skill("mohe-zhi", 450);
	set_skill("boluomi-shou", 450);
	set_skill("yijinjing",450);
	
	map_skill("force", "hunyuan-yiqi");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("finger", "nianhua-zhi");
	map_skill("strike", "sanhua-zhang");
	map_skill("hand", "fengyun-shou");
	map_skill("claw", "longzhua-gong");
	map_skill("parry", "nianhua-zhi");

	prepare_skill("finger", "nianhua-zhi");
	prepare_skill("strike", "sanhua-zhang");

	create_family("少林派", 44, "弟子");

	setup();

        carry_object("/d/shaolin/obj/xuan-cloth")->wear();
}

void unconcious()
{
	die();
}
void die()
{
        object who = this_object()->query_temp("last_damage_from");
        if(who) {
		message_vision("$N说道：阿弥陀佛，少林既已战败，便无权囚禁任盈盈施主，稍后将老衲会派人将任施主送回，施主们请自便。\n" NOR,this_object());
	}
	destruct(this_object());
}