// Npc: /kungfu/class/nanshaolin/fangkong.c
// Last Modified by winder on May. 29 2001

inherit F_MASTER;
inherit NPC;

void create()
{
	set_name("方空", ({ "fang kong", "fang", "kong"}));
	set("long", "他是一位身穿黄布袈裟的青年僧人。脸上稚气未脱，身手却已相\n"
		"当矫捷，看来似乎学过一点武功。\n");
	set("nickname", "知客僧");
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
	set("combat_exp", 50000);
	set("score", 100);
	set_skill("hunyuan-yiqi", 60);
	set_skill("hunyuan-yiqi", 60);
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
	set_skill("force", 30);
	set_skill("yijinjing", 30);
	set_skill("dodge", 30);
	set_skill("shaolin-shenfa", 30);
	set_skill("cuff", 30);
	set_skill("hunyuan-yiqi", 30);
	set_skill("leg", 30);
	set_skill("zui-gun", 30);
	map_skill("force", "yijinjing");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("cuff", "hunyuan-yiqi");
	map_skill("leg", "zui-gun");
	map_skill("parry", "hunyuan-yiqi");
	prepare_skill("cuff", "hunyuan-yiqi");
	prepare_skill("leg", "zui-gun");

	create_family("南少林派", 21, "弟子");

	setup();
	carry_object("/d/shaolin/obj/xu-cloth")->wear();
}

#include "fang.h";
