// Npc: /kungfu/class/shaolin/dao-guo.c
// Date: YZC 96/01/19
//seagate@pkuxkx 2010/10/11 增加对新手任务的支持
//seagate@pkuxkx 2010/10/15 框架标准化修正，提高了新手任务的代码通用性，仅部分发布函数需要特殊
//开发，其他直接使用默认任务处理函数指针就可以了。

inherit NPC;

#include "/newbiequest/questdefault.h"                       //加载默认的任务处理函数
#include "/newbiequest/shaolin/quest_chanting.h"             //加载和诵经任务相关函数
//#include "/newbiequest/shaolin/quest_pichai.h"               //加载和劈柴任务相关函数
#include "/newbiequest/shaolin/quest_qiaozhong.h"            //加载和敲钟任务相关函数
#include "/newbiequest/shaolin/quest_fillwater.h"            //加载和挑水任务相关函数
#include "/newbiequest/shaolin/quest_release.h"              //加载和超度任务相关函数
//新手任务调用入口函数，这里面start表示接任务的函数指针，end表示任务结束的函数指针，
//fail表示任务失败的函数指针，weight表示任务权重，权重越高表示抽到该任务的几率越高，
//reward表示奖励系数，100是初始基数，表示遵循原始奖励。explimit为可选参数表示该任务
//对经验值有限定（方便如果有战斗任务，可以在过新手期后发布给玩家。）
//键值表示为唯一的任务id。
mapping newbie_list=
 (["chanting":
 	  (["start": (: start_chanting, "诵经任务", "chanting" :),
 	    "end"  : (: end_public_proc :),
 	    "fail" : (: fail_public_proc :),
 	    "weight" : 100,
 	    "reward" : 100]),
//劈柴任务的发布，失败和结束任务都使用默认的任务处理函数
 	 "pichai":
 	  (["start": (: start_public_proc, "给厨房劈些木柴。", "劈柴任务", "pichai" :),
 	    "end"  : (: end_public_proc :),
 	    "fail" : (: fail_public_proc :),
 	    "weight" : 100,
 	    "reward" : 110]),
 	 "qiaozhong":
 	  (["start": (: start_knockbell, "敲钟任务", "qiaozhong" :),
 	    "end"  : (: end_public_proc :),
 	    "fail" : (: fail_public_proc :),
 	    "weight" : 100,
 	    "reward" : 130]),
 	 "fillwater":
 	  (["start": (: start_fillwater, "挑水任务", "fillwater" :),
 	    "end"  : (: end_public_proc :),
 	    "fail" : (: fail_public_proc :),
 	    "weight" : 100,
 	    "reward" : 90]),
 	 "release":
 	 	(["start": (: start_release, "超度任务", "release" :),
 	    "end"  : (: end_public_proc :),
 	    "fail" : (: fail_public_proc :),
 	    "weight" : 80,
 	    "reward" : 160])]);

#include "/newbiequest/newbiequest.h";                       //新手任务公共头文件

string ask_me();

string newbie_quest();
string cancel_newbie();
string over_newbie();

void create()
{
	set_name("道果禅师", ({
		"daoguo chanshi",
		"daoguo",
		"chanshi",
	}));
	set("long",
		"他是一位身材高大的中年僧人，两臂粗壮，膀阔腰圆。他手持兵\n"
		"刃，身穿一袭灰布镶边袈裟，似乎有一身武艺。\n"
	);

	set("gender", "男性");
	set("attitude", "friendly");
	set("class", "bonze");

	set("age", 40);
	set("shen_type", 1);
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	set("max_qi", 400);
	set("max_jing", 300);
	set("neili", 450);
	set("max_neili", 450);
	set("jiali", 40);
	set("combat_exp", 100000);
	set("score", 100);

	set_skill("force", 70);
	set_skill("hunyuan-yiqi", 70);
	set_skill("dodge", 70);
	set_skill("shaolin-shenfa", 70);
	set_skill("strike", 70);
	set_skill("banruo-zhang", 70);
	set_skill("parry", 70);
	set_skill("sword", 70);
	set_skill("damo-jian", 70);
	set_skill("buddhism", 70);
	set_skill("literate", 70);

	map_skill("force", "hunyuan-yiqi");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("strike", "banruo-zhang");
	map_skill("sword", "damo-jian");
	map_skill("parry", "damo-jian");

	prepare_skill("strike", "banruo-zhang");

	create_family("少林派", 39, "弟子");

	set("inquiry", ([
		"木人"     : (: ask_me :),
		"修理"	   : (: ask_me :),
		"修木人"   : (: ask_me :),
		"新手任务" : (: newbie_quest :),
		"quest"    : (: newbie_quest :),
		"cancel"   : (: cancel_newbie :),
		"失败"     : (: cancel_newbie :),
		"成功"     : (: over_newbie :),
		"success"  : (: over_newbie :)
	]));

	setup();

        carry_object("/d/shaolin/obj/changjian")->wield();
        carry_object("/d/shaolin/obj/dao-cloth")->wear();
}

