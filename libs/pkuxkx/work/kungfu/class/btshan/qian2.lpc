// banker.c
// originally coded by xiang
// 96-02-16 YZC fixed some math problem
// last changed by bibi on 4,12 1998
// last changed for 去掉所有的busy，现在set_amount() (in /inherit/item/combined.c)   
// 已经改好，不必再有这些busy了
// modified to baituo master by jas 2003.2
// modified by iszt@pkuxkx, 2007-01-15, add ask_silver
// modified by iszt@pkuxkx, 2007-02-16, change to inherit banker

#include <ansi.h>
#include <title.h>
inherit F_MASTER;
inherit NPC;
inherit SILVER_NPC;
inherit BANKER;

int adv();
string ask_me();
string ask_camel();
string rent_camel();
string ask_baituo();
string ask_shedi();
void do_answer(string);

void create()
{
	set_name("钱眼开", ({"qian yankai", "qian", "yankai"}));
	set("long", "他一脸奸诈，十分精明，据说是白驼山在扬州安排的接头人。\n");
	set("title", "钱庄老板");
	set("nickname", "铁公鸡");
	set("gender", "男性");
	set("age", 34);
	set("start_room","/d/city/qianzhuang");

	set("str", 22);
	set("int", 24);
	set("dex", 18);
	set("con", 18);

	set("qi", 800); 
	set("max_qi", 800);
	set("jing", 100);
	set("max_jing", 100);
	set("shen", 0);

	set("combat_exp", 50000);
	set("shen_type", 1);
	set("attitude", "friendly");
	set("env/wimpy", 50);
	set("chat_chance", 2);
	set("chat_msg", ({
	"钱眼开骄傲的说道：本银号已经有上百年的历史，在江南可以说是第一家。\n",
	"钱眼开笑着说道：在本店存钱无利息，客官您看着办吧。\n",
	"钱眼开哭丧着脸说道：巫师为了体谅玩家，连取钱手续费都不收了，让本店赔了一大笔。\n",
	"钱眼开微微一笑，说道：本店还办理不同面额货币的兑换业务。\n",
	"钱眼开微微一笑，说道：如果想一次性存入身上所有黄金，可以cun all gold，同样也可以cun all silver,coin等等。\n",
    (:adv:),
	}));

	set_skill("hand", 50);
	set_skill("strike", 50);
	set_skill("dodge", 50);
	set_skill("parry", 50);
	set_skill("force", 50);
	set_skill("training", 30);
	set_skill("poison", 30);
	set_skill("zhaosheshu", 50);
	set_skill("literate", 50);
	
	set_skill("hamagong",50);
	set_skill("chanchu-bufa", 50);
	set_skill("shexing-diaoshou", 60);
	set_skill("shentuo-zhang", 60);
 
	map_skill("force", "hamagong");
	map_skill("dodge", "chanchu-bufa");
	map_skill("hand", "shexing-diaoshou");
	map_skill("strike", "shentuo-zhang");
	map_skill("parry", "shentuo-zhang");
	
	prepare_skill("strike","shentuo-zhang");
	set("inquiry", ([ 
		"骆驼" : (: ask_camel :),
                "租骆驼" : (: rent_camel :),
                "rent" : (: rent_camel :),
	      "白骆驼" : (: ask_camel :),
		"坐骑" : (: ask_camel :),
	       "camel" : (: ask_camel :),
		"白驼山" : (: ask_baituo :),
		"欧阳锋":(: ask_me() :),
		"分红" : (: ask_silver :),
		"蛇笛" : (: ask_shedi :),
	]) );

	set("silver_name", "分红"); //例银的名称，默认为“例银”
	set("silver_factor", 0.9); //例银的数量因子，默认为1
	set("silver_family_skill", "hamagong"); //门派武功，提升此武功时可以领取例银，默认为parry
	set("msg_silver_firsttime", "让我看看……不错，既然同为白驼山的人，以后你就每月来领分红罢。"); //第一次打听例银的时候说的话
	set("msg_silver_record", "$N在账本上写了半天，记下了什么。\n"); //作记录时的描述\n
	set("msg_silver_check", "$N哗啦哗啦的翻了翻账本。\n"); //检查记录时的描述\n
	set("msg_silver_mudage", "嘿嘿，这个月的分红不是已经给你了么？"); //时间未到不能领取时说的话
	set("msg_silver_paid", "本门绝不亏待忠心有为的佳弟子，这是你的分红。"); //领取成功时说的话
	set("msg_silver_score", "$N微微斜了$n一眼，道：「看来你对庄主确实忠心耿耿啊。」\n"); //由于提升师门忠诚而领取例银时的描述\n
	set("msg_silver_skill", "$N微微斜了$n一眼，道：「看来你的蛤蟆功修为不浅啊。」\n"); //由于提升师门武功而领取例银时的描述\n
	set("msg_silver_exp", "$N微微斜了$n一眼，道：「看来你的武功不错啊。」\n"); //由于提升经验而领取例银时的描述\n
	set("msg_silver_none", "嘿嘿，一事无成还好意思来分红？"); //领取例银条件均不满足时说的话

	create_family("白驼山",3,"弟子");

	set_temp("apply/attack", 100);
	set_temp("apply/defense", 100);
	set_temp("apply/damage", 40);
	set("shen_type",-1);
set("score",5000);
setup();
	add_money("silver", 10);
	carry_object("/clone/misc/cloth")->wear();
}

