//五军大都督

#include <ansi.h>
inherit NPC;
#include <title.h>
#include "huilu2.h"
#include "/d/yingtianfu/neicheng/npc/daming_npc_officer.h"


int ask_task();
int ask_finish();
void create()
{
    set_name("大都督", ({"da dudu", "dudu"}));
    set("title", HIW"大明五军都督府"NOR);
    set("gender", "男性");
    set("age", 50);
    set("long", "他就是当今朝廷的五军大都督。\n");
    set("attitude","heroism");
    set("generation",0);

    set("max_qi",800);
    set("eff_qi",800);
    set("qi",800);
    set("max_jing",300);
    set("jing",300);
    set("shen_type",1);
    set("mingpin",1);
    set("no_clean_up",1);
    set("combat_exp",2000000);

    
	set("inquiry", ([
	
    
	 "帮助": (: ask_task :),
     "help": (: ask_task :),
     "复命": (: ask_finish :),
     "finish": (: ask_finish :),
	]));

    setup();
    setup_player_name();
}
int ask_finish()
{
    object me=this_player();
    object ob=this_object();
    if (!me->query_temp("mingtasks/dudufu/start"))
    {
        command("say 你有在这里要过任务吗？\n");
        return 1;
    }
    if (me->query("mingjiaonewbiejob/damingstart")&& (me->query_temp("mingtasks/dudufu/task1finish")||me->query_temp("mingtasks/dudufu/task2finish")))
    {
        tell_object(me,"完成了大明任务，你可以回杨逍处复命了。\n");
        me->delete("mingjiaonewbiejob");
        me->set("mingjiaonewbiejob/damingfinish",1);
        return 1;
    }
    if (me->query_temp("mingtasks/dudufu/task1finish"))
    {
        command("say 绿林豪杰整编新军完成，不错。\n");
        command("say 不错不错，大人为我大明立下此等功劳，我已上报吏部。\n");
        me->add("ming/credit",6+random(2));
        me->delete_temp("mingtasks");
        return 1;
    }
    if (me->query_temp("mingtasks/dudufu/task2finish"))
    {
        command("say 太湖水匪整编新军完成，不错。\n");
        command("say 不错不错，大人为我大明立下此等功劳，我已上报吏部。\n");
        me->add("ming/credit",6+random(2));
        me->delete_temp("mingtasks");
        return 1;
    }
    else
    {
        command("say 你完成了吗？\n");
        return 1;
    }
}
int ask_task()
{
    object me=this_player();
    object ob=this_object();
    string *taskname=({"城东绿林","太湖水匪"});
    int n;
    if (me->query("mingjiaonewbiejob/damingstart")&& me->query_temp("mingtasks/dudufu/start"))
    {
        if (me->query_temp("mingtasks/dudufu/task"))
        {
            command("say 你领了任务，就赶紧去做吧。\n");
            return 1;
        }
        n=random(sizeof(taskname));
        message_vision("$N看着$n，道：朝廷现在最缺一支劲旅，我先派你去整编"+taskname[n]+"吧。\n",ob,me);
        me->set_temp("mingtasks/dudufu/task",n+1);
        return 1;
    }
    if (!me->query("mingpin"))
    {
        command("say 老夫掌都督府十余年，大明官员都见过，怎么不认识你？\n");
        return 1;
    }
   
    if (!me->query_temp("mingtasks/dudufu/start"))
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
        command("say 你只是一个芝麻小官，恐怕不能胜任都督府的艰巨任务。\n");
        return 1;
    }
    if (me->query_temp("mingtasks/dudufu/task"))
    {
        command("say 你领了任务，就赶紧去做吧。\n");
        return 1;
    }
    else
    {
        n=random(sizeof(taskname));
		if (me->query("mingpin")==1)
		message_vision("$N看着$n，道：朝廷现在最缺一支劲旅，我去整编"+taskname[n]+"吧。\n",me,ob);
		else if (me->query("mingpin")<4)
		command("say 朝廷现在最缺一支劲旅，大人请去整编"+taskname[n]+"吧。");
		else
        message_vision("$N看着$n，道：朝廷现在最缺一支劲旅，我先派你去整编"+taskname[n]+"吧。\n",ob,me);
        me->set_temp("mingtasks/dudufu/task",n+1);
        return 1;
    }
}

