// D:\xkx\d\liuxiu-shanzhuang\chemahang.c车马行
// labaz  2012/10/21.
// fix by yhzzyahoo,截住一些bug偷师的
#include <room.h>
#include <ansi.h>
inherit ROOM;
#include "newbie_village.h"

int qu(string);
int xia();
void arrive_yz(object);

void create()
{
    set("short", "马车");
    set("long", "这是一架普通的马车，去往(qu)扬州。你也可以下(xia)车。车窗的旁边有一行细细的字(zi)。\n");

    set("indoors","liuxiu-shanzhuang");


    set("item_desc", ([
        "zi" : "信马扬州由何处？十年北大侠客行。柳秀山庄由玩家若雨策划，腊八粥构建于2012年11月。\n",
    ]));

    setup();
}

void init()
{
	add_action("show_quest", "quest");
    add_action("do_qu", "qu");
    add_action("do_xia", "xia");
}

int do_xia()
{
    object who,sword;
	object money;
	object ly;
	mapping sk_all;
	string *sk;
    int i;
    who=this_player();
    
	if(who->is_busy())
	{
		write("车夫对你说道：很快就到，请稍安勿躁。\n");
		return 1;
	}
    if (!who->query_temp("newbie/arrive"))
    {
        who->move(__DIR__"chemahang");
        who->set_temp("newbie_village/confirmleave",0);
    }
    else
    {
        who->move("/d/city/guangchang");
        set_nextquest(who,"到南面的车马行坐马车去扬州","欢迎你来到北大侠客行的世界。这里是扬州。你可以四处走走，也可以跟玩家说说话。江湖迎来了一位新的英雄！", 0, 100);
        sword=present("taiyi jian",who);
        if (objectp(sword)) destruct(sword);
        who->set("newbie_village/done",1);
        who->delete_temp("newbie");
		write("你对着柳秀山庄的方向做了一个长揖，将游庄主所赠送的银两交给了车夫，并请他代向庄主致谢。\n");
			sk_all = (mapping)who->query_skills();
			if (mapp(sk_all))
			{
				sk = keys(sk_all);
				i = sizeof(sk);
				 while (i--) 
					 {
    				 who->delete_skill(sk[i]);
					 }
			}

			i=who->query("int")+who->query("dex")+who->query("con")+who->query("str");
			if (i>80)
			{
				who->set("int",20);
				who->set("con",20);
				who->set("dex",20);
				who->set("str",20);
		        tell_object(who,"想偷先天属性，一边平庸着去吧！\n");
			}
			if (who->query("hubo"))
			{
				who->delete("hubo");
		        tell_object(who,"想偷互博，白日做梦！\n");

			}
			if (who->query("zyhb"))
			{
				who->delete("zyhb");
		        tell_object(who,"想偷互博，白日做梦！\n");

			}
			if (who->query("suxin"))
			{
				who->delete("suxin");
		        tell_object(who,"想偷素心mark，门也没有！\n");
			}
		who->set("balance",0);
		if(objectp(money=present("gold",who))) destruct(money);
		if(objectp(money=present("silver",who))) destruct(money);
		if(objectp(money=present("coin",who))) destruct(money);
		if(objectp(money=present("cash",who))) destruct(money);
		write("车夫对你点点头，说道：庄主吩咐在下送你一件礼物。言罢把一个东西塞到你手里。原来是一张路引。(l lu yin)\n");
		ly = new("/clone/misc/guider");
		ly->move(who);
		who->set("startroom","/d/city/kedian");
		who->save();
		who->start_busy(0);

    }
    
    message_vision("$N走下了这辆马车。\n",who);
	

    return 1;
    
}

