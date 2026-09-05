//Zine 先生 ry newbie job
#include <ansi.h>
inherit NPC;

void create()
{
	    string name,*tmp,*pinying;
        name=NAME_D->create_name();
        tmp=explode(name,"@");
        pinying=explode(tmp[1]," ");
        set_name(tmp[0],({tmp[1],pinying[0],pinying[1]}));
        set("title",HIC"饱学之士"NOR);
        set("gender", "男性" );
        set("no_get",1);
        set("age", 33+random(22));
        set("long", 
"这是一位教书先生，肚里的墨水那是刚刚的。\n");

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
        set("inquiry",(["name": "我是大名鼎鼎的"+query("name")+"，你不知道吗？\n",
                     

                    ]));
        setup();

        carry_object(__DIR__"obj/cloth")->wear();
        if (clonep()) call_out("dest",1200);
}

void init()
{
    add_action("do_qingwen","qingwen");
}

int do_qingwen()
{
    object me=this_player();
    if (me->query("family/family_name")!="日月神教")
    {
        tell_object(me,"先生不太愿意理会你。\n");
        return 1;
    }
    if (me->is_busy()||me->is_fighting())
    {
        tell_object(me,"你正忙着呢。\n");
        return 1;
    }
    message_vision("$N恭敬地向"+this_object()->name()+"请教读书中遇到的疑难。\n",me);
    if ((int)me->query_skill("literate",1)>100)
    {
        message_vision("$N道：让我仔细想想，这个，这个。\n",this_object());
        return 1;
    }
    me->add_busy(1+random(3));
    message_vision("$N仔细给$n讲解书中的微言大义。\n",this_object(),me);
    me->improve_skill("literate",1+(int)(me->query_skill("literate")+random(me->query("int"))/3));
    return 1;
}

int dest()
{
    if (clonep() && environment())
    {
        command("yi");
        command("say 你们都懂了，那我就先回去了，明天请早。");
        destruct(this_object());
    }
    
    return 1;
}

void unconcious()
{
    command("heng");
    command("say 伤自尊了，走了。");
    destruct(this_object());
    return;
}

void die()
{
    command("heng");
    command("say 伤自尊了，走了。");
    destruct(this_object());
    return;
}

void yoar()
{
    
    object *ob;
    ob = filter_array(children(USER_OB), (: userp :));
    ob = filter_array(ob, (: environment :));
    ob = filter_array(ob, (: TASK_D->place_belong(environment($1))==TASK_D->place_belong(environment(this_object())) :) );
    ob = filter_array(ob, (: $1->query("family/family_name")=="日月神教":));
    message( "channel:" + "chat",
    HIM "【日月神教】请来的先生现在在书院授课，读书写字较低的神教入门弟子可以过去看看！\n" NOR, ob );
    return ;
}