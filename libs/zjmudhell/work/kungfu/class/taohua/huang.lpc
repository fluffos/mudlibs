// huang.c

inherit NPC;
inherit F_MASTER;
inherit F_GUARDER;
inherit F_QUESTER;

#include <ansi.h>
#include "taohua.h"

void   consider();
string ask_me();
int    ask_leave();
int    ask_medicine();
mixed  ask_qing();
mixed  ask_music_book();

mixed  try_to_learn_bibo();
mixed  try_to_learn_lanhua();
mixed  try_to_learn_tanzhi();
mixed  try_to_learn_yuxiao();

void create()
{
	set_name("黄药师", ({"huang yaoshi", "huang", "yaoshi"}));
	set("title", "桃花岛主");
	set("nickname", HIY "东邪" NOR );
	set("gender", "男性");
	set("age", 42);
	set("long", 
		"他就是桃花岛主。行事好恶全由己心，因此被人称作「东邪」。\n");
	set("attitude", "peaceful");
	set("class", "scholar");
	
	set("str", 31);
	set("int", 38);
	set("con", 34);
	set("dex", 32);
	set("shen_type", 1);

	set("chat_chance", 1);
	set("chat_msg", ({
		"黄药师叹了口气道：“唉 …… 蓉儿这苦命的孩子，从小就没了娘 ……”\n",
		"黄药师低头沉思，悠然不语。\n",
	}));

	set("qi", 5800);
	set("max_qi", 5800);
	set("jing", 2900);
	set("max_jing", 2900);
	set("neili", 7000);
	set("max_neili", 7000);
	set("jiali", 100);

	set("combat_exp", 2500000);
	 
	set_skill("force", 270);	     // 基本内功
	set_skill("bibo-shengong", 270);     // 碧波神功
	set_skill("luoying-xinfa", 270);     // 落英心法
	set_skill("hand", 250);	      // 基本手法
	set_skill("finger", 270);	    // 基本指法
	set_skill("tanzhi-shentong", 270);   // 弹指神通
	set_skill("unarmed", 220);	   // 基本拳脚
	set_skill("strike", 220);	    // 基本拳脚
	set_skill("luoying-shenzhang", 250); // 落英神剑掌
	set_skill("xuanfeng-leg", 250);      // 旋风扫叶腿
	set_skill("dodge", 270);	     // 基本躲闪
	set_skill("anying-fuxiang", 270);    // 暗影浮香
	set_skill("parry", 270);	     // 基本招架
	set_skill("sword", 270);	     // 基本剑法
	set_skill("throwing", 270);	     // 基本暗器
	set_skill("luoying-shenjian", 270);  // 落英神剑
	set_skill("yuxiao-jian", 270);       // 玉箫剑法
	set_skill("lanhua-shou", 270);       // 兰花拂穴手
	set_skill("qimen-wuxing", 250);      // 奇门五行
	set_skill("count", 300);	     // 阴阳八卦
	set_skill("mathematics", 300);       // 算术
	set_skill("literate", 250);	  // 读书识字
	set_skill("chuixiao-jifa", 300);     // 吹箫技法
	set_skill("bihai-chaosheng", 300);   // 碧海潮生
	set_skill("taohua-yuan", 250);       // 桃花怨
	set_skill("medical", 300);	   // 基本医术
	set_skill("taohua-yaoli", 300);      // 桃花药理

	map_skill("force"  , "bibo-shengong");
	map_skill("finger" , "tanzhi-shentong");
	map_skill("hand"   , "lanhua-shou");
	map_skill("unarmed", "xuanfeng-leg");
	map_skill("strike" , "luoying-shenzhang");
	map_skill("dodge"  , "anying-fuxiang");
	map_skill("parry"  , "tanzhi-shentong");
	map_skill("sword"  , "yuxiao-jian");
	map_skill("chuixiao-jifa", "bihai-chaosheng");
	map_skill("throwing", "tanzhi-shentong");

	prepare_skill("finger" , "tanzhi-shentong");
	prepare_skill("hand"   , "lanhua-shou");

	set("no_teach", ([
		"bibo-shengong"   : (: try_to_learn_bibo :),
		"lanhua-shou"     : (: try_to_learn_lanhua :),
		"tanzhi-shentong" : (: try_to_learn_tanzhi :),
		"yuxiao-jian"     : (: try_to_learn_yuxiao :),
	]));

	set("inquiry", ([
		"旋风扫叶腿法" : (: ask_me :),
		"秘籍"      : (: ask_me :),
		"离岛"      : (: ask_leave :),
		"黄蓉"      : "你敢直称我女儿的闺名？ ",
		"九阴真经"  : "如果你能帮我取得真经上册，我一定重重谢你。",
		"兰花手"    : "兰花拂穴手... 唉，可惜我几个弟子都算不得成才！",
		"弹指神通"  : "我... 我... 一身绝艺竟然无人可以继承？",
		"玉萧剑法"  : "哈哈... 不是性情中人，如何能够领会这剑法？",
		"碧波神功"  : "唉... 我桃花岛的内功何等厉害，可惜...",
		"吹箫"      : "对吹箫(chuixiao-jifa)有兴趣么？跟我学点？",
		"天地情长"  : (: ask_qing :),
		"绝招"      : (: ask_qing :),
		"绝技"      : (: ask_qing :),
		"桃花药理"  : (: ask_medicine :),
		"制药"      : (: ask_medicine :),
		"九花玉露丸": "这个东西难制得紧，你好好学学桃花药理，以后自己制吧。",
		"无常丹"    : "嗯...等你学通了桃花药理的奥妙，自己慢慢制吧。",
		"箫谱"      : (: ask_music_book :),
	]));

	create_family("桃花岛", 1, "岛主");

	set("chat_chance_combat", 120);
	set("chat_msg_combat", ({
		(: perform_action, "sword.bihai" :),
		(: perform_action, "sword.qing" :),
		(: perform_action, "sword.tianwai" :),
		(: perform_action, "hand.fuxue" :),
		(: perform_action, "finger.jinglei" :),
		(: exert_function, "powerup" :),
		(: exert_function, "recover" :),
	}));

	set_temp("apply/attack", 150);
	set_temp("apply/defense", 150);
	set_temp("apply/damage", 100);
	set_temp("apply/unarmed_damage", 100);
	set_temp("apply/armor", 200);

	setup();

	set("book_count", 1);
	set("taohua_book", 1);
	set("music_book", 1);

	carry_object("/d/taohua/obj/yuxiao")->wield();
	carry_object("/d/taohua/obj/bupao")->wear();
}

