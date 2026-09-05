// huyidao.c
// by whuan@pkuxkx
#define MAX_WAIT_TIME 600
#include <ansi.h>
#include <title.h>
inherit NPC;
int ask_job();
int ask_cancel();
int ask_times();
int ask_pfm();
int ask_help();
int ask_title();
int give_reward(object me);
string *quest_fail_msg = ({
    CYN"看了看你，然后又失望地摇了摇头，什么也不说。\n"NOR,
    CYN"看起来很是生气，但似乎又发作不出来，只是轻轻哼了一声。\n"NOR,
    CYN"惊奇地问：”什么，连这个都没做好？？！！！”\n"NOR,
    CYN"沮丧地望着你，并不说话，但明显很失望。\n"NOR,
    CYN"叹了口气：“本来对你期望甚高，怎知你却如此辜负于我的苦心...”\n"NOR,
    CYN"摇了摇头：“我本不应该让你去的......”\n"NOR,
    CYN"冷哼一声：“怎的你竟是如此不中用？！！”\n"NOR,
    CYN"拍拍你的肩膀：“不要灰心，我知道你尽力了...”\n"NOR,
    CYN"对着你摇了摇头，说：“连这点事都做不好.....下去吧。”\n"NOR,
    CYN"看上去很不高兴，皱了皱眉头对你说：“下去歇着吧。”，嘴\nNOR"
    CYN"里嘟囔着：“真是没用。。。。”\n"NOR,
    CYN"疑惑地看着你：“怎么回事？怎么你。。。”\n"NOR,
    CYN"失望地看看你，慢慢地转过头去，跟别人说话去了。\n"NOR,
    CYN"嚷道：真是个饭桶！\n"NOR,
    CYN"一晃脑袋，叹息道：也罢，也罢，我本不该让你做这件事的。\n"NOR,
});

#include "hu-quest.h"
#include "/d/yingtiansouth/dufu/npc/Pro.h"
//"深红":HIR,"暗红":RED,"深绿":HIG,"暗绿":GRN,"深黄":HIY,"暗黄":YEL,"深蓝":HIB,"暗蓝":BLU,"深紫":MAG,"暗紫":HIM,"天青":HIC,"靛青":CYN,"深白":HIW,"暗白":WHT
void create()
{
	set("Pro_Colors",({"深黄","暗黄","深绿","暗绿"}));
	set("Pro_id","HYD");
	set_name("胡一刀", ({"hu yidao", "yidao", "hu"}));
	set("gender", "男性");
	set("title", HIR"辽东"HIY"大侠"NOR);
	set("age", 35);
	set("long","这人生得当真凶恶，一张黑漆脸皮，满腮浓髯，头发却又不结辫子，蓬蓬松松的堆在头上。\n他生平只要遇到做坏事的，立时一刀杀了，所以名字叫作胡一刀。\n");
        set("attitude", "friendly");
  set("no_get", "1");
	set("str", 45);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
	set("per", 17);
	set("qi", 3000);
	set("max_qi", 300000);
	set("jing", 100000);
	set("max_jing", 100000);
	set("neili", 300000);
	set("max_neili", 300000);
	set("jiali", 10000);
	set("combat_exp", 2900000000);
	set("score", 2000000);
	 
	set_skill("force", 3500);             // 基本内功
	set_skill("hujia-daofa", 3550);       // 胡家刀法	
	set_skill("blade", 3520);             // 基本刀法
	set_skill("hunyuan-yiqi", 3520);      // 混元一气功
	set_skill("dodge", 3520);             // 基本躲闪
	set_skill("shaolin-shenfa", 3520);    // 胡家身法
	set_skill("parry", 3520);             // 基本招架
		
	map_skill("force", "hunyuan-yiqi");
	map_skill("blade", "hujia-daofa");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("parry", "hujia-daofa");
	set("inquiry",([
		"job":     (: ask_job :),
		"盗宝人":  (: ask_job :),
		"取消":    (: ask_cancel :),
		"cancel":  (: ask_cancel :),
    "帮助":    (: ask_help :),
		"help":  (: ask_help :),
		"次数":    (: ask_times :),
		"times":   (: ask_times :),
		"绝招" :   (: ask_pfm :),
		"头衔" :  (: ask_title :)
	   ]));
	set("shen_type",1);
	set("no_get", 1);
	set("uni_target",1);
	set("score",50000);
	set("job_id","胡一刀");
	set("job_eid","huyidao");

	setup();
  carry_object("/d/city/npc/obj/gangdao")->wield();
  carry_object("/d/city/obj/cloth")->wear();
}

void init()
{
	//add_action("do_answer","answer");
}

int ask_times()
{
	command("say 到目前为止，你共完成了"+this_player()->query("yidao/times")+"次任务！");
	return 1;
}

int destbaotu(object ob,object who)
{
    object newmap=new(__DIR__"obj/newmap");
    if (ob)
    {destruct(ob);}
    if (who)
    {
        command("say 这么点小麻烦你都克服不了？好吧好吧，我再帮你仔细注释一下。");
        tell_object(who,"胡一刀把注释好的藏宝图递给了你。\n");
        newmap->set("owner",who->query("id"));
        newmap->move(who);
        who->set("secondmap",1);
    }
    return 1;
}

