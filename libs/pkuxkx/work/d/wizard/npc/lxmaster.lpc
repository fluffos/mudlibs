//lxmaster.c 蜡像馆蜡像王
//all@pkuxkx, 2012/11/13
#include <ansi.h>
inherit NPC;

int ask_laxiang();
int ask_tiaozhan();

void create()
{  
        set_name("蜡像王", ({ "laxiang master","master"}) ); 
        set("gender","男性");   
        set("title",HIY"北侠蜡像馆"NOR);
	set("long", "这是一个饱经风霜的老人，据说制作蜡像的技术独一无二。\n");
        set("age",65);
        set("per",40); 
        set("str",40); 
        set("int",40); 
        set("dex",40); 
        set("con",40); 
        set("kar",40);
        set("attitude", "friendly");
        set("combat_exp", 2000000000);
        set("apply/attack",  300000); 
        set("apply/defense", 30000);
        set("inquiry", ([
		"laxiang" : (: ask_laxiang :),
		"蜡像" : (: ask_laxiang :),
		"挑战" : (: ask_tiaozhan :),
        ]) );

        set("shen_type",1);
        set("score",500000);
        setup();
        carry_object("/d/huashan/obj/greenrobe")->wear();
}

int ask_laxiang()
{
	object me=this_player();
	if(me->query("laxiang/done")==1)
	{
		tell_object(me,"不要跟我开玩笑，您不都已经制作过蜡像了么。\n");
		return 1;
	}
	if(!me->query("laxiang/tiaozhan"))
	{
		tell_object(me,"您需要先经过挑战才能制作蜡像！\n");
		tell_object(me,"挑战需要交一定的挑战费！\n");		
		return 1;		
	}
	if(me->query_temp("laxiang/make")==1)
		tell_object(me,"你不都已经问过了吗，想制作蜡像请用make_lx id命令。\n");   
	else 
	{
		me->set_temp("laxiang/make",1);
		tell_object(me,"想制作蜡像是吧，你的经验、声望、门忠都必须达到一定水准才行。\n");
		tell_object(me,"制作蜡像需要消耗很多金钱，不知你的存款够不够。\n");
		tell_object(me,"确定要制作蜡像的话，请用make_lx id命令。\n");   
	}
	return 1;
}

int ask_tiaozhan()
{
	object me=this_player();
	object* inv=deep_inventory(me);
	object ob=this_object();
	if(me->query("laxiang/done")==1)
	{
		tell_object(me,"您不都已经制作过蜡像了么！\n");
		return 1;
	}
	if(me->query("laxiang/tiaozhan"))
	{
		tell_object(me,"您已经挑战成功了，赶快制作蜡像吧！\n");
		return 1;
	}
	if(me->query("combat_exp")< 200000000)
	{
		tell_object(me,"你的经验太低了，挑战不是去送死么。\n");
		return 1;
	}
	if(me->query("repute")< 5000000)
	{
		tell_object(me,"你的声望太低了，不能进行挑战。\n");
		return 1;
	}
	if (me->query("combat_exp")-me->query("laxiang/tiaozhan_exp")<=5000000)
	{
		tell_object(me,"你最近没啥长进，挑战也是白搭。\n");
		return 1;
	}
	if (me->query("balance")< 10000000)
	{
		tell_object(me,"挑战需要一定的费用，你的存款不够。\n");
		return 1;
	}
	for (int i=0;i<sizeof(inv);i++ )
	{
                if (inv[i]->is_character())
		{
			write("只能独自挑战，你还背了别人，似乎不大妥当吧！\n");
			return 1;
		}
	}	
	if (query("on_tiaozhan")>0 && time()-query("tiaozhan_time")<=5400)
	{
		tell_object(me,"对不起，有人正在挑战，你等一段时间吧。\n");
		return 1;
	}
	tell_object(me,"城外最近来了一伙身份不明之人，恐对百姓不利，你去把他们解决掉。\n");
	tell_object(me,"这些人心狠手辣，一定要多加小心。\n");
	tell_object(me,"这间屋里有个密道通往城外，我送你进去，你速去速回。\n");
	message("vision","馆长在墙上一拍，然后推了你一下，你发现已经来到了一个密道！ \n",me);
	me->set_temp("laxiang/tiaozhan",1);
	set("on_tiaozhan",1);
	set("tiaozhan_time",time());
	set("tianzhan_id",me->query("id")); 
	remove_call_out("timeup");
	call_out("timeup",900,ob);//900秒的完成时间限制
	me->set("laxiang/tiaozhan_exp", me->query("combat_exp"));          
	me->add("balance",-10000000);  	
	me->move("/d/wizard/lxmidao");  
	return 1;
}

int timeup(object ob)
{	
	object tzid;
	if (ob->query("tianzhan_id"))
	tzid=find_player(ob->query("tianzhan_id"));
	if (!tzid||!objectp(tzid))
	return 1;
	if (base_name(environment(tzid))=="/d/wizard/lxmidao"||base_name(environment(tzid))=="/d/wizard/lxmidao2")
	{
		tell_object(tzid,HIR"你挑战时间太久了，蜡像王有些担心，派人把你找了回来！\n"NOR);
		tzid->move("/d/wizard/nlaxiang");
		return 1;
	}
	return 1;
}
