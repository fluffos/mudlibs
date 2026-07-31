// Npc: /kungfu/class/shaolin/hui-kong.c
// Date: YZC 96/01/19

inherit NPC;
inherit F_MASTER;

mixed carry_water();

void create()
{
	set_name("慧空尊者", ({
		"huikong zunzhe",
		"huikong",
		"zunzhe",
	}));
	set("long",
		"他是一位两鬓斑白的老僧，身穿一袭青布镶边袈裟。他身材略高，\n"
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
	set("combat_exp", 50000);
	set("score", 100);

	set_skill("force", 70);
	set_skill("yijin-jing", 70);
	set_skill("dodge", 70);
	set_skill("shaolin-shenfa", 70);
	set_skill("staff", 70);
	set_skill("wuchang-zhang", 70);
	set_skill("parry", 70);
	set_skill("buddhism", 70);
	set_skill("literate", 70);

	map_skill("force", "yijin-jing");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("staff", "wuchang-zhang");
	map_skill("parry", "wuchang-zhang");

	set("inquiry", ([
		"挑水":	(: carry_water :)
	]));

	create_family("少林派", 38, "弟子");

	setup();

        carry_object("/d/shaolin/obj/chanzhang")->wield();
        carry_object("/d/shaolin/obj/hui-cloth")->wear();
}

mixed carry_water()
{
	object me = this_player();
	object ob = this_object();

	if (!me->query("carry_count"))
    if (present("liao kao", me)) {
        destruct(present("liao kao", me));
        return "你的活已经干完了，我帮你解开镣铐。";
    } else
		return RANK_D->query_respect(me) + "不是开玩笑吧？";
	if (present("tie tong", me))
		return "你不是拿着铁桶吗？快去干活吧。";
	if (present("tie tong", environment()))
		return "铁桶不是在地上放着吗？拿去干活吧。";
	command("buddhi");
	new("/d/shaolin/obj/tie-tong")->move(environment());
	command("say 这是干活的家什，拿去用吧。");
	message_vision("$N从身后拿出一对大铁桶放在地上。\n", ob);
	return 1;
}
