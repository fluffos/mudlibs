//Zine 大师傅 ry newbie job
#include <ansi.h>
inherit NPC;
int ask_shi();
int ask_job();
int ask_fail();
void create()
{
	    string name,*tmp,*pinying;
        name=NAME_D->create_name();
        tmp=explode(name,"@");
        pinying=explode(tmp[1]," ");
        set_name(tmp[0],({tmp[1],pinying[0],pinying[1]}));
        set("title","大师傅");
        set("gender", "男性" );
        set("no_get",1);
        set("age", 33+random(22));
        set("long", 
"这是一位大师傅，做饭的手艺端的是一绝。\n");

        set("str", 17);
        set("dex", 16);
        set("con", 15);
        set("int", 17);
	    set("shen_type", 1);
	    set("shen", 10);
        set("random_npc",1);
        set_temp("apply/defense", 10);
        set("combat_exp", 10000);
        set("attitude", "peaceful");
        set("inquiry",(["食材": (:ask_shi:),
                        "food": (:ask_shi:),
                        "帮忙": (:ask_job:),
                        "help": (:ask_job:),
                        "失败": (:ask_fail:),
                        "fail": (:ask_fail:),

                    ]));
        setup();

        carry_object(__DIR__"obj/cloth")->wear();
        call_out("adv",1);
}

int adv()
{
    int i;
    object *ob;
	if (!environment()||base_name(environment())!="/d/riyuejiao/chufang")
	{
		return 1;
	}
    ob = filter_array(children(USER_OB), (: userp :));
    ob = filter_array(ob, (: environment :));
    ob = filter_array(ob, (: TASK_D->place_belong(environment($1))==TASK_D->place_belong(environment(this_object())) :) );
    for (i=0;i<sizeof(ob);i++)
    {
        if (ob[i]->query("family/family_name")=="日月神教"&&ob[i]->query("combat_exp")<20000&&time()-ob[i]->query_temp("日月广告")>600)
        {
            ob[i]->set_temp("日月广告",time());
            command("tell "+ob[i]->query("id")+" 日月神教新手任务已经开放，你可以到我这里接到新手任务。\n");
        }
    }
	remove_call_out("adv");
    call_out("adv",1200+random(100));
    return 1;
}

int ask_fail()
{
    object me=this_player();
    object ob=this_object();
    
    if (me->query("family/family_name")!="日月神教")
    {
        command("?");
        return 1;
    }
    if (me->is_busy()||me->is_fighting())
    {
        tell_object(me,"你正忙着呢。\n");
        return 1;
    }
    if (!me->query("rynewbiejob/chufang/start"))
    {
        tell_object(me,"我没给过你任务吧？\n");
        return 1;
    }
    me->delete("rynewbiejob/chufang/start");
    me->delete_temp("rynewbiejob/chufang");
    me->set("rynewbiejob/failtime",time());
    command("sigh");
    CHANNEL_D->do_channel(this_object(), "bd", "我教最近招来的弟子……");
    CHANNEL_D->do_channel(this_object(), "bd", "shzi "+me->query("id"), 1);
    return 1;
}

int ask_job()
{
    object me=this_player();
    object ob=this_object();
    
    if (me->query("family/family_name")!="日月神教")
    {
        command("shrug");
        return 1;
    }
    if (me->is_busy()||me->is_fighting())
    {
        tell_object(me,"你正忙着呢。\n");
        return 1;
    }
    
    if (me->query("rynewbiejob/chufang/start"))
    {
        tell_object(me,"还不快去做，等什么呢？\n");
        return 1;
    }
    if (me->query("rynewbiejob/failtime")&&time()-me->query("rynewbiejob/failtime")<120)
    {
        tell_object(me,"谁让你上次不好好干活的，迟点再来吧。\n");
        return 1;
    }
    if (me->query("combat_exp")<10000)
    {
        if (random(100)>5)
        {
            command("say 你去帮我把灶台点着吧，我马上要做饭了了。柴火就在西面的柴房，你拿过来之后把柴加进(add)灶台，点火(dianhuo)就好了。");
            me->delete("rynewbiejob");
            me->set("rynewbiejob/chufang/start",1);
            return 1;
        }
        else
        {
            command("say 我快忙不过来了，你去帮我在灶台上做个菜(zuocai)吧，没有食料可以跟我要，做好以后端(duan)进内厅。");
            me->delete("rynewbiejob");
            me->set("rynewbiejob/chufang/start",2);
            return 1;
        }
    }
    if (me->query("combat_exp")<20000&&me->query("combat_exp")>=10000)
    {
        if (random(100)>85)
        {
            command("say 你去帮我把灶台点着吧，我马上要做饭了了。柴火就在西面的柴房，你拿过来之后把柴加进(add)灶台，点火(dianhuo)就好了。");
            me->delete("rynewbiejob");
            me->set("rynewbiejob/chufang/start",1);
            return 1;
        }
        else
        {
            command("say 我快忙不过来了，你去帮我在灶台上做个菜(zuocai)吧，没有食料可以跟我要，做好以后端(duan)进内厅。");
            me->delete("rynewbiejob");
            me->set("rynewbiejob/chufang/start",2);
            return 1;
        }
    }
    else
    {
        command("say 你已经不是杂役弟子了，不用再做这种活了。");
        return 1;
    }
}

int ask_shi()
{
    object me=this_player();
    object ob=this_object();
    object shi;
    if (me->query("family/family_name")!="日月神教")
    {
        command("shrug");
        return 1;
    }
    if (me->is_busy()||me->is_fighting())
    {
        tell_object(me,"你正忙着呢。\n");
        return 1;
    }
    if (me->query("rynewbiejob/chufang/start")!=2)
    {
        tell_object(me,"大师傅没让你做饭，不要帮倒忙。\n");
        return 1;
    }
    if (me->query_temp("rynewbiejob/chufang/shiasked"))
    {
        command("say 我不是把食材交给你了？我最讨厌有人揩食堂油了。");
        return 1;
    }
    shi=new("/d/riyuejiao/obj/shi");
    shi->set("owner",me->query("id"));
    me->set_temp("rynewbiejob/chufang/shicai",shi->query("shicai"));
    shi->move(me);
    me->set_temp("rynewbiejob/chufang/shiasked",1);
    message_vision("$N拿出一份"+shi->name()+"交给$n，你去帮我做好它吧。\n",ob,me);
    return 1;
}

void unconcious()
{
    die();
}

void die()
{
    this_object()->fullme();
    return;
}