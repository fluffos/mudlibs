//南海神尼
//created by Zine 15 Feb 2011

#include <ansi.h>
#include <localtime.h>
inherit NPC;
int adv();
int ask_start();
int ask_finish();
int ask_team();
int ask_times();
int gettime();
void create()
{
        set_name("南海神尼", ({ "nanhai shenni","shenni","ni"}) );
        set("gender", "女性" );
		set("title",HIC"世外高人"NOR);
        set("age", 181);
        set("long", 
            "她是南海神尼，很多传说都与她有关。\n");
        set("str", 80);
        set("dex", 80);
        set("con", 80);
        set("int", 80);
		set("shen_type", 1);
		set_skill("force", 2500);
        set_skill("jiuyin-zhengong",2500);
        set_skill("strike",2500);
        set_skill("jiuyin-shenzhang",2500);
        set_skill("claw",2500);
        set_skill("parry",2500);
        set_skill("jiuyin-shenzhua",2500);
        set_skill("dodge",2500);
        set_skill("jiuyin-shenfa",2500);

        map_skill("strike","jiuyin-shenzhang");
        map_skill("claw","jiuyin-shenzhua");
        map_skill("dodge","jiuyin-shenfa");
        map_skill("force","jiuyin-zhengong");
        map_skill("parry","jiuyin-shenzhua");

        prepare_skill("claw","jiuyin-shenzhua");
        prepare_skill("strike","jiuyin-shenzhang");

		set("combat_exp", 1000000000);
		set("max_qi", 1000000);
        set("max_jing", 1000000);
        set("neili", 4000000);
        set("max_neili", 4000000);
		set("uni_target",1);
		set("attitude", "friendly");
        set("inquiry", ([
            "name" : "贫尼法号南海",
			"考验开始" : (: ask_start :),
            "start" : (: ask_start :),
            "考验结束" : (: ask_finish :),
			"finish" : (: ask_finish :),
			"find" : (: ask_team :),
            "找队友" : (: ask_team :),
			"times" : (: ask_times :),
			"次数" : (: ask_times :),			
            
       	]) );
		set("chat_chance", 3);
        set("chat_msg", ({
                
                (:adv:),
        }) );
        setup();
        
		carry_object("/d/city/npc/items/cloth1")->wear();

}

int gettime()
{
    object ob=this_object();
    if (ob->query("count"))
    {
        CHANNEL_D->do_channel(this_object(), "bd", "smile", 1);
        CHANNEL_D->do_channel(this_object(), "rw", "从昨日到今天，一天之内共有"+chinese_number(ob->query("count"))+"人次通过考验。");
        ob->set("count",0);
    }
    return 1;
}

int ask_team()
{
    object me=this_player();
    object *all_player;
    int exp=me->query("combat_exp");
    int min,max,i,count=0;
    string name,id;
    if (exp>50000000)
    {
        command("say 你已经很厉害了，自己去找个合适的搭档吧。");
        return 1;
    }
    if (exp<1000000)
    {
        command("0");
        return 1;
    }
    max=exp*11/10;
    min=exp*9/10;
    all_player = filter_array(children(USER_OB), (: userp :));
    all_player = filter_array(all_player, (: environment :));
    tell_object(me,this_object()->query("name")+"道：");
    for (i=0;i<sizeof(all_player);i++)
    {
        if (all_player[i]->query("combat_exp")>min&&all_player[i]->query("combat_exp")<max&&count<10&&all_player[i]->query("id")!=me->query("id"))
        {
            name=all_player[i]->query("name");
            id=all_player[i]->query("id");
            tell_object(me,name+"("+id+")  ");
            count=count+1;
        }
        
        
    }
    if (count==1)
        {
            tell_object(me,"与你功力相若，也许你可以试试找找他。\n");
            return 1;
        }
    if (count>1)
        {
            tell_object(me,"与你功力相若，也许你可以试试找找他们。\n");
            return 1;
        }
    tell_object(me,"现在找不到和你功力相若的人。\n");
    return 1;
}
int adv()
{
	mixed* timeinfos=localtime(time());
    int hour=timeinfos[LT_HOUR];
    if (hour==12)
	gettime();
    if (random(100)>95)
    CHANNEL_D->do_channel(this_object(), "bd", "smile", 1);    
}

