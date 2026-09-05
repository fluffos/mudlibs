// zhaodai.c 新手学堂招待  引路使
// zoom 2004.3.29
#include <ansi.h>

inherit NPC;

int ask_help();
void greeting(object);

void create()
{
	set_name("招待", ({ "zhaodai", "dai"}));
	set("long", "他是新手学堂的招待，专门迎接客人，满脸堆着笑容。\n");
	set("nickname","引路使");
	set("gender", "男性");
	set("age", 16);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("str", 20);
	set("int", 25);
	set("con", 20);
	set("dex", 15);
	set("race", "人类");	
	set("max_qi", 200);
	set("eff_qi", 200);
	set("qi", 200);
	set("max_jing", 200);
	set("eff_jing", 200);
	set("jing", 200);
	set("max_neili", 200);
	set("eff_neili", 200);
	set("neili", 200);
	set("max_jingli", 200);
	set("eff_jingli", 200);
	set("jingli", 200);
	set("combat_exp", 5000);
	set("score", 1000);
	set_skill("literate", 30);
	set_skill("force", 30);
	set_skill("dodge", 30);
	set_skill("parry", 30);
	set_skill("strike", 30);
	set_skill("sword", 30);
	
	set("inquiry", ([
			"help"   : 	(: ask_help :),
			"帮助"   : 	(: ask_help :),
			"庄主"   : 	"庄主在书房\n",
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
{	if (query_temp("met") == 0)
	{	if(me->query_temp("greeted") <= 0)
		{	set_temp("met", 1);
			set_temp("train/guest", me->query("id"));
			me->set_temp("greeted", 1);
			command("bow " + me->query("id"));
			command("say 新手学堂" + query("nickname")+"，奉庄主之命，恭迎" + me->query("name") + "，请跟我来。\n"+
			"    "+HBRED+HIW"(follow " + query("id") +")"NOR);
			remove_call_out("check_follow");
			call_out("check_follow", 5, me, 0);
		}
	}
	else
	{	if (me->query_temp("greeted") == 0)
		{	me->set_temp("greeted", -1);
			command("sorry " + me->query("id"));
			command("say 现在宾客太多，请等一下。");
		}
		remove_call_out("greeting");
		call_out("greeting", 1, me);
	}
	return;
}
int check_follow(object me, int count)
{	string curguest;
	curguest = query_temp("train/guest");
	command("say " + curguest);
	if (!(present(curguest, environment(this_object()))))
	{	command("say ok");
		move("/u/zoom/train/kefang");
		set_temp("met", 0);
		return 1;
	}
	if ((me->query_leader() == this_object()) || (count > 0))
	{	command("tell " + me->query("id") + " 请这边来");
		message_vision("$N拉起$n的手，身形一闪就不知去向了。\n", this_object(), me);
		move("/u/zoom/train/kefang");
		me->move("/u/zoom/train/kefang");
		message_vision("$N拉着$n的手闪了进来。\n", this_object(), me);
		command("say " + RANK_D->query_respect(me) + "先在这里休息一下吧。");
		command("bye " + me->query("id"));
		message_vision("$N说完转身走了出去。\n", this_object());
		me->set_leader("");
		move("/u/zoom/train/gate");
		set_temp("met", 0);
	}
	else
	{	command("tell " + me->query("id") + " 请快跟我来。(请键入"+HBRED+HIW"follow " + query("id") + NOR")");
		call_out("check_follow", 10, me, 1);
	}
	return 1;
}

int ask_help()
{
	command("say 
          这里是新手学堂，你可以在这里学到一些基本的操作，可以熟悉
    一下环境。");
   return 1;
}