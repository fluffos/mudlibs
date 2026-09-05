//D:\xkx\d\liuxiu-shanzhuang\npc\yahuan.c丫鬟
#include <ansi.h>
inherit NPC;
#include "../newbie_village.h"

int ask_me();
int command_me(string);
void mess1(object);
void mess2(object);
void go_back(object,object);

void create()
{
	set_name("丫鬟", ({ "ya huan", "yahuan", "ya"}));
	set("gender", "女性");
	set("age", 18);
	set("long", "生得仪容不俗，眉目清明，虽无十分姿色，却亦有动人之处。\n");
	
	set("inquiry", ([
		   "葫芦" : (: ask_me :),
		   "hulu" : (: ask_me :),
	]));


	set("combat_exp", 4000);
	set_skill("dodge", 20);
	set_skill("unarmed", 20);
	set_temp("apply/attack",  10);
	set_temp("apply/defense", 10);
	set("shen_type", 1);
	setup();

	carry_object("/d/city/obj/qun")->wear();
}

void init()
{
	object ob, me;
	
	ob=this_object();
	me=this_player();

	if (((!ob->query_temp("player")) && (me->query(NEWBIE_VILLAGE_INDEX)==get_questindex("再次敲门(knock gate)，去见山庄庄主"))))
	{
		ob->set_temp("player",1);
		call_other(environment(),"reset_close");
		me->set_leader(ob);
		command("say 嘻嘻，我们山庄的……葫芦让你找了回来，刚刚太高兴，\n忘了引你进门，快进来吧。");
		call_out("command_me",2,"go north");
		call_out("mess1", 2, me);
		call_out("command_me",6,"go north");
		call_out("command_me",7,"say 过了这个花园，你就能见到我们庄主了。\n");
		call_out("command_me",10,"go north");
		call_out("mess2", 13, me);
		call_out("go_back", 15, ob, me);
	}
}

int ask_me()
{
	object ob, me;
	ob=this_object();
	me=this_player();
	
		if (((!ob->query_temp("player")) && (me->query(NEWBIE_VILLAGE_INDEX)==get_questindex("ask yahuan about 葫芦，向丫鬟询问有关“葫芦”的事情"))))
		{
			message_vision(GRN"丫鬟见$N手中的葫芦，惊诧地「咦？」了一声。
她转而眉开眼笑，两手举起来，高兴地「呀！」地跳了起来！显得大为惊喜。
一转身跑到里面去了。\n\n"NOR, me);
			call_other(environment(),"close_gate");
			set_nextquest(me , "ask yahuan about 葫芦，向丫鬟询问有关“葫芦”的事情", "你怔怔地站在那里不知所措，不如再去敲敲门，向她问个究竟", 20, 100);
			return 1;
		}
	    else
		{
			return 0;
		}
}

int command_me(string arg)
{
	command(arg);
	return 1;
}

void mess1(object me)
{
	message_vision("\n那丫鬟看$N乖乖地跟着她，她轻移莲步，笑盈盈地向庄内跑去。\n", me);
}

void mess2(object me)
{
	message_vision(GRN"\n丫鬟敛起了脸上的笑容，恭敬地对端坐在厅中的中年人道：
“庄主，这个人把那个葫芦找了回来……”
那庄主抬头微笑地望向$N，盯着你看了半天，起立躬身做了个揖，说道：
“这葫芦是一个庄丁去采药时遗失的，多谢"+RANK_D->query_respect(me)+"劳心找回。”
丫鬟转过头来瞧着$N，示意$N赶紧把葫芦给这位庄主。\n"NOR, me);
}

void go_back(object ob,object me)
{
	ob->set_temp("player",0);
	me->set_leader(0);

	command("go south");
	command("go south");
}