void init()
{
    add_action("do_kill","kill");
}

int do_kill(string arg)
{
    object me=this_player();
    if (arg=="nanhai shenni"||arg=="shenni"||arg=="ni")
    {
    tell_object(me,"不许对世外高人下手。\n");
    return 1;
    }
}
void unconcious()
{
        die();
}

void die()
{
        message_vision("$N道：不得放肆。\n",this_object());
        this_object()->fullme();
        return;
}

int ask_intro()
{
    object ob=this_object();
    object me=this_player();
    if (ob->is_busy() || ob->is_fighting())
	{
        command("say 没看我正忙着吗？\n");
		return 1;
    }
    if (me->is_busy() || me->is_fighting())
	{
        tell_object(me,"你正忙着呢。\n");
		return 1;
    }
    message_vision("$N开始向$n讲解考验任务……\n",ob,me);
    tell_object(me,"考验任务必须双人完成。\n");
    tell_object(me,"考验任务共含：四次胡一刀任务，四次护镖任务，一次鄱阳湖寻宝任务，四次韩员外任务。两次萧峰任务。\n");
    tell_object(me,"在半小时内必须完成。\n");
    tell_object(me,"你可以用查询(chaxun)命令随时查询任务完成情况。\n");
    tell_object(me,"所有任务完成后回到这里交任务。\n");
    return 1;
}

