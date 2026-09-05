//Zine 本人
//created by Zine 21 Oct 2010

#include <ansi.h>
#include "bonus.h"
inherit NPC;

int ask_job();
int ask_judge();
int ask_skill();
int askforhelp();
int ask_leave();
int ask_desc1();
int ask_desc2();
int ask_desc3();
int ask_desc4();
int ask_desc5();
int ask_item1();
int ask_item2();
int ask_item3();
int ask_item4();
int ask_item5();
int ask_whatsup();
int Jobs(object me,int flag);
int ask_dian();
void get_myname()
{
	string id,name;
	name=FAMILY_D->get_dadizi_name("星宿派");
	id=FAMILY_D->get_dadizi("星宿派")+" npc";
	set_name(name,({id,"da dizi"}));
	set("long","他是星宿派第二代亲传弟子——"+name+"，奉老仙之命掌管后山。\n");
	set("chat_msg", ({
                this_object()->name()+"低头看着自己的掌纹，不知道在想什么。\n",
                (: random_move :),
                //(:askforhelp:),
        }) );
	return;
}
string my_name()
{
	return this_object()->name();
}
void create()
{
        set_name("我踏月色而来", ({ "zine npc", "zine" }) );
        set("gender", "男性" );
		set("title", "星宿派"HIR"掌门大弟子"NOR);
        set("age", 20);
        set("long", 
            "他是星宿派第二代亲传弟子——我踏月色而来，奉老仙之命掌管后山。\n");
        set("str", 200);
        set("dex", 200);
        set("con", 200);
        set("int", 200);
		set("shen_type", 1);
		set("env/no_emote",1);
		set_skill("force", 50);
		set("combat_exp", 500000000);
		set("max_qi", 200000);
        set("max_jing", 200000);
        set("neili", 400000);
        set("max_neili", 400000);
		set("uni_target",1);
        set_skill("force", 1000);
        set_skill("huagong-dafa", 1800);
        set_skill("dodge", 1500);
        set_skill("zhaixinggong", 1500);
        set_skill("strike", 1500);
        set_skill("xingxiu-duzhang", 1800);
        set_skill("hand", 1500);
        set_skill("zhaixing-shou", 1500);
        set_skill("parry", 1500);
        set_skill("staff", 1500);
        set_skill("tianshan-zhang", 1500);
        set_skill("literate", 800);
        set_skill("poison", 1000);
        map_skill("force", "huagong-dafa");
        map_skill("dodge", "zhaixinggong");
        map_skill("strike", "xingxiu-duzhang");
        map_skill("hand", "zhaixing-shou");
        map_skill("parry", "xingxiu-duzhang");
        map_skill("staff", "tianshan-zhang");
        prepare_skill("strike", "xingxiu-duzhang");
        set("per",100);
		set("attitude", "friendly");
        
		set("chat_chance", 10);
        setup();
        get_myname();
		set("inquiry", ([
            "name" : "我就是亘古宇宙，盖世无双，天下无敌，豪情万丈，英俊潇洒，聪明睿智的"+my_name()+"了。",
            "山林" : "山林白天有毒雾，进入要谨慎。",
            "天秀宫" : "天秀宫是我星宿派的中枢，一定要誓死保卫。",
			//"Jason" : "Jason说去看看丐帮了，还没回来。",
            "here" : "这里是星宿海的后山。",
            "石壁" : "石壁中记载了高深的杖法，怎么领悟就看你自己了。",
			"job" : (: ask_job :),
            "任务" : (: ask_job :),
            "辨毒" : (: ask_judge :),
            "biandu" : (: ask_judge :),
			"martial" : (: ask_skill :),
            "武学" : (: ask_skill :),
            "bye" : (: ask_leave :),
            "辞行" : (: ask_leave :),
            "木杖" : (: ask_desc1 :),
            "冰杖" : (: ask_desc2 :),
            "冰魄杖" : (: ask_desc3 :),
            "毒液" : (: ask_desc4 :),
            "打造暗器" : (: ask_desc5 :),
            "极乐刺" : (: ask_item1 :),
            "无形粉" : (: ask_item2 :),
            "穿心钉" : (: ask_item4 :),
            "烁心弹" : (: ask_item5 :),
            "大悲丸" : (: ask_item3 :),
            "怎么回事" : (: ask_whatsup :),
			"whatsup" : (: ask_whatsup :),
            "dian" : (: ask_dian :),
            "点香" : (: ask_dian :),
			
            
       	]) );
		carry_object("/d/city/npc/items/dudou")->wear();

}

