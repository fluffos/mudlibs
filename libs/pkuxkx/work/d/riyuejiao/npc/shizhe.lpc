//shizhe.c	紫衫使者
//by bing
inherit NPC;
#include "riyuenpc.h"
#include <ansi.h>
int ask_job();
int ask_fail();
void create()
{
        set_name(MAG "紫衫使者" NOR, ({ "zishan shizhe", "shizhe","zhe" }));
        set("long","他身穿紫袍，这在教中乃是地位显赫的标志。虽然他入教也不久，
但近年教中变化甚大，不可以常理度之。\n");
	set("gender", "男性");
        set("age", 45);
        set("shen_type", -1);
        set("str", 20);
        set("int", 23);
        set("con", 24);
        set("dex", 20);
        set("max_qi", 800);
        set("max_jing", 800);
        set("neili", 800);
        set("max_neili", 800);
        set("combat_exp", 150000);

        set("inquiry", ([
            "东方不败" : "东方教主的名字也是你叫得的？",
            "东方教主" : (: ask_df :),
	        "任我行" : (: ask_ren :),
            "帮助": (: ask_job :),
            "help": (: ask_job :),
			"放弃": (: ask_fail :),
			"fail": (: ask_fail :),
	      ]) );

        set_skill("force", 60);
        set_skill("riyue-shengong", 60);
        set_skill("dodge", 40);
        set_skill("parry", 40);
	set_skill("strike",40);
	set_skill("kaishan-zhang",40);
        set_skill("feitian-shenfa", 40);
        set_skill("literate",60);
        map_skill("force", "riyue-shengong");
        map_skill("parry", "kaishan-zhang");
        map_skill("dodge", "feitian-shenfa");
        map_skill("strike","kaishan-zhang");
	create_family("日月神教", 22, "弟子");
        setup();
        carry_object(__DIR__"obj/heiyi")->wear();
        call_out("adv",1);
}

int adv()
{
    int i;
    object *ob;
	if (!environment()||base_name(environment())!="/d/riyuejiao/dadian1")
	{
		return 1;
	}
    ob = filter_array(children(USER_OB), (: userp :));
    ob = filter_array(ob, (: environment :));
    ob = filter_array(ob, (: TASK_D->place_belong(environment($1))==TASK_D->place_belong(environment(this_object())) :) );
    for (i=0;i<sizeof(ob);i++)
    {
        if (ob[i]->query("family/family_name")=="日月神教"&&ob[i]->query("combat_exp")>=45000&&ob[i]->query("combat_exp")<=70000&&ob[i]->query("combat_exp")<=55000&&time()-ob[i]->query_temp("日月广告")>600)
        {
            ob[i]->set_temp("日月广告",time());
            command("tell "+ob[i]->query("id")+" 日月神教新手任务已经开放，你可以到我这里接到新手任务。\n");
        }
    }
	remove_call_out("adv");
    call_out("adv",1200+random(100));
    return 1;
}


int appear(object fighter)
{
    if (random(100)>49)
    {
        fighter->move("/d/riyuejiao/lianwu1");
        return 1;
    }
    else
    {
        fighter->move("/d/riyuejiao/lianwu2");
        return 1;
    }
}

int ask_job()
{
    object fighter;
    object me=this_player();
    object ob=this_object();
    
    if (me->query("family/family_name")!="日月神教")
    {
        command("taoyan");
        return 1;
    }
    if (me->is_busy()||me->is_fighting())
    {
        tell_object(me,"你正忙着呢。\n");
        return 1;
    }
    if (me->query_temp("rynewbiejob/lianwu/start"))
    {
        tell_object(me,"还不快去做，等什么呢？\n");
        return 1;
    }
    if (me->query("combat_exp")<45000)
    {
        tell_object(me,"你只是个普通杂役弟子，不用在总坛受训。\n");
        return 1;
    }
    if (me->query("combat_exp")>70000)
    {
        tell_object(me,"你已经完成了总坛的训练，可以去试试其他了。\n");
        return 1;
    }
    else
    {
            command("say 我教弟子，必须熟悉战斗，和不同门派的人战斗才能获得进步。");
            fighter=new(__DIR__"fighter");
            fighter->do_copy(me);
            call_out("appear",3,fighter);
            command("say 有我派弟子"+fighter->name()+"偷学得别派武技，你片刻后去练武场和他较量一下吧。");
            tell_object(me,"找到练功弟子后，可以用ask <id> about fight开始比武。\n");
            me->delete("rynewbiejob");
            me->set_temp("rynewbiejob/lianwu/start",1);
            return 1;
    }
       
}

int ask_fail()
{
	object me=this_player();
	object ob=this_object();
    
    if (me->query("family/family_name")!="日月神教")
    {
        command("taoyan");
        return 1;
    }
    if (me->is_busy()||me->is_fighting())
    {
        tell_object(me,"你正忙着呢。\n");
        return 1;
    }
    if (!me->query_temp("rynewbiejob/lianwu/start"))
    {
        tell_object(me,"你要放弃什么？\n");
        return 1;
    }
	else
	{
		me->delete_temp("rynewbiejob/lianwu/start");
		command("ok");
		tell_object(me,ob->name()+"帮你取消了练武场较量的任务。\n");
		return 1;
	}
}