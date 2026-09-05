//应天府尹

#include <ansi.h>
inherit NPC;

int ask_paper();

void create()
{
    set_name("应天府尹", ({"yingtian fuyin", "fuyin"}));
    set("title", HIW"大明"NOR);
    set("gender", "男性");
    set("age", 50);
    set("long", "他就是当今朝廷的应天府尹。\n");
    set("attitude","heroism");
    set("generation",0);
    set("mingpin",4);
    set("max_qi",800);
    set("eff_qi",800);
    set("qi",800);
    set("max_jing",300);
    set("jing",300);
    set("shen_type",1);
    set("no_clean_up",1);
    set("combat_exp",20000);

    
	set("inquiry", ([
	
     
	 "批文": (: ask_paper :),
     "piwen": (: ask_paper :),
     
	]));

    setup();
   
}

int ask_paper()
{
    object me=this_player();
    object ob=this_object();
    object piwen;
    string* taskname=({"囚衣","囚粮","药品"});
    int n;
    if (!me->query("mingpin")&&!me->query("mingjiaonewbiejob/damingstart"))
    {
        command("say 老夫在朝十余年，大明官员都见过，怎么不认识你？\n");
        return 1;
    }
    if (me->query_temp("mingtasks/xingbu/task")!=1)
    {
        command("say 没有刑部的照会，我不能给你批文。\n");
        return 1;
    }
    if (me->is_busy() || me->is_fighting())
    {
		return notify_fail("你正忙着哪！\n");
    }
    if (me->query_temp("mingtasks/xingbu/task1no"))
    {
        tell_object(me,"你不是拿过批文了吗？\n");
        return 1;
    }
    else
    {
        n=random(sizeof(taskname));
        me->set_temp("mingtasks/xingbu/task1no",n+1);
        piwen=new(__DIR__"obj/piwen");
        piwen->set("owner",me->query("id"));
        piwen->move(me);
        
        message_vision("$N看着$n，道：刑部尚书的手令，你去把"+taskname[n]+"送到刑部大牢吧。\n",ob,me);
        tell_object(me,"应天府尹给你一张批文。\n");
        tell_object(me,"药品在太医院领(ling)取，囚衣在刑部库房领取，囚粮暂时不足，需要去城西军仓领取。\n");
        
        return 1;
    }
}