int ask_dian()
{
	object xiang,me=this_player();
	object ob=this_object();
	if (ob->is_busy())
	{
		tell_object(this_player(),ob->name()+"正忙着呢。\n");
		return 1;
	}
	if (me->query("family/family_name")!="星宿派")
	{
		message_vision("$N淡淡道，阁下与我星宿派素无渊源，不知这是何意？\n",ob);
		return 1;
	}
	if (!present("xiang",me))
	{
		message_vision("$N淡淡道，你究竟想做什么？\n",ob);
		return 1;
	}
	xiang=present("xiang",me);
	if (!xiang->query("is_xiang"))
	{
		message_vision("$N淡淡道，你从哪找来这个破玩意？\n",ob);
		return 1;
	}
	if (xiang->query("is_on")||xiang->query("dian"))
	{
		message_vision("$N道，镇魂香已经被点燃了，融合毒素时有宁神的功效。\n",ob);
		return 1;
	}
	message_vision("$N道，这是本门的镇魂香，原料不够，失传很久了，你从哪找到的？我来帮你点燃吧。\n",ob);
	xiang->dian(ob);
	return 1;
}

void init()
{
	add_action("do_kill", ({ "kill", "hit"}));
}
void die()
{
	message_vision("$N叹了口气。\n",this_object());
	this_object()->fullme();
	return;
}
void unconcious()
{
	die();
}

int ask_whatsup()
{
	object me=this_player();
	object ob=this_object();
	int n=random(100);
	if (ob->is_busy() || ob->is_fighting())	return notify_fail(this_object()->name()+"正忙着呐，等一会再问！\n");
	if (me->query("emnewbiejob_miejue_task")!=1||me->query("family/family_name")!="峨嵋派")
	{
		command("say 怎么回事？我还想问你呢。");
	}
	else
	{
		message_vision("$N道：灭绝老尼也太有趣了，派你来送死吗？但我偏不杀你，做完一次苦力就送你回去。\n",ob);
		Jobs(me,1+random(3));
	}
	return 1;
}

void AssignJudgeTask(object me,string Name,string Mark)
{
	tell_object(me,this_object()->name()+"道，我派弟子毒技是为基础，你去山林给我挖根"+Name+"来吧。\n");
	me->set_temp("judge",Mark);
	return;
}
int ask_judge()
{
	int i=random(1600);
	object me=this_player(),ob=this_object();
	string *Names=({"白色三叶草","紫色三叶草","红色三叶草","蓝色三叶草","白色单叶草","粉色单叶草","红色单叶草","蓝色单叶草"}),
	*Marks=({"bssyc","zssyc","hssyc","lssyc","baise","fense","hongse","lanse"});
	if (ob->is_busy() || ob->is_fighting())
	return notify_fail(ob->name()+"正忙着呐，等一会再问！\n");
	if (me->query("family/family_name")!="星宿派")
	{
		tell_object(me,ob->name()+"淡淡的看着你，阁下不是我星宿派弟子，请回吧。\n");
		return 1;
	}
	if (time()-(me->query("xxnewbiejob/wa"))<150+random(30))
	{
		command("say 你刚刚辨识过毒草，过会再来吧。");
		return 1;
	}
	if (me->query_skill("poison",1)>105)
	{
		tell_object(me,ob->name()+"道，你的毒技已经达到了一定程度，已不能通过辨识毒草来提高。\n");
		return 1;
	}
	ob->add_busy(1);
	me->set("xxnewbiejob/wa",time());
	me->set_temp("xxnewbiejob/bianshi",1);
	if (i>1400)
	AssignJudgeTask(me,Names[1],Marks[1]);
	else if (i>1200)
	AssignJudgeTask(me,Names[2],Marks[2]);
	else if (i>1000)
	AssignJudgeTask(me,Names[3],Marks[3]);
	else if (i>800)
	AssignJudgeTask(me,Names[4],Marks[4]);
	else if (i>600)
	AssignJudgeTask(me,Names[5],Marks[5]);
	else if (i>400)
	AssignJudgeTask(me,Names[6],Marks[6]);
	else if (i>200)
	AssignJudgeTask(me,Names[7],Marks[7]);
	else
	AssignJudgeTask(me,Names[0],Marks[0]);	
    return 1;
}
int IfRefuseGive(object me,string WeaponName,string WName,int PeriodRequire,int ScoreRequire,int PoisonRequire,string file)
{
	object ob;
	int pflv;
	if (me->query("family/family_name")!="星宿派")
    {
        message_vision("$N淡淡道，阁下与我星宿派素无渊源，不知这是何意？\n",this_object());
        return 1;
    }
    if (time()-this_object()->query("xxanqi/ask"+WName+"time")<600)
    {
        command("say "+WeaponName+"乃镇派之宝，我这里现在也没有了。");
        return 1;
    }
    if (me->query("score")<ScoreRequire)
    {
        command("say "+WeaponName+"乃是我派镇派之宝，你还是去多为我星宿派做点贡献再来吧。\n");
        return 1;
    }
    if (me->query_skill("poison",1)<=PoisonRequire)
    {
        command("say "+WeaponName+"需要高深的毒技才能发挥功效，你是不是该先去提高一下毒技？\n");
        return 1;
    }
	pflv = (int)me->query("purefamily/level");
	if (pflv>0 && me->query("purefamily/family_name") != "星宿派") 
		pflv=0;
	ob=new(file);
	if (ob)
	{
		if (pflv>0)
			ob->set_amount((pflv>=4)?((pflv+1)*(pflv+1)):(pflv*5));
		ob->set("owner",me->query("id"));
		command("say 好吧，我就把"+WeaponName+"交给你了，切记不可滥用。\n");
		ob->move(me);
		this_object()->set("xxanqi/ask"+WName+"time",time());
		message_vision("$N递给$n一"+((pflv>0)?"小袋":"枚")+""+WeaponName+"。\n"NOR,this_object(),me);
	}
	return 1;
}
int ask_item1()
{
	return IfRefuseGive(this_player(),"极乐刺","jlc",2400,8000,500,"/d/xingxiu/npc/obj/jileci");
}

