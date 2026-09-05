// 十夫长
// create by zine 
#include <ansi.h>
inherit NPC;
int re_long();
int ask_code();
int check();
void create()
{
	set_name("十夫长", ({"shifu zhang","zhang"}));
	set("long", "他是桑坤帐下的一名斥候。\n");
	set("gender", "男性");
	set("age", 35);
    set("combat_exp", 150000);
    set_skill("unarmed", 200);
    set_skill("force", 200);
    set_skill("dodge", 200);
    set_temp("apply/attack", 30);
    set_temp("apply/defense", 40);
    set("uni_target",1);
	set("shen_type", 1);
	set("per",20);
    set("inquiry", ([
                "口令":   (: ask_code() :),
                "kouling":   (: ask_code() :),
           
       	]) );
	setup();
	carry_object(__DIR__"items/pixue")->wear();
	carry_object(__DIR__"items/cloth20")->wear();
	
    call_out("re_long",1);
    call_out("check",1);
}

int check()
{
    if (!find_player(this_object()->query("uni_target")))
    {
        destruct(this_object());
        return 1;
    }
    remove_call_out("check");
    call_out("check",2);
    return 1;
}

int re_long()
{
    object env=environment(this_object());
    if (!env)
    {
        return 1;
    }
    if (!env->isroom())
    {
        return 1;
    }
    this_object()->set("long","他是桑坤帐下的一名斥候，常年在"+env->query("short")+"一带刺探军情。\n");
    return 1;
}

string get_kouling()
{
    object place=TASK_D->random_place(),*ob;
    string time,placename,people,dowhat,*times,*dowhats;
    times=({"昨天，","前天，","今天，","刚才，","昨夜，","今晨，",});
    dowhats=({"放了一个屁","下了一碗面","生了个孩子","调戏了老大娘","被老虎吃掉了","随地吐痰被罚款了","吃坏了肚子","回家过年了","很好很强大","很傻很天真",});
    while (!place->isroom()||!place->query("short"))
    {
        place=TASK_D->random_place();
    }
    placename=COLOR_D->uncolor(place->query("short"));
    ob = filter_array(children(USER_OB), (: userp :));
    people=COLOR_D->uncolor(ob[random(sizeof(ob))]->query("name"));
    time=times[random(sizeof(times))];
    dowhat=dowhats[random(sizeof(dowhats))];
    return time+people+"在"+placename+dowhat+"。";
}
	
int ask_code()
{
    object me=this_player();
    object ob=this_object();
    string kouling;
    if (ob->query("uni_target")!=me->query("id"))
    {
        command("say 口令？该是我问你口令才是！");
        return 1;
    }
    else if (me->query_temp("shediaoquest/jdfm/kouling"))
    {
        command("say 口令？该是我问你口令才是！");
        return 1;
    }
    else
    {
        message_vision("$N看着$n，不假思索的说出了今天的口令。\n",ob,me);
        kouling=get_kouling();
        command("say 今天的口令是“"+kouling+"”\n");
        me->set_temp("shediaoquest/jdfm/kouling",kouling);
        message_vision("$N疑惑地看着$n：兄弟，你面生得紧啊。\n",ob,me);
		tell_object(me,"你默默记下今天的口令，到了桑昆大帐前用say 说出口令一定能混进去。\n");
        tell_object(me,HIG+"还等什么，既然套的了口令，就一棍子夯死(hang)他得了，难道还等他报信吗？\n"+NOR);
        return 1;
    }
}

void die()
{
    object me,cloth;
    if (!find_player(this_object()->query("uni_target")))
    {
        ::die();
    }
    me=find_player(this_object()->query("uni_target"));
    if (present(me,environment(this_object())))
    {
		cloth=new(__DIR__"items/cloth20");
		cloth->move(me);
        tell_object(me,"你心念一动，穿上他的衣服，乔装成"+this_object()->name()+"的样子，也许可以轻松混进敌营。\n");
		message_vision("$N从十夫长的尸体上剥下一件"+cloth->query("name")+"。\n",me);
    }
    ::die();
}

int do_hang(string arg)
{
    object me=this_player();
    object ob=this_object();
    if (!me->query_temp("shediaoquest/jdfm/kouling"))
    {
        return 0;
    }
    if (ob->query("uni_target")!=me->query("id"))
    {
        return 0;
    }
    message_vision("$N趁着$n不备，重重一棍子敲在了$n的天灵盖上，$n哼都没哼一声，就被报销了。\n",me,ob);
    me->add_temp("shediaoquest/jdfm/lie_kouling",1);
    ob->die();
    return 1;
}

void init()
{
    add_action("do_hang","hang");
}