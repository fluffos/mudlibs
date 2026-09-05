// /d/luoyang/npc/xiaozhonghui.c
// Created By Zine ,Nov 13 2010，一天一次20环任务
// Modified by Zine Nov 08 2012,重新修订

#include <ansi.h>
inherit NPC;
#include "banhe_bonus.h"

int ask_follow();
int leave_UNATTEND();
void create()
{
	set_name("萧中慧", ({ "xiao zhonghui", "xiao", "zhonghui" }));
	set("long",
		"她就是有「晋阳大侠」的女儿萧中慧。\n");
    set("title", HIG"任性少女"NOR);
	set("gender", "女性");
	set("age", 16);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
	set("combat_exp", 100000);
	set("shen_type", 1);
    set("uni_target",1);
    set("no_get", 1);
	set("attitude", "friendly");
	set("max_jingli",300);
	set("jingli",300);
	set("neili",300);
	set("max_neili",300);
	set("jiali",10);
	set("score", 1200);

	
	set_skill("sword", 25);
	set_skill("parry",25);
	set_skill("dodge", 25);
	set_skill("force",25);
	set_skill("literate",25);
	set_skill("taiyi-zhang",25);
	set_skill("strike",25);
	set_skill("taiyi-jian",25);
	set_skill("taiyi-shengong",25);
	set_skill("taiyi-you",25);
	

	map_skill("parry","taiyi-zhang");
	map_skill("sword","taiyi-jian");
	map_skill("force","taiyi-shengong");
	map_skill("dodge","taiyi-you");
	map_skill("strike","taiyi-zhang");

	
	prepare_skill("strike","taiyi-zhang");
	set_temp("apply/attack", 20);
	set_temp("apply/defense", 20);

	

	set("inquiry", ([
		"回家": (: ask_follow() :),
		"home": (: ask_follow() :),
    ]));

	set("chat_chance_combat",100);
	set("chat_msg_combat", ({
		(: perform_action, "dodge.lingxu" :),
		(: perform_action, "sword.jianqi" :),
		(: perform_action, "sword.jianzhang" :),
		(: perform_action, "strike.jianzhang" :),
	}));
	
	setup();
	carry_object("/clone/cloth/female3-cloth")->wear();
	carry_object("/d/city/obj/changjian")->wield();
	call_out("leave_UNATTEND",600);
}
int leave_UNATTEND()
{
	object ob=this_object(),me;
	if (!environment())
	return 1;
	if (ob&&!query("reward")&&!present(query("owner"),environment()))
	{
		if (me&&living(me))
		tell_object(me,"萧半和让人传来消息，萧中慧已经回到了萧府，多谢你之前的帮助。\n");
		destruct(ob);
		return 1;
	}
}
int ask_follow()
{
	object me=this_player(),ob=this_object();
	if (query("owner")!=me)
	{
		command("say 我还没玩够呢，现在不想回家。");
		return 1;
	}
	tell_object(me,"你急吼吼地对"+ob->query("name")+"咆哮：“萧中慧，你爸喊你回家！”\n");
	tell_object(me,ob->query("name")+"一脸不情愿，但也没什么办法，只好乖乖地跟着你！”\n");
	command("follow "+me->query("id"));
	command("angry");
	if (!query("reward"))
	{
		bonus(me,3);
		set("reward",1);
	}
	return 1;
}
void die()
{
	message_vision(HIG"$N狡黠地一笑，远远躲开了。\n"NOR,this_object());
	if (objectp(query("startline")))
	{
		fullme();
		move(query("startline"));
	}
}
void unconcious()
{
	die();
}
int leave()
{
	object me=query("owner"),xiao;
	if (me&&me->query_temp("banhe")&&xiao=present("xiao banhe",environment()))
	{
		xiao->gene_robber(me,2);
	}
	message_vision("$N走进了萧府内宅。\n",this_object());
	destruct(this_object());
	return 1;
}
void init()
{
	object env=environment();
	if (base_name(env)=="/d/jinyang/xiaofu")
	{
		leave();
	}
}