int ask_start()
{
    int i,st1,st2,st3,st4,st5,st6,difficult;
    object ob=this_object();
    object me=this_player();
    object partner,xinwu;
    object *team = me->query_team();
    if (ob->is_busy() || ob->is_fighting())
	{
        command("say 没看我正忙着吗？\n");
		return 1;
    }
    if (me->is_busy() || me->is_fighting())
	{
        tell_object(me,"你正忙着呢。\n");
		return 1;
    }
    if (!team)
    {
        command("say 你必须加入一个Team才能开始考验。\n");
		return 1;
    }
    if (sizeof(team)>2)
    {
        command("say 考验考验的是两个人的配合能力，你队伍里的人太多了。\n");
		return 1;
    }
    
    for (i=0; i<sizeof(team); i++)
    {
        if (team[i]->query("id")!=me->query("id"))
        {
            partner=team[i];
        }
    }
    if (!partner)
    {
        command("say 你的伙伴呢？\n");
		return 1;
    }
    if (me->query("yidao/on_job"))
      	{
         message_vision("$N说道：胡一刀大侠交给你的任务完成了吗？搞定再说吧。\n",ob);
         return 1;
        }
      
      if (me->query("in_dart"))
      	{
         message_vision("$N说道：林镇南大侠交给你的任务完成了吗？搞定再说吧。\n",ob);
         return 1;
        }
    if(me->query("xiaofeng/on_job"))
      	{
         message_vision("$N说道：萧峰大侠交给你的任务完成了吗？搞定再说吧。\n",ob);
         return 1;
        }
    if (me->query_temp("hyw/start"))
    {
         message_vision("$N说道：韩员外交给你的任务完成了吗？搞定再说吧。\n",ob);
         return 1;
    }
    if (me->query("pyh/exp"))
    {
        message_vision("$N说道：你的鄱阳湖寻宝搞了一半，想半途而废吗？搞定再说吧。\n",ob);
        return 1;
    }
    if (partner->query("yidao/on_job"))
      	{
         message_vision("$N说道：胡一刀大侠交给他的任务完成了吗？搞定再说吧。\n",ob);
         return 1;
        }
      
      if (partner->query("in_dart"))
      	{
         message_vision("$N说道：林镇南大侠交给他的任务完成了吗？搞定再说吧。\n",ob);
         return 1;
        }
        
    if(partner->query("xiaofeng/on_job"))
      	{
         message_vision("$N说道：萧峰大侠交给他的任务完成了吗？搞定再说吧。\n",ob);
         return 1;
        }
    if (partner->query_temp("hyw/start"))
    {
         message_vision("$N说道：韩员外交给他的任务完成了吗？搞定再说吧。\n",ob);
         return 1;
    }
    if (partner->query("pyh/exp"))
    {
        message_vision("$N说道：他的鄱阳湖寻宝任务搞了一半，想半途而废吗？搞定再说吧。\n",ob);
        return 1;
    }
    if (base_name(environment(partner))!=base_name(environment(me)))
    {
        command("say 你的伙伴呢？\n");
		return 1;
    }
    if (me->query_temp("shilian/start"))
    {
        command("say 你已经开始了一次考验，还没有结束就又来了？\n");
		return 1;
    }
    if (partner->query_temp("shilian/start"))
    {
        command("say 你的伙伴已经开始了一次考验，还没有结束就又来了？\n");
		return 1;
    }
    if (me->query("combat_exp")<1000000)
    {
        command("say 你的经验太欠缺，还是努力努力再来吧。\n");
		return 1;
    }
    if (partner->query("combat_exp")<1000000)
    {
        command("say 你的伙伴经验太欠缺，还是努力努力再来吧。\n");
		return 1;
    }
    if (me->query("combat_exp")<50000000 && (partner->query("combat_exp")>me->query("combat_exp")/10*11 ||partner->query("combat_exp")<me->query("combat_exp")/10*9))
    {
        command("say 你们俩经验相差太远，无法配合。\n");
		return 1;
        
    }
    if (me->query("combat_exp")>=50000000&&me->query("combat_exp")<100000000 && (partner->query("combat_exp")>me->query("combat_exp")/3*4 ||partner->query("combat_exp")<me->query("combat_exp")/3*2))
    {
        command("say 你们俩经验相差太远，无法配合。\n");
	    return 1;
    
    }
    if (me->query("combat_exp")>=100000000&&me->query("combat_exp")<200000000 && (partner->query("combat_exp")>me->query("combat_exp")*2 ||partner->query("combat_exp")<me->query("combat_exp")/2))
    {
        command("say 你们俩经验相差太远，无法配合。\n");
	    return 1;
    
    }
    if (me->query("combat_exp")>=200000000&&partner->query("combat_exp")<100000000)
    {
        command("say 你们俩经验相差太远，无法配合。\n");
	    return 1;
    
    }
    else
    {
        difficult=me->query("newjobs/completed/shenni");
        if ((int)partner->query("newjobs/completed/shenni")>difficult)
        {
            difficult=partner->query("newjobs/completed/shenni");
        }
        if (difficult<10)
        {
            me->set_temp("shilian/level",0);
            partner->set_temp("shilian/level",0);
        }
        else if (difficult<20)
        {
            me->set_temp("shilian/level",1);
            partner->set_temp("shilian/level",1);
        }
        else if (difficult<30)
        {
            me->set_temp("shilian/level",2);
            partner->set_temp("shilian/level",2);
        }
        else if (difficult<40)
        {
            me->set_temp("shilian/level",3);
            partner->set_temp("shilian/level",3);
        }
        else if (difficult<50)
        {
            me->set_temp("shilian/level",4);
            partner->set_temp("shilian/level",4);
        }
        else
        {
            me->set_temp("shilian/level",5);
            partner->set_temp("shilian/level",5);
        }
        
        st1=me->query("jobs/completed/huyidao")+partner->query("jobs/completed/huyidao");
        st2=me->query("jobs/completed/hubiao")+partner->query("jobs/completed/hubiao");
        st3=me->query("jobs/completed/xiaofeng")+partner->query("jobs/completed/xiaofeng");
        //st4=me->query("jobs/completed/task")+partner->query("jobs/completed/task");
        st5=me->query("newjobs/completed/pyh")+partner->query("newjobs/completed/pyh");
        st6=me->query("newjobs/completed/hyw")+partner->query("newjobs/completed/hyw");
        
        me->set_temp("shilian/start",time());
        partner->set_temp("shilian/start",time());
        if (me->query_temp("shilian/level")>3)
        {
            me->set_temp("shilian/start",time()-120*((int)me->query_temp("shilian/level")-3));
            partner->set_temp("shilian/start",time()-120*((int)me->query_temp("shilian/level")-3));
            if (me->query_temp("shilian/level")==5)
            {
                me->set_temp("shilian/start",me->query_temp("shilian/start")-60);
                partner->set_temp("shilian/start",me->query_temp("shilian/start")-60);
            }
        }
        me->set_temp("shilian/st1",st1);
        partner->set_temp("shilian/st1",st1);
        me->set_temp("shilian/st2",st2);
        partner->set_temp("shilian/st2",st2);
        me->set_temp("shilian/st3",st3);
        partner->set_temp("shilian/st3",st3);
        me->set_temp("shilian/st4",st4);
        partner->set_temp("shilian/st4",st4);
        me->set_temp("shilian/st5",st5);
        partner->set_temp("shilian/st5",st5);
        me->set_temp("shilian/st6",st6);
        partner->set_temp("shilian/st6",st6);
        me->set_temp("shilian/partner",partner->query("id"));
        partner->set_temp("shilian/partner",me->query("id"));
        xinwu=new(__DIR__"obj/xinwu");
        xinwu->set("me",me->query("id"));
        xinwu->set("myname",me->query("name"));
        xinwu->set("partner",partner->query("id"));
        xinwu->set("partnername",partner->query("name"));
        xinwu->set("st1",st1);
        xinwu->set("st2",st2);
        xinwu->set("st3",st3);
        xinwu->set("st4",st4);
        xinwu->set("st5",st5);
        xinwu->set("st6",st6);
        xinwu->move(me);
        message_vision("南海神尼给了$N一件信物。\n",me);
        xinwu=new(__DIR__"obj/xinwu");
        xinwu->set("me",partner->query("id"));
        xinwu->set("myname",partner->query("name"));
        xinwu->set("partner",me->query("id"));
        xinwu->set("partnername",me->query("name"));
        xinwu->set("st1",st1);
        xinwu->set("st2",st2);
        xinwu->set("st3",st3);
        xinwu->set("st4",st4);
        xinwu->set("st5",st5);
        xinwu->set("st6",st6);
        xinwu->move(partner);
        message_vision("南海神尼给了$N一件信物。\n",partner);
        message_vision("$N笑道：持有我的信物，完成考验后再来找我吧。\n",ob);
        if (me->query_temp("shilian/level"))
        {
            command("say 你们俩都通过考验多次了，这次考验的难度会比以前提高一些。");
            CHANNEL_D->do_channel(this_object(), "rw", me->query("name")+"和"+partner->query("name")+"开始特殊考验任务，难度系数是"+chinese_number((int)me->query_temp("shilian/level"))+"。");
        }
        me->add_busy(1);
        partner->add_busy(1);
        ob->add_busy(1);
        return 1;
    }
}

