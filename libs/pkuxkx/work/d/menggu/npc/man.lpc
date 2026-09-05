//小姑娘
//created by zine 2012

inherit NPC;
#include <ansi.h>
int ask_job();
void create()
{
        set_name("札儿赤兀惕", ({ "zhaer chiwuti", "zha", "man" }) );
        set("gender", "男性" );
		set("title", "草原一枝花的心上人");
        set("age", 20+random(5));
		set("per",15);
        set("long", 
            "他是札儿赤兀惕，在这里似乎也遇到了一些麻烦。\n");
        set("str", 30);
        set("dex", 10);
        set("con", 20);
        set("int", 10);
		set("shen_type", 1);
		set_skill("force", 25);
		set("combat_exp", 50000);
		set("max_qi", 1000);
        set("max_jing", 500);
        set("neili", 100);
        set("max_neili", 100);
		set("attitude", "friendly");
        set("inquiry", ([
            "name" : "我就是札儿赤兀惕。",
			"带信" : (: ask_job :),
            "daixin" : (: ask_job :),
            
       	]) );
        setup();
		carry_object(__DIR__"items/pixue")->wear();
		carry_object(__DIR__"items/cloth22")->wear();
		
}

int ask_job()
{
	object me=this_player();
	object ob=this_object();
	if (me->query("mengguquest/xinshi"))
	{
		command("thank "+me->query("id"));
		return 1;
	}
	if (!me->query_temp("mengguquest/xinshi_1"))
	{
		command("what");
		return 1;
	}
	if (me->query_temp("mengguquest/xinshi_2"))
	{
		command("say 说了不回就是不回！");
		return 1;
	}
	if (me->query_temp("mengguquest/xinshi_f"))
	{
		command("say 再麻烦你一次，给一枝花带个口信吧。");
		return 1;
	}
	else
	{
		message_vision("$N向$n述说了一枝花难忍思念之苦的种种。\n",me,ob);
		command("say 我也很想一枝花了，可我没找到黑石头之前，是不能回去的。");
		me->set_temp("mengguquest/xinshi_2",1);
		tell_object(me,"你想帮手，却又觉得无从帮起，也许在也儿的石河河畔转转也许能碰到这种黑石头的。\n");
		return 1;
	}
}
int dest(object ob)
{
	if (ob)
	{
		destruct(ob);
	}
	return 1;
}
int accept_object(object me,object ob)
{
	if (me->query_temp("mengguquest/xinshi_2")&&ob->query("heishi")==50)
	{
		call_out("dest",1,ob);
		command("jump");
		command("say 这就是我需要的东西，如果可以请你带信给一枝花，我很快就回去。");
		me->delete_temp("mengguquest/xinshi_2");
		me->set_temp("mengguquest/xinshi_f",1);
		tell_object(me,"你自觉做了一件善事，赶紧回去让一枝花安心吧。\n");
		return 1;
	}
	return notify_fail("你的东西，我要来作甚？\n");
}