// 负责京畿武官，皇宫侍卫的赏罚，记录，升迁，降级等

#include <ansi.h>
inherit NPC;
#include <title.h>
#include "ct_title.h"
string do_shengqian();
string do_salary();
int ask_salary2();
void do_check(object ob);
string do_achievement();
int ask_emperor();
void create()
{
    int i, *speed_cur;

    set_name("吴潜", ({"wu qian", "wu"}));
    set("title", HIR"大宋"+HIW+"  枢密使"+NOR);
    set("gender", "男性");
    set("age", 50);
    set("long", "他就是当今朝廷的枢密相公吴潜。\n");
    set("attitude","heroism");
    set("generation",0);

    set("max_qi",800);
    set("eff_qi",800);
    set("qi",800);
    set("max_jing",300);
    set("jing",300);
    set("shen_type",1);
    set("no_clean_up",1);
    set("combat_exp",20000);

    create_family("朝廷", 2, "官员");

	set("inquiry", ([
	"任务" : "这个你去问问袁大府吧。",
	"job" : "这个你去问问袁大府吧。",
	"升迁" : (: do_shengqian :),
	"晋升" : (: do_shengqian :),
	"promotion" : (: do_shengqian :),
        "奖金": (: do_salary :),
        "bonus": (: do_salary :),
     
    // "package": (: ask_salary2 :),
	"功劳": (: do_achievement :),
	"御前问对": (:ask_emperor:),
	]));

    setup();
    carry_object("/d/song/npc/obj/cloth1")->wear();
}
int grant_ob(object me)
{
	string title;
	if (me->query("class")!="officer")
	return 0;
	if (me->query("pin")!=1)
	return 0;
	if (me->query("chaoting/wang")||me->query("chaoting/jiawang"))
	return 0;
	command("say 大人在襄阳劳苦功高，朝廷特晋大人为上柱国。");
	me->set("chaoting/wang",1);
	me->delete("chaoting/prewang");
	title=give_title(me);
	if (me->query("pin")==1)
	CHANNEL_D->do_channel(this_object(), "jh", me->query("name")+"积累功勋，特晋上柱国、骠骑大将军。\n");
	me->set("title", title);
//title系统记录玩家title by seagate@pkuxkx
	me->set_title(TITLE_RANK, title);
	return 1;
}
int init()
{
	object ob = this_player();
    	do_check(ob);
		if (ob->query("chaoting/prewang/total_check")>=7&&!ob->query("chaoting/wang")&&!ob->query("chaoting/jiawang"))
		{
			grant_ob(ob);
		}
}
int ask_emperor()
{
	object *all_ob,me=this_player();
	int *set=({}),count=0;
	if (me->query("pin")>2||me->query("class")!="officer")
	{
		command("say 官家并没有召见你。");
		return 1;
	}
	all_ob=all_inventory(me);
	for (int i=0;i<sizeof(all_ob);i++)
	{
		if (all_ob[i]->query("Strategy_Book_Series")&&member_array(all_ob[i]->query("Strategy_Book_Series"),set)==-1)
		{
			set+=({all_ob[i]->query("Strategy_Book_Series")});
			count+=1;
		}
	}
	if (count<7)
	{
		command("say 你尚未备齐兵书，去御前不怕丢人吗？");
		return 1;
	}
	me->set_temp("chaoting/see_emperor",1);
	command("say 官家正在传召你，快去御前吧。");
	return 1;
}
void do_check(object ob)
{
	if(ob->query("class") == "officer"
		&& ob->query_condition("bjkiller"))
	{
		message_vision(HIR"$N对$n怒喝道：「身为朝廷官员居然知法犯法，念你初犯姑且记你一过，记住，若有再犯军法伺候！！」\n"NOR, this_object(), ob);
		ob->add("chaoting/mistake", 1);
		ob->set("chaoting/salary", ob->query("chaoting/salary") + 7200);
		ob->clear_condition("bjkiller");
		tell_object(ob,"你被扣除了一个月的俸禄。\n你被兵部记过一次。\n");
	}
	if(ob->query("class") == "officer"
		&& ob->query("chaoting/job_fail") / (ob->query("chaoting/job_bonus") + 1) >= 10 )
	{
		message_vision(HIR"$N对$n怒喝道：「身为朝廷官员屡次玩忽职守，念你初犯姑且记你一过，记住，若有再犯军法伺候！！」\n"NOR, this_object(), ob);
		ob->add("chaoting/mistake", 1);
		ob->set("chaoting/salary", ob->query("chaoting/salary") + 7200);
		ob->add("chaoting/job_bonus", 1);
		tell_object(ob,"你被扣除了一个月的俸禄。\n你被兵部记过一次。\n");
	}
	if(ob->query("class") == "officer" && ob->query("chaoting/mistake") >= 10 )
	{
		message_vision(HIR"$N对$n怒喝道：「身为朝廷官员屡次知法犯法，来人啊，给我拉出去斩了！！」\n"NOR, this_object(), ob);
		message_vision(HIR"$N吓得面如土灰，全身不断哆嗦。\n"NOR, ob);
		ob->start_busy(100);
		remove_call_out("responsing");
		call_out("responsing", 3, ob);
	}
}
void processing(object ob)
{
    if (ob->is_ghost()) return;
	ob->revive();
	write(HIW "\n你恢复了神志，环顾四周，只见数十名刽子手将你团团围起来，\n"
		"一片雪亮的刀光逼得你眼都睁不开。正前方的高台上放着一把\n"
		"铡刀，笼罩着浓烈的肃杀的气氛。\n\n" NOR);
	message_vision(HIR "周围挤满了围观群众，$N心道：「这回真的完了。」\n"
			"旁边的监斩官员扔出一道令牌，.....\n"
			"刽子手大刀一挥..........\n\n" NOR, ob);
	ob->set("chaoting/mistake",0);
	ob->add("chaoting/decapitate", 1);
	ob->start_busy(0);
    ob->receive_damage("qi", 0, this_object());
	ob->die();
	CHANNEL_D->do_channel(this_object(), "rumor", ob->name()+"在大理寺外被斩首示众！");
	return;
}
void responsing(object ob)
{
	if( !ob||ob->is_ghost() ) return;
	message_vision(HIR "兵营内冲进来几个官兵，将$N五花大绑！\n" NOR, ob);
	remove_call_out("beating");
	call_out("beating", 8, ob);
	return;
}
void beating(object ob)
{
	if( !ob||ob->is_ghost() ) return;
	message_vision(HIY "\n$N喝道：「将$n押到大理寺外斩首示众！！」\n" NOR, this_object(), ob);
	message_vision(HIR "官兵们一涌而上，乱棒齐下将$N打得昏了过去......\n" NOR, ob);
	ob->move("/d/hangzhou/fengbo");
	ob->unconcious();
	remove_call_out("processing");
	call_out("processing", 15, ob);
}



