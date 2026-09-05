//diaoyuren
//modified by Zine 2012/11/08 
#define FACTOR 16 //系数 Zine e.g. 16既为1.6倍,如需调整2倍奖励，则factor 20.
#include <login.h>
#include <ansi.h>
inherit NPC;
#include "/d/luoyang/npc/banhe_events.h" //完成随机奖励事件统一定义在这里。Zine
int port=query_ip_port();
int ask_job();
int ask_fail();
int ask_task();
int ask_newbie();
int ask_intro(int);
void create()
{
	set_name("钓鱼人", ({ "diaoyu ren", "ren", "fisherman" }));
	set("long",
		"他一身白衣，正一动不动地钓着鱼。\n"
		"他看起来不到四十岁，却有一种不怒而威的感觉。\n");
	set("gender", "男性");
	set("age", 30+random(10));
	set("str", 35);
	set("int", 35);
	set("con", 35);
	set("dex", 35);
	set("combat_exp", 2000000);
	set("shen_type", 1);
    set("attitude", "friendly");
	set("max_jingli",3000);
	set("jingli",3000);
	set("neili",3000);
	set("max_neili",3000);
	set("jiali",60);
	set("score", 12000);
    set("max_qi",1000000);
    set("qi",1000000);
    set("no_get", "1");
	set_skill("hand", 250);
	set_skill("parry",250);
	set_skill("dodge", 250);
	set_skill("force",250);
	set_skill("literate",250);
	set_skill("pipa-shou",250);
	set_skill("taiyi-you",250);
	set_skill("jiuyin-shengong",250);

	map_skill("parry","pipa-shou");
	map_skill("hand","pipa-shou");
	map_skill("force","jiuyin-shengong");
	map_skill("dodge","taiyi-you");
	
	prepare_skill("hand","pipa-shou");
	set_temp("apply/attack", 20);
	set_temp("apply/defense", 20);


	set("inquiry", ([
		"here" : "你眼前的就是鄱阳湖了。\n",
        "鄱阳湖" : (: ask_intro,0 :),
        "大战" : (: ask_intro,1 :),
        "湖底" : (: ask_intro,2 :),
        "宝藏" : (: ask_intro,3 :),
        "小船" : (: ask_intro,4 :),
        "练手" : (: ask_newbie() :),
        "lianshou" : (: ask_newbie() :),
		"任务" : (: ask_job() :),
		"job" : (: ask_job() :),
		"寻宝" : (: ask_job() :),
        "重宝" : (: ask_task() :),
        "沉船" : (: ask_task() :),
        "task" : (: ask_task() :),
		"失败" : (: ask_fail() :),
        "fangqi" : (: ask_fail() :),
		"fail" : (: ask_fail() :),
        
		
	]));

	set("chat_chance",1);
	set("chat_msg",({
		"钓鱼人想起了什么，嘿嘿笑出声来。\n",
	}) );
	set("chat_chance_combat",100);
	set("chat_msg_combat", ({
		(: perform_action, "dodge.lingxu" :),
	}));
	
	setup();
	carry_object("/d/murong/npc/obj/shoes1")->wear();
	carry_object("/d/murong/npc/obj/cloth")->wear();
}

void init()
{
    add_action("do_answer","answer");
	add_action("do_check_bonus_factor","bonus_check");
}

int ask_intro(int flag)
{
    object me=this_player();
	string *msgs=({"鄱阳湖是本朝太祖和陈友谅大战的所在","鄱阳湖大战之后，无数战船沉在鄱阳湖底","无数宝藏也沉在了湖底","我备了一条小船，你来帮我啊？我们可以三七分账，你三我七","小船上有机关，如果有人袭船，用zhi命令可以暂时制住敌人。我会告诉你具体位置的，比如飘九东八，你上了下船，先顺流飘九里，然后停船向东划八里就到了"});
	if (me->query_temp("pyh/intro")<flag)
	{
        command("tell "+me->query("id")+" 我也不知道啊。");
    }
	else
	{
		command("tell "+me->query("id")+" "+msgs[flag]+"。");
		me->set_temp("pyh/intro",flag+1);
	}
    return 1;
}