void init()
{
	npc::init();
	banker::init();
}

int adv()
{
    command("mp 本派弟子可以骑白骆驼在渡口旁的黄河岸边涉水(sheshui)过河。\n");
    command("mp 就在丝绸之路东边，回白驼也是相同的地点涉水而过。\n");
}

int destroying(object ob,object who)
{
	who->move("/d/baituo/gebi");
	destruct(ob);
	return 1;
}

int accept_object(object who, object ob)
{
	int MoneyValue;
	if (who->query("family/family_name") == "白驼山")
		MoneyValue = 2000;
	else
		MoneyValue = 10000;
	if (who->query_temp("baituo/go_bt"))
	{
		if (ob->query("money_id") && ob->value() >= MoneyValue) {
			if (base_name(environment(this_object())) != this_object()->query("start_room"))
			{
				tell_object(who,"钱眼开一脸茫然：「我在哪？？在哪？？我是谁？？是谁？？」\n");
				return 1;
			}
			tell_object(who,"钱眼开一见有钱，喜笑颜开，双手捧过来，揣在怀里，偷偷左右看了看，低声道：我给你指引一条小路，可以直达白驼山！打铁铺的张二楞是我的拜把子兄弟，你回来时可以问他『扬州』！\n");
			tell_object(who,"你沿着钱眼开指点的途径，很快来到白驼山下。\n");
			who->delete_temp("baituo/go_bt");
			who->set_temp("baituo/go_yz",1);
			call_out("destroying",1,ob,who);
			return 1;
		}
	}
	command("say 这种东西鬼才要！滚一边去！");
	return 0;
}

string ask_me()
{
	object me=this_player();
	if(((string)me->query("family/family_name")=="白驼山") 
		|| me->query_temp("baituo_asked") ) 
		return "庄主现在应该在白驼山内。";
	else
		return ("不该知道的事还是不问为好。");
}

string ask_baituo()
{
	object me=this_player();

	tell_object(me,"钱眼开左右看了看，偷偷对着你做了个数钱的手势。\n");
	me->set_temp("baituo/go_bt",1);

	if ((string)me->query("family/family_name")=="白驼山") 
		return "从这里一直向西方走很久就到了，记着过沙漠时要骑骆驼。";
	else if (me->query_temp("baituo_asked"))
		return ("你不是刚问过了么？");         

	me->set_temp("baituo_asked",1);
	command("ah " + me->query("id"));
	return ("你是怎么知道这个秘密的，莫非你想拜入我白驼山门中？");       
}

string ask_shedi()
{
	object me=this_player();
	object di;

	if ((string)me->query("family/family_name")!="白驼山") 
	{
		command("shake");
		return "蛇笛是我的宝贝，可不能给你。";
	}
	
	if ( (int)me->query("purefamily/level") <=0 || me->query("purefamily/family_name") != "白驼山" ) 
	{
		command("sigh");
		return "抱歉，蛇笛只提供给我白驼山的内门弟子。";
	}

	if (present("she di", me))
		return ("你不是已经有了吗，要那么多笛子有什么用？");

	command("ok " + me->query("id"));
	
	di = new("/d/baituo/obj/shedi");
	if (objectp(di))
	{
		di->move(me);
		return "拿去吧！";
	}
	return ("呃……抱歉，我这里也没有蛇笛了。");
}

string ask_camel()
{
	object ob, me=this_player();

	if (me->query("family/family_name")!="白驼山") {
		command("say 你是哪里来的" + RANK_D->query_rude(me) +
			"到我们庄来混食？快给我滚！");
		command("kick " + me->query("id"));
		return ("小心我宰了你！");
	}

	if (me->query_temp("白骆驼") || present("camel",me) || me->query_temp("mark/驼")){
		return("你不是有坐骑了吗？");
	}

	if (query("camel_count") > 1)
		return("骆驼都让你师兄弟们骑走了，"+ RANK_D->query_respect(me)+
		       "要回山，等他们回来在说吧。");

	ob=new("/d/baituo/npc/camel");
	ob->move(environment(me));
	ob->set_lord(me);
	 add("camel_count", 1);
	me->set_temp("mark/驼", 1);
		command("nod");
		say("钱眼开从钱庄后院里牵出一匹骆驼来交给你。\n");
		return(RANK_D->query_respect(me) + "路上小心，早去早归！");
}