//升值的同时把旧品位的俸禄先结清，以免出现问题(或者判断没结清就不让升)
string do_shengqian()
{
    object me = this_object();
    object player = this_player();
    string *rank_name, title;
    int    pin, i, exp, pot, bonus, age, salary, time;
    string name, new_name;
    string *all_color = ({HIR,HIB,HIG,HIY,HIC,HIW,HIM,GRN});

    name = player->query("name");

    if ( player->query("class") != "officer")
    {
	return "你开什么玩笑？当心我把你抓起来。";
    }
        age = player->query("mud_age");
        salary = player->query("chaoting/salary");
	time = age - salary;

//whuan,2007-3-17
// iszt, 2007-03-18
/*
	if ( time > 7200 )
	return "请先把以前的俸禄结算完毕再升职。";
*/
 
    pin = player->query("pin");

	if (!player->query("chaoting/eunuch") && player->query("chaoting/officer"))
	{
    switch (pin)
    {
    	case 9:
    	if ( player->query("score") < 200)
    	{
		return "你的贡献度不够，怎么升啊？";
    	}
        if ( player->query_skill("strategy", 1) < 30)
	return "你的兵法战策等级不够，怎么升啊？";
        if ( player->query_skill("leadership", 1) < 30)
	return "你的为官之道等级不够，怎么升啊？";

    	break;

    	case 8:
    	if ( player->query("score") < 400)
    	{
		return "你的贡献度不够，怎么升啊？";
    	}
        if ( player->query_skill("strategy", 1) < 50)
	return "你的兵法战策等级不够，怎么升啊？";
        if ( player->query_skill("leadership", 1) < 50)
	return "你的为官之道等级不够，怎么升啊？";

    	break;

    	case 7:
    	if ( player->query("score") < 600)
    	{
		return "你的贡献度不够，怎么升啊？";
    	}
        if ( player->query_skill("strategy", 1) < 80)
	return "你的兵法战策等级不够，怎么升啊？";
        if ( player->query_skill("leadership", 1) < 80)
	return "你的为官之道等级不够，怎么升啊？";

    	break;

    	case 6:
    	if ( player->query("score") < 800)
    	{
		return "你的贡献度不够，怎么升啊？";
    	}
        if ( player->query_skill("strategy", 1) < 100)
	return "你的兵法战策等级不够，怎么升啊？";
        if ( player->query_skill("leadership", 1) < 100)
	return "你的为官之道等级不够，怎么升啊？";
    	break;

    	case 5:
    	if ( player->query("score") < 1000)
    	{
		return "你的贡献度不够，怎么升啊？";
    	}
        if ( player->query_skill("strategy", 1) < 120)
	return "你的兵法战策等级不够，怎么升啊？";
        if ( player->query_skill("leadership", 1) < 120)
	return "你的为官之道等级不够，怎么升啊？";
    	break;

    	case 4:
    	if ( player->query("score") < 1200)
    	{
		return "你的贡献度不够，怎么升啊？";
    	}
        if ( player->query_skill("strategy", 1) < 140)
	return "你的兵法战策等级不够，怎么升啊？";
        if ( player->query_skill("leadership", 1) < 140)
	return "你的为官之道等级不够，怎么升啊？";
        if ( player->query("chaoting/catch_feizei") < 10)
        return "你对地方治安贡献不够，需要抓够十个随机出现的飞贼才可以。";
	player->set("chaoting/salary_feizei",player->query("chaoting/catch_feizei"));
        break;

    	case 3:
    	if ( player->query("score") < 1400)
    	{
		return "你的贡献度不够，怎么升啊？";
    	}
        if ( player->query_skill("strategy", 1) < 170)
	return "你的兵法战策等级不够，怎么升啊？";
        if ( player->query_skill("leadership", 1) < 150)
	return "你的为官之道等级不够，怎么升啊？";
        if ( player->query("chaoting/catch_feizei") < 15)
        return "你对地方治安贡献不够，需要抓够十五个随机出现的飞贼才可以。";
	player->set("chaoting/salary_feizei",player->query("chaoting/catch_feizei"));

    	break;

    	case 2:
        if ( player->query("betrayer") )
    	{
                return "你多次背叛师门，能官至二品已是极致，我看你还是知足吧。";
    	}
        if ( player->query("score") < 1410)
    	{
		return "你的贡献度不够，怎么升啊？";
    	}
        if ( player->query("chaoting/jing") < 1)
    	{
		return "你要为朝廷找齐一些兵书，才能继续升职。";
    	}
        if ( player->query_skill("strategy", 1) < 180)
	return "你的兵法战策等级不够，怎么升啊？";
        if ( player->query_skill("leadership", 1) < 180)
	return "你的为官之道等级不够，怎么升啊？";
    	break;

    	default:
	return "大人您已经是“一人之下，万人之上”了，再升就。。。";
    	break;

	}
	bonus = 1;
	}
	/*else
	if (player->query("chaoting/eunuch") && !player->query("chaoting/officer"))
	{
    switch (pin)
    {
    	case 9:
    	if ( player->query("score") < 200)
    	{
		return "你的功劳不够，怎么升迁啊？";
    	}
    	title = WHT"尚膳监管事太监"NOR;
    	break;

    	case 8:
    	if ( player->query("score") < 400)
    	{
		return "你的功劳不够，怎么升迁啊？";
    	}
    	title = HIC"尚膳监副首领太监"NOR;
    	break;

    	case 7:
    	if ( player->query("score") < 600)
    	{
		return "你的功劳不够，怎么升迁啊？";
    	}
    	title = MAG"尚膳监首领太监"NOR;
    	break;

    	case 6:
    	if ( player->query("score") < 800)
    	{
		return "你的功劳不够，怎么升迁啊？";
    	}
        new_name = name[1..1] + "公公";
        player->set("name", new_name);
        player->set_face( FACE_FACT, player->query("name") );
    	title = HIW"尚膳监副总管太监"NOR;
    	break;

    	case 5:
    	if ( player->query("score") < 1000)
    	{
		return "你的功劳不够，怎么升迁啊？";
    	}
    	title = HIM"尚膳监总管太监"NOR;
    	break;

    	default:
		return "太监能做到你这个份上已经是人之极品了。";
    	break;
	}
	bonus = 2;
	}*/
	else return "出现BUG了:请立刻通知巫师解决！！";

//修改title请同时修改duolong.c和hai.c里面的相应地方 - vast
	exp = bonus * (10 - pin) * (10 - pin) * (10 - pin) * 200;
	pot = bonus * (10 - pin) * (10 - pin) * 100;
	player->add("pin", -1);
	title=give_title(player);
	if (player->query("pin")==1)
	CHANNEL_D->do_channel(this_object(), "jh", player->query("name")+"积累功勋，依制除"+title+"。");
	player->add("combat_exp", exp);
	player->add("potential", pot);
	player->set("title", title);
//title系统记录玩家title by seagate@pkuxkx
	player->set_title(TITLE_RANK, title);
    player->set("chaoting/newtitle",1);
	tell_object(player, "你的经验增加了" + chinese_number(exp)+ "点。\n你的潜能增加了" + chinese_number(pot)+ "点。\n你的俸禄增加了。\n");
        player->set("chaoting/salary", player->query("mud_age"));

    	return "好，" + RANK_D->query_respect(player)+ "贡献度卓著，依制升为" + title + "吧。";
}
/*int ask_salary2()
{
    object me=this_player();
    int i,money=1600000;
    i=50+random(50);
    if (!me->query("chaoting/kingbonus"))
    {
        money=money/100*i;
    }
    
    money=money+(int)me->query("chaoting/kingbonus")*10000;
    if (!me->query("chaoting/wang")&&!me->query("chaoting/jiawang"))
    {
        tell_object(me,"你不是宗室子弟，不能领取宗室俸禄。\n");
        return 1;
    }
    if (me->query("mud_age")-me->query("chaoting/salaryofwang")<86399)
    {
        tell_object(me,"你今年的宗室俸禄已经领过了。\n");
        return 1;
    }
    else
    {
        me->set("chaoting/salaryofwang",me->query("mud_age"));
        MONEY_D->pay_player(me, money);
	    CHANNEL_D->do_channel(this_object(), "sys",sprintf("%s领朝廷俸禄：%s。", me->name(),MONEY_D->money_str(money)));
        tell_object(me,"你的俸禄一共是" + MONEY_D->money_str(money) + "。\n");
	    return 1;
    }
}*/
string do_salary()
{
	int age, salary, time, month, money, remain, feizei, paymonth, feizeigot;
	object me = this_player();
	int *salary_list;
	string strFeizei;
	salary_list = ({
              5000,
			 10000,
			 20000,
			 50000,
			 80000,
			100000,
			120000,
			150000,
			200000,//20 gold
			});
	age = me->query("mud_age");
	salary = me->query("chaoting/salary");
	time = age - salary;
    	if ( me->query("class") != "officer")
	return "你开什么玩笑？当心我把你抓起来。";
	if ( time < 7200 )
	return "急什么？本月还没到发饷银的时候呢。";
	remain = time % 7200;
	month = time / 7200;
	//检查飞贼数量，一月至少抓1-2个飞贼，不能闲着
	feizei = 0;
	paymonth = month;

        //added by iszt, exp must add at least 14k / month
        if(me->query("combat_exp") - me->query("silver/last_exp") < paymonth * (14000 - 500*me->query("pin"))
                && me->query("pin") >= 4)
                return "你的武功精进太慢了，好意思领俸禄？";
        me->set("silver/last_exp", me->query("combat_exp"));

	if (me->query("pin") <4)
	{
                feizei = month-(me->query("chaoting/catch_feizei")-me->query("chaoting/salary_feizei"));
                strFeizei="一";
		if (me->query("pin")==1)
		{
                        strFeizei="两";
                        feizei = month*2-(me->query("chaoting/catch_feizei")-me->query("chaoting/salary_feizei"));
		}
	}
	//
	if (feizei>0)
	{
		paymonth = me->query("chaoting/catch_feizei")-me->query("chaoting/salary_feizei");
		feizeigot = paymonth;
		if (me->query("pin") == 1)
		{
			paymonth = paymonth / 2;		
			me->add("chaoting/salary_feizei",paymonth*2);
		}
		else 	me->set("chaoting/salary_feizei",me->query("chaoting/catch_feizei"));
		money = paymonth * salary_list[9 - me->query("pin")];
		me->set("chaoting/salary", age - remain - (month-paymonth)*7200);
		if (money > 0) 
		{
			MONEY_D->pay_player(me, money);
			CHANNEL_D->do_channel(this_object(), "sys_misc",sprintf("%s领朝廷俸禄：%s。", me->name(),MONEY_D->money_str(money)));
		
                        return "你对地方治安贡献不够，领一个月俸禄至少要抓" + strFeizei + "个随机出现的飞贼。\n你现在有" + 
				CHINESE_D->chinese_number(month) + "个月的俸禄未领，自上次领俸禄以来只抓了" + 
				CHINESE_D->chinese_number(feizeigot) + 
                                "个飞贼，\n只能领" + CHINESE_D->chinese_number(paymonth) + "个月的俸禄，还需抓" + CHINESE_D->chinese_number(feizei) +
				"个飞贼才能领余下的。你的俸禄一共是" + MONEY_D->money_str(money) + "。";
		}
		else 
			return "你对地方治安贡献不够，领一个月俸禄至少要抓" + strFeizei + "个随机出现的飞贼，你现在有" + 
				CHINESE_D->chinese_number(month) + "个月的俸禄未领，自上次领俸禄以来一个飞贼也没抓，还需抓" + CHINESE_D->chinese_number(feizei) +
				"个飞贼才能领余下的。";
	}
	else if (me->query("pin") <4)
	{
		me->add("chaoting/salary_feizei",month);
		if (me->query("pin") == 1)
			me->add("chaoting/salary_feizei",month);
	}		
	money = month * salary_list[9 - me->query("pin")];
	me->set("chaoting/salary", age - remain);
	
	MONEY_D->pay_player(me, money);
	CHANNEL_D->do_channel(this_object(), "sys_misc",sprintf("%s领朝廷俸禄：%s。", me->name(),MONEY_D->money_str(money)));

	return "你的俸禄一共是" + MONEY_D->money_str(money) + "。";
}

string do_achievement()
{
	object me = this_player();
	string msg;
	int n;
	if (me->query("class") != "officer")
	return "你又不是朝廷官员，有什么功劳可言？";
	msg = "你到目前为止共完成：\n";
	if (n = me->query("chaoting/xuncheng"))
	msg += "巡城任务" + chinese_number(n) + "次，\n";
	if (n = me->query("chaoting/gate"))
	msg += "守门任务" + chinese_number(n) + "次，\n";
	if (n = me->query("chaoting/catchman"))
	msg += "抓人任务" + chinese_number(n) + "次，\n";
	if (n = me->query("chaoting/feizei"))
	msg += "抓飞贼任务" + chinese_number(n) + "次，\n";
	if (n = me->query("chaoting/jianzhan"))
	msg += "监斩任务" + chinese_number(n) + "次，\n";
	if (n = me->query("chaoting/job_fail"))
	msg += "你的任务失败次数为" + chinese_number(n) + "次，\n";
	if (n = me->query("chaoting/decapitate"))
	msg += "你被斩首了" + chinese_number(n) + "次。\n";
	if (n = me->query("chaoting/mistake"))
	msg += "你目前被记过了" + chinese_number(n) + "次，要小心哦！！！\n";
	return msg;
}