int do_answer(string arg)
{
    object me=this_player();
    object ob=this_object();
    if (!me->query_temp("pyh/answer"))
    {
        return 0;
    }
    if (!arg)
    {
        tell_object(me,"你要回答什么！\n");
        return 1;
    }
    if (arg!=me->query_temp("pyh/password"))
    {
        command("tell "+me->query("id")+" 小样，要么没弄懂我的要求，要么是机器人，下次请早吧。\n");
        me->delete_temp("pyh");
        me->delete("pyh");
        me->set("pyh/starttime",time());
        return 1;
    }
	me->delete_temp("pyh/password");
	me->set_temp("pyh/downflow",20);
    ANTIROBOT_D->same_as_fullme(me);
	message_vision("$N对$n道：看来你还挺机灵的，先练练手，以后再帮我真正寻宝吧。\n",ob,me);
	tell_object(me,"你可以上船了，按钓鱼人的说法，你最远可以漂出"+BLINK+RED+"二十"+NOR+"里，三里后可以随时停船划回来(hua back)。\n");
	tell_object(me,BLINK+RED+"前三里划回来是没有奖励的。\n"+NOR);
	return 1;
}
int if_task_give(object me)
{
	mixed *tm=localtime(time());
    string date=sprintf("%d-%d-%d", tm[5], tm[4]+1, tm[3]);
	if (environment(me)!=environment(this_object()))
	{
		return 0;
	}
	if (me->is_busy() || me->is_fighting())
    {
        tell_object(me,"你正忙着呢！\n");
        return 0;
    }
    if (me->query("pyh/start"))
    {
        command("tell "+me->query("id")+" 你上次开了我的船去，还没给我分账呢？");
        return 0;
    }
    if (time()-(me->query("pyh/starttime"))<7200)
    {
        command("tell "+me->query("id")+" 你上次寻宝太辛苦了，过一会再来帮我吧。");
        me->add_busy(5);//防止有人刷屏
        return 0;
    }
	if (me->query("pyh_suc/time")!=date)
    {
		me->delete("pyh_suc/time");
		me->delete("pyh_suc/number");
    }
    if (me->query("pyh_suc/number")>=5)
    {
		command("tell "+me->query("id")+" 今天你寻宝太辛苦了，等明天再来吧。");
		return 0;
    }
    if(ANTIROBOT_D->stopped())
    {
		command("tell "+me->query("id")+" 我有点头晕，你迟点再来吧。");
		return 0;
    }
	return 1;
}
int give_task(object me,int flag)
{
	string *dirs=({"north","south","west","east"});
	string *directions=({"北","南","西","东"}),address;
	int downflow,i=random(4),step=random(8)+2;
	me->delete_temp("pyh");
	me->delete("pyh");
	if (flag==1)
	{
		downflow=5+random(50);
		me->set("pyh/simpletask",1);
	}
	if (flag==2)
	{
		downflow=5+random(14);
		if (me->query_temp("shilian/level")>2)
		downflow=14+random(5);
		if (me->query_temp("shilian/level")>3)
		downflow=16+random(3);
		me->set("pyh/easytask",1);
	}
	if (flag==3)
	downflow=18+random(15);
	address="漂"+ chinese_number(downflow)+"里后往"+directions[i]+"划"+chinese_number(step)+"里";
	if (flag==2||flag==3)
	{
		command("whisper "+me->query("id")+" 船已经准备好了，你上船后须得如此如此，这般这般。");
	}
	ANTIROBOT_D->mxpantirobot_ex(me,address);
	if (flag==2||flag==3)
	{
		command("whisper "+me->query("id")+" 那你先上船吧。\n");
	}
	if (flag==1)
	{
		me->set_temp("pyh/answer",1);
		me->set_temp("pyh/password",address);
	}
	me->set_temp("pyh/downflow",downflow);
	me->set_temp("pyh/step",step);
	me->set_temp("pyh/direction",dirs[i]);
	me->set_temp("pyh/boatpermit",1);
	me->set("pyh/start",1);
	me->set("pyh/starttime",time());
	return 1;
}
int give_team_task(object * team,int flag)
{
	string *dirs=({"north","south","west","east"});
	string *directions=({"北","南","西","东"}),address;
	int downflow,i=random(4),step=random(8)+2;
	if (flag==2)
	downflow=14+random(5);
	else
	downflow=18+random(15);
	for (int j=0;j<sizeof(team);j++ )
	{
		team[j]->delete_temp("pyh");
		team[j]->delete("pyh");
		if (flag==2)
		team[j]->set("pyh/easytask",1);
		address="漂"+ chinese_number(downflow)+"里后往"+directions[i]+"划"+chinese_number(step)+"里";
		command("whisper "+team[j]->query("id")+" 船已经准备好了，你上船后须得如此如此，这般这般。");
		ANTIROBOT_D->mxpantirobot_ex(team[j],address);
		command("whisper "+team[j]->query("id")+" 那你先上船吧。\n");
		team[j]->set_temp("pyh/downflow",downflow);
		team[j]->set_temp("pyh/step",step);
		team[j]->set_temp("pyh/direction",dirs[i]);
		team[j]->set_temp("pyh/boatpermit",1);
		team[j]->set("pyh/start",1);
		team[j]->set("pyh/starttime",time());
		team[j]->set_temp("pyh/team",team);
	}
	return 1;
}
object *team_work(object me)
{
	object *team = me->query_team(),*output=({});
	if (!arrayp(team))
	{
		return ({});
	}
	for (int i=0;i<sizeof(team);i++)
	{
		if (team[i]&&userp(team[i])&&if_task_give(team[i])&&present(team[i],environment(this_object())))
		output+=({team[i]});
	}
	return output;
}
int give_team_work(object me,int flag)
{
	object *team;
	if (sizeof(team=team_work(me))>1)
	{
		give_team_task(team,flag);
		return 1;
	}
	return 0;
}
int ask_newbie()
{
	object me = this_player();
    if (if_task_give(me)==0)
    return 1;
    if (me->query_temp("shilian"))
    {
        command("say 你想欺骗南海神尼前辈吗？");
        return 1;
    }
    command("whisper "+me->query("id")+" 考验一下你的能力，用answer回答我应该怎么做：");
	give_task(me,1);
	tell_object(me,"请用answer回答钓鱼人给出的要求。\n");
	return 1;
}


