// shaonian.c

#include <ansi.h>

inherit NPC;

int ask_me(object who);

void create()
{
	set_name("诸葛武", ({ "zhuge wu","wu" }) );
	set("title","粗壮少年");

	set("gender", "男性" );
	set("age", 25);
	set("str",30);

	set("max_force",1000);
	set("force",1000);
	set("force_factor",10);
	set("max_qi",1200);

	set("long","这位粗壮的少年是这里主人的少公子，自幼好武，
曾请过不少武师教习武术，在大同府里小有名气，
对付个地皮流氓绰绰有余。\n");

	set("combat_exp", 5300000);

	set_skill("force",300);
	set_skill("dodge",100);
	set_skill("parry",100);
	set_skill("unarmed",100);
	set_skill("changquan",100);
	//set_skill("ganchan",100);

	//map_skill("unarmed","changquan");
	map_skill("dodge","ganchan");

	set("inquiry",([
	"石头" : (: ask_me :),
]));

	setup();
	carry_object("/clone/misc/cloth")->wear();
}

int ask_me(object who)
{
	if(who->query("quest/shaolin_quest/asked_shijian") != "大同府")
		return 0;

	if(who->query("quest/shaolin_quest/win_zhuge"))
	{
		tell_object(who,sprintf(CYN"%s说道：您去问问小翠吧，她是专门管衣服的，就说是我让您去的。\n"NOR,name()));
		return 1;
	}

	if(who->query("quest/shaolin_quest/asked_zhuge"))
	{
		write(sprintf(CYN"%s说道：不愿意比试(fight)就算了。\n"NOR,name()));
		return 1;
	}

	write(sprintf(CYN"%s说道：是有这么回事，前两年我去开封游玩，路过一个石匠门前看见院子里
            一块大石头上刻着小人在打拳，像是一套拳法，我就喜欢这东西
            就脱下穿的衣服给拓了下来，回来捉摸半天也没看出个所以然。
            看你的样子也练过武功，咱们比划比划(fight)。\n"NOR,name()));

	who->set("quest/shaolin_quest/asked_zhuge",1);

	return 1;
}

int accept_fight(object who)
{
	if(who->query("quest/shaolin_quest/name") != "拳法图谱")
		return 0;

	if(!who->query("quest/shaolin_quest/asked_zhuge"))
	{
		command("say 好呀！来玩两手！");
		return 1;
	}
	if(who->query("quest/shaolin_quest/win_zhuge"))
	{
		command("say 小的说什么也不敢和您再打了。");
		return 0;
	}

	if( ((query("qi")*100)/query("max_qi") < 90) || (query("force") < 300))
	{
		call_out("do_full",5+random(5));
		return notify_fail(name()+"我现在有点累，你让我歇会儿咱们大战三百合。\n");
	}

	if(who->query_temp("weapon"))
		return notify_fail("说好了只是比划比划，你怎么还拿家伙！！\n");

	command("say 好！小生就来领教你的高招！");
	call_out("check_state",2,who);
	return 1;
}

private void check_state(object who)
{
	if(!who || environment(who) != environment())
		return;

	if(is_fighting())
	{
		if(member_array(who,query_enemy()) != -1)
			call_out("check_state",2,who);
		return;
	}

	if( (query("qi") * 100 / query("max_qi")) < 50 )
	{
		tell_object(who,sprintf(CYN"%s说道：真看不出来您是个武林高手！近日方知天外有天，人外有人！
            小的输的心服口服。对了，我们家的丫鬟小翠是专门管
            衣服的，你可以去问问他，就说是我让您去的。\n"NOR,name()));

		who->set("quest/shaolin_quest/win_zhuge",1);
		who->add("quest/shaolin_quest/hint",sprintf("      %s\n",
			"丫鬟小翠是诸葛家专门管衣服的，可以去问问她。"));
	}
}

void do_full()
{
	set("eff_qi",query("max_qi"));
	set("qi",query("max_qi"));
	set("eff_jing",query("max_jing"));
	set("jing",query("max_jing"));
	set("eff_jingli",query("max_jingli"));
	set("jingli",query("max_jingli"));
}

int remove_enemy(object ob)
{
	int n;

	n = ::remove_enemy(ob);
	if(!is_fighting())
		call_out("do_full",3);
	return n;
}

int accept_kill(object who)
{
	return notify_fail("这家伙你不能动就是不能动。\n");
}
