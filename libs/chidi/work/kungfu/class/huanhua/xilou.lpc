// sample master.c code
// xiake island master.c

inherit BHNPC;
inherit F_MASTER;
#include <ansi.h>

void heal_ob();
void recover_ob();

void create()
{
	set_name("萧西楼", ({"xiao xilou", "xiao", "xilou"}));
	set("gender", "男性");
	set("title", "浣花剑派第二代弟子、"HIG"现任掌门"NOR);
	set("age", 54);
	set("long", 
"他就是萧西楼——“浣花剑派”的一代宗师，天下“七大名剑”之一。\n"
"他一脸正气，三缕短须，无风自动，双目炯炯，令人不敢正视。\n");
	set("attitude", "peaceful");
	set("str", 15);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	set("bac", 25);
	
        set("qi", 24000);	
        set("neili", 3200);
        set("jingli", 3400);
	set("max_qi", 24000);
	set("max_jingli", 3400);
	set("max_neili", 3200);
	set("jiali", 50);
	
	set("combat_exp", 140000000);
	set("shen", 30000);
	
	set_skill("force", 1200);
	set_skill("jiuqu-xinfa", 1200);
	set_skill("strike", 1200);
	set_skill("feixu-zhang", 1200);
	set_skill("dodge", 1180);
	set_skill("huanhua-shenfa", 1180); 
	set_skill("sword", 5220);
	set_skill("huanhua-jianfa", 1220);
	set_skill("cuff", 1120);
	set_skill("tiexian-quan", 1120);
	set_skill("parry", 1200);
	set_skill("literate", 1160);
	set_skill("confu", 1160); 
	
	map_skill("force", "jiuqu-xinfa");
	map_skill("cuff", "tiexian-quan");
	map_skill("dodge", "huanhua-shenfa");
	map_skill("strike", "feixu-zhang");
	map_skill("parry", "huanhua-jianfa");
	map_skill("sword", "huanhua-jianfa");

	prepare_skill("strike", "feixu-zhang");
	prepare_skill("cuff", "tiexian-quan");
	prepare_skill("sword", "huanhua-jianfa");
	
	create_family("浣花剑派", 2, "弟子");

	setup();

	carry_object("/d/huanhua/npc/obj/changshan")->wear();
	carry_object("/clone/weapon/changjian")->wield();

	set("chat_chance", 3);
	set("chat_msg", ({
		(: heal_ob :),
		"萧西楼双眉紧缩，不停的踱着脚步。\n",
		"萧西楼摇了摇头，叹到：“权力帮贻害江湖，可是……”\n",
	}));

	set("chat_chance_combat", 30);
	set("chat_msg_combat", ({
		(: perform_action, "sword.snow" :),
		(: perform_action, "sword.mantian" :),
		(: perform_action, "sword.luanhong" :),
		(: perform_action, "strike.fenfei" :),
		(: recover_ob :)
	}) );
}

void heal_ob()
{
	command("yun heal");
	command("yun heal");
	command("yun heal");
	command("yun recover");
	return;
}

void recover_ob()
{
	command("yun recover");
	return;
}

void attempt_apprentice(object ob)
{
	object me;
	mapping my_fam, ob_fam;
	string title;

	me = this_object();

	my_fam = ob->query("family");
	ob_fam = me->query("family");

	title = ob->query("title");

	if (!(my_fam = ob->query("family")) || my_fam["family_name"] != "浣花剑派")
	{
		command("say 我只收浣花弟子中有天分且刻苦者，你根本不是浣花弟子，我怎能收你？");
		return;
	}

	if ((int)ob->query("shen") <= (-100))
	{
		command("say 你身为浣花弟子却不主张正义，甘入魔道，我浣花容不下你！");
		command("kaichu "+ob->query("id"));
		return;
	}

	if (ob->query("shen")<100000)
	{
		command("say 你维护武林正义的义举做得不够，我还不能收你。");
		command("addoil " + ob->query("id"));
		return;
	}

	if (ob->query_skill("huanhua-jianfa",1)< 120 || ob->query_skill("sword",1)<120)
	{
		command("say 我们浣花剑派以剑法为本，你是否应该在剑法方面多下些功夫呢？");
		command("addoil " + ob->query("id"));
		return;
	}

	command("say 好吧，我收下你无妨，但能否成才还要看你自己的努力。");
	command("recruit " + ob->query("id"));

	return;
}