int ask_job()
{
	object me = this_player();
	object *allob;
	allob=all_inventory(me);
	for (int i=0;i<sizeof(allob);i++ )
	{
		if (userp(allob[i]))
		{
			write("钓鱼人说道：阁下还背了一个人，似乎不大妥当吧！\n");
			return 1;
		}
	}			
	if (give_team_work(me,2)==1)
	return 1;
    if (if_task_give(me)==0)
    return 1;
	if (me->query_temp("shilian/level")>4)
	{
		command("say 神尼前辈的任务，需要通过重宝完成。");
		return 1;
	}
	give_task(me,2);
	return 1;
}

int ask_task()
{
	object me = this_player();
	object *allob;
	allob=all_inventory(me);
	for (int i=0;i<sizeof(allob);i++ )
	{
		if (userp(allob[i]))
		{
			write("钓鱼人说道：阁下还背了一个人，似乎不大妥当吧！\n");
			return 1;
		}
	}			
	if (give_team_work(me,3)==1)
	return 1;
    if (if_task_give(me)==0)
    return 1;
	if (me->query("env/pyh") == "piao")
	me->set_temp("pyh/canrobot",1);
	give_task(me,3);
	if (!random(10))
	command("say 韩前辈铁琵琶手中绝技手挥五弦真是厉害，尤其方寸之间，比如船上，对付明教的对手无往不利。");
	return 1;
}


