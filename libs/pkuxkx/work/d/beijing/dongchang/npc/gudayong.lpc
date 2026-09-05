// gudayong.c 谷大用

#include <ansi.h>
#include "/d/beijing/autok.h"
#include "autocheck.h"

inherit NPC;
#include <title.h>

string do_shengqian();
string do_salary();
string do_achievement();

void create()
{
        set_name("谷大用", ({"gu dayong", "gu",}));
        set("title", HIY"『内侍八虎』" + MAG"御马监掌印太监"NOR);
        set("long",
                "他主管东厂太监的任命和升迁。\n\n"
        );

        set("gender", "无性");
        set("rank_info/respect", "公公");

        set("attitude", "heroism");
        set("class", "eunuch");

        set("age", 50 + random(20));
        set("shen_type", -1);

				set("pin", 3);
//				set("yin_count", 5);
				
				set("combat_exp", 1000);
      	set("inquiry", ([
      	"晋升" : (: do_shengqian :),
        "俸禄": (: do_salary :),
      	"功劳": (: do_achievement :),
      	]));
		
        set("chat_chance", 15);
        set("chat_msg", ({
//                (: random_move :)
        }) );
        
				setup();

        carry_object("/d/beijing/dongchang/obj/guanfu")->wear();
//        add_money("silver", 50);
}

void init()
{
	object ob;

	::init();
	if( !query_heart_beat(this_object()) ) set_heart_beat(1);

//	add_action("do_join", "join");
	
	ob = this_player();
	do_check(ob, this_object());
}

string do_shengqian()
{
    object me = this_object();
    object player = this_player();
    string *rank_name, title;
    int    pin, i, exp, pot, bonus, age, salary, time;
    string name, new_name;
    string *all_color = ({HIB,HIR,HIG,HIY,HIC,HIM,MAG,YEL});

    name = player->query("name");

    if ( player->query("class") != "eunuch")
    {
	return "你开什么玩笑？当心我把你抓起来。";
    }
        age = player->query("mud_age");
        salary = player->query("dongchang/salary");
	time = age - salary;

//whuan,2007-3-17
// iszt, 2007-03-18
/*
	if ( time > 7200 )
	return "请先把以前的俸禄结算完毕再升职。";
*/
 
    pin = player->query("pin");

//	if (!player->query("dongchang/eunuch") && player->query("dongchang/eunuch"))
//	{
    switch (pin)
    {
    	case 9:
    	if ( player->query("score") < 200)
				return "你的功劳不够，暂时还不能升迁！";

    	if ( player->query("shen") > -5000)
				return "你行事不够心狠手辣，暂时还不能升迁！";
				
	rank_name = ({ HIW"尚膳监奉御"NOR, HIW"尚衣监监丞"NOR});
	title = rank_name[random(sizeof(rank_name))];
    	break;

    	case 8:
    	if ( player->query("score") < 400)
				return "你的功劳不够，暂时还不能升迁！";

    	if ( player->query("shen") > -10000)
				return "你行事不够心狠手辣，暂时还不能升迁！";
				
	rank_name = ({ CYN"尚宝监少监"NOR, CYN"印绶监少监"NOR});
	title = rank_name[random(sizeof(rank_name))];
    	break;

    	case 7:
    	if ( player->query("score") < 600)
				return "你的功劳不够，暂时还不能升迁！";
    	if ( player->query("shen") > -20000)
				return "你行事不够心狠手辣，暂时还不能升迁！";
				
			name = player->query("dongchang/oldname");
			name = name[0..0] + "公公";
			
	rank_name = ({ HIC"内官监管事太监"NOR, HIC"司设监管事太监"NOR,});
	title = rank_name[random(sizeof(rank_name))];
    	break;

    	case 6:
    	if ( player->query("score") < 800)
			return "你的功劳不够，暂时还不能升迁！";
    	if ( player->query("shen") > -50000)
				return "你行事不够心狠手辣，暂时还不能升迁！";
			
    	title = BLU"神宫监管事太监"NOR;
    	break;

    	case 5:
    	if ( player->query("score") < 1000)
			return "你的功劳不够，暂时还不能升迁！";
    	if ( player->query("shen") > -75000)
				return "你行事不够心狠手辣，暂时还不能升迁！";
				
			title = HIB"御用监理刑百户"NOR;
    	break;

    	case 4:
    	if ( player->query("score") < 1200)
			return "你的功劳不够，暂时还不能升迁！";
    	if ( player->query("shen") > -100000)
				return "你行事不够心狠手辣，暂时还不能升迁！";
/*			
        if ( player->query("dongchang/catch_feizei") < 10)
        return "你对地方治安贡献不够，需要抓够十个随机出现的飞贼才可以。";
	player->set("dongchang/salary_feizei",player->query("dongchang/catch_feizei"));
*/	
    	title = HIM"御马监掌刑千户"NOR;
    	break;

    	case 3:
    	if ( player->query("score") < 1400)
			return "你的功劳不够，暂时还不能升迁！";
    	if ( player->query("shen") > -150000)
				return "你行事不够心狠手辣，暂时还不能升迁！";
				
			title = MAG"东厂掌印太监"NOR;
    	break;

    	case 2:
        if ( player->query("betrayer") )
            return "你多次背叛师门，能官至二品已是极致，我看你还是知足吧。";
        if ( player->query("score") < 1500)
						return "你的功劳不够，暂时还不能升迁！";
    	if ( player->query("shen") > -300000)
				return "你行事不够心狠手辣，暂时还不能升迁！";
										
        if ( player->query("dongchang/jing") < 1)
    	{
		return "你的功劳不够，暂时还不能升迁！";
    	}
	
    		title = HIY"司礼监掌印太监"NOR;
    	break;

    	default:
			return "大人您已经是位极人臣了，再升就。。。";
    	break;

		}

//	}

	bonus = 2;

	exp = bonus * (10 - pin) * (10 - pin) * (10 - pin) * 200;
	pot = bonus * (10 - pin) * (10 - pin) * 100;
	player->add("pin", -1);
	title = all_color[random(sizeof(all_color))] + "东厂" + chinese_number(pin - 1) + "品官员 "NOR + title;
	player->add("combat_exp", exp);
	player->add("potential", pot);
	player->set("name", name);
	player->set("title", title);
//title系统记录玩家title by seagate@pkuxkx
	player->set_title(TITLE_RANK, title);
	tell_object(player, "你的经验增加了" + chinese_number(exp)+ "点。\n你的潜能增加了" + chinese_number(pot)+ "点。\n你的俸禄增加了。\n");
  player->set("dongchang/salary", player->query("mud_age"));

    	return "好，" + RANK_D->query_respect(player)+ "功劳卓著，我就升您为" + title + "吧。";
}