int bonus_new(object me)
{
    object baoshi;
    int i,num;
    string gem;
    if (me)
    {
            num = 10000 - random(554); 
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
            baoshi->set_level(num,num,gem);
            baoshi->move(me);
            CHANNEL_D->do_channel(this_object(), "rw", me->query("name")+"初次尝试完成南海神尼考验任务，获得"+baoshi->query("name")+"一枚。");
            this_object()->add("count",1);
            me->delete_temp("shilian");
            return 1;
    }
}

int bonus(object me)
{
    object baoshi,baoshi2,baoshi3,material;
    int i,num,nrn;
    string gem;
    if (me)
    {
			if (!me->query("hsz_auto") && 
				((me->query_temp("shilian/level")>=5 && random(10000)>9880)
				|| (me->query_temp("shilian/level")==4 && random(10000)>9920)
				|| (random(10000)>9960)))
			{
				material=new("/obj/remedy/drug/wuchang-material");
				if (objectp(material))
				{
					material->set("owner", me->query("id"));
					material->move(me);
					tell_object(me, "南海神尼送你一份罕见的珍贵药材作为额外馈赠。\n");
				}
			}
			
            num = 10000 - random(554); 
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
            if (me->query_temp("shilian/level")<4)
            {
				i=3;
	         }
			else
			{
				i=6-me->query_temp("shilian/level");
			}
			if (!random(i))
			{
				if (gem=="yan"||gem=="mu")
				{
					gem="yu";
				}
				if (gem=="sui"||gem=="jin")
				{
					gem="gu";
				}
			}
			if (me->query_temp("shilian/level")==5)
			{
				if (num<9940)
				{
					num=9940;
				}
			}

            if (me->query_temp("shilian/level")==5&&random(100)>90&&num<9980)
            {
                gem="yue";
            }
			baoshi->set_level(num,num,gem);
            baoshi->move(me);
			nrn = random(1000);
            if ((nrn>939&&!random(4))||(me->query_temp("shilian/level")>4&&!random(3)))
            {	
				if ((nrn>939)||(me->query_temp("shilian/level")>4))
				{
					baoshi2= new("obj/gem/ring");
					if (baoshi2->query("forge/max")<2)
					{
						baoshi2->set("forge/max",2);
					}
                CHANNEL_D->do_channel(this_object(), "rw", me->query("name")+"完成南海神尼考验任务，获得"+baoshi->query("name")+"一枚，及"+baoshi2->query("name")+"一件。");
                baoshi2->move(me);
				}
				
				if (nrn>996)
				{
					baoshi2= new("obj/taozhuang/xiaobao/boots");
					baoshi2->set("forge/max",2);
				}
				else if (nrn>989) 
				{
					baoshi2= new("obj/taozhuang/xiaobao/boots");
					baoshi2->set("forge/max",1);

				}
				else if (nrn>984) 
				{
					baoshi2= new("obj/taozhuang/xiaobao/cloth");
					baoshi2->set("forge/max",1);

				}
				else if (nrn>979) 
				{
					baoshi2= new("obj/taozhuang/xiaobao/dagger");
					baoshi2->set("forge/max",1);
				}
				else if (nrn>973) baoshi2= new("obj/taozhuang/xiaobao/cloth");
				else if (nrn>964) baoshi2= new("obj/taozhuang/xiaobao/dagger");
				if (me->query_temp("shilian/level")>4)
				{
					i=random(20);
					if (i>19)
					{
						baoshi2= new("obj/taozhuang/xiaobao/boots");
					}
					else if (i>12)
					{
						baoshi2= new("obj/taozhuang/xiaobao/cloth");
					}
					else
					{
						baoshi2= new("obj/taozhuang/xiaobao/dagger");
					}
					baoshi2->set("forge/max",2);
				}
				if (nrn>964||me->query_temp("shilian/level")>4)
				{
					baoshi2->move(me);
					CHANNEL_D->do_channel(this_object(), "rw", me->query("name")+"完成南海神尼考验任务，获得"+baoshi2->query("name")+"一件。");
				}
                this_object()->add("count",1);
                me->delete_temp("shilian");
                return 1;
            }
            num = 10000 - random(554);
            if (num<9815) //第二颗雷以上，但是降低高级火，泽，天宝石的概率
            {
                num=9815;
            }
            //保证雷以上，但是火以上概率降低至少５０％
            else if ( num>=9940 && random(10)<(10-me->query_temp("shilian/level")) )
            {
                num=9815;
            }
            


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
            if (me->query_temp("shilian/level")<4)
            {
				i=3;
            }
			else
			{
				i=6-me->query_temp("shilian/level");
			}
			if (!random(i))
			{
				if (gem=="yan"||gem=="mu")
				{
					gem="yu";
				}
				if (gem=="sui"||gem=="jin")
				{
					gem="gu";
				}
			}
            if (me->query_temp("shilian/level")==5&&random(100)>90&&num<9980)
            {
                gem="yue";
            }
			if (me->query_temp("shilian/level")==5)
			{
				if (num<9940)
				{
					num=9940;
				}
			}
            baoshi2->set_level(num,num,gem);
            baoshi2->move(me);
            CHANNEL_D->do_channel(this_object(), "rw", me->query("name")+"完成南海神尼考验任务，获得"+baoshi->query("name")+"及"+baoshi2->query("name")+"各一枚。");
            this_object()->add("count",1);
			if (me->query_temp("shilian/level")>3)
			{
				i=13-me->query_temp("shilian/level");
				if (!random(i))
				{
					//bug fix 1下
		            baoshi3 = new("/obj/gem/gem");
		            baoshi3->set_level(num,num,gem);
					baoshi3->move(me);
					CHANNEL_D->do_channel(this_object(), "rw", "南海神尼鉴于"+me->query("name")+"在考验任务中劳苦功高，额外奖励"+baoshi3->query("name")+"一枚。");
				}
			}
			  			
			if(me->query_temp("shilian/level")>4)
			{
				log_file("user/shenni",ctime(time())+":"+me->query("id")+"通过了一次神尼5。\n");
			}
            me->delete_temp("shilian");
            return 1;
    }
}

