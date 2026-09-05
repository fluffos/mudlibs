// mingzhu.c 兵部尚书
// 负责京畿武官，皇宫侍卫的赏罚，记录，升迁，降级等

#include <ansi.h>

#include "/d/beijing/beijing_defs.h"

inherit NPC;
#include <title.h>

string do_shengqian();
string do_salary();
int ask_salary2();
void do_check(object ob);
string do_achievement();
string * province=({"两广","两江","四川","直隶"});
string * pin9=({"外委把总","兰翎长","协领"});
string * pin8=({"典仪","亲军校","前锋校","护军校","骁骑校","千总"});
string * pin7=({"七品典仪","盛京游牧副尉","城门史","马厂协领","把总","安抚使司佥事"});
string * pin6=({"卫千总","安抚使司副使","内务府六品兰翎长","六品典仪","门千总","营千总","宣抚使司佥事","安抚使司同知","副招讨使","百户","兰翎侍卫","整仪尉"});
string * pin5=({"关口守御","防御","守备","宣慰使司佥事","宣抚使司同知","千户","分管佐领","监守信礮官","步军校","步军副尉","三等侍卫","治仪正","守御所千总","河营协办守备","安抚使","招讨使","宣抚使司副使","副千户","四等侍卫","委署前锋参领","委署护军参领","委署鸟枪护军参领","委署前锋侍卫","下五旗包衣参领","五品典仪","印物章京","三等护卫"});
string * pin4=({"贝勒府司仪长","侍卫领班","指挥佥事","宣慰使司同知","二等侍卫","云麾使","副护军参领","副前锋参领","副骁骑参领","太仆寺马厂驼厂总管","宣抚使","宣慰使司副使","二等护卫","四品典仪","城门领","包衣副护军参领","包衣副骁骑参领","包衣佐领","防守尉","佐领","都司"});
string * pin3=({"城守尉","骁骑参领","王府长史","参将","指挥使","一等侍卫","火器营翼长","健锐营翼长","前锋参领","护军参领","游击","五旗参领","协领","宣慰使","指挥同知","包衣护军参领","包衣骁骑参领","王府一等护卫"});
string * pin2=({"副将","散秩大臣","副都统","总兵","右翼前锋营统领","左翼前锋营统领","八旗护军统领","銮仪使"});
string * pin1=({province[random(sizeof(province))]+"将军",province[random(sizeof(province))]+"都统",province[random(sizeof(province))]+"提督","提督九门步军巡捕五营统领","内大臣","领侍卫内大臣","掌銮仪卫事大臣"});
string * jue3=({"忠诚伯"});
string * jue2=({"延恩侯","同安侯"});
string * jue1=({"忠襄公","承恩公","孝愍公","海澄公","忠锐公","辅国公","镇国公","鹿鼎公"});
void create()
{
    int i, *speed_cur;

    set_name("明珠", ({"ming zhu", "ming"}));
    set("title", "兵部尚书");
    set("gender", "男性");
    set("age", 30);
    set("long", "他就是当今朝廷的兵部尚书，\n"
    "京畿侍卫，武官的升迁就全看他了。\n");
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

    //create_family("朝廷", 3, "官员");

	/*set("inquiry", ([
	"任务" : "这个你去问军营的多总管吧。",
	"job" : "这个你去问军营的多总管吧。",
	"here" : "这里就是堂堂兵部衙门。",
	"兵部" : "兵部统领骁骑营，近日皇上开恩，让下官代领侍卫营。",
	"为官之道" : "为官之道需要先研究大清律法，你可以去问问多总管。",
	"兵法战策" : "这个最好问问多隆多总管、鳌拜鳌少保，据说平西王吴三桂也是领兵打仗的行家。",
	"升迁" : (: do_shengqian :),
	"晋升" : (: do_shengqian :),
	"promotion" : (: do_shengqian :),
        "奖金": (: do_salary :),
        "bonus": (: do_salary :),
     "宗室俸禄": (: ask_salary2 :),
     "package": (: ask_salary2 :),
	"功劳": (: do_achievement :),
	]));*/

    setup();
    carry_object(__DIR__"obj/guanfu")->wear();

    remove_call_out("refresh_members");
    call_out("refresh_members", 1200);  // do it every 20 min
}

