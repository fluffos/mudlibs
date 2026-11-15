// zhou.c 周博通


#include "quanzhen.h"

inherit NPC;
inherit F_MASTER;
int ask_jiuyin();

void create()
{
	object book;

	set_name("周博通", ({"zhou botong", "zhou"}));
	set("gender", "男性");
	set("age", 62);
	set("class", "taoist");
	set("nickname",HIY "老顽童" NOR);
	set("long", "他看上去须眉皆白，一副得道模样，然而眼神却透露出一股狡黠。\n");
	set("attitude", "peaceful");
	set("shen_type",1);
	set("str", 31);
	set("int", 36);
	set("con", 32);
	set("dex", 29);

	set("chat_chance_combat", 120);
	set("chat_msg_combat", ({
		(: exert_function, "powerup" :),
		(: exert_function, "recover" :),
		(: perform_action, "strike.ju" :),
	}));

	set("qi", 6200);
	set("max_qi", 6200);
	set("jing", 3100);
	set("max_jing", 3100);
	set("neili", 6500);
	set("max_neili", 6500);
	set("jiali", 50);

	set("combat_exp", 2800000);

	set_skill("force", 280);
	set_skill("quanzhen-xinfa", 280);
	set_skill("xiantian-gong", 280);
	set_skill("sword", 250);
	set_skill("quanzhen-jian",250);
	set_skill("dodge", 260);
	set_skill("jinyan-gong", 260);
	set_skill("parry", 270);
	set_skill("unarmed", 270);
	set_skill("kongming-quan", 270);
	set_skill("strike", 250);
	set_skill("chongyang-shenzhang", 250);
	set_skill("haotian-zhang", 250);
	set_skill("literate", 120);
	set_skill("finger", 250);
	set_skill("taoism", 220);
	set_skill("finger", 260);
	set_skill("zhongnan-zhi", 270);
	set_skill("zuoyou-hubo", 360);

	map_skill("force", "xiantian-gong");
	map_skill("sword", "quanzhen-jian");
	map_skill("dodge", "jinyan-gong");
	map_skill("parry", "kongming-quan");
	map_skill("finger","zhongnan-zhi");
	map_skill("strike", "haotian-zhang");
	map_skill("unarmed", "kongming-quan");

	prepare_skill("unarmed", "kongming-quan");

	create_family("全真教", 1, "掌教");
	set("title", "全真教第一代弟子");

	set("book_count",1);
	set("inquiry", ([
		"全真教" :  "我全真教是天下道家玄门正宗。\n",
		"玄阴真经" : (: ask_jiuyin :),
		"段皇爷" : "段... 段皇爷？人家是皇爷，我不认识！",
		"英姑"   : "你，你说啥？",
		"刘瑛"   : "嗯...嗯...嗯？",
	]));

	set_temp("apply/attack", 50);
	set_temp("apply/dodge", 80);
	set_temp("apply/parry", 80);
	set_temp("apply/unarmed_damage", 30);
	set_temp("apply/damage", 30);

	setup();

	if (clonep())
	{
		book = find_object("/clone/book/jiuyin1");
		if (! book) book = load_object("/clone/book/jiuyin1");
		if (! environment(book))
			book->move(this_object());
	}
		
	carry_object("/d/quanzhen/npc/obj/greenrobe")->wear();
}

int ask_jiuyin()
{
	object me,ob,obj ;
	me = this_player ( ) ;
	obj = find_object("/clone/book/jiuyin1");
	if(obj)
		ob = environment(obj);
	if(ob && ob!=this_object())
	{
		say("老顽童说：玄阴真经之前倒是在我这儿，只可惜被人抢走了，现在在"+ob->query("name")+"身上！\n");
	}
	else
	{
		say("老顽童说：想要玄阴真经？那先陪我玩玩吧，嘿嘿嘿！\n");
	}

	return 1;
}

void attempt_apprentice(object ob)
{
	command("hehe");
	command("inn");
}

int recognize_apprentice(object ob, string skill)
{
	if (! ob->query("can_learn/zhou"))
	{
		message_vision("$N眨眨眼睛，看着$n，嘻嘻笑个不停。\n",
			       this_object(), ob);
		return -1;
	}

	if (skill != "kongming-quan" &&
	    skill != "zuoyou-hubo" &&
	    skill != "unarmed")
	{
		command("say 我...这里可没有什么好教你的！");
		return -1;
	}

	return 1;
}

int accept_fight(object ob)
{
	if (ob->query("combat_exp") < 500000)
	{
		message_vision("$N嘻嘻一笑，对$n道：“你还是"
			       "把功夫练好了再说吧！”\n",
			       this_object(), ob);
		return -1;
	}

	if (is_fighting())
	{
		message_vision("$N对$n叫道：“你先别急，我打完这"
			       "架就来领教你的！”\n",
			       this_object(), ob);
		return -1;
	}

	if (query("qi") < 4000 ||
	    query("jing") < 2000 ||
	    query("neili") < 4000)
	{
		message_vision("$N摇摇头对$n道：“我现在"
			       "太累了，等会儿再说吧！”\n",
			       this_object(), ob);
		return -1;
	}

	if (ob->query("can_learn/zhou"))
	{
		message_vision("$N对$n道：“好，那咱们就玩玩！”\n",
			       this_object(), ob);
		return 1;
	}

	message_vision("$N大喜道，好...好，我正手痒痒，咱们来比划比划！\n",
		       this_object(), ob);

	competition_with(ob);
	return -1;
}

void win()
{
	object ob;
	if (! objectp(ob = query_competitor()))
		return;

	message_vision("$N看了看$n，嘿嘿笑道：“你的水平还算"
		       "是马马虎虎，要好好练功，好好练功。”\n",
		       this_object(), ob);
	::win();
}

void lost()
{
	object ob;
	if (! objectp(ob = query_competitor()))
		return;

	message_vision("$N哎呀一声，抹了抹头上的汗，喜道：“这位" +
		       RANK_D->query_respect(ob) + "，你的武功真厉害，\n"
		       "这样吧，我拜你为师好了，你教我点功夫，我这里有一套"
		       "空灵拳法和玄虚互质\n的小伎俩，你有兴趣也可以学学，怎么样。”\n",
		       this_object(), ob);
	ob->set("can_learn/zhou", 1);
	::lost();
}