int do_qu(string arg)
{
    object who;
	mapping sk_all;
	string *sk;
    int i;
	int pt;
    who=this_player();

    if (!arg)
    {
        tell_object(who,"马车的目的地有 扬州\n请输入qu <地名>到达目的地，输入的地名可以是中文也可以是中文的汉语拼音。\n");
        return 1;
    }
	if(who->query_temp("newbie_village/confirmleave") == 2)
	{
		write("你已经上车了，马上就到扬州。\n");
		return 1;
	}
    if (arg=="yangzhou" || arg=="扬州")
    {
        if (!who->query("newbie_village/arrive"))
        {
    		if(!who->query_temp("newbie_village/confirmleave"))
    		{
    			write("你真的决定离开了吗？今日一别，再不能回。如果你下定了决心，请再输入一次:qu 扬州\n");
    			who->set_temp("newbie_village/confirmleave",1);
    			return 1;
    		}
    		write(GRN"你为报游庄主的知遇之恩，不给这片隐迹留下什么麻烦，你决定
将柳秀山庄的不传之心法留在这片杏花疏影里，不带入纷纷扰扰的江湖。
外面将是一个新的世界，你决心不再使用任何从柳秀山庄所学会的武功，也不
跟任何人提起你在柳秀山庄的经历。但你对未来的日子满怀信心，因为你知
道，自己的身体中蕴藏了巨大的潜能！\n"NOR);

    		who->prepare_skill("strike");
    		who->map_skill("dodge");
    		who->map_skill("force");
    		who->map_skill("sword");
    		who->map_skill("parry");
    		who->map_skill("strike");
    		
    		who->delete_skill("dodge");
    		who->delete_skill("force");
    		who->delete_skill("sword");
    		who->delete_skill("parry");
    		who->delete_skill("strike");
    		who->delete_skill("taiyi-jian");
    		who->delete_skill("taiyi-zhang");
    		who->delete_skill("taiyi-you");
    		who->delete_skill("taiyi-shengong");
    		who->reset_action();

			sk_all = (mapping)who->query_skills();
			if (mapp(sk_all))
			{
				sk = keys(sk_all);
				i = sizeof(sk);
				 while (i--) 
					 {
    				 who->delete_skill(sk[i]);
					 }
			}

			i=who->query("int")+who->query("dex")+who->query("con")+who->query("str");
			if (i>80)
			{
				who->set("int",20);
				who->set("con",20);
				who->set("dex",20);
				who->set("str",20);
		        tell_object(who,"想偷先天属性，一边平庸着去吧！\n");
			}
			if (who->query("hubo"))
			{
				who->delete("hubo");
		        tell_object(who,"想偷互博，白日做梦！\n");

			}
			if (who->query("zyhb"))
			{
				who->delete("zyhb");
		        tell_object(who,"想偷互博，白日做梦！\n");
			}

			if (who->query("suxin"))
			{
				who->delete("suxin");
		        tell_object(who,"想偷素心mark，门也没有！\n");
			}

    		
    		who->set("combat_exp",0);
			if (who->query("potential")>20000)
			{
				who->set("potential",20000);
			}
    		pt = 2000+random(100);
    		who->add("potential",pt);
            who->add("pot/lxsz", pt);
    		write(HIC"你的潜能增加了"+chinese_number(pt)+"点。\n"NOR);
            CHANNEL_D->do_channel(load_object(__DOMAIN_DIR__"npc/youkunyi"), "sys_misc", sprintf("%s离开柳秀山庄时获得潜能：%d。", who->name(), pt));
    		who->set_temp("newbie_village/confirmleave",2);
        }
        tell_object(who,"马车缓缓开动，向着扬州驶去。\n");
        who->start_busy(10);
        call_out("arrive_yz",10,who);
    }
    else
    {
        tell_object(who,"这里的车只去扬州。\n");
    }
    return 1;
}

void arrive_yz(object who)
{
    if (!objectp(who)) return;
    
    tell_object(who,"大车停稳了下来，你可以下车(xia)了。\n");
    who->set("newbie_village/arrive",1);
    who->set_temp("newbie/arrive",1);
}
 
