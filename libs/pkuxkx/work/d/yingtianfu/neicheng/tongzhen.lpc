//城门
// By Zine 23 Nov 2010

inherit ROOM;
#include <ansi.h>
#include <title.h>
#include "/d/yingtianfu/neicheng/npc/promote.h"
void create()
{
        set("short", "通政司");
        set("long", 
"这里通政司的衙门，现在代发大明官员门的俸禄，一张大桌子(desk)之后几\n个官员在点算着些什么。\n"

        );
        set("item_desc", ([
		"desk" : "大桌子上很多信封，写着官员的名字。每岁将有人发出你的俸禄，但职贴就需要你自己来领(ling)了。\n", 
	    ]));
        set("exits", ([
                
              
                
                
                "southeast" : __DIR__"datong2",
               
                
                
                
        ]));
        set("objects", ([
                __DIR__"npc/tongzhen-guanyuan" : 1,
                __DIR__"obj/book" : 1,
        ]));
        
        setup();
        "/clone/board/daming_tz_b"->foo();
}

/*void init()
{
    add_action("do_retitle","retitle");
    add_action("do_baodao","baodao");
    add_action("do_suikao","suikao");
	add_action("do_ling","ling");
}*/
int do_retitle(string arg)
{
	object me;
	string* title1a_pre=({"太师","太傅","太保",});
    string* title2a_pre=({"太子太师","太子太傅","太子太保",});
    string* title3a_pre=({"太子少师","太子少傅","太子少保",});
	string* color=({HIR,RED,HIY,YEL,HIB,BLU,HIG,GRN,HIC,CYN,MAG,HIM,HIW,WHT});
	string ming_jue="";
	if (!arg)
	{
		me=this_player();
	}
	else
	{
		me=find_player(arg);
	}
	if (!me||!userp(me))
	{
		me=this_player();
	}
	if (!me->query("mingpin"))
	{
		return 1;
	}
	if (!me->query("ming/juewei_3")&&!me->query("ming/juewei_2")&&!me->query("ming/juewei_1"))
	{
		return 0;
	}
	if (me->query("ming/juewei_3")&&me->get_title(TITLE_MING3) && member_array(COLOR_D->uncolor(me->get_title(TITLE_MING3)),title3a_pre)==-1)
	{
		ming_jue=title3a_pre[random(sizeof(title3a_pre))];
	}
	if (me->query("ming/juewei_2")&&me->get_title(TITLE_MING3) && member_array(COLOR_D->uncolor(me->get_title(TITLE_MING3)),title2a_pre)==-1 )
	{
		ming_jue=title2a_pre[random(sizeof(title2a_pre))];
	}
	if (me->query("ming/juewei_1")&&me->get_title(TITLE_MING3) && member_array(COLOR_D->uncolor(me->get_title(TITLE_MING3)),title1a_pre)==-1 )
	{
		ming_jue=title1a_pre[random(sizeof(title1a_pre))];
	}
	if (me->query("ming/juewei_3")&&!me->get_title(TITLE_MING3))
	{
		ming_jue=title3a_pre[random(sizeof(title3a_pre))];
	}
	if (me->query("ming/juewei_2")&&!me->get_title(TITLE_MING3))
	{
		ming_jue=title2a_pre[random(sizeof(title2a_pre))];
	}
	if (me->query("ming/juewei_1")&&!me->get_title(TITLE_MING3))
	{
		ming_jue=title1a_pre[random(sizeof(title1a_pre))];
	}
	if (stringp(ming_jue)&&ming_jue!="")
	{
		me->set_title(TITLE_MING3,color[random(sizeof(color))]+ming_jue+NOR);
		tell_object(me,"你被加衔"+ming_jue+"。\n");
	}
	return 3;
}
int do_suikao()
{
    object me=this_player();
    int age=me->query("mud_age");
    string zhengji,renmai,title,title_place;
    int p;
    string* title1a_pre=({"太师","太傅","太保",});
    string* title2a_pre=({"太子太师","太子太傅","太子太保",});
    string* title3a_pre=({"太子少师","太子少傅","太子少保",});
    if (!me->query("mingpin"))
    {
        tell_object(me,"你不是大明官员，无须岁考。\n");
        return 1;
    }
	if (me->query("mingpin")==1)
	{
		tell_object(me,"一品大员无需岁考。\n");
        return 1;
	}
    if (!me->query("ming/suikao/time"))
    {
        tell_object(me,"官员道：第一次来岁考吗？朝廷其实对官员第一次都不算苛责，你取得了两个“中”。\n");
        tell_object(me,HIW"官员告诉你：岁考分每年的政绩和同僚印象两个部分。\n");
        tell_object(me,"政绩就是大明的功勋，同僚印象就主要是六部的堂官和侍郎对你的印象了。\n");
        tell_object(me,"记住，有钱能使鬼推磨，如果是古玩字画类效果可能更好。\n"NOR);
        tell_object(me,HIR"如果连续三次岁考是差或者连续五年不参加岁考，将受到降品或者逐出官场的处罚。\n"NOR);
        me->set("ming/suikao/time",age);
        return 1;
    }
    if (me->query("mud_age")-me->query("ming/suikao/time")<3600*24)
    {
        tell_object(me,"你今年已经参加过岁考了。\n");
        return 1;
    }
    me->set("ming/suikao/time",age);
    if (me->query("ming/suikao/renmaipoint")>5000000)
    {
        renmai="优";
        me->set("ming/suikao/r_renmai",3);
    }
    else if (me->query("ming/suikao/renmaipoint")>2500000)
    {
        renmai="中";
        me->set("ming/suikao/r_renmai",2);
    }
    else 
    {
        renmai="差";
        me->set("ming/suikao/r_renmai",1);
    }
	if (identification(me,"大理寺卿"))
	{
		renmai="优";
        me->set("ming/suikao/r_renmai",3);
	}
    me->set("ming/suikao/renmaipoint",0);
    if (me->query("ming/credit")-me->query("ming/suikao/zhengji/lastpoint")>8&&me->query("ming/credit")-me->query("ming/suikao/zhengji/lastpoint")>(9-me->query("mingpin"))*5)
    {
        zhengji="优";
        me->set("ming/suikao/z_zhengji",3);
    }
    else if (me->query("ming/credit")-me->query("ming/suikao/zhengji/lastpoint")>8&&me->query("ming/credit")-me->query("ming/suikao/zhengji/lastpoint")>(9-me->query("mingpin"))*2)
    {
        zhengji="中";
        me->set("ming/suikao/z_zhengji",2);
    }
    else
    {
        zhengji="差";
        me->set("ming/suikao/z_zhengji",1);
    }
    me->set("ming/suikao/zhengji/lastpoint",me->query("ming/credit"));
    tell_object(me,"你今年岁考政绩为"+zhengji+"，同僚印象为"+renmai+"。\n");
    if (me->query("ming/suikao/r_renmai")+me->query("ming/suikao/z_zhengji")<3)
    {
        tell_object(me,"你被记大过一次，有可能影响自己的仕途。\n");
        me->add("ming/credit",-(1+random(10)));
        me->add("ming/suikao/overall",-1);
    }
    else if (me->query("ming/suikao/r_renmai")+me->query("ming/suikao/z_zhengji")<5)
    {
        tell_object(me,"无功无过，又是一年。\n");
    }
    else
    {
        tell_object(me,"政绩突出，是为干吏，深谙官场规则，如鱼得水。\n");
        p=1+random(10);
        me->add("ming/credit",p);
        me->set("ming/suikao/excellent_year",age);
        tell_object(me,HIC"你的大明功勋增加了"+chinese_number(p)+"点。\n"NOR);
        me->add("ming/suikao/overall",1);
		if (me->query("ming/suikao_longtime_not_in"))
		{
			me->delete("ming/suikao_longtime_not_in");
			tell_object(me,"本次岁考之后你获得了重新回到中枢的机会。\n");
		}
    }
    if (me->query("mingpin")==2&&me->query("ming/suikao/overall")>8&&me->query("ming/credit")>=3500&&!random(5)&&!me->query("ming/2to1"))//2pin升1pin quest
    {
        me->set("ming/2to1",1);
        tell_object(me,HIW+BLINK+"岁考连年是优，听说现在朝廷一品大员致仕的很多，这次是你的机会了。\n"NOR);
        return 1;
    }
    if (me->query("mingpin")==3&&me->query("ming/suikao/overall")>3&&!me->query("ming/juewei_3"))
    {
        title=title3a_pre[random(sizeof(title3a_pre))];
        me->set("ming/juewei_3",1);
        me->set("title",HIM+title+NOR);
        me->set_title(TITLE_MING3,me->query("title"));
        message( "channel:" + "baowei",HIW + "【大明】" + me->query("ming/title")+me->query("name")+HIW+"大人政绩连年为优，特进"+me->query("title")+HIW+"。\n"NOR,users());
        return 1;
    }
    if (me->query("mingpin")==2&&me->query("ming/suikao/overall")>6&&!me->query("ming/juewei_2"))
    {
        title=title2a_pre[random(sizeof(title2a_pre))];
        me->set("ming/juewei_2",1);
        me->set("title",RED+title+NOR);
        me->set_title(TITLE_MING3,me->query("title"));
        message( "channel:" + "baowei",HIW + "【大明】" + me->query("ming/title")+me->query("name")+HIW+"大人政绩连年为优，特进"+me->query("title")+HIW+"。\n"NOR,users());
        return 1;
    }
    if (me->query("mingpin")==1&&me->query("ming/suikao/overall")>9&&!me->query("ming/juewei_1"))
    {
        title=title1a_pre[random(sizeof(title1a_pre))];
        me->set("ming/juewei_1",1);
        me->set("title",HIR+title+NOR);
        me->set_title(TITLE_MING3,me->query("title"));
        message( "channel:" + "baowei",HIW + "【大明】" + me->query("ming/title")+me->query("name")+HIW+"大人政绩连年为优，特进"+me->query("title")+HIW+"。\n"NOR,users());
        return 1;
    }
	if (me->query("ming/suikao/z_zhengji")==3)
	{
		me->add("ming/duty_promote/promote_time",-3600*2);
		tell_object(me,"因为政绩出众，你在"+chinese_number(me->query("mingpin"))+"品任上的迁转时间被缩短了。\n");
	}
    if (me->query("ming/suikao/overall")<-4)
    {
        tell_object(me,"你连续被发现严重失职，官品被降了一级。\n");
        me->set("mingpin",me->query("mingpin")+1);
        if (me->query("ming/pro")=="文")
		{
			if (me->query("mingpin")==2)
			{
				me->set("ming/credit",3150);
			}
			if (me->query("mingpin")==3)
			{
				me->set("ming/credit",1440);
			}
			if (me->query("mingpin")==4)
			{
				me->set("ming/credit",675);
			}
			if (me->query("mingpin")==5)
			{
				me->set("ming/credit",216);
			}
			if (me->query("mingpin")==6)
			{
				me->set("ming/credit",108);
			}
			if (me->query("mingpin")==7)
			{
				me->set("ming/credit",22);
			}
			if (me->query("mingpin")==8)
			{
				me->set("ming/credit",0);
			}
			if (me->query("mingpin")==9)
			{
				me->set("ming/credit",0);
			}
			position_me(me);
			if (me->query("mingpin")>=10)
			{
				tell_object(me,"你被革职查办了。\n");
				me->delete("ming");
				me->delete("mingpin");
				return 1;
			}
		}
		if (me->query("ming/pro")=="武")
		{
			if (me->query("mingpin")==2)
			{
				me->set("ming/credit",3150);
			}
			if (me->query("mingpin")==3)
			{
				me->set("ming/credit",1890);
			}
			if (me->query("mingpin")==4)
			{
				me->set("ming/credit",1125);
			}
			if (me->query("mingpin")==5)
			{
				me->set("ming/credit",585);
			}
			if (me->query("mingpin")==6)
			{
				me->set("ming/credit",198);
			}
			if (me->query("mingpin")==7)
			{
				me->set("ming/credit",0);
			}
			position_me(me);
			if (me->query("mingpin")>=8)
			{
				tell_object(me,"你被革职查办了。\n");
				me->delete("ming");
				me->delete("mingpin");
				return 1;
			}
		}
    }
    return 1;
}

