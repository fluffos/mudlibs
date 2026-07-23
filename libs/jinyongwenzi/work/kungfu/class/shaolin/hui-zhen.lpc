// Npc: /kungfu/class/shaolin/hui-zhen.c
// Date: YZC 96/01/19

inherit NPC;
inherit F_MASTER;


void create()
{
	set_name("慧真尊者", ({
		"huizhen zunzhe",
		"huizhen",
		"zunzhe",
	}));
	set("long",
		"他是一位两鬓斑白的老僧，身穿一袭青布镶边袈裟。他身材略高，\n"
		"太阳穴微凸，双目炯炯有神。\n"
	);

	set("no_get", 1);
	set("gender", "男性");
	set("attitude", "friendly");
	set("class", "bonze");

        set("no_bark",1);
	set("age", 50);
	set("shen_type", 1);
        set("str", 80);
	set("int", 60);
	set("con", 60);
	set("dex", 60);
	set("max_qi", 1000);
	set("max_jing", 1000);
	set("neili", 2000);
	set("max_neili", 2000);
	set("jiali", 100);
	set("combat_exp", 750000);
	set("chat_msg", ({ "" }));

	set_skill("force", 150);
	set_skill("yijin-jing", 180);
	set_skill("dodge", 180);
	set_skill("shaolin-shenfa", 80);
	set_skill("finger", 90);
	set_skill("yizhi-chan", 90);
	set_skill("strike", 90);
	set_skill("banruo-zhang", 90);
	set_skill("sword", 150);
	set_skill("damo-jian", 150);
	set_skill("parry", 80);
	set_skill("buddhism", 100);
	set_skill("literate", 150);

	map_skill("force", "hunyuan-yiqi");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("finger", "yizhi-chan");
	map_skill("strike", "banruo-zhang");
	map_skill("sword", "damo-jian");
	map_skill("parry", "damo-jian");

	prepare_skill("finger", "yizhi-chan");
	prepare_skill("strike", "banruo-zhang");

	create_family("少林派", 38, "弟子");

	setup();

	set_temp("apply/damage", 100);
        carry_object("/d/shaolin/obj/changjian")->wield();
        carry_object("/d/shaolin/obj/hui-cloth")->wear();
}

void init()
{
	object me = this_player();

	::init();
	if (!userp(me) || is_killing(me->query("id"))) return;
	call_out("confirm", 0, me);
}

void confirm(object me)
{
	mapping mine;
	object room;

    if (!me || !present(me, environment()) || !mapp(mine = me->query("family")) || is_killing(me->query("id")))
		return;

	room = load_object("/d/shaolin/cjlou");

	if( (mapp(mine = me->query("family")) && mine["family_name"] != "少林派")
    || ((!present("daoyi chanshi", room)) && (!present("shou yu", me))))
	{
		  command("say 大胆狂徒，竟敢闯入藏经阁，速速离开！");
		call_out("kill", 3, me);
	}
}

void kill(object me)
{
	if (!me || !present(me, environment())) return;
	command("kill " + me->query("id")); 
	set("chat_chance_combat", 50);
	set("chat_msg_combat", ({
		(: perform_action, "sword.sanjue" :)
	}));
}
