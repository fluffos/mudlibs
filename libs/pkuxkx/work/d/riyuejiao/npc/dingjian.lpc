// dingjian.c 丁坚
//by bing
#include "riyuenpc.h"
#include "riyuenpc2.h"

string ask_jianyi();

inherit NPC;
#include <ansi.h>
void create()
{
        set_name("丁坚", ({ "ding jian", "ding","jian" }));
        set("title",HIR "一字电剑" NOR);
        set("long","他目光炯炯，步履稳重，显是武功不低，却作家人装束。\n");
	set("gender", "男性");
        set("age", 56);
        set("shen_type", -1);
        set("str", 30);
        set("int", 23);
        set("con", 24);
        set("dex", 28);
        set("max_qi", 400);
        set("max_jing", 300);
        set("neili", 500);
        set("max_neili", 500);
        set("jiali", 20);
        set("combat_exp", 100000);
	set("score",1000);
        set("chat_chance", 50);
        set("chat_msg", ({
                (: heal :),
        }));
        set("inquiry", ([
	    "剑术" : (: ask_jianyi :),
       ]) );

        set_skill("force", 80);
        set_skill("riyue-shengong", 80);
        set_skill("dodge", 80);
        set_skill("parry", 80);
	set_skill("sword",80);
	set_skill("pomo-jianfa",80);
        set_skill("feitian-shenfa", 80);
        set_skill("literate",80);
        map_skill("force", "riyue-shengong");
        map_skill("parry", "pomo-jianfa");
        map_skill("dodge", "feitian-shenfa");
        map_skill("sword","pomo-jianfa");
        set("chat_chance_combat", 40);
        set("chat_msg_combat", ({
                (: perform_action, "sword.yulong" :),
        }) );
	create_family("日月神教", 22, "弟子");
        setup();
        carry_object(__DIR__"obj/cloth")->wear();
	carry_object(__DIR__"obj/changjian")->wield();
       }
void init()
{
	object ob;
	mapping fam;
        ::init();
	ob = this_player();
    if (interactive(ob) && !is_fighting()) {
		remove_call_out("greeting");
             call_out("greeting",1,ob);
     }
	add_action("do_look","look");
	add_action("do_look","l");

}


string ask_jianyi()
{
	object me = this_player();
	if ( me->query_temp("riyue/看画") )
	{
		command("wa " + me->query("id"));
		command("say " + RANK_D->query_respect(me) + "果然是剑术名家。我家四庄主丹青生说道：那日他大醉后绘此一画，
无意中将剑法蕴蓄于内，那是他生平最得意之作，酒醒之后再也绘不出来了。
风爷居然能从此画中看出剑意，四庄主定当引为知己。我进去告知。");
		message_vision("丁坚说着喜孜孜的走了进去。\n",me);
		me->set_temp("riyue/fight丹",1);
        remove_call_out("goin");
        call_out("goin",1,me);
		return "四庄主一定会很高兴的。\n";
	}
	else return "什么剑术?\n";
}

void goin(object me)
{
	object dan;
		
	message_vision("过了一会儿，忽听得门外一人大声道：「他从我画中看出了剑法？
这人的眼光可了不起啊。」叫嚷声中，走进一个人来。\n",me);
	seteuid(getuid());
	dan = new(__DIR__"danqing");
	dan->move(environment(this_object()));
	destruct(this_object());
}

int do_look(string arg)
{
	object me = this_player();
	if (!arg || arg != "drawing")
	{
		return 0;
	}
    message_vision("丁坚对$N说道：「" + RANK_D->query_respect(me) + "觉得这幅画如何？」\n",me);
	me->set_temp("riyue/看画",1);
      return 0;
}

