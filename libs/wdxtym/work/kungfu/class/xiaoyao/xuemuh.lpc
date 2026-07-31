// xuemuh.c 薛慕华
// shilling 97.2

inherit NPC;
inherit F_MASTER;

#include "xiaoyao.h"

int ask_me();
int ask_book();

void create()
{
	set_name("薛慕华", ({ "xue muhua", "xue" }));
	set("long", 
		"他就是号称阎王敌的神医——薛慕华，据说他精通医理，可以起死回生。\n");
	set("gender", "男性");
	set("title","逍遥派“函谷八友”");
	set("nickname","阎王敌薛神医");
	set("age", 50);
	set("class", "shaman");
	set("attitude", "peaceful");
	set("str", 25);
	set("int", 27);
	set("con", 25);
	set("dex", 25);

	set("inquiry", ([
		"疗伤"       : (: ask_me :),
		"医书"       : (: ask_book :),
		"逍遥奇学"   : "逍遥奇学？哦，你是问我要《子午针灸经》吧。",
		"子午针灸经" : (: ask_book :),
		"玉洞黑石丹" : "待你学好了逍遥奇学就可以炼出了。",
		"九转熊蛇丸" : "待你学好了逍遥奇学就可以炼出了。",
	]));

	set("max_qi", 1900);
	set("max_jing", 800);
	set("neili", 3100);
	set("max_neili", 3100);
	set("jiali", 60);
	set("combat_exp", 120000);

	set_skill("force", 90);
	set_skill("dodge", 90);
	set_skill("strike",90);
	set_skill("parry", 90);
	set_skill("feiyan-zoubi",80);
	set_skill("xiaoyao-xinfa", 80);
	set_skill("liuyang-zhang", 80);
	set_skill("medical", 150);
	set_skill("xiaoyao-qixue", 150);

	map_skill("strike", "liuyang-zhang");
	map_skill("dodge", "feiyan-zoubi");
	map_skill("force", "xiaoyao-xinfa");

	prepare_skill("strike", "liuyang-zhang");

	create_family("逍遥派", 3, "弟子");
	setup();

	set("xiaoyao_book", 1); 
	carry_object("/clone/cloth/cloth")->wear();
}

void attempt_apprentice(object ob)
{
	if (! permit_recruit(ob))
		return;

	if (ob->query_int() < 26)
	{
		command("sigh");
		command("say 虽然都说勤能补拙，可是... 我看你还是走吧。");
		return;
	}

	command("say 好吧，我就收下你了，以后要多为逍遥派出力啊。");
	command("recruit " + ob->query("id"));
}

int ask_me()
{
	object ob;
	int time;

	ob = this_player();

	if (ob->query("family/family_name") != "逍遥派")
	{
		 command("say 你不是我派弟子，我不可以为你疗伤。");
		return 1;
	}
	if ((int)ob->query("eff_qi") == (int)ob->query("max_qi"))
	{
		command("?" + ob->query("id"));     
		command("say 你没有受任何伤啊？");
		return 1;
	} else
	if (ob->is_busy())
	{
		command("say 等你有空了再说。");
		return 1;
	} else
	if (objectp(query_temp("recover")))
	{
		command("say 没看见我正忙么！");
		return 1;
	} else
	{
		time = 2 + random(3);
		message_vision("薛慕华喂$N服下一颗药丸，然后盘膝坐下，双掌贴着$N的背心。\n", ob);
		set_temp("recover", ob);
		remove_call_out("recover");
		call_out("recover", time, ob);
		ob->start_busy(time);
		return 1;
	}
}

int recover(object ob)
{
	delete_temp("recover");
	if (! objectp(ob))
		return 0;

	ob->set("eff_qi", (int)ob->query("max_qi"));
	ob->set("eff_jing", (int)ob->query("max_jing"));  
	message_vision("大约过了一盅茶的时份，薛慕华慢慢地站了起来。\n",ob);
	command("say 你的伤势已经全好了,可以走啦。\n");
	 ob->interrupt_me(ob, 5);//解除busy状态
	return 1;
}

int ask_book()
{
	object me;
	object ob;

	me = this_player();
	if (me->query("family/family_name") != query("family/family_name"))
	{
		command("say 你是什么人，打听我的医书有何目的？");
		return 1;
	}

	if ((int)me->query_skill("xiaoyao-qixue", 1) < 100)
	{
		command("say 你对逍遥奇学的了解太浅，等你学得再"
			"好一些我才能把秘本传与你。");
		return 1;
	}

	if (query("xiaoyao_book") < 1)
	{
		command("say 真是可惜，你来晚了，书我已经借出去了。");
		return 1;
	}

	add("xiaoyao_book", -1);
	ob = new("/clone/book/xiaoyao");
	message_vision("$n拿出一本破破烂烂的的小册子递给$N，叮嘱"
		       "道：“嗯，就是这本了，好好看。”\n",
		       me, this_object());
	ob->move(me, 1);
	return 1;
}
