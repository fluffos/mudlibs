//cao.c	假曹化淳
//by Zine
inherit NPC;
#include <ansi.h>
int ask_task();
int ask_finish();
void create()
{
        set_name("曹化淳", ({ "cao huachun", "cao" }));
        set("long","他是东厂现任督公曹化淳。\n");
	    set("gender", "无性");
	    set("title",HIM+"大明 "+HIR+"东厂督公"+NOR);
        set("age", 50);
        set("shen_type", -1);
        set("str", 20);
        set("int", 23);
        set("con", 24);
        set("dex", 20);
        set("max_qi", 5000);
        set("max_jing", 5000);
        set("neili", 5000);
        set("max_neili", 5000);
        set("combat_exp", 5000000);

        set_skill("force", 400);
        set_skill("jiuyin-shengong", 400);
        set_skill("dodge", 400);
        set_skill("parry", 400);
	    set_skill("hand",400);
	    set_skill("pipa-shou",400);
        set_skill("feitian-shenfa", 400);
        set_skill("literate",200);
        map_skill("force", "jiuyin-shengong");
        map_skill("parry", "pipa-shou");
        map_skill("dodge", "feitian-shenfa");
        map_skill("hand","pipa-shou");
	    set("inquiry", ([
	
         "帮助": (: ask_task :),
         "help": (: ask_task :),
         "复命": (: ask_finish :),
         "finish": (: ask_finish :),
        
        ]));
        setup();
       
}

int ask_finish()
{
    object me=this_player();
    object ob=this_object();
    if (!me->query_temp("mingtasks/dongchang/start"))
    {
        command("say 你有在这里要过任务吗？\n");
        return 1;
    }
    
    if (me->query_temp("mingtasks/dongchang/kaoda_degree")>=50)
    {
        command("say 小皮猴子，不错嘛，这么快就完成任务回来了，后浪推前浪啊。\n");
        me->add("ming/credit",4+random(4));
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
    object theif,where;
    string *taskname=({"找回失落的宝贝","拷问犯人"});
    int n;
    if (!me->query("ming/tj/pin"))
    {
        command("say 你不是我内廷中人也敢来欺骗杂家？\n");
        return 1;
    }
    if (me->query("gender")!="无性")
    {
        command("say 你到底是何人，混入我内廷？\n");
        return 1;
    }
    if (me->is_busy() || me->is_fighting())
    {
        tell_object(me,"你正忙着哪！\n");
		return 1;
    }
    if (!me->query_temp("mingtasks/dongchang/start"))
    {
        command("say 杂家这里没事，你去别处看看。\n");
        return 1;
    }
    if (me->query_temp("mingtasks/dongchang/task"))
    {
        command("say 你领了任务，就赶紧去做吧。\n");
        return 1;
    }
    else
    {
        n=random(sizeof(taskname));
        if (n==0)
        {
            theif=new(__DIR__"jinshen-taijian");
            where=TASK_D->random_room("/d/yingtianfu/neicheng/");
            theif->move(where);
            me->set_temp("mingtasks/dongchang/task1where",where);
            message_vision("$N看着$n，尖声道：我的宝贝不见了，你快去帮我"+taskname[n]+"吧，可能是我近身太监干的，应该他还没有离开应天府。\n",ob,me);
            me->set_temp("mingtasks/dongchang/task",n+1);
            me->set_temp("mingtasks/dongchang/task1",1);
            return 1;
        }
        if (n==1)
        {
            message_vision("$N看着$n，尖声道：诏狱里关了几个硬骨头，你去"+taskname[n]+"吧。\n",ob,me);
            me->set_temp("mingtasks/dongchang/task",n+1);
            me->set_temp("mingtasks/dongchang/task2",1);
            return 1;
        }
    }
}

int dest(object thing)
{
	if(thing)
	destruct(thing);
	return 1;
}

int accept_object(object me, object thing)
{
	if( thing->query("xiaojiji") && me->query_temp("mingtasks/dongchang/task")==1)
	{
        command("say 小皮猴子，不错嘛，这么快就完成任务回来了，本厂公重重有赏。\n");
        me->add("ming/credit",4+random(5));
        call_out("dest",1,thing);
        me->delete_temp("mingtasks");
        return 1;
    }
    if (thing->query("gettheif")==me && me->query_temp("mingtasks/dongchang/task1thief")==thing && me->query_temp("mingtasks/dongchang/task")==1)
    {
        command("say 小皮猴子，不错嘛，这么快就完成任务回来了，本厂公重重有赏。\n");
        me->add("ming/credit",5+random(4));
        call_out("dest",1,thing);
        me->delete_temp("mingtasks");
        return 1;
    }
	else
	{
		return notify_fail("曹化淳不想要你的东西。\n");
	}

}