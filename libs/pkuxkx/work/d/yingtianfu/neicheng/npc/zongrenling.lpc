//宗人令 Zine 

#include <ansi.h>
inherit NPC;
#include "/d/yingtianfu/neicheng/npc/daming_npc_officer.h"

int ask_task();

void create()
{
    set_name("宗人令", ({"zongren ling", "ling","zongren"}));
    set("title", HIW"大明"NOR);
    set("gender", "男性");
    set("age", 45);
    set("long", "他就是当今朝廷的宗人令，负责管理藩王事宜。\n");
    set("attitude","heroism");
    set("generation",0);

    set("max_qi",800);
    set("eff_qi",800);
    set("qi",800);
    set("max_jing",300);
    set("jing",300);
    set("shen_type",1);
    set("no_clean_up",1);
    set("combat_exp",20000);

    
	set("inquiry", ([
	
     "帮助": (: ask_task :),
     "help": (: ask_task :),
	
	]));

    setup();
   
}

void init()
{
    add_action("do_gaosu","gaosu");
}

int do_gaosu(string arg)
{
    object me=this_player();
    if (!me->query_temp("mingtasks/zongrenfu/task"))
    {
        return 0;
    }
    if (me->is_busy()||me->is_fighting())
    {
        tell_object(me,"你正忙着呢。\n");
        return 1;
    }
    if (me->query_temp("mingtasks/zongrenfu/ningcount")<3||!me->query_temp("mingtasks/zongrenfu/ningcount"))
    {
        tell_object(me,"你还没调查清楚呢，来忽悠宗人令吗？\n");
        return 1;
    }
    if (!arg)
    {
        tell_object(me,"你要告诉宗人令什么情况？\n");
        return 1;
    }
    if (arg!="宁王造反"&&arg!="宁王忠顺")
    {
        tell_object(me,"你要简明扼要，直接告诉(gaosu)宗人令“宁王造反”或者“宁王忠顺”吧。\n");
        return 1;
    }
    if (arg=="宁王造反"&&me->query_temp("mingtasks/zongrenfu/ning")>0)
    {
        if (me->query("mingjiaonewbiejob/damingstart"))
        {
            tell_object(me,"完成了大明任务，你可以回杨逍处复命了。\n");
            me->delete("mingjiaonewbiejob");
            me->set("mingjiaonewbiejob/damingfinish",1);
            return 1;
        }
        command("say 宁王要反？朝廷不得不防啊，你下去吧。");
        tell_object(me,HIC"你的大明功勋上升了。\n"NOR);
        me->add("ming/credit",4+random(3));
        me->delete_temp("mingtasks");
        return 1;
    }
    if (arg=="宁王忠顺"&&me->query_temp("mingtasks/zongrenfu/ning")<0)
    {
        if (me->query("mingjiaonewbiejob/damingstart"))
        {
            tell_object(me,"完成了大明任务，你可以回杨逍处复命了。\n");
            me->delete("mingjiaonewbiejob");
            me->set("mingjiaonewbiejob/damingfinish",1);
            return 1;
        }
        command("say 宁王忠顺，国之栋梁啊，你下去吧。");
        tell_object(me,HIC"你的大明功勋上升了。\n"NOR);
        me->add("ming/credit",4+random(3));
        me->delete_temp("mingtasks");
        return 1;
    }
    else
    {
        command("say 叫你去悉心调查，你居然敷衍与我，还不快退下。");
        tell_object(me,"你的大明功勋下降了。\n");
        me->add("ming/credit",-random(4));
        me->delete_temp("mingtasks");
        return 1;
    }

}



int ask_task()
{
    object me=this_player();
    object ob=this_object();
    string *taskname=({"监督宁王",});
    int n;
    if (me->query("mingjiaonewbiejob/damingstart")&& me->query_temp("mingtasks/zongrenfu/start"))
    {
        if (me->query_temp("mingtasks/zongrenfu/task"))
        {
            command("say 你领了任务，就赶紧去做吧。\n");
            return 1;
        }
        n=random(sizeof(taskname));
        message_vision("$N看着$n，沉声道：你且去南昌"+taskname[n]+"吧。\n",ob,me);
        me->set_temp("mingtasks/zongrenfu/task",n+1);
        return 1;
    }
    if (!me->query("mingpin"))
    {
        command("say 老夫领宗人府十余年，大明官员都见过，怎么不认识你？\n");
        return 1;
    }
    if (!me->query_temp("mingtasks/zongrenfu/start"))
    {
        command("say 我这里暂时没有什么事，你去别的衙门看看哪里需要帮忙吧。\n");
        return 1;
    }
    if (me->is_busy() || me->is_fighting())
    {
		return notify_fail("你正忙着哪！\n");
    }
    if (me->query("mingpin")>6)
    {
        command("say 你只是一个芝麻小官，恐怕不能胜任宗人府的任务。\n");
        return 1;
    }
    if (me->query_temp("mingtasks/zongrenfu/task"))
    {
        command("say 你领了任务，就赶紧去做吧。\n");
        return 1;
    }
    else
    {
        n=random(sizeof(taskname));
		if (me->query("mingpin")<4)
		command("say 大人请去南昌"+taskname[n]+"吧。");
		else
        message_vision("$N看着$n，沉声道：你且去南昌"+taskname[n]+"吧。\n",ob,me);
        me->set_temp("mingtasks/zongrenfu/task",n+1);
        return 1;
    }
}

