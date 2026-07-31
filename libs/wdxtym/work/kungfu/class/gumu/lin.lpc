// lin.c 林朝英
// 1998.9 by Lgg

inherit NPC;
inherit F_MASTER;

#include <ansi.h>
#include "gumu.h"

string ask_yunv();

void create()
{
	set_name("林朝英", ({"lin chaoying", "lin"}));
	set("gender", "女性");
	set("age", 42);
	set("long",
		"她就是古墓派的开山祖师林朝英，虽然已经是四十许人，望之却\n"
		"还如同三十出头。当年她与全真教主王重阳本是一对痴心爱侣，\n"
		"只可惜有缘无份，只得独自在这古墓上幽居。\n");
	set("attitude", "friendly");

	set("str", 28);
	set("int", 35);
	set("con", 31);
	set("dex", 33);

	set("chat_chance_combat", 20);
	set("chat_msg_combat", ({
		(: exert_function, "powerup" :),
		(: exert_function, "recover" :),
		(: perform_action, "sword.he" :),
		(: perform_action, "sword.he" :),
		(: perform_action, "sword.ding" :),
		(: perform_action, "sword.ding" :),
	}));

	set("qi", 5500);
	set("max_qi", 5500);
	set("jing", 2700);
	set("max_jing", 2700);
	set("neili", 6800);
	set("max_neili", 6800);
	set("jiali", 100);

	set("combat_exp", 2700000);
	set("score", 0);

	set_skill("force", 280);
	set_skill("yunv-xinfa", 280);
	set_skill("sword", 270);
	set_skill("yunv-jian", 270);
	set_skill("quanzhen-jian", 270);
	set_skill("dodge", 250);
	set_skill("yunv-shenfa", 250);
	set_skill("parry", 270);
	set_skill("unarmed",250);
	set_skill("meinv-quan", 250);
	set_skill("strike", 250);
	set_skill("fireice-strike", 250);
	set_skill("tianluo-diwang", 250);
	set_skill("whip", 240);
	set_skill("yinsuo-jinling", 240);
	set_skill("literate", 180);
	set_skill("taoism", 240);
	set_skill("medical", 270);
	set_skill("yunv-xinjing", 270);
	set_skill("throwing", 260);
	set_skill("yufeng-zhen", 260);

	map_skill("force", "yunv-xinfa");
	map_skill("sword", "yunv-jian");
	map_skill("dodge", "yunv-shenfa");
	map_skill("parry", "meinv-quan");
	map_skill("unarmed", "meinv-quan");
	map_skill("strike", "tianluo-diwang");

	prepare_skill("unarmed", "meinv-quan");
	prepare_skill("strike", "tianluo-diwang");

	create_family("古墓派", 1, "开山祖师");

	set("book_count",1);
	set("inquiry", ([
		"王重阳" :  "大胆后辈小子，也敢直呼重阳祖师之名？\n",
		"重阳祖师" : "重阳是全真教的掌教，自号“活死人”。\n",
		"古墓派" :  "是啊，这里就是我一手创下的古墓派\n",
		"玉女心经" : (: ask_yunv :),
		"玉蜂针" : "我这儿没有，别问我。",
	]));

	set_temp("apply/attack", 150);
	set_temp("apply/defense", 150);
	set_temp("apply/damage", 100);
	set_temp("apply/unarmed_damage", 100);
	set_temp("apply/armor", 200);

	set("chat_chance_combat", 120);
	set("chat_msg_combat", ({
		(: perform_action, "sword.he" :),
		(: perform_action, "sword.lian" :),
		(: perform_action, "unarmed.you" :),
		(: perform_action, "strike.wang" :),
		(: exert_function, "recover" :),
		(: exert_function, "powerup" :),
	}));

	setup();

	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/clone/cloth/qingyi")->wear();

}

void attempt_apprentice(object ob)
{
	if (! permit_recruit(ob) )
		return;

	if (ob->query_int() < 35) {
		command("say 我古墓派的功夫最讲一个悟字，你的资质不够。");
		return;
	}

	if ((int)ob->query_skill("yunv-xinfa", 1) < 100 ) {
		command("say 你的玉女心法火候不足,难以领略更高深的武功。");
		return;
	}

	command("say 好吧，看你也是性情中人，我就收下你这个徒弟了。");
	command("recruit " + ob->query("id"));
}

string ask_yunv()
{
	object ob;
	object me;

	me = this_player();
	if (me->query("family/family_name") != query("family/family_name"))
		return RANK_D->query_respect(me) +
		       "与本派毫无瓜葛，何以问起本派的心经？";

	if (me->query_skill("yunv-xinfa", 1) < 55)
		return RANK_D->query_respect(this_player()) +
			"的玉女心法火候太浅，我不能将玉女心经交给你";

	if (query("book_count") < 1)
		return "你来晚了，本派的玉女心经已经被人取走了。";
	add("book_count", -1);
	ob = new("/clone/book/yunvjing2");
	ob->move(me, 1);
	return "好吧，这本「玉女心经」你拿回去好好研读。";
}

void reset()
{
	set("book_count", 1);
}