/*int init()
{
	object ob = this_player();
    	do_check(ob);
}
void do_check(object ob)
{
	if(ob->query("class") == "officer"
		&& ob->query_condition("bjkiller"))
	{
		message_vision(HIR"$N对$n怒喝道：“身为朝廷官员居然知法犯法，念你初犯姑且记你一过，记住，若有再犯军法伺候！！”\n"NOR, this_object(), ob);
		ob->add("chaoting/mistake", 1);
		ob->set("chaoting/salary", ob->query("chaoting/salary") + 7200);
		ob->clear_condition("bjkiller");
		tell_object(ob,"你被扣除了一个月的俸禄。\n你被兵部记过一次。\n");
	}
	if(ob->query("class") == "officer"
		&& ob->query("chaoting/job_fail") / (ob->query("chaoting/job_bonus") + 1) >= 10 )
	{
		message_vision(HIR"$N对$n怒喝道：“身为朝廷官员屡次玩忽职守，念你初犯姑且记你一过，记住，若有再犯军法伺候！！”\n"NOR, this_object(), ob);
		ob->add("chaoting/mistake", 1);
		ob->set("chaoting/salary", ob->query("chaoting/salary") + 7200);
		ob->add("chaoting/job_bonus", 1);
		tell_object(ob,"你被扣除了一个月的俸禄。\n你被兵部记过一次。\n");
	}
	if(ob->query("class") == "officer" && ob->query("chaoting/mistake") >= 10 )
	{
		message_vision(HIR"$N对$n怒喝道：“身为朝廷官员屡次知法犯法，来人啊，给我拉出去斩了！！”\n"NOR, this_object(), ob);
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
        message_vision(HIR "周围挤满了围观群众，$N心道：这回真的完了，\n"
                        "旁边的监斩官员扔出一道令牌，.....\n"
                        "刽子手大刀一挥..........\n\n" NOR, ob);
        ob->set("chaoting/mistake",0);
//        ob->set("startroom", START_ROOM);
        ob->start_busy(0);
        ob->receive_damage("qi", 0, this_object());
        ob->die();
        CHANNEL_D->do_channel(this_object(), "rumor", ob->name()+"在菜市口被斩首示众！");
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
        message_vision(HIY "\n$N喝道：将$n押到菜市口斩首示众！！\n" NOR, this_object(), ob);
        message_vision(HIR "官兵们一涌而上，乱棒齐下将$N打得昏了过去......\n" NOR, ob);
        ob->move("/d/beijing/caishikou");
        ob->unconcious();
        remove_call_out("processing");
        call_out("processing", 15, ob);
}


int add_user_succ(object me, object player, int rank)
{
    int slot, i;
    string *members;

    members = me->query("members/rank"+rank);
    if (!members) {
	members = allocate(HELPER->rank_position_num(rank));
  	for (i=0; i<sizeof(members); i++){
	    members[i] = 0;
	}
	slot = 0;
    }else{
  	for (i=0; i<sizeof(members); i++){
	    if (members[i] == 0) slot = i;
	    break;
	}
        if (i == sizeof(members))
	    return 0;
    }

    player->set("family/generation", rank);
    player->set("bingbu/death_count", player->query("death_count"));
    player->set("bingbu/job_cur", 0);
    player->set("bingbu/job_lazy", 0);
    player->set("bingbu/job_lazy_time", time());
    player->set("bingbu/job_lazy_mud", 0);
    player->set("bingbu/job_lazy_mudtime", player->query("mud_age"));
    player->set("bingbu/last_check", player->query("mud_age"));

    if (rank >= 5) {
	player->set("bingbu/dept", HELPER->dept_name(slot%2));
	player->set("title", player->query("bingbu/dept")+HELPER->rank_name(rank));
    }else{
	player->set("title", HELPER->rank_name(rank));
    }
    player->save();

    members[slot] = player->query("id");
    me->set("members/rank"+rank, members);
    me->save();
    return 1;
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

	if ( time > 7200 )
	return "请先把以前的俸禄结算完毕再升职。";

 
    pin = player->query("pin");

	if (!player->query("chaoting/eunuch") && player->query("chaoting/officer"))
	{
    switch (pin)
    {
    	case 9:
    	if ( player->query("score") < 200)
    	{
		return "你的军功不够，怎么升啊？";
    	}
        if ( player->query_skill("strategy", 1) < 30)
	return "你的兵法战策等级不够，怎么升啊？";
        if ( player->query_skill("leadership", 1) < 30)
	return "你的为官之道等级不够，怎么升啊？";

    	/*rank_name = ({ YEL"清兵千总"NOR, YEL"清兵守备"NOR,});
    	title = rank_name[random(sizeof(rank_name))];
        title=YEL+pin8[random(sizeof(pin8))]+NOR;
    	break;

    	case 8:
    	if ( player->query("score") < 400)
    	{
		return "你的军功不够，怎么升啊？";
    	}
        if ( player->query_skill("strategy", 1) < 50)
	return "你的兵法战策等级不够，怎么升啊？";
        if ( player->query_skill("leadership", 1) < 50)
	return "你的为官之道等级不够，怎么升啊？";

    	//title = HIC"侍卫营侍卫"NOR;
        title=HIY+pin7[random(sizeof(pin7))]+NOR;
    	break;

    	case 7:
    	if ( player->query("score") < 600)
    	{
		return "你的军功不够，怎么升啊？";
    	}
        if ( player->query_skill("strategy", 1) < 80)
	return "你的兵法战策等级不够，怎么升啊？";
        if ( player->query_skill("leadership", 1) < 80)
	return "你的为官之道等级不够，怎么升啊？";

    	/*rank_name = ({ RED"侍卫营佐领"NOR, RED"侍卫营参将"NOR,});
    	title = rank_name[random(sizeof(rank_name))];
        title=WHT+pin6[random(sizeof(pin6))]+NOR;
    	break;

    	case 6:
    	if ( player->query("score") < 800)
    	{
		return "你的军功不够，怎么升啊？";
    	}
        if ( player->query_skill("strategy", 1) < 100)
	return "你的兵法战策等级不够，怎么升啊？";
        if ( player->query_skill("leadership", 1) < 100)
	return "你的为官之道等级不够，怎么升啊？";
    	//title = MAG"侍卫营副都统"NOR;
        title=HIW+pin5[random(sizeof(pin5))]+NOR;
    	break;

    	case 5:
    	if ( player->query("score") < 1000)
    	{
		return "你的军功不够，怎么升啊？";
    	}
        if ( player->query_skill("strategy", 1) < 120)
	return "你的兵法战策等级不够，怎么升啊？";
        if ( player->query_skill("leadership", 1) < 120)
	return "你的为官之道等级不够，怎么升啊？";
    	/*rank_name = ({
    		BLU"侍卫营都统"NOR,
    		BLU"侍卫营云骑尉"NOR,
    		BLU"侍卫营骑都尉"NOR,
    		BLU"前锋营都统"NOR,
    		BLU"前锋营云骑尉"NOR,
    		BLU"前锋营骑都尉"NOR,
    		});
    	title = rank_name[random(sizeof(rank_name))];
        title=CYN+pin4[random(sizeof(pin4))]+NOR;
    	break;

    	case 4:
    	if ( player->query("score") < 1200)
    	{
		return "你的军功不够，怎么升啊？";
    	}
        if ( player->query_skill("strategy", 1) < 140)
	return "你的兵法战策等级不够，怎么升啊？";
        if ( player->query_skill("leadership", 1) < 140)
	return "你的为官之道等级不够，怎么升啊？";
        if ( player->query("chaoting/catch_feizei") < 10)
        return "你对地方治安贡献不够，需要抓够十个随机出现的飞贼才可以。";
	player->set("chaoting/salary_feizei",player->query("chaoting/catch_feizei"));
    	//title = CYN"御前侍卫总管"NOR;
    	title=HIY+jue3[random(sizeof(jue3))]+" "+HIB+pin3[random(sizeof(pin3))]+NOR;
        break;

    	case 3:
    	if ( player->query("score") < 1400)
    	{
		return "你的军功不够，怎么升啊？";
    	}
        if ( player->query_skill("strategy", 1) < 170)
	return "你的兵法战策等级不够，怎么升啊？";
        if ( player->query_skill("leadership", 1) < 150)
	return "你的为官之道等级不够，怎么升啊？";
        if ( player->query("chaoting/catch_feizei") < 15)
        return "你对地方治安贡献不够，需要抓够十五个随机出现的飞贼才可以。";
	player->set("chaoting/salary_feizei",player->query("chaoting/catch_feizei"));
    	/*rank_name = ({
    		HIR"平西将军"NOR,
    		HIR"镇南将军"NOR,
    		HIR"征东将军"NOR,
    		HIR"抚远将军"NOR,
    		});
    	if (player->query("gender") == "男性")
    		title = rank_name[random(sizeof(rank_name))];
    	else
    		title = HIR"巾帼英雄"NOR;
        title=HIY+jue2[random(sizeof(jue2))]+" "+RED+pin2[random(sizeof(pin2))]+NOR;

    	break;

    	case 2:
        if ( player->query("betrayer") )
    	{
                return "你多次背叛师门，能官至二品已是极致，我看你还是知足吧。";
    	}
        if ( player->query("score") < 1410)
    	{
		return "你的军功不够，怎么升啊？";
    	}
        if ( player->query("chaoting/jing") < 1)
    	{
		return "你的军功不够，怎么升啊？";
    	}
        if ( player->query_skill("strategy", 1) < 180)
	return "你的兵法战策等级不够，怎么升啊？";
        if ( player->query_skill("leadership", 1) < 180)
	return "你的为官之道等级不够，怎么升啊？";
	
    	/*rank_name = ({
    		HIY"鹿鼎公"NOR,
    		HIY"镇国公"NOR,
    		HIY"辅国公"NOR,
    		});
    	if (player->query("gender") == "男性")
    		title = rank_name[random(sizeof(rank_name))];
    	else
    		title = HIY"女元帅"NOR;
        if (!player->query("chaoting/wang")&&!player->query("chaoting/jiawang"))
        {
            title=HIY+jue1[random(sizeof(jue1))]+" "+HIR+pin1[random(sizeof(pin1))]+NOR;
        }
        
    	break;

    	default:
	return "大人您已经是“一人之下，万人之上”了，再升就。。。";
    	break;

	}
	bonus = 1;
	}
	else
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
	}
	else return "出现BUG了:请立刻通知巫师解决！！";

//修改title请同时修改duolong.c和hai.c里面的相应地方 - vast
	exp = bonus * (10 - pin) * (10 - pin) * (10 - pin) * 200;
	pot = bonus * (10 - pin) * (10 - pin) * 100;
	player->add("pin", -1);
	title = HIG+ "朝廷" + chinese_number(pin-1) + "品官员 "NOR + title;
	player->add("combat_exp", exp);
	player->add("potential", pot);
	player->set("title", title);
//title系统记录玩家title by seagate@pkuxkx
	player->set_title(TITLE_RANK, title);
    player->set("chaoting/newtitle",1);
	tell_object(player, "你的经验增加了" + chinese_number(exp)+ "点。\n你的潜能增加了" + chinese_number(pot)+ "点。\n你的俸禄增加了。\n");
        player->set("chaoting/salary", player->query("mud_age"));

    	return "好，" + RANK_D->query_respect(player)+ "军功卓著，我就升您为" + title + "吧。";
}
int ask_salary2()
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
}
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
			CHANNEL_D->do_channel(this_object(), "sys",sprintf("%s领朝廷俸禄：%s。", me->name(),MONEY_D->money_str(money)));
		
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
	CHANNEL_D->do_channel(this_object(), "sys",sprintf("%s领朝廷俸禄：%s。", me->name(),MONEY_D->money_str(money)));

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
	if (n = me->query("chaoting/xima"))
	msg += "洗马任务" + chinese_number(n) + "次，\n";
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
	if (n = me->query("chaoting/jing"))
	msg += "找四十二章经任务" + chinese_number(n) + "次，\n";
	if (n = me->query("chaoting/job_fail"))
	msg += "你的任务失败次数为" + chinese_number(n) + "次，\n";
	if (n = me->query("chaoting/decapitate"))
	msg += "你被斩首了" + chinese_number(n) + "次。\n";
	if (n = me->query("chaoting/mistake"))
	msg += "你目前被记过了" + chinese_number(n) + "次，要小心哦！！！\n";
	return msg;
}
*/