string do_salary()
{
	int age, salary, time, month, money, remain, feizei, paymonth, feizeigot;
	object me = this_player();
	int *salary_list;
	string strFeizei;
	salary_list = ({
			  2500,//25 silver
			  5000,
			 10000,
			 25000,
			 40000,
			 50000,
			 60000,
			 75000,
			100000,//10 gold
			});
	age = me->query("mud_age");
	salary = me->query("dongchang/salary");
	time = age - salary;
    	if ( me->query("class") != "eunuch")
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
                feizei = month-(me->query("dongchang/catch_feizei")-me->query("dongchang/salary_feizei"));
                strFeizei="一";
		if (me->query("pin")==1)
		{
                        strFeizei="两";
                        feizei = month*2-(me->query("dongchang/catch_feizei")-me->query("dongchang/salary_feizei"));
		}
	}
	//
	if (feizei>0)
	{
		paymonth = me->query("dongchang/catch_feizei")-me->query("dongchang/salary_feizei");
		feizeigot = paymonth;
		if (me->query("pin") == 1)
		{
			paymonth = paymonth / 2;		
			me->add("dongchang/salary_feizei",paymonth*2);
		}
		else 	me->set("dongchang/salary_feizei",me->query("dongchang/catch_feizei"));
		money = paymonth * salary_list[9 - me->query("pin")];
		me->set("dongchang/salary", age - remain - (month-paymonth)*7200);
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
		me->add("dongchang/salary_feizei",month);
		if (me->query("pin") == 1)
			me->add("dongchang/salary_feizei",month);
	}		
	money = month * salary_list[9 - me->query("pin")];
	me->set("dongchang/salary", age - remain);
	
	MONEY_D->pay_player(me, money);
	CHANNEL_D->do_channel(this_object(), "sys_misc",sprintf("%s领朝廷俸禄：%s。", me->name(),MONEY_D->money_str(money)));

	return "你的俸禄一共是" + MONEY_D->money_str(money) + "。";
}

string do_achievement()
{
	object me = this_player();
	string msg;
	int n;
	if (me->query("class") != "eunuch")
	return "你并非东厂官员，有什么功劳可言？";
	msg = "你到目前为止共完成：\n";
	if (n = me->query("dongchang/xima"))
	msg += "洗马任务" + chinese_number(n) + "次，\n";
	if (n = me->query("dongchang/xuncheng"))
	msg += "巡城任务" + chinese_number(n) + "次，\n";
	if (n = me->query("dongchang/gate"))
	msg += "守门任务" + chinese_number(n) + "次，\n";
	if (n = me->query("dongchang/catchman"))
	msg += "抓人任务" + chinese_number(n) + "次，\n";
	if (n = me->query("dongchang/feizei"))
	msg += "抓飞贼任务" + chinese_number(n) + "次，\n";
	if (n = me->query("dongchang/jianzhan"))
	msg += "监斩任务" + chinese_number(n) + "次，\n";
	if (n = me->query("dongchang/jing"))
	msg += "找四十二章经任务" + chinese_number(n) + "次，\n";
	if (n = me->query("dongchang/job_fail"))
	msg += "你的任务失败次数为" + chinese_number(n) + "次，\n";
	if (n = me->query("dongchang/decapitate"))
	msg += "你被斩首了" + chinese_number(n) + "次。\n";
	if (n = me->query("dongchang/mistake"))
	msg += "你目前被记过了" + chinese_number(n) + "次，要小心哦！！！\n";
	return msg;
}