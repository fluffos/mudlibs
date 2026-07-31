// xiaoyaozi.c 逍遥子
#include <ansi.h>

inherit NPC;
inherit F_MASTER;
inherit F_COAGENT;

#include "xiaoyao.h"

void create()
{
	set_name("逍遥子", ({ "xiaoyao zi", "xiaoyao","zi" }));
	set("title", "逍遥派开山祖师");
	set("long", @LONG
眼前此人须眉皆白，看不出有多老。然而似乎身染重疾，行动不便。虽然
如此，从眉宇仍然看得出此人当年必然是一位风流倜傥的美男子。想不到
今天沦落到这个地步，真是世事难料。
LONG );
	set("gender", "男性");
	set("age", 75);
	set("class", "scholar");
	set("attitude", "friendly");
	set("shen_type", 1);

	set("str", 36);
	set("int", 41);
	set("con", 37);
	set("dex", 38);
	
	set("max_qi", 6200);
	set("max_jing", 3100);
	set("neili", 7700);
	set("max_neili", 7700);
	set("jiali", 100);
	set("combat_exp", 2700000);

	set_skill("force", 2700);
	set_skill("xiaoyao-xinfa", 2700);
	set_skill("beiming-shengong", 2700);
	set_skill("xiaowuxiang", 2700);
	set_skill("dodge", 2700);
	set_skill("lingbo-weibu", 2700);
	set_skill("feiyan-zoubi", 2700);
	set_skill("liuyang-zhang", 2400);
	set_skill("parry", 2700);
	set_skill("blade", 2040);
	set_skill("ruyi-dao", 2040);
	set_skill("zhemei-shou", 2400);
	set_skill("hand", 2040);
	set_skill("strike", 2400);
	set_skill("literate", 200);
	set_skill("medical", 290);
	set_skill("xiaoyao-qixue", 290);

	map_skill("force", "beiming-shengong");
	map_skill("dodge", "lingbo-weibu");
	map_skill("hand", "zhemei-shou");
	map_skill("strike", "liuyang-zhang");
	map_skill("parry", "ruyi-dao");
	map_skill("blade", "ruyi-dao");

	prepare_skill("hand","zhemei-shou");
	prepare_skill("strike","liuyang-zhang");

	create_family("逍遥派", 1, "开山祖师");
	set("class", "taoist");

	set("chat_chance_combat", 120);
	set("chat_msg_combat", ({
		(: perform_action, "blade.ruyi" :),
		(: perform_action, "hand.jiubu" :),
		(: perform_action, "strike.jiutian" :),
		(: perform_action, "dodge.lingbo" :),
		(: exert_function, "recover" :),
		(: exert_function, "powerup" :),
	}));

	set_temp("apply/attack", 150);
	set_temp("apply/defense", 150);
	set_temp("apply/damage", 100);
	set_temp("apply/unarmed_damage", 100);
	set_temp("apply/armor", 200);

	setup();
	carry_object("/clone/weapon/blade")->wield();
}

void attempt_apprentice(object ob)
{
	if (ob->query_temp("pass_zhenlong"))
	{
		int btimes;
		ob->delete_temp("pass_zhenlong");
		if (ob->query("betrayer/times"))
		{
			command("sigh");
			command("say 你破了珍珑，和我是有缘人，可是你曾经判师，却不能收你。");
			return;
		}

		command("haha");
		command("say 你破了珍珑，和我是有缘人，我一定要收你为徒！");
		btimes = ob->query("betrayer/times");
		command("recruit " + ob->query("id"));
		ob->set("betryer/times", btimes);

		if (ob->query("max_neili") < 500)
		{
			command("say 不过你内力太差... 待我传功于你！");
			ob->set("max_neili", 500 + random(100));
			if (ob->query_skill("force", 1) < 50)
				ob->set_skill("force", 50 + random(10));

			if (ob->query_skill("beiming-shengong", 1) < 50)
				ob->set_skill("beiming-shengong", 50 + random(10));

			message_vision("$N把掌心按在$n天灵盖上，双眼微争，手掌不住的颤动，忽的落下，缓缓道：好，好！\n",
				       this_object(), ob);
		}

		return;
	}

	if (! permit_recruit(ob))
		return;

	if ((int)ob->query_skill("xiaoyao-xinfa", 1) < 120 &&
	    (int)ob->query_skill("beiming-shengong", 1) < 120) {
		command("say 我逍遥派的本门内功的你都没有学利索，还谈什么？"); 
		return;
	}

	if ((int)ob->query_skill("force", 1) < 120) {
		command("say 我逍遥派的的武功基础就是内功，你先把内功基础打好。"); 
		return;
	}

	if ((int)ob->query_skill("dodge", 1) < 120) {
		command("say 逍遥逍遥，你轻功基础这么差，何谈逍遥？"); 
		return;
	}

	if (ob->query_int() < 38) {
		command("say 我逍遥讲究的就是悟，但是" + RANK_D->query_respect(ob) + "的悟性似乎还有待提高啊。");
		return;
	}

	if (ob->query("combat_exp") < 250000)
	{
		command("say 你的修为也忒低了点，好好锻炼锻炼再说吧。");
		return;
	}

	command("smile");
	command("chat 想不到在这世上竟然还有人可以继承我逍遥派的衣钵！");
	command("recruit " + ob->query("id"));
	ob->set("title", HIC "逍遥护法" NOR);
}

void unconcious()
{
	die();
}