void init()
{	
	object me, ob;

	me = this_object();

	::init();
	if( objectp(ob = present("mu ren", environment())) )
	{
		remove_call_out("repairing_1");
		call_out("repairing_1", 5, me, ob);
	}
}

int repairing_1(object me, object ob)
{
	if ( !present(ob, environment()) ) return 1; 

	command("say 是这个木人吧？ 唔，我来瞧瞧！ 你在边上呆着，看能帮我什么忙。");
	
	remove_call_out("repairing_2");
	call_out("repairing_2", 2+random(3), me, ob);

	return 1;
}

int repairing_2(object me, object ob)
{
	if ( !present(ob, environment()) ) return 1; 

	if( ob->query("damaged") )
	{
		message_vision(GRN "\n道果禅师对着木人瞧了一会，又试着扳动木人的四肢和脑袋，嘴里喃喃念叨着什么。\n\n" NOR, me);
		remove_call_out("repairing_3");
		call_out("repairing_3", 2+random(2), me, ob);
	}
	else
	{
		command("say 这木人好端端地又没坏！ 还大老远地拖着我过来！");
		command("follow none");

		message_vision(GRN "\n道果禅师气鼓鼓地走了。\n" NOR, me);
		me->move("/d/shaolin/guangchang3");

		remove_call_out("do_back");
		call_out("do_back", random(15), me);
	}

	return 1;
}
	
int repairing_3(object me, object ob)
{
	command("say 唔，原来如此，我来修修看吧！");
	message_vision(GRN "\n他接着从怀里掏出一大堆工具来，打开木人的身体，摆弄了几下。\n\n" NOR, me);

	remove_call_out("repairing_4");
	call_out("repairing_4", 3+random(3), me, ob);

	return 1;
}

int repairing_4(object me, object ob)
{
	if( random(2) == 0 ) 
	{		
		command("say 好，修好了！");
		ob->delete("damaged");
		ob->set("fight_times", 0);	
		message_vision(GRN "\n木人的身体吱吱地扭动了几下，恢复了正常站立的姿态。\n\n" NOR, me);
	}
	else 
		message_vision(GRN "\n道果禅师叹了口气，说道：看来不行，这木人损坏得太厉害了，没法子修了！\n" NOR, me);

	command("say 好，那我走了！");
	command("wave");
	command("follow none");

	message_vision(GRN "\n道果禅师走了出去。\n" NOR, me);
	me->move("/d/shaolin/guangchang3");

	remove_call_out("do_back");
	call_out("do_back", random(15), me);

	return 1;
}

int do_back(object me)
{
	me->move("/d/shaolin/twdian");
	return 1;
}

string ask_me()
{
	mapping fam; 
	object ob;

	ob = this_player();
	
	if (!(fam = ob->query("family")) || fam["family_name"] != "少林派")
		return RANK_D->query_respect(ob) + 
		"与本派素无来往，不知此话从何谈起？";

	command("say 木人打坏了是吧？ 好吧，我跟你去看看。");
	command("follow " + ob->query("id"));

	return "我们走罢！\n";
}