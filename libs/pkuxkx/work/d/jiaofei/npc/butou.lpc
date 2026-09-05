
inherit NPC;
#include <ansi.h>
#include <localtime.h>

int ask_jiaofei();
int ask_lingshang();
int ask_difficulty();
int ask_cishu();
int ask_special();
int ask_score();
int ask_attack();
int ask_retreat();

int do_select(string arg);

int start_task();

void eat_food();
int chat_for_ad();

//改为一周一次剿匪，奖励提升至5倍
int reward_factor = 5;

void create()
{	
	set_name("渡月", ({ "duyue npc" ,"butou"}));
	set("title",HIY"临安府总捕头"NOR);
	set("gender", "男性");
	set("age", 39);
	set("long", "临安府的总捕头，办案无数，最近正为一伙土匪而招募江湖侠士。\n");
	set("combat_exp", 100000);
	set("attitude", "peaceful");

    set("per",25);
	set("str", 50);
	set("int", 30);
	set("con", 30);
	set("dex", 50);
	set("shen",100);
	set("max_qi", 2000);
	set("max_jing", 2000);
	set("max_neili", 1000);
	set("neili", 1000);
	set("inquiry", ([
			"剿匪":(:ask_jiaofei:),
            "领赏":(:ask_lingshang:),
            "难度":(:ask_difficulty:),
			"贡献":(:ask_cishu:),
			"特技点数":(:ask_special:),
            "战功":(:ask_score:),               
            "进攻": (:ask_attack:)            
       ]));
    set("chat_chance",5);
	set("chat_msg",({
		"渡月道：我一路追踪到此，总算让我找到了土匪的巢穴。\r\n",
		"渡月道：不日我必将这帮乱匪铲除！\r\n",
		"渡月道：兵力太少，如果能有江湖侠士相助就好了。\r\n",
		(:eat_food:),
		(:chat_for_ad:),
		}));
	setup();    
    carry_object("/clone/weapon/changjian")->wield();	
    carry_object("/clone/cloth/cloth")->wear();	
    
    carry_object("/clone/food/mantou");
    carry_object("/clone/food/jiudai");
}

void init()
{
    add_action("do_select","select");
}

int do_select(string arg)
{
    string name;
    int difficulty = 100;
    string msg = "";
    int changed = 1;

    if(this_player()->is_busy())
    {
        write("你正忙着呢。\n");
        return 1;
    }
    
    if(JIAOFEI_D->queryinitprogress() == 1 || JIAOFEI_D->istaskstart() == 1)
    {
        write("剿匪方案已经确定，不能更改了。\n");        
    }
    else if(arg == "贩夫走卒")
    {
        JIAOFEI_D->setdifficulty(50);
    }
    else if(arg == "无畏勇士")
    {
        JIAOFEI_D->setdifficulty(100);
    }
    else if(arg == "大义侠客")
    {
        JIAOFEI_D->setdifficulty(150);
    }
    else if(arg == "超然宗师")
    {
        JIAOFEI_D->setdifficulty(200);
    }            
    else
    {
        changed = 0;
        write("你想好了没有？\n");
        
    }
    difficulty = JIAOFEI_D->getdifficulty();
    msg = "现在朝廷选择的剿匪方略是：";
    if(difficulty < 100)
    {
        msg += GRN"贩夫走卒\n"NOR;
    }
    else if(difficulty == 100)
    {
        msg += HIB"无畏勇士\n"NOR;
    }    
    else if(difficulty > 100 && difficulty < 200)
    {
        msg += HIY"大义侠客\n"NOR;
    } 
    else
    {
        msg += HIW"超然宗师\n"NOR;
    }       
    write(msg);
    if(changed == 1)
    {
        JIAOFEI_D->announce(msg, "bd");
    }

    this_player()->add_busy(2);
    return 1;
}

int ask_jiaofei()
{
	int mday;
	int hour;
	int minute;
	int second;

	command(sprintf("say 剿匪任务将在%d点左右开始。如果碰上有其他紧急军务，可能稍微往后延迟。\r\n",JIAOFEI_D->getstarttaskclock()));
	command("say 一定多穿一些厚甲，带足了伤药。土匪的机关厉害啊！\r\n");
	command("worry "+this_player()->query("id"));
	return 1;
}

int ask_cishu()
{	
    object me = this_player();
	command("say 查询次数啊 ，厉害啊！\r\n");
    tell_object(me,HIY"你已经为朝廷做出了" + chinese_number(me->query("jiaofei/succ_times_1")) + "次贡献！\n"NOR);
	return 1;
}

