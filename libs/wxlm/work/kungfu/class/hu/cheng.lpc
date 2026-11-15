// NPC: cheng.c 陈灵素
// Date: Mar. 1 2002 Modify by Pound



inherit NPC;

string ask_me();
int    ask_shu();
int    ask_candle();
int    ask_lianzhi();

void create()
{
	set_name("陈灵素", ({ "cheng lingsu", "cheng" }));
	set("gender", "女性");
	set("age", 24);
	set("long", @long
她看上去双眉紧缩，不知道有什么心事，长得相貌平平，并不出众。
身材瘦小，穿着粗布衣衫。
long);
	set("attitude", "peaceful");
	set("str", 22);
	set("int", 35);
	set("con", 31);
	set("dex", 27);
	set("chat_chance", 10);
	set("chat_msg", ({
		"陈灵素哀哀的叹了口气。\n",
	}));

	set("qi", 2500);
	set("max_qi", 2500);
	set("jing", 1200);
	set("max_jing", 1200);
	set("neili", 2800);
	set("max_neili", 2800);
	set("jiali", 40);
	set("combat_exp", 400000);
     
	set_skill("force", 150);
	set_skill("poison", 270);
	set_skill("dispel-poison", 270);
	set_skill("medical", 270);
	set_skill("yaowang-miaoshu", 270);

	set("inquiry",([
		"胡飞"     : "他...他...\n",
		"原紫衣"   : "我...你提他干什么？\n",
		"药王神篇" : (: ask_shu :), 
		"七心海棠" : "幸好这七心海棠难以培植，否则世上还有谁能得平安。\n",
		"种子" : (: ask_me :),
		"蜡烛" : (: ask_candle :),
		"炼制蜡烛" : (: ask_lianzhi :),
	]));

	set("book_count", 1);

	setup();
	carry_object("/clone/cloth/cloth")->wear();
}

int recognize_apprentice(object me, string skill)
{
	if (me->query("family/family_name") != "关外胡家")
	{
		command("say 你是谁？来干什么？");
		return -1;
	}

	if (skill != "poison" && skill != "dispel-poison" &&
	    skill != "medical" && skill != "yaowang-miaoshu")
	{
		command("say 我只会毒功和医术，别的我就没法子教你啦！");
		return -1;
	}

	if ((int)me->query("shen") < 0)
	{
		command("sigh");
		command("say 你怎能走上邪路？我可不能教你毒技。");
		return -1;
	}

	if (! me->query_temp("can_learn/cheng/poison"))
	{
		me->set_temp("can_learn/cheng/poison", 1);
		command("say 看在胡飞的面子上，我就教你一点本事吧，你可要好自为之！");
		return 1;
	}

	return 1;
}

int ask_shu()
{
	object me;
	object ob;

	me = this_player();
	if (me->query("family/family_name") != "关外胡家")
	{
		command("say 你是谁？想干啥？");
		return -1;
	}

	if (me->query_skill("yaowang-miaoshu", 1) < 50)
	{
		command("say 你于药道了解的太少，还是先好好和我学学吧。");
		return -1;
	}

	if (query("book_count") < 1)
	{
		command("say 没了，刚借走。");
		return -1;
	}

	message_vision("$N掏出一本小册子，递给$n，叮嘱道："
		       "“你就好好研究吧，可别糟踏了。”\n",
		       this_object(), me);
	ob = new("/clone/book/yaowang");
	ob->move(me, 1);
	add("book_count", -1);
	return 1;
}

int ask_candle()
{
	object me;
	object ob;
	int count;

	me = this_player();
	if (me->query("family/family_name") != "关外胡家")
	{
		command("say 你是谁？想干啥？");
		return -1;
	}

	if (present("haitang candle", me))
	{
		command("say 你身上不是有一根么？千万要慎重使用呀！");
		return -1;
	}

	if (! me->query("yaowang/makehaitang"))
	{
		command("say 七心海棠毒性极强，炼制成蜡烛以后更能杀人于无形之中。");
		me->set_temp("yaowang/candle/ask", 1); // 设置临时参数用于陈灵素接受七心海棠
		return -1;
	}

	count = me->query("yaowang/makehaitang"); 
	message_vision("$N从怀中掏出一根细小的蜡烛，递给$n，叮嘱道："
		       "“这蜡烛点燃后可以杀人于无形，慎之慎之。”\n",
		       this_object(), me);
	ob = new("/clone/herb/candle");
	ob->move(me, 1);
	me->set("yaowang/candle/using", count); // 蜡烛可使用的次数
	tell_object(me, "七心海棠蜡烛还能使用" + count + "次。\n");
	me->delete("yaowang/makehaitang");
	return 1;
}

int ask_lianzhi()
{
	object who, me, ob;
	int count;

	me = this_object();
	who = this_player();
	if(objectp(ob = present("qixin haitang", who)) && who->query_temp("yaowang/candle/ask")) 
	{
	    count = 4 - who->query("yaowang/qxht/using");

	    if (count < 2)
	    {
		command("hmm");
		command("say 七心海棠都快被你用完啦，已经不能用来炼制蜡烛了。");
		return 0;
	    }

	    who->set("yaowang/makehaitang", count);
	    destruct(ob);
	    who->delete("yaowang/qxht");
	    message_vision("$n给了$N一棵七心海棠。\n", me, who);
	    command("say 我这就去帮你炼制蜡烛，你先去忙吧，过段时间再来跟我要。");
	    message_vision("$N急急忙忙地离开了。\n", me);
	    destruct(me);
	    return 1;
	}
	return 0;
}

string ask_me()
{
	object me;
	me = this_player();

	if (me->query("family/family_name") != "关外胡家")
	{
	    command("en");
	    return "你问的事情太多了吧。\n";
	}

// 如小说所写，先帮忙做些舀粪浇花的工作，程才会产生好感，有可能告诉你秘密。
	if (me->query_temp("yaowang/jiao") < 30)
	{
	    return "师祖曾从海外得了这七心海棠的种子，传给了师父九粒！\n";
	}
	else
	{    
	    if (me->query_skill("yaowang-miaoshu", 1) < 200)
	    {
		return ("这七心海棠的极难培植，以你的修为恐怕种它不活！\n"); 
	    }
	    command("nod"); 
	    me->set_temp("yaowang/zhongzi", 1);
	    return "你到房里找师父留下的七心海棠种子培植看看，记得不要用来害人！\n";
	}
}

void reset()
{
	set("book_count", 1);
}