int ask_item4()
{
	return IfRefuseGive(this_player(),"穿心钉","cxd",1200,4000,400,"/d/xingxiu/npc/obj/chuanxinding");
}

int ask_item5()
{
	return IfRefuseGive(this_player(),"烁心弹","sxd",300,1000,150,"/d/xingxiu/npc/obj/shuoxindan");
}

int ask_item2()
{
	return IfRefuseGive(this_player(),"无形粉","item",0,3000,400,"/d/xingxiu/npc/obj/wuxingfen");
}
int ask_item3()
{
	return IfRefuseGive(this_player(),"大悲丸","item",0,1000,0,"/d/xingxiu/obj/wuxingfen");
}

int ask_desc1()
{
    command("tell "+this_player()->query("id")+" 木杖最简单了，把山林的木头劈下来，推回密室削成木杖的样子就可以了。\n");
    return 1;
}

int ask_desc2()
{
    command("tell "+this_player()->query("id")+" 冰杖也不难，把木杖放到小湖里泡一会就成功了。\n");
    return 1;
}

int ask_desc3()
{
    command("tell "+this_player()->query("id")+" 冰魄杖需要把冰杖淬毒以后制成。\n");
    return 1;
}

int ask_desc4()
{
    command("tell "+this_player()->query("id")+" 毒液嘛？山林里石头下很多毒虫，把石头掀起来一般能找到。\n");
    return 1;
}

int ask_desc5()
{
	if (this_player()->query("score") < 500)
	command("tell "+this_player()->query("id")+" 我还不信任你，以后再说吧。\n");
	else
	command("tell "+this_player()->query("id")+" 洛阳打铁铺是我派一处暗桩，打造暗器你除了需要欧冶子的铁锤和原料，还需要一点锻造术的知识。\n");
	return 1;
}

int dest(object items)
{
	if (items)
	destruct(items);
	return 1;
}

/*int askforhelp()
{
    if (random(100)>95&&time()-(int)this_object()->query("time")>600)
    {
        this_object()->set("time",time());
        command("chat 星宿派广收门徒，愿天下邪士来共襄盛举。\n");
    }
        
}*/

int ask_leave()
{
    object me=this_player();
    object ob=this_object();
    object jinhe;
    if (me->query("xxnewbiequest3"))
    {
        command("say 你既已辞行，就去江湖中闯荡一番吧，不要坠了我星宿派名头。\n");
        return 1;
    }
    if (me->query("family/family_name")=="星宿派" && me->query("xxnewbiequest") && me->query("xxnewbiequest2") && me->query("combat_exp")>100000 && me->query("combat_exp")<105000)
    {
        command("say 这么久的磨练，"+me->query("name")+"你也该去江湖中闯一闯了。\n");
        command("say 临走之际，我再赠你一个锦盒。\n");
        message_vision("$N从怀里拿出一个锦盒。\n",ob);
         message_vision("$N给你一个锦盒。\n",ob);
        jinhe=new("/d/xingxiu/obj/jinhe");
        jinhe->set("owner",me->query("id"));
		jinhe->set("givenBy",ob->query("name"));
        jinhe->move(me);
        me->set("xxnewbiequest3",1);
        CHANNEL_D->do_channel(this_object(), "jh", "我星宿派弟子"+me->query("name")+"今日学成下山，望江湖同道多多照应。");
        return 1;
    }
    else
	{
		message_vision("$N冷冷地看着你，一言不发。\n",ob);
        return 1;
	}
}

