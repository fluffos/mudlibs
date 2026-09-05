//zhuangzhu.c
//by zoom
//2003.3.30

#include <ansi.h>

inherit NPC;

int ask_leave();
void do_leave(object);
void greeting(object);

void create()
{
        set_name("庄主", ({ "zhuang zhu","zhu"}) );
        set("gender", "男性" );
        set("age", 25);
        set("long", "新手学堂就是他一手兴办的。\n");
        set("attitude", "friendly");
        set("shen_type", 1);
        set("str", 23);
        set("int", 23);
        set("con", 22);
        set("dex", 20);
        set("max_qi", 300);
        set("max_jing", 300);
        set("neili", 200);
        set("max_neili", 200);
        set("combat_exp", 30000);
        set("score", 20000);
        set_skill("dodge", 20);
        set_skill("parry", 20);
        set_skill("unarmed", 20);
        set_skill("sword", 20);
        set_skill("blade", 20);
	set("inquiry", ([
			"leave"   : 	(: ask_leave :),
		]));
        setup();
}

void init()
{
        object me = this_player();        

        ::init();

        if( interactive(me) )
        {
                remove_call_out("greeting");
                call_out("greeting", 1, me);
        }
}

void greeting(object me)
{	if (me->query_temp(this_object()->query("id")) == 0 )
	{	command("hi " + me->query("id"));
		command("say 
         这位" + RANK_D->query_respect(me) + 
	          "四处逛逛吧，实在没事做了去扬州看看吧的。");
	command("say 想离开就来问我"+HBRED+HIW"(ask zhu about leave)"NOR+"。");

		me->set_temp(this_object()->query("id"), 1);

	}
}

int ask_leave()
{
        object me = this_player();        

	command("say 
          好吧，老朽送你出去。");

        call_out("do_leave", 1, me);

   return 1;
}

void do_leave(object ob)
{
	ob->move("/d/city/kedian");
}
