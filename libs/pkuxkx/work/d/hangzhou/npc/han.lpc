#include <ansi.h>

inherit NPC;
#include <cooldown.h>
int ask_blade();
int ask_job();
int ask_fail();
int ask_finish();
#include "/d/luoyang/npc/reward.h"
#include "/d/yingtiansouth/dufu/npc/Pro.h"
//"深红":HIR,"暗红":RED,"深绿":HIG,"暗绿":GRN,"深黄":HIY,"暗黄":YEL,"深蓝":HIB,"暗蓝":BLU,"深紫":MAG,"暗紫":HIM,"天青":HIC,"靛青":CYN,"深白":HIW,"暗白":WHT
void create()
{
	set("Pro_Colors",({"深白","暗白"}));
	set("Pro_id","HSZ");
	set_name("韩世忠", ({ "han shizhong", "han","shizhong" }));
	set("title", HIB"蕲王"NOR);
	set("long", "他的样貌英武不凡，却又让人感觉不乏亲近。\n");
	set("gender", "男性");
	set("age", 42);
	set("attitude", "friendly");
	set("shen_type", 1);
	set("per", 30);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
	set("NoBusyAsking",1);
	set("max_qi", 14000);
	set("max_jing", 15000);
	set("neili", 15000);
	set("max_neili", 15000);
	set("jiali", 100);
	set("combat_exp", 20000000);
	set("score", 500000);

	set_skill("literate", 200);
	set_skill("force", 400);
	set_skill("dodge", 400);
	set_skill("parry", 400);
	set_skill("strike", 400);
	set_skill("luoxuan-jiuying",400);
	set_skill("bingchuan-xinfa", 400);
	set_skill("taiyi-zhang", 400);

	map_skill("dodge", "luoxuan-jiuying");
	map_skill("force", "bingchuan-xinfa");
	prepare_skill("strike","taiyi-zhang");
	 set("inquiry", ([

                "blade" : (: ask_blade() :),
                "借刀" : (: ask_blade() :),
				"job" : (: ask_job :),
				"任务" : (: ask_job :),
				"fail" : (: ask_fail :),
				"放弃" : (: ask_fail :),
				"finish" : (: ask_finish :),
				"完成" : (: ask_finish :),

	]) );
	set("job_id","韩世忠");
	set("job_eid","hansz");
	set("fake_finish","奸细已经被剿灭了，那你下去吧，下次再来。");
	set("no_get","韩王爷你也敢偷？还想不想离开蕲王府了？\n");
 	setup();
	carry_object("/clone/cloth/male5-cloth")->wear();

}

//任务npc不死
void unconcious()
{
	die();
}

void die()
{
	set("eff_qi",this_object()->query("max_qi"));
	set("qi",this_object()->query("max_qi"));
	set("eff_jing",this_object()->query("max_jing"));
	set("jing",this_object()->query("max_jing"));
	return;
}

int ask_blade()
{
	object me=this_player(),ob,*blades;
	message_vision("$N向$n陪着笑脸，希望能借金背砍山刀一观。\n",me,this_object());
	blades=children(__DIR__"obj/jindao");
	for (int i=0;i<sizeof(blades);i++)
	{
		if (!clonep(blades[i]))
		{
			blades-=({blades[i]});
		}
	}
	if (sizeof(blades)>=1)
	{
		command("shake");
		command("say 我的金背砍山刀被一个家伙借走了，到现在还没有还给我。");
		return 1;
	}
	if (me->query("shen")<10000000)
	{
		command("say 不借！");
		return 1;
	}
	ob=new(__DIR__"obj/jindao");
	ob->move(this_object());
	message_vision("$N摩挲着$n，似乎在回忆着什么。\n",this_object(),ob);
	command("say 好吧，我就把金背砍山刀借给你吧。");
	command("give "+me->query("id")+" dao");
	return 1;
}

