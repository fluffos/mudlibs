// Last Modified by winder on May. 29 2001
// Npc: /kungfu/class/nanshaolin/fangjie.c

inherit NPC;
inherit F_MASTER;
mixed carry_water();

void create()
{
	set_name("方戒", ({ "fang jie", "fang", "jie"}));
	set("long",
		"他是一位精神抖擞的中年和尚，身穿一袭青布镶边袈裟。身材略高，\n"
		"太阳穴微凸，双目炯炯有神。\n"
	);

	set("gender", "男性");
	set("attitude", "friendly");
	set("class", "bonze");

	set("age", 50);
	set("shen_type", 1);
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	set("max_qi", 450);
	set("max_jing", 300);
	set("neili", 600);
	set("max_neili", 600);
	set("jiali", 50);
	set("combat_exp", 100000);
	set("score", 100);
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
	set_skill("leg", 50);
	set_skill("zui-gun", 50);
	set_skill("staff", 50);
	set_skill("pudu-zhang", 50);
	map_skill("force", "yijinjing");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("cuff", "hunyuan-yiqi");
	map_skill("leg", "zui-gun");
	map_skill("staff", "pudu-zhang");
	map_skill("parry", "pudu-zhang");
	prepare_skill("cuff", "hunyuan-yiqi");
	prepare_skill("leg", "zui-gun");

	set("inquiry", ([
		"挑水":	(: carry_water :)
	]));
	create_family("南少林派", 21, "弟子");
	setup();

	carry_object("/d/shaolin/obj/xu-cloth")->wear();
	carry_object(__DIR__"chanzhang")->wield();
}

mixed carry_water()
{
	object me = this_player();
	object ob = this_object();

	if (!me->query("carry_count"))
		if (present("liao kao", me))
		{
			destruct(present("liao kao", me));
			return "你的活已经干完了，我帮你解开镣铐。";
		}
		else
			return RANK_D->query_respect(me) + "不是开玩笑吧？";
	if (present("tie tong", me))
		return "你不是拿着铁桶吗？快去干活吧。";
	if (present("tie tong", environment()))
		return "铁桶不是在地上放着吗？拿去干活吧。";
	command("buddhi");
	new("/d/nanshaolin/obj/tie-tong")->move(environment());
	command("say 这是干活的家什，拿去用吧。");
	message_vision("$N从身后拿出一对大铁桶放在地上。\n", ob);
	return 1;
}

#include "fang.h";