int ask_fail()
{
	object me = this_player();
    int pot;
	if (me->query("pyh/start")) 
    {
        if (!me->query_temp("pyh/humanerror")&&me->query_temp("pyh/real_distance")>25)
        {
            pot=(int)me->query_temp("pyh/real_distance")*((int)me->query("int")+(int)me->query("con")+(int)me->query("dex")+(int)me->query("str"));
            pot=REWARD_D->add_pot(me,pot);
            tell_object(me,HIC+"虽然并未完成，想起之前九死一生的战斗，你不禁觉得自己还是相当牛叉的！\n"+NOR);
            tell_object(me,HIC+"你的潜能增加了"+chinese_number(pot)+"点。\n"+NOR);
        }
		command("tell "+me->query("id")+" 没想到你这么不中用，算了算了。");
        if (!me->query_temp("pyh/humanerror")&&me->query_temp("pyh/real_distance")<20&&me->query_temp("pyh/real_distance"))
        {
            command("tell "+me->query("id")+" 在"+chinese_number((int)me->query_temp("pyh/real_distance"))+"里也能挂掉，真有够菜啊。");
            command("tell "+me->query("id")+" 船上机关不会用吧？去仔细看看这张贴：http://www.pkuxkx.net/forum/thread-22601-1-2.html。");
        }
		me->delete("pyh/start");
        me->delete_temp("pyh");
        me->set("pyh/starttime",time());
        if (me->query("pyh/toohighbonus"))
        {
            me->set("pyh/starttime",time()+3600);
        }
        if (me->query("pyh/toohighvalue"))
        {
            me->set("pyh/starttime",(int)me->query("pyh/starttime")+3600);
        }
		return 1;
	}
	else
	{
        command("? " + me->query("id"));
	    return 1;
    }
}
void die()
{
	fullme();
	return;
}
void unconcious()
{
	die();
}

int dest(object box,object me)
{
	object baoshi,clue,xian;
	int i,exp,dep,pot,rep,min,lucky=0,siling=0,index=0;
	string gem;
	if (box)
	destruct(box);
	tell_object(me,this_object()->query("name")+"打开了藏宝箱。\n");
	tell_object(me,HIY+this_object()->query("name")+"被眼前的珠宝闪耀得睁不开眼睛。\n"+NOR);
	tell_object(me,this_object()->query("name")+"从藏宝箱里取出一颗"+HIY+"天◎玉髓"+NOR+"。\n");
	tell_object(me,this_object()->query("name")+"从藏宝箱里取出一颗"+HIR+"天★炎晶"+NOR+"。\n");
	tell_object(me,this_object()->query("name")+"从藏宝箱里取出一颗"+HIG+"天★木灵"+NOR+"。\n");
	tell_object(me,this_object()->query("name")+"从藏宝箱里取出一颗"+HIB+"天☆玄冰"+NOR+"。\n");
	tell_object(me,this_object()->query("name")+"从藏宝箱里取出一颗"+HIW+"天☆精金"+NOR+"。\n");
	if (random(me->query("kar"))>29)
	lucky=1;
	min=30*(int)me->query("pyh/dalao")+999*lucky+1200+me->query("kar")*me->query("kar"); //宝石和打捞次数福源挂钩，Zine
    if (min<5000)
    min=5000;
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
	if (me->query("env/pyh_no_siling")&&(gem=="jia"||gem=="jiao"||gem=="yu"||gem=="gu"))
	gem="sui";
	if (me->query("pyh_obtain_high_gem"))
    min=5000;
    baoshi->set_level(min,9999,gem);
	if (me->query_temp("pyh/low_contribute"))
	{
		me->delete_temp("pyh/low_contribute");
		baoshi->set_level(1,4999,gem);
		tell_object(me,HIR+BLINK+"你在刚才的漂流中贡献太低，无法获得正常的奖励！\n");
	}
    baoshi->move(me);
    me->add("newjobs/completed/pyh",1);
    command("say 你的三成就用这个抵吧。\n");
    tell_object(me,this_object()->query("name")+"给你一枚"+baoshi->query("name")+"。\n");
    if (baoshi->query("level")<3)
    {
        CHANNEL_D->do_channel(this_object(), "bd", "rich "+me->query("id"), 1);
    }
    else if (baoshi->query("level")>=6)
    {
        CHANNEL_D->do_channel(this_object(), "bd", "zt4 "+me->query("id"), 1);
        me->set("pyh_obtain_high_gem",1);
        if (xian=load_object("/d/city/npc/xian")) //加个广告
		xian->adv_tell(me);
        if (xian=load_object("/d/luoyang/npc/du")) //加个广告
		xian->adv_tell(me);
    }
    else
    {
        CHANNEL_D->do_channel(this_object(), "bd", "good "+me->query("id"), 1);
    }
    exp=me->query("pyh/exp");
    pot=me->query("pyh/pot");
	rep=me->query("pyh/rep");
    if (exp<=0)
    exp=0;
    if (pot<=0)
	pot=0;
    if (me->query("env/pyh_deposit"))
    index=1;
    if (me->query("env/pyh_no_siling"))
	siling=1;
    dep=exp/5*index*2;
    exp=exp/5*(5-index-siling);
	exp = REWARD_D->add_exp(me,exp,"piaoliu");
    pot = REWARD_D->add_pot(me,pot);
    rep = REWARD_D->add_rep(me,rep);
    me->add("exp_dep",dep);//类似公积金，存1块，得2块，用途另表，zine
    me->add("exp/pyh", exp);
    me->add("pot/pyh", pot);
	me->delete("pyh/exp");
    me->delete("pyh/pot");
	me->delete("pyh/rep");
	me->delete_temp("pyh");
	CHANNEL_D->do_channel(this_object(), "rw", me->query("name")+"完成鄱阳湖寻宝任务，获得经验"+ chinese_number(exp) +"点、"+"潜能"+ chinese_number(pot) +"点。");
	tell_object(me,HIC "你觉得自己获得了：\n"
                + chinese_number(exp) + "点实战经验，\n"
                + chinese_number(pot) + "点潜能。\n"NOR);
	tell_object(me,"你已经完成了"+chinese_number((int)me->query("newjobs/completed/pyh"))+"次鄱阳湖寻宝任务。\n"NOR);
	message_vision(YEL"$N在巨岩的岩缝里刻下了些什么。\n"NOR,this_object());
	CHANNEL_D->do_channel(this_object(), "rw", me->name(1) + "在鄱阳湖寻宝任务中，获得"+baoshi->name()+"一枚!");
    if (!random(9))
    finish_bonus(me);
    return 1;
}

