// Npc: /kungfu/class/nanshaolin/fangge.c
// Last Modified by winder on May. 29 2001

inherit F_MASTER;
inherit NPC;
string ask_me(string name);

void create()
{
	set_name("方戈", ({ "fang ge", "fang", "ge"}));
	set("long", "他是一位身穿黄布袈裟的青年僧人。脸上稚气未脱，身手却已相\n"
		"当矫捷，看来似乎学过一点武功。\n");
	set("gender", "男性");
	set("attitude", "friendly");
	set("class", "bonze");

	set("age", 20);
	set("shen_type", 1);
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	set("max_qi", 500);
	set("max_jing", 300);
	set("neili", 500);
	set("max_neili", 500);
	set("jiali", 100);
	set("combat_exp", 100000);
	set("score", 50);
	set_skill("zhanzhuang-gong", 60);
	set_skill("shaolin-cuff", 60);
	set_skill("shaolin-leg", 60);
	set_skill("yiwei-dujiang", 60);
	set_skill("boluomi-hand", 60);
	set_skill("jingang-strike", 60);
	set_skill("wuxiang-finger", 60);
	set_skill("literate", 50);
	set_skill("buddhism", 50);
	set_skill("parry", 50);
	set_skill("force", 50);
	set_skill("yijinjing", 50);
	set_skill("dodge", 50);
	set_skill("shaolin-shenfa", 50);
	set_skill("cuff", 50);
	set_skill("hunyuan-yiqi", 50);
	set_skill("luohan-quan", 50);
	set_skill("strike", 50);
	set_skill("sanhua-zhang", 50);
	set_skill("sanhua-zhang", 50);
	set_skill("finger", 50);
	set_skill("yizhi-chan", 50);
	set_skill("sword", 50);
	set_skill("damo-jian", 50);

	map_skill("force", "yijinjing");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("cuff", "luohan-quan");
	map_skill("strike", "sanhua-zhang");
	map_skill("finger", "yizhi-chan");
	map_skill("sword", "damo-jian");
	map_skill("parry", "damo-jian");
	prepare_skill("strike", "sanhua-zhang");
	prepare_skill("finger", "yizhi-chan");

	create_family("南少林派", 21, "弟子");

	setup();
	carry_object("/d/shaolin/obj/xu-cloth")->wear();
}

void init()
{
	remove_call_out("confirm");
	call_out("confirm", 0, this_player());
}

void confirm(object me)
{
	mapping mine;
	object room;

	if(!me || !present(me, environment()) ||
		!mapp(mine = me->query("family"))) return;
	if(!( room = find_object("/d/nanshaolin/cjlou")) )
	room = load_object("/d/nanshaolin/cjlou");

	if( (mapp(mine = me->query("family")) &&
		mine["family_name"] != "南少林派") ||
		((!present("fang ge", room)) && (!present("shou yu", me))))
	{
		command("say 大胆狂徒，竟敢闯入藏经阁，看招!");
		command("kill " + me->query("id")); 
		set("chat_chance_combat", 50);
		set("chat_msg_combat", ({
			(: perform_action, "sword.sanjue" :)
		}));
		return;
	}
	return;
}
#include "fang.h";