int spec(object me)
{
    string *special=({"风水","贪婪","文曲","突击","群战","鼓舞"});
    string *specialmark=({"fengshui","tanlan","wenqu","tuji","qunzhan","guwu"});
    int n;
    n=random(sizeof(special));
    me->set("ming/special",specialmark[n]);
    tell_object(me,"听了官员的述说，你不禁觉得匪夷所思，官场居然有这么多潜规则。\n");
    tell_object(me,HIW"恭喜，你获得大明官员特技——【"+special[n]+"】\n"NOR);
    message( "channel:" + "baowei",HIW + "【大明】" + me->query("name")+HIW+"大人资质非凡，悟出"+special[n]+"特技！\n"NOR,users());
}

int do_baodao()
{
    object me=this_player();
    message_vision("$N大声喊道：“报到！”\n",me);
    if (!me->query("mingpin"))
    {
        tell_object(me,"“报到？”官员满脸嘲讽地看着你，“报你大头，你哪来的呀？”\n");
        return 1;
    }
    if (me->query("ming/special"))
    {
        tell_object(me,"你不是早就来报到过了吗？又来？\n");
        return 1;
    }
    else
    {
        tell_object(me,"官员道：大人您来了，我们做一点记录，马上就好。\n");
        message_vision(HIG"在等待的过程中，$N和官员们随意攀谈起来……\n"NOR,me);
        me->add_busy(5);
        remove_call_out("spec");
        call_out("spec",4,me);
        return 1;
    }
}
int do_ling()
{
    object bc;
    int salary,rank;
    int *salary_list,inc,fine=1;
	object me=this_player();
    salary_list = ({
			2400000,
			2320000,
			2280000,
			2120000,
			1980000,
			1920000,
			1850000,
			1820000,
			1800000,
			1780000,
			1540000,
			1530000,
			1515000,
			1470000,
			1455000,
			1400000,
			1250000,
			1220000,
			1200000,
			1180000,
			1150000,
			1080000,
			1000000,
			970000,
			950000,
			910000,
			800000,
			700000,
			680000,
			650000,
			610000,
			490000,
			470000,
			450000,
			410000,
			390000,
			300000,
			280000,
			250000,
			230000,
			225000,
			220000,
			200000,
			195000,
			});
	if (me->query("mud_age")-me->query("ming/duty_salary")<3600*48)
	{
		return notify_fail("还没有到领职贴的时间。\n");
	}
	rank=me->query("ming/duty_rank");
	if (!rank)
	{
		rank=44;
	}
	salary=salary_list[rank-1];
	if (me->query("mingpin")!=1)
	{
		inc=me->query("ming/credit")-me->query("ming/last_duty_credit");
		me->set("ming/last_duty_credit",me->query("ming/credit"));
		if (inc>=30)
		{
			fine=1;
		}
		else if (inc>18)
		{
			fine=2;
		}
		else if (inc>12)
		{
			fine=3;
		}
		else if (inc>6)
		{
			fine=4;
		}
		else if (inc>0)
		{
			fine=5;
		}
		else
		{
			fine=6;
		}
		salary=salary/fine;
	}
	me->set("ming/duty_salary",me->query("mud_age"));
    me->add("ming/salary_detail/bc_amount",salary);
	log_file("user/ming_players_benefit",sprintf("%s%s%s\n",me->query("id"),ctime(time()),MONEY_D->money_str(salary)));
	if (!present("daming baochao",me))
	{
		bc=new("/d/yingtianfu/neicheng/obj/money");
		bc->move(me);
	}
	message_vision("$N领取了今年的职贴。\n",me);
	tell_object(me,"一共是" + MONEY_D->money_str(salary) + "。\n");
	if (fine>1)
	{
		tell_object(me,"因为整年没做什么正经事，你的职贴只被以"+chinese_number(fine)+"分之一发放。\n");
	}
	return 1;
}
int salary(object me)
{
    object baoshi,baoshi2,bc;
    int salary,i,n;
    string gem;
    int *salary_list;
    salary_list = ({
              84000,
             168000,
			 252000,
			 312000,
			 576000,
			 888000,
			1080000,
			1480200,
			2180000,
			});
    salary=salary_list[9 - me->query("mingpin")];
	me->set("ming/salary",me->query("mud_age"));
        if (me->query("ming/suikao/excellent_year")+3600*24>me->query("mud_age"))
        {
            n=2+random(2);
            salary=salary*n;
            tell_object(me,"今年岁考为全优，你的俸禄被"+chinese_number(n)+"倍发放。\n");
        }
        //MONEY_D->pay_player(me, salary);
	    //CHANNEL_D->do_channel(this_object(), "sys",sprintf("%s领大明俸禄：%s。", me->name(),MONEY_D->money_str(salary)));
        me->add("ming/salary_detail/bc_amount",salary);
		log_file("user/ming_players_benefit",sprintf("%s%s%s\n",me->query("id"),ctime(time()),MONEY_D->money_str(salary)));
		if (!present("daming baochao",me))
		{
			bc=new("/d/yingtianfu/neicheng/obj/money");
			bc->move(me);
		}
		tell_object(me,"户部派人送来了你今年的俸禄，一共是" + MONEY_D->money_str(salary) + "。\n");
        /*if (me->query("mingpin")==3)
        {
            i=random(300);
            if (i<99)
            {
                baoshi=new("/d/guiyunzhuang/obj/guwan");
                if (random(3))
                {baoshi->rename();
                baoshi->set("guwan_jiandinged", 1);}
                baoshi->move(me);
                message( "channel:" + "baowei",HIW + "【大明】" + me->query("name")+HIW+"今年政绩卓著，特赐"+baoshi->query("name")+HIW+"一件。钦此。\n"NOR,users());
            }
            else if (i<199)
            {
                baoshi=new("/d/guiyunzhuang/obj/zihua");
                if (random(3))
                {baoshi->rename();}
                baoshi->move(me);
                message( "channel:" + "baowei",HIW + "【大明】" + me->query("name")+HIW+"今年政绩卓著，特赐"+baoshi->query("name")+HIW+"一幅。钦此。\n"NOR,users());
            }
            else
            {
                baoshi= new("/obj/gem/gem");
                i = random(20);
                if (i < 3) gem = "yan";
                else if (i < 6) gem = "mu";
                else if (i < 9) gem = "sui";
                else if (i < 12) gem = "jin";
                else if (i < 15) gem = "bing";
                else if (i < 16) gem = "gu";
                else if (i < 17) gem = "yu";
                else if (i < 18) gem = "jiao";
                else gem = "jia";
                baoshi->set_level(1,9999,gem);
                baoshi->move(me);
                tell_object(me,"作为朝廷三品大员，皇上御赐宝石一枚。\n");
                message( "channel:" + "baowei",HIW + "【大明】" + me->query("name")+HIW+"今年政绩卓著，特赐"+baoshi->query("name")+HIW+"一枚。钦此。\n"NOR,users());
            }
        }
        if (me->query("mingpin")==2)
        {
            i=random(300);
            if (i<99)
            {
                baoshi=new("/d/guiyunzhuang/obj/guwan");
                if (random(3))
                {baoshi->rename();
                baoshi->set("guwan_jiandinged", 1);}
                baoshi->move(me);
                message( "channel:" + "baowei",HIW + "【大明】" + me->query("name")+HIW+"今年政绩卓著，特赐"+baoshi->query("name")+HIW+"一件。钦此。\n"NOR,users());
            }
            else if (i<199)
            {
                baoshi=new("/d/guiyunzhuang/obj/zihua");
                if (random(3))
                {baoshi->rename();}
                baoshi->move(me);
                message( "channel:" + "baowei",HIW + "【大明】" + me->query("name")+HIW+"今年政绩卓著，特赐"+baoshi->query("name")+HIW+"一幅。钦此。\n"NOR,users());
            }
            else
            {
                baoshi= new("/obj/gem/gem");
                i = random(20);
                if (i < 3) gem = "yan";
                else if (i < 6) gem = "mu";
                else if (i < 9) gem = "sui";
                else if (i < 12) gem = "jin";
                else if (i < 15) gem = "bing";
                else if (i < 16) gem = "gu";
                else if (i < 17) gem = "yu";
                else if (i < 18) gem = "jiao";
                else gem = "jia";
                baoshi->set_level(5001,9999,gem);
                baoshi->move(me);
                tell_object(me,"作为朝廷二品大员，皇上御赐宝石一枚。\n");
                message( "channel:" + "baowei",HIW + "【大明】" + me->query("name")+HIW+"为朕肱骨之臣，特赐"+baoshi->query("name")+HIW+"一枚。钦此。\n"NOR,users());
            }
        }
        if (me->query("mingpin")==1)
        {
            i=random(300);
            if (i<99)
            {
                baoshi=new("/d/guiyunzhuang/obj/guwan");
                if (random(3))
                {baoshi->rename();}
                baoshi->move(me);
                message( "channel:" + "baowei",HIW + "【大明】" + me->query("name")+HIW+"今年政绩卓著，特赐"+baoshi->query("name")+HIW+"一件。钦此。\n"NOR,users());
            }
            else if (i<199)
            {
                baoshi=new("/d/guiyunzhuang/obj/zihua");
                if (random(3))
                {baoshi->rename();
                baoshi->set("guwan_jiandinged", 1);}
                baoshi->move(me);
                message( "channel:" + "baowei",HIW + "【大明】" + me->query("name")+HIW+"今年政绩卓著，特赐"+baoshi->query("name")+HIW+"一幅。钦此。\n"NOR,users());
            }
            else
            {
                baoshi= new("/obj/gem/gem");
                i = random(20);
                if (i < 3) gem = "yan";
                else if (i < 6) gem = "mu";
                else if (i < 9) gem = "sui";
                else if (i < 12) gem = "jin";
                else if (i < 15) gem = "bing";
                else if (i < 16) gem = "gu";
                else if (i < 17) gem = "yu";
                else if (i < 18) gem = "jiao";
                else gem = "jia";
                baoshi->set_level(5001,9999,gem);
                baoshi->move(me);
                baoshi2= new("/obj/gem/gem");
                i = random(20);
                if (i < 3) gem = "yan";
                else if (i < 6) gem = "mu";
                else if (i < 9) gem = "sui";
                else if (i < 12) gem = "jin";
                else if (i < 15) gem = "bing";
                else if (i < 16) gem = "gu";
                else if (i < 17) gem = "yu";
                else if (i < 18) gem = "jiao";
                else gem = "jia";
                baoshi2->set_level(5001,9999,gem);
                baoshi2->move(me);
                tell_object(me,"作为朝廷一品大员，皇上御赐宝石两枚。\n");
                message( "channel:" + "baowei",HIW + "【大明】" + me->query("name")+HIW+"实乃国之柱石，特赐"+baoshi->query("name")+HIW+"一枚、"+baoshi2->query("name")+HIW+"一枚。钦此。\n"NOR,users());
            }
        }*/
	    return 1;
    
}