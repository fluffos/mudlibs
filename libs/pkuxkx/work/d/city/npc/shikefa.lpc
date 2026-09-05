//史可法
//created by Zine 2 Sep 2010

#include <ansi.h>
inherit NPC;
int ask_job();
int ask_fail();
int ask_query();
int askforhelp();
int ask_fuming();

void create()
{
        set_name("史可法", ({ "shi kefa", "shi", "kefa" }) );
        set("gender", "男性" );
		set("title", HIW"大明"HIC"江北督师 "HIW"兵部尚书"NOR);
        set("age", 44);
        set("long", 
            "他是大明督师史可法，不怒而威，让人不敢逼视。\n");
        set("str", 30);
        set("dex", 30);
        set("con", 20);
        set("int", 60);
		set("shen_type", 1);
		set_skill("force", 50);
		set("combat_exp", 500000);
		set("max_qi", 2000);
        set("max_jing", 2000);
        set("neili", 4000);
        set("max_neili", 4000);
		set("uni_target",1);
		set("attitude", "friendly");
        set("inquiry", ([
            "name" : "本官就是史可法。",
            "马士英" : "马士英卑鄙小人，误我大明。",
            "满清" : "我就是死，也要死在战场上，不会后退一步。",
			"撤退" : "我就是死，也要死在战场上，不会后退一步。",
            "here" : "这里已经是抗击满洲人的最前线了。",
			"job" : (: ask_job :),
            "护送" : (: ask_job :),
			"fail" : (: ask_fail :),
			"失败" : (: ask_fail :),
            "复命" : (: ask_fuming :),
            "fuming" : (: ask_fuming :),
			"任务等待" : (: ask_query :),
			"query" : (: ask_query :),
			
            
       	]) );
		set("chat_chance", 1);
        set("chat_msg", ({
                "史可法喃喃说道：但愿天佑我大明，不然九泉之下无颜见左师。\n",
                "史可法怒道：马士英让我守扬州，不外是想独掌朝政。\n",
				"史可法道：谁来帮我掩护这一批百姓撤退呢？\n",
                (:askforhelp:),
        }) );
        setup();
        
		carry_object(__DIR__"items/cloth")->wear();

}

void init()
{
	add_action("do_kill", ({ "kill", "hit"}));
}

void unconcious()
{
	die();
}

void die()
{
	message_vision("$N摇了摇头，似乎遇到什么很难理解的事情。\n",this_object());
	this_object()->fullme();
	return;
}


int askforhelp()
{
    if (!this_object()->query("skf/deliver"))
    {
		CHANNEL_D->do_channel(this_object(), "rw", "扬州被女真鞑子包围，希望再有志士仁人拯救扬州百姓于危难之中。");
    }
    return 1;
}
int ask_query()
{	
	object ob=this_object();
	object me=this_player();
	int time,time1;
	time=600-(time()-(ob->query("skf/time")));
    time1=21600-(time()-(me->query("skfjob_last_time")));
    if (me->query("zhusantimes"))
    {
        command("whisper "+me->query("id")+" 你已经完成了"+sprintf("%d", me->query("zhusantimes"))+"次转移难民任务。");
    }
	if (time<0)
	{
		command("tell "+me->query("id")+" 现在就有难民等待护送。");
	}
	else
	{
		command("tell "+me->query("id")+" 下个难民还需要"+CHINESE_D->chinese_period(time)+"从城里撤出来。");
	}
	if (time1<=0)
	{
		command("tell "+me->query("id")+" 你如果有意，现在就可以去帮助难民撤退。");
	}
	else
	{
		command("tell "+me->query("id")+" 你上次辛苦了，好生休养一下，等"+CHINESE_D->chinese_period(time1)+"再来吧。");       
	}
	return 1;
}

int ask_fuming()
{
    object me=this_player();
	object ob=this_object();
	int i,j;
    if (!me->query("skf/jobasked")||!me->query_temp("skf/skf2"))
    {
        command("say 你来我这里要过任务吗？\n");
        return 1;
    }
    if (!me->query("mingpin")&&!me->query("ming/tj/pin"))
    {
        command("say 你不是大明官员，不用和我复命！\n");
        return 1;
    }
    if (!me->query_temp("skf/winwin"))
    {
        command("say 你把女真骑兵击退了吗？\n");
        return 1;
    }
    else
    {
		if (!me->query("biography/jobs/skf"))
		{
			me->set("biography/jobs/skf",time());//个人传记记录第一次完成任务时间ZINE
		}
        me->delete("skf/jobasked");
		me->delete_temp("skf");
        command("say 大人真不愧为我大明藩篱啊！\n");
        CHANNEL_D->do_channel(this_object(), "rw", me->query("name")+"在长江天险率大明铁骑击退女真骑兵，实乃天佑我大明。" );
        if (me->query("mingpin")>6)
        {
            me->add("zhusantimes",1);
            if (me->query_temp("skf/qbzengyuan"))
            me->add("zhusantimes",1);
            return 1;
        }
        else
        {
			i=1+random(3);
            me->add("ming/credit",i);
            if (me->query_temp("skf/qbzengyuan"))
            {
				j=3+random(3);
                me->add("ming/credit",j);
            }
			tell_object(me,"你获得了"+chinese_number(i+j)+"点大明功勋。\n");
            return 1;
        }
    }
}