int recognize_apprentice(object ob, string skill)
{
	if (skill == "chuixiao-jifa" ||
	    skill == "taohua-yuan")
	{
		if (! ob->query_temp("can_learn/huang/chuixiao-jifa"))
		{
			ob->set_temp("can_learn/huang/chuixiao-jifa", 1);
			command("say 你既然对吹箫有兴趣，我就教你一点吧。");
		}
		return 1;
	}

	return 0;
}

mixed try_to_learn_bibo()
{
	object ob = this_player();

	if (ob->query("can_learn/huang/bibo-shengong"))
		return 0;

	if (ob->query_skill("luoying-xinfa", 1) >= 120)
	{
		command("say 哈哈！想不到我的弟子如此出色，你的"
			"落英心法已颇有造诣，我就传你碧波神功吧！");
		ob->set("can_learn/huang/bibo-shengong", 1);
		return 0;
	}

	return "碧波神功是我独门内功，概不外传。";
}

mixed try_to_learn_lanhua()
{
	object ob = this_player();

	if (ob->query("can_learn/huang/lanhua-shou"))
		return 0;

	if (ob->query_skill("bibo-shengong", 1) >= 100)
	{
		command("say 不错，不错！你碧波神功已经颇有基"
			"础了，我就传你兰花拂穴手法吧！");
		ob->set("can_learn/huang/lanhua-shou", 1);
		return 0;
	}

	return "兰花拂穴手不外传。";
}

mixed try_to_learn_tanzhi()
{
	object ob = this_player();

	if (ob->query("can_learn/huang/tanzhi-shentong"))
		return 0;

	return "想学我成名绝技？嘿嘿...";
}

mixed try_to_learn_yuxiao()
{
	object ob = this_player();

	if (ob->query("can_learn/huang/yuxiao-jian"))
		return 0;

	if (ob->query("couple"))
	{
		command("say 看你也是性情中人，就传你玉箫剑法吧！");
		ob->set("can_learn/huang/yuxiao-jian", 1);
		return 0;
	}

	return "唉！玉萧剑法只赋予有缘人！";
}

void attempt_apprentice(object ob)
{
	string master;
	string *app = ({ "冯默风", "陆乘风", "曲灵风" });

	if (! permit_recruit(ob))
		return;

	if (ob->query_int() < 28)
	{
		command("say 我不收资质差的弟子，您请回吧！");
		return;
	}

	if ((int)ob->query("shen") >100000 || (int)ob->query ("shen") < -100000 )
	{
		command("say 我桃花岛与世隔绝，向来不与您这种成名人物打交道，您请回吧！");
		return;
	}

	if (ob->query("combat_exp") < 200000)
	{
		if (stringp(master = ob->query_temp("taohua/master")))
		{
			command("say 不是让你和" + master + "学艺吗？你这人怎么回事？");
			return;
		}

		if (ob->query("family/family_name") == "桃花岛" &&
		    ob->query("family/master_name") != "黄药师")
		{
			command("say 好好和" + ob->query("family/master_name") +
				"学艺，不要三心二意，到了一定水平我自然会亲自点拨你。");
			return;
		}

		master = app[random(sizeof(app))];
		
		command("say 我收你入桃花岛了，不过你武学方面成就有限，先和我弟子" +
			master + "学习吧。");
		ob->set_temp("taohua/master", master);
		ob->set("family/family_name", "桃花岛");
		return;
	}

	command("say 很好，很好。");
	command("recruit " + ob->query("id"));
}