void attempt_apprentice(object ob)
{
	if((string)this_player()->query("family/master_id") == "ouyang feng" || (string)this_player()->query("family/master_id") == "ouyang ke")
	{
		command ("say 不敢当，不敢当！");
		return;
	}
	else if ((string)this_player()->query("family/master_id") == "qian yankai")
	{ 
		command("say 你可要好好练功呀！");
		return;
	}
	if (!this_player()->query_temp("baituo_asked"))
	{
		command ("say 老夫不会武功，我可不收什么徒弟！");
		return;
	}
	if ( ob->query("class")=="bonze" ) {
		if (ob->query("gender")=="女性")
			command ("say 小师太练蛤蟆功，不怕别人叫你秃头蛤蟆吗？");
		else
			command ("say 大师傅练蛤蟆功，不怕别人叫你秃头蛤蟆吗？");
		return;
	}
	if( ob->query("family/family_name") == "丐帮") {
		command ("say 庄主平生最恨叫化子，我可不想收你。");
		return;
	}
	if ( ob->query("family/family_name") == "武当派" 
		|| ob->query("family/family_name") == "全真派") {
		command ("say 老道练蛤蟆功，不怕别人叫你牛鼻子蛤蟆吗？");
		return;
	}
	if((int)ob->query("betrayer")>=2)
	{
		command("say 你多次判师，我怎么能够收你！\n");
		return;
	}
	if((int)ob->query("shen")>10000)
	{
		command("say 我不收行事不狠毒的人。\n");
		return;
	}
	if ((string)ob->query("family/family_name") == "灵鹫宫" 
		&& ob->query("lingjiu/xiulian"))
	{
		ob->set_temp("bai/ask",1);
		command("say "+RANK_D->query_respect(ob)+"，你现在拜我似乎会有很大损失，你能拿定主意吗？(answer)");
		
	}
	else
	{
		this_player()->delete_temp("baituo_asked");
		command("say 好吧，"+RANK_D->query_respect(ob)+"！我就收下你了！\n");
		command("recruit "+ob->query("id"));
	}
}

void do_answer(string arg)
{
	object me=this_player();
	if (!me->query_temp("bai/ask")) return;
	if (!arg || (arg != "是" && arg != "能" && arg != "yes"))
		command("say 你说的什么乱七八糟的，看来你是没有诚心，算了！");
	else
	{
		command("say 好吧，"+RANK_D->query_respect(me)+"，我就收下你了！");
		me->set("mud_age",me->query("lingjiu/mud_age"));
		me->set("age",14+me->query("mud_age")/3600/24);
		me->delete("lingjiu/skill_status");
		me->delete("lingjiu/qi");
		me->delete("lingjiu/eff_qi");
		me->delete("lingjiu/max_qi");
		me->delete("lingjiu/jing");
		me->delete("lingjiu/eff_jing");
		me->delete("lingjiu/max_jing");
		me->delete("lingjiu/jingli");
		me->delete("lingjiu/neili");
		me->delete("lingjiu/max_jingli");
		me->delete("lingjiu/max_neili");
		me->delete("lingjiu/combat_exp");
		me->delete("lingjiu/need_xiulian");
		me->delete("lingjiu/mud_age");
		me->delete("lingjiu/xiulian");
		me->delete("lingjiu/last_xiulian_time");
		me->delete_temp("bai/ask");
		command("recruit "+me->query("id"));
	}
}

void recruit_apprentice(object ob)
{
	if( ::recruit_apprentice(ob) )
	{
		if (ob->query("gender")=="女性")
			ob->set("title", HIG "白驼山" NOR + YEL "婢女" NOR);
		else
			ob->set("title", HIG "白驼山" NOR + YEL "家丁" NOR);
//title系统记录玩家title by seagate@pkuxkx
    ob->set_title(TITLE_RANK, ob->query("title"));
	}
}
void re_rank(object student)
{
	if( ::recruit_apprentice(student) )
	{
		if (student->query("gender")=="女性")
			student->set("title", HIG "白驼山" NOR + YEL "婢女" NOR);
		else
			student->set("title", HIG "白驼山" NOR + YEL "家丁" NOR);
//title系统记录玩家title by seagate@pkuxkx
    student->set_title(TITLE_RANK, student->query("title"));
	}
}
string rent_camel()
{
        object ob, me=this_player();

        if (me->query("balance")<50000) {
                command("say " + RANK_D->query_rude(me) +
                        "没钱还想租骆驼？");
                command("goaway " + me->query("id"));
                return ("快滚");
        }

        if (me->query_temp("白骆驼") || present("camel",me) || me->query_temp("mark/驼")){
                return("你不是有坐骑了吗？");
        }

        if (query_temp("rent_count")>=5)
                return("骆驼都让人租走了，"+ RANK_D->query_respect(me)+
                       "要租等下次吧。");

        ob=new("/d/baituo/npc/camel");
        ob->move(environment(me));
        ob->set_lord(me);
        add_temp("rent_count", 1);
        me->set_temp("mark/驼", 1);
        command("interest qian yankai");
         me->add("balance",-50000);
        command("say 租金五两黄金，直接从帐户上扣。");
        say("钱眼开吩咐人从后院里牵出一匹骆驼来交给你。\n");
                return(RANK_D->query_respect(me) + "慢走，欢迎下次光临。");
}