int ask_fail()
{
	object me=this_player();
	object ob=this_object();
	if (me->query("skf/jobasked"))
	{
		if (me->query_temp("skf/xiang"))//现在不存在这个状态了
		{
			me->add("combat_exp",-10000);
			me->delete_temp("skf");
			me->delete("skf/jobasked");
			command("say 听说你降了女真人，还敢来欺瞒本督师？来人呐，绑了。\n");
			tell_object(me,"你听了之后大惊失色，事情那么隐秘竟被人发现，脚下抹油，赶紧溜了。\n");
			me->move("/d/city/beimen"); //希望move到这个地点的临近一格，也就是这个任务的接口，应该是扬州北门
			CHANNEL_D->do_channel(this_object(), "rw", me->query("name")+"卑鄙无耻，已经投降了女真，大家不要见到不要放过他。" );
			return 1;
		}
		else
		{
			me->delete("skf/jobasked");
			//me->add("combat_exp",0);//测试时期不减
			me->delete_temp("skf");
			command("say 唉，国事破败如此，非人力可为，也不全然是你的错。\n");
			return 1;
		}
	}
	else
	{
		command("say 我什么时候让你带百姓撤退的？大胆刁民，敢戏弄本督师，来人呐，重打三十军棍。\n");
		message_vision(WHT"$N被武将绑住，推出帐外，狠狠重打了三十军棍。\n"NOR,me);
		me->delete_temp("skf");
		me->unconcious();
		return 1;
	}
}

int ming_skf(object me)
{
    int i;
    int bing;
    object fighter;
    object ob=this_object();
    if (me->query("ming/tj/pin"))
    bing=10+random(5)-(int)me->query("ming/tj/pin");
	else
	bing=10+random(5)-(int)me->query("mingpin");
	me->set("skf/jobasked",1);
	me->set("skfjob_last_time",time());
	me->delete_temp("skf");
	me->set_temp("skf/migong",1);
	me->set_temp("skf/mingpin",1);
	me->set_temp("skf/refugeeasked",1);
	me->move("/d/city/xiaolu");
	me->set_temp("skf/skf2",1);
	ob->set("skf/time",time());
	ob->set("skf/deliver",1);
	ob->set("skf/jobid",me->query("name"));
	ob->set("skf/jobid2",me->query("id"));
	call_out("timeup",600,ob);//测试期600秒
	message_vision(MAG"$N只见小队骑兵从旁边的军营走了出来。\n"NOR,me);
	for (i=0;i<bing;i++)
	{
		fighter=new(__DIR__"fighter");
		fighter->set_temp("skf/huaquanpass",1);
		fighter->set_temp("skf/migong",1);
		fighter->set("skfleader",me->query("id"));
		fighter->move(environment(me));
		fighter->copy(me);
		fighter->gen(me);
		me->set_temp("skf/fighter"+i,fighter);
	}
	me->set_temp("skf/bingnumber",i);
	return 1;
}
int qing_skf(object me)
{
    me->set("skf/jobasked",1);
	me->set("skfjob_last_time",time());
	me->delete_temp("skf");
    me->set_temp("skf/skf-ct",1);
    return 1;
}
int ask_job()
{
	object me=this_player();
	object ob=this_object();
    string title;
	if (me->query("combat_exp")<5000000)
	{
		command("say 阁下的爱国之心让本官很是感动，但护送途中凶险无比，阁下的功夫似乎太差了点。");
		return 1;
	}
	if (ob->query("skf/deliver"))
	{
		command("say 现在已经有人正在帮助转移难民，人多反而容易打草惊蛇，你等会再来吧。");
		command("pat " + me->query("id"));
		return 1;
	}
	if (time()-(me->query("skfjob_last_time"))<21600)//cd时间
	{
		command( "say 你刚刚掩护过扬州民众撤退，且下去休整过后再来。");
		return 1;
	}
	if(me->query("skf/jobasked"))
	{
		command( "say 你刚才不是掩护难民撤退了吗？");
		command("consider " + me->query("id"));
		return 1;
	}
	else
	{
		if (me->query("mingpin"))
		{   
			command( "say 有大人相助，何愁大事不成？");
			command( "say 听说长江天险，难民遇袭，大人速领一队骑兵前去驰援。");
			command( "chat 大明官员"+me->query("name")+"带领一队骑兵前往长江天险抗击女真南下。\n" );
			ming_skf(me);
			return 1;
		}
		if (me->query("ming/tj/pin") && me->query("ming/tj/pin")<=6)
		{   
			command( "say 有公公相助，何愁大事不成？");
			command( "say 听说长江天险，难民遇袭，公公请领一队骑兵前去驰援。");
			command( "chat 大明中官"+me->query("name")+"带领一队骑兵前往长江天险抗击女真南下。\n" );
			ming_skf(me);
			return 1;
		}
		if (me->query("chaoting/jiawang")||me->query("chaoting/wang"))
		{   
			command( "say 嘿嘿，鞑子也来了。");
			command( "chat 女真鞑子"+me->query("name")+"企图偷营，被发现后逃逸。\n" );
			me->move("/d/city/beimen");
			tell_object(me,"你思前想后，还是决定去找找多尔衮商量该怎么做。\n");
			qing_skf(me);
			return 1;
		}
		else
		{
			command("look " + me->query("id"));
			command("tell " + me->query("id")+ " 国难当头，人人自危，难得你不忘自己华夏儿女的本色。\n" );
			command("whisper "+ me->query("id")+ " 好吧，我告诉你一条小路，希望你能带领这些百姓逃出生天。\n" );
			command("whisper "+ me->query("id")+ " 那里有我的亲军把守，口令是。。。。。。\n" );
			if (me->query("zhusantimes")>=20)
            title=HIW+"大明 "+HIR+"扬州大营 百户 "+NOR+me->query("name") + "(" + capitalize(me->query("id")) + ")";
			else if (me->query("zhusantimes")>=10)
			title=HIW+"大明 "+HIB+"扬州大营 总旗 "+NOR+me->query("name") + "(" + capitalize(me->query("id")) + ")";
			else
			title=HIW+"大明 "+HIG+"扬州大营 小旗 "+NOR+me->query("name") + "(" + capitalize(me->query("id")) + ")";
			if (me->query("family/family_name")!="朝廷")
			{
				me->set_temp("apply/short",title);
			}
			tell_object(me,"史可法给你指点了一条向东的小路。\n");
			command("say 民众已经出发了，一路上艰险重重，还望你不负我所托。\n");
			CHANNEL_D->do_channel(this_object(), "rw", me->query("name")+"侠义无双，力图救扬州军民于危难之中。" );
			me->set("skf/jobasked",1);
			me->set("skfjob_last_time",time());
			me->delete_temp("skf");
			me->move("/d/city/xiaolu");
			ob->set("skf/time",time());
			ob->set("skf/deliver",1);
			ob->set("skf/jobid",me->query("name"));
			ob->set("skf/jobid2",me->query("id"));
			call_out("timeup",600,ob);//测试期600秒
			return 1;
		}
	}
}