int ask_job()
{
	int flag=0;
	object me=this_player();
	object ob, where,*all_ob;
	string msg="",respect = RANK_D->query_respect(me);

	
	if (time()-me->query_temp("askjob")-me->query_temp("askjobtimes")<=0)
	{
		me->add_temp("askjobtimes",1);
		tell_object(me,"过"+(me->query_temp("askjob")-time()+me->query_temp("askjobtimes"))+"秒再来问吧。\n");
		return 1;
	}
	else
	{
		me->set_temp("askjob",time());
		me->delete_temp("askjobtimes");
	}
	if(me->is_fighting())
	{
		command("say 你先打完架吧。");
		return 1;
	}
	if(me->query_temp("hansz/job"))
	{
		//command("say 这位"+respect+"，不是已经给过你任务了么？");
		tell_object(me,"这位"+respect+"，不是已经给过你任务了么？\n");
		me->start_busy(2+random(2));
		return 1;
	}
	if(me->query("hansz/on_job"))
	{
		//command("say 这位"+respect+"，上次交给你的任务还没有完成么？");
		tell_object(me,"这位"+respect+"，上次交给你的任务还没有完成么？\n");
		me->start_busy(2+random(2));
		return 1;
	}
	if(!wizardp(me) && time() - query("last_give_time") < 10)
	{
		//command("say 刚刚已经有人前去了，多谢"+respect+"好意。");
		tell_object(me,"刚刚已经有人前去了，多谢"+respect+"好意。\n");
		me->start_busy(2+random(2));
		return 1;
	}
	if(IfInCoolDown(me,1))
	return 1;
	if(me->query_combatgrade() < 30)
	{
		command("say "+respect+"，此行凶险无比，你还是等武功有成再来吧。");
		return 1;
	}
	me->set("hansz/on_job", 1);
	me->set_temp("hansz/job","清除异族奸细");
	set("last_give_time", time());
	me->set_temp("task_stat/hansz/hansz_starttime",time());
	command("ok");
	while (!objectp(where) || 
          !where->isroom()||
          TASK_D->place_belong(where)=="不明区域"||
          base_name(where) == "/adm/daemons/taskd"||
		where->query("hsz_no_task"))
	{
		me->set_temp("map/keepsameregion",1);
		where = MAP_D->random_place_ex(me);
	}
	me->set_temp("hansz/task_place", where);
	me->set_temp("hansz/task_area",where->query("main_dir"));
	all_ob=deep_inventory(me);
	for (int i=0;i<sizeof(all_ob);i++)
	{
		if (all_ob[i]->is_bingfu())
		{
			ob=all_ob[i];
			flag=1;
			break;
		}
	}
	if (!flag)
	{
		ob=new(__DIR__"obj/bingfu");
		msg="带上我的兵符，";
		ob->move(this_object());
		start_busy(0);
		command("give "+me->query("id")+" bing fu");
	}
	ob->set("jianxi_in_area",MAP_D->place_belong(where));
	ob->set("jianxi_in_room",where->query("short"));
	//if (1)  还是加点图片地址吧
	if(random(4))
	command("say 我听说有一群异族奸细在"+TASK_D->place_belong(where)+"的"+where->query("short")+"附近出没，你"+msg+"去打探(datan)一下，必须要留下一两个奸细，给他们一个教训。");
	else
	{
		command("say 我听说有一群异族奸细在此地出没，你"+msg+"去打探(datan)一下，必须要留下一两个奸细，给他们一个教训。");
		ANTIROBOT_D->mxpantirobot_ex(me,TASK_D->place_belong(where)+"的"+where->query("short"));
		me->set_temp("hansz/pic_job",1);
	}
	me->set("hansz/last_job", time());
	return 1;
}
string gem_drop_msg(object me,object item)
{
	return query("name")+"拿出了一"+item->query("unit")+item->name()+"交给"+me->name()+"，作为任务的酬谢。\n";
}
int ask_finish()
{
	object me = this_player();
	mapping skills = me->query_skills();
	string* sname;
	string skill;
	if (me->query_temp(this_object()->query("job_eid")+"/fake_finish"))
	{
		command("say "+this_object()->query("fake_finish"));
		ask_fail();
		return 1;
	}
	if( !me->query_temp("hansz/finish") || 
		  me->query_temp("hansz/fail") || 
		  !me->query("hansz/on_job") )
	{
	//	command("heng");
	//	message_vision(CYN"$N"+CYN+"冷冷的盯着$n"+CYN+"道：「你以为如此弄虚作假能瞒得过我么？」\n"NOR, this_object(), me);
		tell_object(me,"韩世忠冷冷道：「你以为如此弄虚作假能瞒得过我么？」\n");
		me->start_busy(3+random(2));
		return 1;
	}
	if (me->query_temp("hansz/pic_job"))
	{
		me->delete("hansz/pic_fail");
		ANTIROBOT_D->same_as_fullme(me);
	}
	if (me->query_temp("hansz/finish_degree")<1.0)
	command("say 奸细很狡猾，虽然没除尽，不过也不错了。");
	command("say 很好。"+me->query("name")[0..0]+"兄弟，辛苦你了！");
	if (!me->query("biography/jobs/hansz"))
	{
		me->set("biography/jobs/hansz",time());//个人传记记录第一次完成任务时间ZINE
	}
	if (me->query_temp("hansz/finish_degree")>=0.5)
	GEM_D->drop(this_object(),me);	
	give_reward(me);
	
	return 1;
}