int ask_finish()
{
    object me=this_player();
    object ob=this_object();
    object xinwu,partner;
    int st1,st2,st3,st4,st5,st6;
    if (!me->query_temp("shilian/start"))
    {
        return notify_fail("你什么时候开始的考验任务？\n");
    }
    if (me->is_busy() || me->is_fighting())
    {
		return notify_fail("你正忙着哪！\n");
    }
    if (present("xin wu",me))
    {
        xinwu=present("xin wu",me);
        destruct(xinwu);
        tell_object(me,"南海神尼收走了你身上的信物。\n");
    }
    partner=find_player(me->query_temp("shilian/partner"));
    if (!partner)
    {
        st1=me->query("jobs/completed/huyidao");
        st2=me->query("jobs/completed/hubiao");
        st3=me->query("jobs/completed/xiaofeng");
        //st4=me->query("jobs/completed/task");
        st5=me->query("newjobs/completed/pyh");
        st6=me->query("newjobs/completed/hyw");
    }
    else
    {
        st1=me->query("jobs/completed/huyidao")+partner->query("jobs/completed/huyidao");
        st2=me->query("jobs/completed/hubiao")+partner->query("jobs/completed/hubiao");
        st3=me->query("jobs/completed/xiaofeng")+partner->query("jobs/completed/xiaofeng");
        //st4=me->query("jobs/completed/task")+partner->query("jobs/completed/task");
        st5=me->query("newjobs/completed/pyh")+partner->query("newjobs/completed/pyh");
        st6=me->query("newjobs/completed/hyw")+partner->query("newjobs/completed/hyw");
    }
    if (st1-me->query_temp("shilian/st1")<4
        || st2-me->query_temp("shilian/st2")<4
        || st3-me->query_temp("shilian/st3")<2
        || st5-me->query_temp("shilian/st5")<1
        || st6-me->query_temp("shilian/st6")<4)//没完成
    {
        message_vision("$N道：你还没有完成呢，再努力努力吧。\n",ob);
        return 1;
    }
    else if (time()-me->query_temp("shilian/start")<1800-(int)me->query_temp("shilian/level")*90)//完成且满足时间要求
    {
        message_vision("$N微笑道：不错，在规定时间内完成了考验，我有几颗没用的石头，全给你吧。\n",ob);
        me->add("newjobs/completed/shenni",1);
        if (!me->query("biography/jobs/shenni"))
		{
			me->set("biography/jobs/shenni",time());//个人传记记录第一次完成任务时间ZINE
		}
		bonus(me);
        return 1;
    }
    else//完成不满足时间要求
    {
        if (!me->query("newjobs/completed/shenni")&&time()-me->query_temp("shilian/start")<2700)//第一次做的额外优待时间。
        {
            message_vision("$N微笑道：虽然没有在规定时间内完成了考验，但考虑这是你第一次尝试，我有颗没用的石头，就送给你留个纪念吧。\n",ob);
            me->add("newjobs/completed/shenni",1);
            bonus_new(me);
            return 1;
        }
        if (time()-me->query_temp("shilian/start")<2400)
        {
            me->add("newjobs/completed/shenni",-1);
        }
        if (me->query("newjobs/completed/shenni")<0)
        {
            me->set("newjobs/completed/shenni",0);
        }
        me->set("shenni_fail_info/finish_time",time());
        me->set("shenni_fail_info/start_time",me->query_temp("shilian/start"));
        me->set("shenni_fail_info/cur_level",me->query_temp("shilian/level"));
        me->delete_temp("shilian");
        message_vision("$N淡淡道：可惜可惜。\n",ob);
        return 1;
    }
    
}

int ask_times()
{	
    object me = this_player();
    tell_object(me,HIY"你已经成功完成组队神尼任务" + chinese_number(me->query("newjobs/completed/shenni")) + "次！\n"NOR);
	return 1;
}

