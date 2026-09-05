//詹事府詹事 Zine 

#include <ansi.h>
inherit NPC;
#include "/d/yingtianfu/neicheng/npc/daming_npc_officer.h"

int ask_task();
int ask_finish();
void create()
{
    set_name("詹事府詹事", ({"zhanshifu zhanshi", "zhanshi"}));
    set("title", HIW"大明"NOR);
    set("gender", "男性");
    set("age", 40);
    set("long", "他就是当今朝廷的詹事府詹事。\n");
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
    if (me->query("mingjiaonewbiejob/damingstart")&& me->query_temp("mingtasks/zhanshifu/jd_degree")>10)
    {
        tell_object(me,"完成了大明任务，你可以回杨逍处复命了。\n");
        me->delete("mingjiaonewbiejob");
        me->set("mingjiaonewbiejob/damingfinish",1);
        return 1;
    }
    if (!me->query_temp("mingtasks/zhanshifu/start"))
    {
        command("say 你有在这里要过任务吗？\n");
        return 1;
    }
    
    if (me->query_temp("mingtasks/zhanshifu/jd_degree")>50)
    {
        command("say 不错不错，皇帝听说了，龙颜大悦。\n");
        command("say 漂亮，大人为我大明立下此等功劳，我已上报吏部。\n");
        me->add("ming/credit",3+random(5));
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
    object huangzi;
    string *taskname=({"教导皇子",});
    int n;
    if (me->query("mingjiaonewbiejob/damingstart")&& me->query_temp("mingtasks/zhanshifu/start"))
    {
        if (me->query_temp("mingtasks/zhanshifu/task"))
        {
            command("say 你领了任务，就赶紧去做吧。\n");
            return 1;
        }
        n=random(sizeof(taskname));
        message_vision("$N看着$n，道：詹事府主要为皇子和皇上办差，你且去"+taskname[n]+"吧。\n",ob,me);
        me->set_temp("mingtasks/zhanshifu/task",n+1);
        if (me->query_temp("mingtasks/zhanshifu/task")==1)
        {
            tell_object(me,"皇子已经到门外了，你去接一下吧。\n");
        }
        huangzi=new(__DIR__"huangzi");
        huangzi->set("owner",me->query("id"));
        huangzi->set("mingpin",(int)me->query("mingpin"));
        if (!huangzi->query("mingpin"))
        {
            huangzi->set("mingpin",6);
        }
        huangzi->move("/d/yingtianfu/neicheng/qinglong2");
        return 1;
    }
    if (!me->query("mingpin"))
    {
        command("say 老夫在朝二十余年，大明官员都见过，怎么不认识你？\n");
        return 1;
    }
    if (!me->query_temp("mingtasks/zhanshifu/start"))
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
        command("say 你只是一个芝麻小官，恐怕不能胜任詹事府的艰巨任务。\n");
        return 1;
    }
    if (me->query_temp("mingtasks/zhanshifu/task"))
    {
        command("say 你领了任务，就赶紧去做吧。\n");
        return 1;
    }
    else
    {
        n=random(sizeof(taskname));
		if (me->query("mingpin")<4)
		message_vision("$N看着$n，道：詹事府主要为皇子和皇上办差，大人若有余暇，请去"+taskname[n]+"吧。\n",ob,me);
		else
        message_vision("$N看着$n，道：詹事府主要为皇子和皇上办差，你且去"+taskname[n]+"吧。\n",ob,me);
        me->set_temp("mingtasks/zhanshifu/task",n+1);
        if (me->query_temp("mingtasks/zhanshifu/task")==1)
        {
            tell_object(me,"皇子已经到门外了，你去接一下吧。\n");
        }
        huangzi=new(__DIR__"huangzi");
        huangzi->set("owner",me->query("id"));
        huangzi->set("mingpin",(int)me->query("mingpin"));
        if (!huangzi->query("mingpin"))
        {
            huangzi->set("mingpin",6);
        }
        huangzi->move("/d/yingtianfu/neicheng/qinglong2");
        return 1;
    }
}

