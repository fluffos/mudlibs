//五军大都督

#include <ansi.h>
inherit NPC;
#include <title.h>
#include "huilu2.h"
#include "/d/yingtianfu/neicheng/npc/daming_npc_officer.h"
#include "/d/yingtianfu/neicheng/npc/promote.h"
int ask_job();
int ask_task();
void create()
{
    set_name("御前侍卫统领", ({"shiwei tongling", "shiwei"}));
    set("title", HIW"大明"NOR);
    set("gender", "男性");
    set("age", 40);
    set("long", "他就是御前侍卫的统领。\n");
    set("attitude","heroism");
    set("generation",0);

    set("max_qi",800);
    set("eff_qi",800);
    set("qi",800);
    set("max_jing",300);
    set("jing",300);
    set("shen_type",1);
    set("no_clean_up",1);
    set("mingpin",2);
    set("combat_exp",2000000);
	set("inquiry", ([
	
     "巡视": (: ask_job :),
     "xunshi": (: ask_job :),
	 "刺客": (: ask_task :),
     "cike": (: ask_task :),
	]));
    setup();
    setup_player_name();
}

int ask_job()
{
	mixed tm=localtime(time());
	object me=this_player();
	string name=me->query("name");
	string day=sprintf("%d-%d-%d", tm[5], tm[4]+1,tm[3]);
	if (!me->query("mingpin")&&!me->query("ming/tj/pin"))
	{
		command("say 大胆贼人，竟敢戏弄本官！");
		command("kill "+me->query("id"));
		return 1;
	}
	if (!identification(me,"御前侍卫统领")&&!identification(me,"一等侍卫")&&!identification(me,"御前带刀侍卫")&&me->query("id")!="zine") 
	{
		command("say 这是侍卫处的职责所在，就不劳大人了。");
		return 1;
	}
	if (me->query("ming/shiweichu/job")!=day)
	{
		me->set("ming/shiweichu/job",day);
		me->set_temp("ming/shiweichu/job",1);
		command("say "+name[0..0]+"大人去巡视(xunshi)一下从大明门到奉天门这段之间，不知道手下那些小兔崽子们有没有懈怠！");
		tell_object(me,"可使用xunshi命令，随意巡视完大明门至奉天门，左中门，右中门之间十处即可。\n");
		return 1;
	}
	else
	{
		command("say 大人今天已经辛苦过一次了。");
		return 1;
	}
}

int ask_task()
{
	string *places=({"/d/yingtianfu/neicheng/beianmen",
		"/d/yingtianfu/neicheng/jiaotai",
		"/d/yingtianfu/neicheng/chunhe",
		"/d/yingtianfu/neicheng/rouyi",
		"/d/yingtianfu/neicheng/qianqing",
		"/d/yingtianfu/neicheng/yudao6",
		"/d/yingtianfu/neicheng/jianji",
		"/d/yingtianfu/neicheng/jinshen",
		"/d/yingtianfu/neicheng/yudao5",
		"/d/yingtianfu/neicheng/zhongji",
		"/d/yingtianfu/neicheng/huagai",
		"/d/yingtianfu/neicheng/fengtiandian",});
	mixed tm=localtime(time());
	object me=this_player(),place,killer;
	string name=me->query("name");
	string day=sprintf("%d-%d-%d", tm[5], tm[4]+1,tm[3]);
	if (!me->query("mingpin")&&!me->query("ming/tj/pin"))
	{
		command("say 大胆贼人，竟敢戏弄本官！");
		command("kill "+me->query("id"));
		return 1;
	}
	if (!identification(me,"御前侍卫统领")&&!identification(me,"一等侍卫")&&!identification(me,"御前带刀侍卫")&&me->query("id")!="zine") 
	{
		command("say 这是侍卫处的职责所在，就不劳大人了。");
		return 1;
	}
	if (!identification(me,"御前侍卫统领")&&me->query("id")!="zine") 
	{
		command("oh");
		tell_object(me,this_object()->name()+"似乎觉得你不够分量去做这件事！\n");
		return 1;
	}
	if (me->query("ming/shiweichu/task")!=day)
	{
		place=load_object(places[random(sizeof(place))]);
		if (!place)
		{
			command("wait");
			return 1;
		}
		killer=new(__DIR__"killer");
		killer->move(place);
		me->set("ming/shiweichu/task",day);
		me->set_temp("ming/shiweichu/task",1);
		command("say 听说有日月高手化装成太监潜入宫里，"+name[0..0]+"大人赶紧去查一下！");
		tell_object(me,"日月高手潜藏的范围大约是奉天殿到北安门之间的范围。\n");
		return 1;
	}
	else
	{
		command("say 大人今天已经辛苦过一次了。");
		return 1;
	}
}