int timeup(object ob)
{	
	object pl,nm;
	ob->delete("skf/deliver");
	if (ob->query("skf/jobid2"))
	pl=find_player(ob->query("skf/jobid2"));
	if (!pl||!pl->query("skf/jobasked")||!pl->query_temp("skf/qjasked"))
	{
		CHANNEL_D->do_channel(this_object(), "rw", "扬州正被女真鞑子包围，希望再有志士仁人拯救扬州百姓于危难之中。" );
		return 1;
	}
	nm=pl->query_temp("skf/nanmin");
	if (pl&&pl->query_temp("skf/canceltimeup")) 
	{
		pl->delete_temp("skf/canceltimeup");
		CHANNEL_D->do_channel(this_object(), "rw", ob->query("skf/jobid")+"已护送民众过江，希望再有志士仁人救扬州百姓于危难之中。" );
		return 1;
	}
	else if (pl&&pl->query_temp("skf/canceltimeup2")) 
	{
		pl->delete_temp("skf/canceltimeup2");
		CHANNEL_D->do_channel(this_object(), "rw", ob->query("skf/jobid")+"护送民众过江失败，希望再有志士仁人救扬州百姓于危难之中。" );
		return 1;
	}
	else
	{
		tell_object(pl,HIR"突然间出现了大队女真骑兵！！！\n"NOR);
		tell_object(pl,"难民被女真骑兵虏去，你深感自责，回到史督师处负荆领罪。\n");
		if (nm)
		destruct(nm);
		pl->move("/d/city/junying");
		pl->delete_temp("skf");
		CHANNEL_D->do_channel(this_object(), "rw", "扬州被女真鞑子包围，希望再有志士仁人拯救扬州百姓于危难之中。" );
		return 1;
	}
}

int do_kill(string arg)
{
	object me=this_player();
	if((arg=="shi kefa"||arg =="shi"||arg =="kefa")&&userp(me))
	{
		tell_room(this_object(),"周围武将大喝，狗贼"+me->query("name")+"，敢对督师无礼！\n");
		return 1;
	}
	return 0;
}

