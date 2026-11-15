
#include "duan.h"

inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("朱丹臣", ({ "zhu danchen", "zhu", "danchen" }));
	set("title", "大理国护卫" );
	set("nickname", CYN "笔砚生" NOR);
	set("long", "他是大理国四大护卫之一。一副书生酸溜溜的打扮行头。\n");
	set("gender", "男性");
	set("age", 40);
	set("class", "officer");
	set("attitude", "friendly");
	set("shen_type", 1);
	set("str", 30);
	set("int", 20);
	set("con", 25);
	set("dex", 25);
	
	set("max_qi", 1800);
	set("max_jing", 1000);
	set("neili", 2200);
	set("max_neili", 2200);
	set("jiali", 50);
	set("combat_exp", 500000);
	set("score", 5000);

	set_skill("force", 120);
	set_skill("duanshi-xinfa", 120);
	set_skill("dodge", 120);
	set_skill("tiannan-step", 120);
	set_skill("cuff", 120);
	set_skill("jinyu-quan", 120);
	set_skill("strike", 120);
	set_skill("wuluo-zhang", 120);
	set_skill("dagger", 140);
	set_skill("qingliang-daxuefa", 140);
	set_skill("parry", 120);
	set_skill("literate", 280);
	set_skill("martial-cognize", 140);

	map_skill("force", "duanshi-xinfa");
	map_skill("dodge", "tiannan-step");
	map_skill("cuff", "jinyu-quan");
	map_skill("strike", "wuluo-zhang");
	map_skill("dagger", "qingliang-daxuefa");
	map_skill("parry", "qingliang-daxuefa");

	prepare_skill("cuff", "jinyu-quan");
	prepare_skill("strike", "wuluo-zhang");

	create_family("段氏皇族", 15, "家臣");

	set("chat_chance_combat", 120);
	set("chat_msg_combat", ({
		(: perform_action, "dagger.ding" :),
		(: perform_action, "cuff.man" :),
		(: perform_action, "strike.bian" :),
		(: exert_function, "recover" :),
	}));

	setup();
	carry_object("/d/dali/npc/obj/junfu")->wear();
	carry_object("/d/meizhuang/obj/panguanbi")->wield();
	add_money("silver", 10);
}

void attempt_apprentice(object ob)
{
	if (! permit_recruit(ob))
		return;

	command("smile");
	command("say 世子殿下何需如此，只要有事吩咐在下一声便是。");
	command("say 若世子不嫌弃，我这里倒是有一套笔法可以传授予你。");

	return;
}

int recognize_apprentice(object ob, string skill)
{
	if (ob->query("family/family_name") != "段氏皇族")
	{
		command("sneer");
		command("say 我与阁下素不相识，不知阁下此话从何说起？");
		return -1;
	}

	if (skill != "qingliang-daxuefa" && skill != "dagger")
	{
		command("say 朱某生平只对笔法一项有所研究，其它功夫所知甚浅。");
		return -1;
	}

	if (! ob->query_temp("can_learn/zhudanchen"))
	{
		command("hehe");
		command("say 既然世子有心习武，在下理当竭尽所能传授。");
		ob->set_temp("can_learn/zhudanchen", 1);
	}
	return 1;
}

