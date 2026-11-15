// feng.c

#include "taohua.h"

inherit NPC;
inherit F_MASTER;

int ask_me();

void create()								   
{
	set_name( "冯墨封" ,({ "feng mofeng", "feng" }));
	set("gender", "男性");
	set("age", 39);
	set("long",
	    "冯墨封是黄岛主最小的一个徒弟，他的根基不错，但性子较为愚鲁。\n"
	    "他的基本功扎实，一副忠厚老实的样子。\n");
	set("attitude", "friendly");
	set("class", "scholar");
	set("str", 30);
	set("int", 24);
	set("con", 27);
	set("dex", 23);
	set("shen_type",1);

	set("chat_chance", 1);
	set("chat_msg", ({
	    "冯墨封说道：“师父疼爱小师妹，他的软猬甲一直由小师妹穿着。”\n",
	    "冯墨封自言自语地说道：“这个桃花阵，嗨，不简单！”\n",
	}));

	set("max_qi", 4100);
	set("max_jing", 2100);
	set("neili", 4500);
	set("max_neili", 4500);
	set("jiali", 50);
	set("combat_exp", 950000);

	set_skill("force", 165);	    // 基本内功
	set_skill("luoying-xinfa", 165);    // 落英心法
	set_skill("unarmed", 140);	  // 基本拳脚
	set_skill("xuanfeng-leg", 140);     // 旋风扫叶腿
	set_skill("strike", 150);	   // 基本掌法
	set_skill("luoying-shenzhang", 150);// 落红凝剑掌
	set_skill("dodge", 140);	    // 基本躲闪
	set_skill("anying-fuxiang", 140);   // 暗影浮香
	set_skill("parry", 160);	    // 基本招架
	set_skill("sword", 140);	    // 基本剑法
	set_skill("luoying-shenjian", 140); // 落英神剑
	set_skill("literate", 90);	  // 读书识字

	map_skill("force"  , "luoying-xinfa");
	map_skill("unarmed", "xuanfeng-leg");
	map_skill("strike" , "luoying-zhang");
	map_skill("dodge"  , "anying-fuxiang");
	map_skill("parry"  , "luoying-shenjian");
	map_skill("sword"  , "luoying-shenjian");

	prepare_skill("unarmed", "xuanfeng-leg");
	prepare_skill("strike" , "luoying-zhang");

	create_family("桃花岛", 2, "弟子");

	set("inquiry", ([
	   "桃花岛":   "这儿就是桃花岛，你若不是本派弟子，要过桃花阵。",
	   "桃花阵":   "往南就是了。",
	   "东邪":     "家师人称东邪！呵呵。",
	   "西毒":     "欧阳锋是与家师并世齐名的高手，人称老毒物。",
	   "南帝":     "听家师说段王爷现在出家当了和尚，法名一灯。",
	   "北丐":     "北丐洪九指是丐帮帮主，现在扬州城外。",
	   "黄帮主":     "她是师父的爱女。",
	   "黄岛主":   "你要拜访家师？",
	   "拜师":     (: ask_me :),
	   "投师":     (: ask_me :),
	]) );
	setup();
	carry_object("/clone/misc/cloth")->wear();
	carry_object("/clone/weapon/changjian");
}									       

void attempt_apprentice(object ob)
{
	string master;
	if (! permit_recruit(ob))
		return;
	
	if (stringp(master = ob->query_temp("taohua/master")))
	{
		if (master != name())
		{
			command("say 家师不是让你拜" + master +
				"的吗？你怎么来找我来了？");
			return;
		}

		command("say 好吧，既然家师有令，我就收下你了，不过要好好遵守桃花岛的规矩。");
		command("recruit " + ob->query("id"));
		ob->delete_temp("taohua/master");
		return;
	}

	if (ob->query("family/master_name") == "黄岛主" &&
	    ob->query("family/family_name") == "桃花岛")
	{
		command("say 大家都是黄岛主的弟子，你就别和我寻开心了。");
		return;
	}

	command("shake");
	command("say 我可不敢擅自收徒，你还是找家师黄岛主吧！");
}

int accept_fight(object ob)
{
	command("wield jian");
}

int ask_me()
{
	object me;

	me = this_player();
	if (me->query("family/family_name"))
	{
		if (me->query("family/family_name") != "桃花岛")
		{
			command("say 阁下已有门派，家师是不会收留你的，请走吧！");
			return 1;
		}

		if (me->query("family/master_name"))
		{
			command("say 你已在我们桃花岛学艺，就别和我开玩笑了。");
			return 1;
		}
	}

	if (me->query("detach/桃花岛"))
	{
		command("say 当年你离开了桃花岛，今天还敢回来见家师？");
		return 1;
	}

	if (me->query("betrayer/times"))
	{
		command("say 你这判师之人，家师是绝对不会收你为徒的！");
		return 1;
	}

	command("say 好吧，我带你过桃花阵，你自己去找黄岛主吧。");
	tell_object(me, "你开始和紧跟冯墨封。\n");
	message_vision("$N大步的向南走去，$n紧随其后。\n", this_object(), me);
	this_object()->move("/d/taohua/damen");
	me->move("/d/taohua/damen");
	command("say 好了，我带你到大门，你进去就可以见到家师了，我先走了。");
	message_vision("$N头也不回的往北面去了。\n", this_object());
	this_object()->move(query("startroom"));
	message_vision("$N急匆匆的走了过来。\n", this_object());
	return 1;
}
