//兵部尚书 Zine 

#include <ansi.h>
inherit NPC;


int ask_task();
int ask_finish();
void create()
{
    set_name("掌印太监", ({"zhangyin taijian", "taijian","jian"}));
    set("title", HIW"大明 "HIM"司设监"NOR);
    set("gender", "男性");
    set("age", 60);
    set("long", "他就是当今内廷司设监的掌印太监。\n");
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
     "复命": (: ask_finish :),
     "finish": (: ask_finish :),
	
	]));

    setup();
   
}

int ask_finish()
{
    object me=this_player();
    object ob=this_object();
    if (!me->query_temp("mingtasks/sishe/start"))
    {
        command("say 你有在这里要过任务吗？\n");
        return 1;
    }
    
    if (me->query_temp("mingtasks/sishe/yizhang_finish")>=8)
    {
        command("say 小皮猴子，不错嘛，这么快就完成任务回来了。\n");
        me->add("ming/credit",6+random(3));
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
    string *taskname=({"出行仪仗"});
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
    if (!me->query_temp("mingtasks/sishe/start"))
    {
        command("say 杂家这里没事，你去别处看看。\n");
        return 1;
    }
    if (me->query_temp("mingtasks/sishe/task"))
    {
        command("say 你领了任务，就赶紧去做吧。\n");
        return 1;
    }
    else
    {
        n=random(sizeof(taskname));
        message_vision("$N看着$n，尖声道：陛下马上要出行，这会一个人都不见了，你开去奉天殿加入(join)"+taskname[n]+"吧。\n",ob,me);
        me->set_temp("mingtasks/sishe/task",n+1);
        return 1;
    }
}

