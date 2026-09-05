// File		: suwanhong.c
// Created By	: iszt@pkuxkx, 2007-03-07

#include "setdizi.h"
#include <title.h>
void create()
{
        setcreate(240);

	set_name("苏万虹", ({ "su wanhong", "su", "wanhong", }));
	set("long", "这是白老爷子最心爱的小弟子，正在这里独自守着。\n");
	set("age", 26);
	set("gender","男性");
	set("str", 25);
	set("dex", 15);
	set("con", 20);
	set("int", 25);
	set("per", 19);

	add("inquiry", ([
		"name" : "在下苏万虹。",
	]));

	create_family("雪山派", 6, "长门弟子");

	setup();
	setequip();
}

void attempt_apprentice(object ob)
{
	object me  = this_object();
	mapping fam = ob->query("family");

	if(fam && ob->query("betrayer")>1 && fam["family_name"] != "雪山派")
	{
		command("say 你屡次叛师，将师门之义一手抹煞，在外早已是臭名昭著。"
			"本门信义为先，岂能容你！\n");
		return;
	}
	if(fam && fam["generation"] == me->query("family/generation"))
	{
		command("say " + (ob->query("gender")=="男性" ? "师弟" : "师妹") +
			"说笑了，有什么疑难之处可以和师兄切磋切磋，拜师哪谈得上！");
		return;
	}
	if(fam && fam["generation"] < me->query("family/generation"))
	{
		command("say 师叔说笑了，晚辈怎敢收您为徒？");
		return;
	}

	command("nod "+ ob->query("id"));
	command("recruit "+ ob->query("id"));
	ob->set("title", "雪山派第七代长门弟子");
//title系统记录玩家title by seagate@pkuxkx
	ob->set_title(TITLE_RANK, "雪山派第七代长门弟子");
}