int accept_object(object me, object items)
{
	int exp,pot,rep,neili,jingli;
	object ob=this_object();
	if (ob->is_busy() || ob->is_fighting())	
	{
		write(ob->name()+"正忙着呐！\n");
		return 0;
	}
	if (items->query("owner") != me->query("id"))
	{
		write(HIG+ob->name()+"看了看你，又摇了摇头。\n"NOR);
        return 1;
	}
	if (me->query_skill("poison",1)<106 && me->query_temp("xxnewbiejob/bianshi") && items->query("id") == "du cao" && 
		me->query("family/family_name")=="星宿派" && items->query("judge")==me->query_temp("judge"))
	{
		me->set_skill("poison", me->query_skill("poison", 1)+1);
		write(HIG+ob->name()+"指点了你一些基本毒技的心得。\n"NOR);
		return 1;
	}
	if ((me->query_temp("xxnewbiejob/lv1") && items->query("id") == "mu zhang")
		||(me->query_temp("xxnewbiejob/lv2") &&items->query("id") == "bing zhang")
		||(me->query_temp("xxnewbiejob/lv3") && items->query("id") == "bingpo zhang"))//完成
	{
		if (me->query("emnewbiejob_miejue_task")==1&&me->query("family/family_name")=="峨嵋派")
		{
			write(HIG+ob->name()+"点了点头，轻轻抚了一下你的昏穴。\n"NOR);
			tell_object(me,HIW"半睡半醒间，你像腾云驾雾一般被人扛着，不知去向何处。\n"NOR);
			me->unconcious();
			me->move("/d/emei/houshan/jxan");
			me->set("startroom", "/d/emei/houshan/jxan");
			me->set("emnewbiejob_miejue_task","xx");
			return 1;
		}
		if (me->query("family/family_name")!="星宿派")
		{
			message_vision(HIG"$N看了看你，又摇了摇头。\n"NOR,ob);
			return 1;
		}
		if (me->query_temp("xxnewbiejob/lv1"))
		bonus(me,1,"literate",80);
		if (me->query_temp("xxnewbiejob/lv2") )
		bonus(me,2,"staff",80);
		if (me->query_temp("xxnewbiejob/lv3") )
		bonus(me,3,"huagong-dafa",80);
		ob->start_busy(1);
		call_out("dest",1,items);
		return 1;
	}
	if (me->query_temp("xxnewbiejob/lv4") && items->query("id") == "du ye")
	{
		bonus(me,4,"poison",60);
		call_out("dest",1,items);
		ob->start_busy(1);
		return 1;
	}
	else
	{
		tell_object(me,ob->name()+"冷冷地看着你，一言不发。\n");
		return 1;
	}
}



void givetool(object me)
{
	object item;
	command("tell "+me->query("id")+" 这两样工具也许你会需要，一定要保管好。\n");
	item=new("/d/xingxiu/obj/axe");
	item->move(me);
	message_vision("$N给$n一把"+item->query("name")+"。\n",this_object(),me);
	item=new("/d/xingxiu/obj/questdao");
	item->move(me);
	message_vision("$N给$n一把"+item->query("name")+"。\n",this_object(),me);
	return;
}