int accept_object(object me, object box)
{
    mixed *tm;
       
    if (this_object()->is_busy() || this_object()->is_fighting())
    {
        tell_object(me,this_object()->query("name")+"正忙着呢！\n");
        return 1;
    }
    if (box->query("id")=="yugou" && box->query("jiangnan") && me->query_temp("jn/step7a"))
    {
        me->delete_temp("jn/step7a");
        me->set_temp("jn/step7b",1);
        tell_object(me,this_object()->query("name")+"道：韩前辈送来鱼钩必有深意！\n");
        tell_object(me,this_object()->query("name")+"开始认真思考这个问题。\n");
        tell_object(me,this_object()->query("name")+"道：你去温峤府上看看吧\n");
        return 1;
    }
	if( box->query("id") != "cangbao xiang" || !box->query("pyh"))
	return notify_fail(this_object()->query("name")+"道：别拿不相干的东西来忽悠我。\n");
	if( box->query("owner") != me->query("id"))
	return notify_fail(this_object()->query("name")+"道：这是你找来的吗？\n");
	me->add_busy(1);
	this_object()->add_busy(1);
	me->set("pyh/starttime",time()-900);
	if (me->query("pyh/toohighbonus"))
	me->set("pyh/starttime",time()+3600);
	if (me->query("pyh/toohighvalue"))
	me->set("pyh/starttime",(int)me->query("pyh/starttime")+3600);
	tm=localtime(time());
	if (!me->query("pyh_suc/time"))
	me->set("pyh_suc/time", sprintf("%d-%d-%d", tm[5], tm[4]+1, tm[3]));
    me->add("pyh_suc/number", 1);
    me->delete("pyh/start");
    call_out("dest",1,box,me);
	return 1;
}

int do_check_bonus_factor()
{
	float factor=1-to_float(this_player()->query("exp/pyh"))/200000000;
	if (factor<0.5)
    	factor=0.5;
    tell_object(this_player(),"你的鄱阳湖奖励系数为"+factor+"，单人任务奖励系数，最低为"+LINEB+RED+"0.5"+NOR+"，单人重宝最低奖励系数为"+LINEB+RED+"0.8"+NOR+"，多人版漂流最低奖励系数为"+LINEB+RED+"0.75"+NOR+"。\n");
	return 1;
}