string ask_me()
{
	object ob;
	
	if (this_player()->query("family/master_id")!="huang yaoshi")
		return RANK_D->query_respect(this_player()) + 
		"非我弟子，不知此话从何谈起？";
	if (query("book_count") < 1)
		return "你来晚了，本派的秘籍不在此处。";
	add("book_count", -1);
	ob = new("/clone/book/xuanfeng_book");
	ob->move(this_player());
	return "好吧，这本「旋风扫叶腿法」你拿回去好好钻研。";
}

int ask_leave()
{
	object me;

	me = this_player();
	if (me->query("family/family_name") == "桃花岛")
	{
		message_vision("$N对$n怒道：你既然入了桃花岛门下，"
			       "桃花阵就不会伤害你，要离岛自己走去海边！\n",
				this_object(), me);
		return 1;
	}

	command("say 好吧，我就送你一程。");
	message_vision("$N说罢，一掌拍在$n的屁股上，就见$n一"
		       "个平沙落雁式飞了出去。\n", this_object(), me);
	me->move("/d/taohua/haitan");
	message_vision("$N一跤摔在沙滩上，哼哼呀呀半天才起来。\n", me);
	return 1;
}

mixed ask_qing()
{
	object me;

	me = this_player();
	if (me->query("can_perform/yuxiao-jian/qing"))
		return "你好好练习武功，不要丢我的脸！";

	if (me->query("family/family_name") != query("family/family_name"))
		return "你不是我们桃花岛的人，打听我的武功想要干什么？";

	if (me->query_skill("yuxiao-jian", 1) < 100)
		return "就你这点本事？等你把玉箫剑法练熟了再来找我吧！";

	message_vision(HIC "$n" HIC "举头望天，若有所思，随手搭在$N"
		       HIC "的肩头，$N" HIC "忽然发现内力源源而逝，不由大惊！"NOR"\n",
		       me, this_object());
	command("sigh");
	command("say 你懂了么？");
	tell_object(me, HIG "你通晓了天地情长的奥妙。"NOR"\n");
	if (me->can_improve_skill("force"))
		me->improve_skill("force", 90000);
	me->set("can_perform/yuxiao-jian/qing", 1);
	me->set("neili", 0);
	return 1;
}

int ask_medicine()
{
	object me;
	object ob;

	me = this_player();
	if (me->query("family/family_name") != query("family/family_name"))
	{
		command("say 你是什么人，打听我的医书有何目的？");
		return 1;
	}

	if ((int)me->query_skill("taohua-yaoli", 1) < 100)
	{
		command("say 你对桃花药理的了解太浅，等你学得再"
			"好一些我才能把秘本传与你。");
		return 1;
	}

	if (query("taohua_book") < 1)
	{
		command("say 真是可惜，你来晚了，书我已经借出去了。");
		return 1;
	}

	add("taohua_book", -1);
	ob = new("/clone/book/taohua");
	message_vision("$n拿出一本泛黄的薄册子递给$N，叮嘱"
		       "道：“你可要给我好好研读！”\n",
		       me, this_object());
	ob->move(me, 1);
	return 1;
}

int accept_object(object who, object ob)
{
	int r;

	if (r = ::accept_object(who, ob))
		return r;

	if (ob->query("id") == "jiuyin zhenjing2")
	{
		destruct(ob);
		command("sigh");
		if (who->is_apprentice_of(this_object()))
		{
			if (who->query("can_learn/huang/tanzhi-shentong"))
				return 1;
			command("say 好...好！不愧是我的好徒儿，不像... 唉！");
			command("look " + who->query("id"));
			if (who->query("combat_exp") < 500000)
			{
				command("say 我倒想教你一门绝技，可惜"
					"你现在武功太差、经验不足，还是以后再说吧！");
				return 1;
			}
			command("haha");
			command("say 你武功已然不错，好！我就传你弹指"
				"神通指法，你要好好学习这门绝技！");
			who->set("can_learn/huang/tanzhi-shentong", 1);
			return 1;
		}
		message_vision("$N对$n道：多谢这位" +
			       RANK_D->query_respect(who) + "了。\n",
			       this_object(), who);
		return 1;
	}

	return 0;
}

mixed ask_music_book()
{
	object me;
	object ob;

	me = this_player();
	if (query("music_book") < 1)
		return "我的箫谱已经借出去了。\n";

	ob = new("/clone/book/xiaopu");
	ob->move(me, 1);
	message_vision("$n把箫谱给了$N，道：你拿去自己好好研究吧。\n",
		       me, this_object());
	set("music_book", 0);
	return 1;
}

void reset()
{
	set("music_book", 1);
	set("book_count", 1);
	set("taohua_book", 1);
}

void unconcious()
{
	die();
}