int ask_skill()
{
    object me=this_player();
    if (me->query_temp("xxnewbiejob/quest2"))
    {
        if (me->query_skill("staff",1)>=85 && me->query_skill("tianshan-zhang",1)>=85 &&me->query_skill("dodge",1)>=85 &&me->query_skill("zhaixinggong",1)>=85)
        {
            command( "say 不错，看来你已领悟了我星宿派武功的真谛。");
            me->add("combat_exp",2500);
            me->delete_temp("xxnewbiejob");
            me->set("xxnewbiequest2",1);
            tell_object(me,"你认真体会"+this_object()->name()+"的话，觉得自己在武学道路上领悟了很多。\n");
            return 1;
        }
        else
        {
            command( "say 你武学上的障碍只有自己去突破，别人帮不了你。");
            return 1;
        }
    }
    else if (me->query_temp("xx_valley_quest_ask_zine_skill"))
    {
        me->delete_temp("xx_valley_quest_ask_zine_skill");
        command("ah");
        command("say 武学之道，殊途同归，本来就是一理通，百里通的。");
        if (me->query_skill("poison",1)<500)
        {
            message_vision("$N指点了$n一些用毒的技巧。\n",this_object(),me);
            me->improve_skill("poison",1+(int)(me->query_skill("poison",1)*me->query("int")/10));
        }
        else
        {
            message_vision("$N指点了$n一些化功大法的心得。\n",this_object(),me);
            me->improve_skill("huagong-dafa",1+(int)(me->query_skill("huagong-dafa",1)*me->query("int")/10));
        }
        return 1;
    }
    else
    {
        command( "say 武学之道，欲速则不达。");
        return 1;
    }
}

int Jobs(object me,int flag)
{
	string *units=({"根","根","根","滴"}),*names=({"木杖","冰杖","冰魄杖","毒液"}),*ObMark=({"bpz","bpz","bpz","non_bpz"}),*lv=({"lv1","lv2","lv3","lv4"});
	command("pat " + me->query("id"));
	command("say 你去帮我弄"+units[flag-1]+names[flag-1]+"过来吧。");
	givetool(me);
	me->set_temp("xxnewbiejob/"+ObMark[flag-1],1);
	me->set_temp("xxnewbiejob/"+lv[flag-1],1);
	me->set("xxnewbiejob/lasttime",time());
	this_object()->start_busy(1);
	return 1;
}

void AssginJob(object me,int S4,int S3,int S2,int S1)
{
	int i=random(100);
	if (i>95)
	Jobs(me,S4);
	else if (i>93)
	Jobs(me,S3);
	else if (i>90)
	Jobs(me,S2);
	else
	Jobs(me,S1);
	return;
}

int ask_job()
{
	object me=this_player();
	object ob=this_object();
	if (ob->is_busy() || ob->is_fighting())
	return notify_fail(ob->name()+"正忙着呐，等一会再问！\n");
	if (me->query("family/family_name")!="星宿派")
	{
		tell_object(me,ob->name()+"淡淡的看着你，阁下不是我星宿派弟子，请回吧。\n");
		return 1;
	}
	if (time()-(me->query("xxnewbiejob/lasttime"))<150+random(30))
	{
		command("say 你刚刚辛苦过，过会再来吧。");
		return 1;
	}
	if (me->query("combat_exp")>=120000)
	{
		command( "say 星宿新手任务是帮助新手成长的，阁下的这么老的新手我倒是没见过。");
		return 1;
	}
	if (me->query("food")<50 || me->query("water")<50)
	{
		command( "say 皇帝还不差饿兵呢，山林了可以摘到果子，延至馆也有井水可以喝。");
		return 1;
	}
	if (me->query("combat_exp")>30000 && me->query("combat_exp")<32000 && !me->query("xxnewbiequest"))
	{
		command( "say 南边小湖里有一条鳄鱼，你去把它杀了吧，在湖边可以潜(qian)下去。");
		command( "say 鳄鱼不是那么好对付的，你要掂量一下自己的武功。");
		me->set_temp("xxnewbiejob/quest1",1);
		ob->start_busy(1);
		return 1;
	}
	if (me->query("combat_exp")>66000 && me->query("combat_exp")<68000 && !me->query("xxnewbiequest2"))
	{
		command( "say 武学之道，欲速则不达，你最近是不是有点贪多嚼不烂啊？");
		command( "say 你去把天山杖法，摘星功，以及杖法和轻功都练到八十五级以上再来要找我探讨一下『武学』吧。");
		me->set_temp("xxnewbiejob/quest2",1);
		ob->start_busy(1);
		return 1;
	}
	if (me->query("combat_exp")<30000)
	AssginJob(me,4,3,2,1);
	else if (me->query("combat_exp")<60000)
	AssginJob(me,1,4,3,2);
	else if (me->query("combat_exp")<90000)
	AssginJob(me,1,2,4,3,);
	else
	AssginJob(me,3,4,4,4);
	return 1;
}

int do_kill(string arg)
{
	if(arg=="zine"||arg =="zine npc")
	{
		if (userp(this_player()))
		command("say 勇气可嘉啊，可遗憾的是，我是不死之身！\n"NOR);
		return 1;
	}
}