int ask_special()
{	
    object me = this_player();
	if (me->query("jiaofei/special"))
	{
	    tell_object(me,HIY"你已经取得了这个特技升级点数，就别再来问了！\n"NOR);
	}
	else
	{
		if (me->query("jiaofei/succ_times_2")>10)
		{
			me->set("jiaofei/special",1);
			me->add("special/levelup_point",1);
			tell_object(me,HIY"感谢你为朝廷做出的贡献，特奖励你一次特技升级机会！\n"NOR);
		    CHANNEL_D->do_channel(this_object(), "jh", "小道消息："+me->query("name")+"因为在剿匪中做出的卓绝贡献，特奖励特技升级点数一次，以资鼓励。\n",-1);
		}
		else
		{
			tell_object(me,HIY"你已成功杀入大义侠客难度宝库" + chinese_number(me->query("jiaofei/succ_times_2")) + "次！\n"NOR);
		}
	}
	return 1;
}


int ask_lingshang()
{
    int exp,pot,money;
    object me = this_player();
    if(me->query_temp("jiaofei/quan_number") > 0)
    {
        if(time() - me->query_temp("jiaofei/quan_time") > 60)
        {
            command("sigh");
            command("say 这位"+RANK_D->query_respect(me)+"为何现在才来领赏？朝廷的期限已经过了。");
            me->delete_temp("jiaofei/quan_number");            
            me->delete_temp("jiaofei/quan_time");                        
        }
        else
        {
			if (!me->query("biography/jobs/jiaofei"))
			{
				me->set("biography/jobs/jiaofei",time());//个人传记记录第一次完成任务时间ZINE
			}
            command("haha");
            command("say 这位"+RANK_D->query_respect(me)+"机智过人，将土匪的援军骗了回去，避免我军腹背受敌，真乃大功一件！");
            //每劝回去一个土匪，奖励如下：
            //exp = 1000 + random(1000)
            //pot = 300 + random(300)
            //money = 10000
            
            exp = 1000 + random(1000);
            pot = 300 + random(300);
            money = 10000;
            exp = exp * reward_factor* SPEWEEK_D->query_jiaofei_bonus()/100;
            pot = pot * reward_factor * SPEWEEK_D->query_jiaofei_bonus()/100;
            money = money * reward_factor* SPEWEEK_D->query_jiaofei_bonus()/100;
                    
						exp = REWARD_D->add_exp(me,exp);
						pot = REWARD_D->add_pot(me,pot);
						money = REWARD_D->add_money(me,money);
						
			if (exp>7000000)
			{
				exp=exp*8/10;
				pot=exp*8/10;
			}
			else if (exp>4000000)
			{
				exp=exp*9/10;
				pot=pot*9/10;
			}

            write(sprintf("你被奖励了经验%d点，潜能%d点，白银%d两！\n",exp,pot,money/100));
            me->add("exp/jiaofei",exp);
		    		me->add("pot/jiaofei",pot);         
    		
            me->delete_temp("jiaofei/quan_number");            
            me->delete_temp("jiaofei/quan_time");                  		
        }
    }
    else
    {
        command("?");
        write("此话不知从何说起？\n");
    }
    return 1;
}

int ask_difficulty()
{
    command("say 朝廷根据参加剿匪义士的能力，制定了四套不同的剿匪方案，代号分别是 贩夫走卒，无畏勇士，大义侠客，超然宗师");
    command("say 你赞成哪套方案？可以选。(select)");
    return 1;
}
void eat_food()
{
    object jiudai;
    if(!present("man tou",this_object()))
    {
        carry_object("/clone/food/mantou");
    }
    if(!present("jiudai",this_object()))
    {
        carry_object("/clone/food/jiudai");
    }
    jiudai = present("jiudai",this_object());
    
	jiudai->set("liquid/type", "water");
	jiudai->set("liquid/name", "清水");
	jiudai->set("liquid/remaining", jiudai->query("max_liquid"));
	jiudai->set("liquid/drink_func", 0);    
	command("eat man tou");
    command("drink jiudai");        
	command("eat man tou");
    command("drink jiudai");
	command("eat man tou");
    command("drink jiudai");
	command("eat man tou");
    command("drink jiudai");
	command("eat man tou");
    command("drink jiudai");               
}