int accept_object(object who, object ob)
{
    object newmap;
    object hu=this_object();
	//修正一次性给无数藏宝图的bug，piece是允许的
	if(!who->query("yidao/on_job") && ob->query("id")=="cangbao tu") 
		{
		command("say 我并没有给你任务啊，你无缘无故给我东西干什么？");
		return 1;
	  }
	
	if(who->query("yidao/done") != 5 && ob->query("id")=="cangbao tu") 
		{
		command("say 你这张图是什么时候的呀，还敢来骗我？");
		return 1;
	  }
	  
	if(ob->query("id")=="cangbao tu" && ob->query("owner")==who->query("id"))
		{
			who->set_temp("yidao/lvl",8);
			give_reward(who);
                        call_out("do_dest", 1, ob);
			return 1;
		}
	if(ob->query("id")=="map piece1" && ob->query("owner")==who->query("id"))
		{
			who->set_temp("yidao/lvl",1);
			give_reward(who);
                        call_out("do_dest", 1, ob);
			return 1;
		}
	if(ob->query("id")=="map piece2" && ob->query("owner")==who->query("id"))
		{
			who->set_temp("yidao/lvl",1);
			give_reward(who);
                        call_out("do_dest", 1, ob);
			return 1;
		}
	if(ob->query("id")=="map piece3" && ob->query("owner")==who->query("id"))
		{
			who->set_temp("yidao/lvl",1);
			give_reward(who);
                        call_out("do_dest", 1, ob);
			return 1;
		}
	if(ob->query("id")=="map piece4" && ob->query("owner")==who->query("id"))
		{
			who->set_temp("yidao/lvl",1);
			give_reward(who);
                        call_out("do_dest", 1, ob);
			return 1;
		}
	if(ob->query("id")=="map piece5" && ob->query("owner")==who->query("id"))
		{
			who->set_temp("yidao/lvl",1);
			give_reward(who);
                        call_out("do_dest", 1, ob);
			return 1;
		}
    if (hu->is_busy())
		{
			return notify_fail("胡一刀正忙着注释地图呢！\n");
    }
    
    if( ob->query("letterback")==1&&ob->query("owner")==who->query("id"))
    {
        call_out("do_dest", 1, ob);
        hu->add_busy(1);
        message_vision("$N接过$n手里的家信，感动的热泪盈眶：这是老婆写给我的信，我，我不会亏待你的！",hu,who);
	    who->set_temp("extrajob/hyd",1);
        return 1;
    }
    if (ob->query("id")=="bao tu" && ob->query("owner")==who->query("id"))
    {
        if (!ob->query_temp("mapread"))
        {
            call_out("destbaotu",1,ob);
            hu->add_busy(1);
            command("say 看都没看就还给我？好吧，既然你用不上我自己留着。");
            return 1;
        }
        if (who->query("secondmap"))
        {
            call_out("destbaotu",1,ob);
            hu->add_busy(1);
            command("say 你上次就偷懒，这次还来这套？");
            return 1;
        }
        call_out("destbaotu",1,ob,who);
        hu->add_busy(1);
        who->add_busy(1);
        return 1;
    }
		return 1;					
}

int do_answer(string arg)
{
	object me = this_player();
	if(!arg || sizeof(arg) == 0 || (arg != "in" && arg != "out")) return 0;
		
	if(!me->query_temp("hyd/maze_map"))
	{
		tell_object(me,"胡一刀疑惑的问道，此事与你何干？\n");
	}
	else
	{
		if(time() - me->query_temp("hyd/maze_map_time") > 60)
		{
			tell_object(me,"你是自己看出来的吗？问过多少人了？胡一刀难以察觉的哼了一声。\n");
			me->delete_temp("hyd");			
		}
		else if((me->query_temp("hyd/maze_map") == "True" && arg == "in") || (me->query_temp("hyd/maze_map") == "False" && arg == "out"))
		{
			tell_object(me,"胡一刀微微笑了笑: 看来你的眼力还是正常的，以后继续努力吧！\n");
			tell_object(me,"你鉴别地图真伪的能力提升了！\n");
			me->add("yidao/check_map_ability",1);//maybe someday, use this to open HYD II task
			me->add("yidao/last_asked",-610);
		}
		else
		{			
			tell_object(me,"胡一刀勃然大怒：你是睁眼瞎吗？这么简单的地图都看不明白？以后不要来了！\n");
		}
		me->delete_temp("hyd");
	}
	return 1;
}

int ask_pfm()
{
	if (this_player()->query_skill("hujia-daofa",1)<250)
		{
			tell_object(this_player(),HIY"胡一刀给你讲了讲【刀影连环】的诀窍，不过你听了半天也不明白他在说什么。\n"NOR);
			return 1;
		}
	this_player()->set("daoying",1);
	tell_object(this_player(),HIY"胡一刀给你讲了讲【刀影连环】的诀窍。\n"NOR);
	return 1;
}

int ask_title()
{
	string title;
	int times;
	times=this_player()->query("yidao/times");
	
	if ( times<500 )
	{
		command("say 你还没有完全掌握追缉盗宝人的诀窍。\n");
		return 1;
	}
	else if ( times <=1000 )
		title=YEL"十里"MAG"缉凶"NOR;
	else if ( times <=2000 )
		title=HIY"百里"HIM"荡魔"NOR;
	else if ( times <=3000 )
		title=CYN"千里"RED"追魂"NOR;
	else
		title=HIC"万里"HIR"绝命"NOR;
	
	this_player()->set_title(({TITLE_MJOB1, TITLE_MJOB2, TITLE_MJOB3}), title, ({"十里","百里","千里","万里","宝藏猎"}));
	command("say 你已经达到"+title+"的境界。\n");
	return 1;
}

void unconcious()
{
        die();
}

void die()
{
        this_object()->set("eff_qi",this_object()->query("max_qi"));
        this_object()->set("qi",this_object()->query("max_qi"));
        this_object()->set("eff_jing",this_object()->query("max_jing"));
        this_object()->set("jing",this_object()->query("max_jing"));
        return;
}

void do_dest(object ob)
{
        if(!objectp(ob))
                return;
        destruct(ob);
}