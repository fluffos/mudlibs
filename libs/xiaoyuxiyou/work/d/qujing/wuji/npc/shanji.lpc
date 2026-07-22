// by snowcat on 11/5/1997 
inherit NPC;
#include <ansi.h>

void create()
{
  set_name("山姬", ({ "shan ji", "ji" }) );
  set("gender", "女性");
  set_level(45);
  set("daoxing", 250000);

  set("long","一位娇艳迷人的野女子。\n");
  set("age", 20);
  set("attitude", "friendly");

  set_skill("unarmed",450);
  set_skill("dodge",450);
  set_skill("parry",450);
  set_skill("force",450);
  set_skill("spells",450);
  set("force_factor", 50);
  set("chat_chance",10);
  set("chat_msg",({
  	CYN"山姬对着你咯咯地笑着。\n"NOR,
  }));
  setup();
  carry_object("/d/obj/cloth/skirt")->wear();
}

void init ()
{
	object me = this_object();
  	object who = this_player();
  	object where = environment(me);
	if (! interactive(who))
    		return;
  	if (where->query("short")!="山路")
  	{
    		me->set_follow(0);
    		return;
  	}
  	if (me->query("has_followed"))
    		return;
  	me->set("has_followed",1);
  	me->command_function("giggle "+who->query("id"));
  	me->command_function("follow "+who->query("id"));
  	me->set_follow(who);
}

void die ()
{
  object me = this_object();
  object ji = new (__DIR__"ji");
  message_vision ("\n$N身子一软现了原形，竟是一只母山鸡，扑打着翅膀。\n",me);
  ji->move(environment(me));
  destruct (me);
}

void unconcious()
{
  die();
}