int chat_for_ad()
{
    switch(random(300))
    {
    case 1:
        JIAOFEI_D->announce("诸位英雄豪杰，五指山土匪猖獗，朝廷恳请各位相助，平定土匪！", "bd");
        break;
    case 2:    
        JIAOFEI_D->announce("朝廷许诺，剿灭土匪后，所有土匪赃物都归各位英雄所有！", "bd");
        break;
    case 3:
        JIAOFEI_D->announce("据我的捕快侦查，土匪有一处极为隐秘的宝库，积累着铁掌帮数百年搜刮而来的宝物。", "bd");
        break;
    }
}

int ask_score()
{
    object me = this_player();
    int exp,pot,repute;
	mixed* timeinfos;
	int week;
	int hour;

	timeinfos = localtime(time());

	hour = timeinfos[LT_HOUR];
	week = timeinfos[LT_WDAY];

    if(me->query_temp("jiaofei/score") > 0)
    {
        if(JIAOFEI_D->istaskstart() || JIAOFEI_D->queryinitprogress())
        {
            command("say 朝廷现在正忙于剿匪，请稍候再来。");
            return 1;
        }
		if (week!=6)
		{
           return notify_fail("为何现在才来领赏，朝廷等级战功发放奖励的时间早就过了!\n");
		}
		if (hour>22)
		{
           return notify_fail("为何现在才来领赏，朝廷等级战功发放奖励的时间早就过了!\n");
		}
		if (hour<21)
		{
           return notify_fail("为何现在才来领赏，朝廷等级战功发放奖励的时间早就过了!\n");
		}

        exp = me->query_temp("jiaofei/score") * 300;
        pot = me->query_temp("jiaofei/score") * 30;
        repute = me->query_temp("jiaofei/score");
        
        exp = exp * reward_factor*  SPEWEEK_D->query_jiaofei_bonus()/100;
        pot = pot * reward_factor*  SPEWEEK_D->query_jiaofei_bonus()/100;
        repute = repute * reward_factor*  SPEWEEK_D->query_jiaofei_bonus()/100;
        
        if(JIAOFEI_D->query_last_time_succeed_flag() != 1)
        {
            exp /= 3;
            pot /= 3;            
						command("sigh");
						command("say 想不到朝廷精心准备，我费劲心机，终于还是失败了。");
						command("say 微薄心意，还请笑纳。");
        }

			exp = REWARD_D->add_exp(me,exp);
			pot = REWARD_D->add_pot(me,pot);
			repute = REWARD_D->add_rep(me,repute);
			if (exp>7000000)
			{
				exp=exp*8/10;
				pot=exp*8/10;
			}
			else if (exp>4000000)
			{
				exp=exp*9/10;
				pot=pot*9/10;
			}

		me->add("newjobs/completed/jiaofei",1);			
   		me->add("exp/jiaofei",exp);
   		me->add("pot/jiaofei",pot);
   		
        me->delete_temp("jiaofei/score");
        JIAOFEI_D->announce(sprintf("%s精忠报国，为平定五指山铁掌帮叛匪立下汗马功劳，朝廷特封赏经验%d点，潜能%d点，声望%d点！以彰义举。",me->query("name"),exp,pot,repute));        
    }
    else
    {
        command("say 朝廷有令，临阵退缩者，淫人妻女者，冒领战功者，夷三族！");
    }
    return 1;
}

//提前开始
int ask_attack()
{
	mixed* timeinfos;
	int hour;
	int minute;
	int mday;
	

	timeinfos = localtime(time());

	hour = timeinfos[LT_HOUR];
	minute = timeinfos[LT_MIN];
	mday = timeinfos[LT_MDAY];
	    
    if(JIAOFEI_D->istaskstart() || JIAOFEI_D->queryinitprogress())
    {
        command("say 这不是已经开战了吗？快上山去吧！");
        return 1;
    }
    if(hour == JIAOFEI_D->query_start_time() - 1)
    {
        if(minute >= 40)
        {
            command("say 别着急，大军马上就要开拔了。");
            return 1;            
        }
        else
        {
            command("say 好吧，既然你一力请战，那就提前开始吧。快去准备准备，一刻钟后进攻！\n");
            JIAOFEI_D->announce("剿匪大军一刻钟后提前开拔！");
            JIAOFEI_D->announce("剿匪大军一刻钟后提前开拔！", "bd");
            remove_call_out("start_task");
            call_out("start_task",15*60);
        }
    }
    else
    {
        command("say 开什么玩笑，现在时机完全不成熟。\n");
    }
    return 1;       
}

int start_task()
{
    if(JIAOFEI_D->istaskstart() || JIAOFEI_D->queryinitprogress())
    {
        return 1;
    }
    JIAOFEI_D->start_task();
    return 1;
}