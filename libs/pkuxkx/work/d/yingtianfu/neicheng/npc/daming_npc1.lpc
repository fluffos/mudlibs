#include <ansi.h>
inherit NPC;
#include "huilu.h"
#include "/d/yingtianfu/neicheng/npc/daming_npc_officer.h"
int ask_help();
void create()
{
    set_name("大理寺卿", ({"dalisi qing", "qing"}));
    set("title", HIW"大明"NOR);
    set("gender", "男性");
    set("age", 50);
    set("long", "他就是当今朝廷的大理寺卿。\n");
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

    set("mingpin",3);
	
	set("inquiry", ([
	
     "help": (: ask_help :),
     "帮助": (: ask_help :),
     
	]));
    setup();
    setup_player_name();
}

int ask_help()
{
	object me=this_player();
    object ob=this_object(),an;
    string *taskname=({"复核案卷","回复刑部"});
    int n;
    if (!me->query("mingpin"))
    {
        command("say 老夫在朝二十余年，大明官员都见过，怎么不认识你？\n");
        return 1;
    }
   
    if (!me->query_temp("mingtasks/dalisi/start"))
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
        command("say 你只是一个芝麻小官，恐怕不能胜任大理寺的艰巨任务。\n");
        return 1;
    }
    if (me->query_temp("mingtasks/dalisi/task"))
    {
        command("say 你领了任务，就赶紧去做吧。\n");
        return 1;
    }
    else
    {
		n=random(sizeof(taskname));
		me->set_temp("mingtasks/dalisi/task",n+1);
        if (n==0)
        {
			if (me->query("mingpin")<4)
			command("say 宗卷室有一件案子正等着复核(fuhe)，请大人协助完成。");
			else
            command("say 宗卷室有一件案子正等着复核(fuhe)，你快去把它完成。");
        }
		if (n==1)
        {
			an=new(__DIR__"obj/an");
			an->move(this_object());
			an->set("owner",me);
			if (me->query("mingpin")<4)
			command("say 这里有一份案子已经通过复核，请大人代为递送到刑部库房。");
			else
            command("say 这里有一份案子已经通过复核，你快去把它送到刑部库房。");
			command("give "+me->query("id")+" an juan");
        }
        return 1;
    }
}