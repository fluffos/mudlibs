// modified by smile 12/12/1998
#include <ansi.h>

inherit NPC;
#include "/d/migong/romnpc2.c"
void create()
{
  set_name("老妇人", ({"fu ren", "fu", "ren"}));
  set("gender", "女性");
    set("long",@LONG
两鬓如冰雪，行步需怯怯。
弱体瘦伶仃，脸如枯菜叶。
颧骨望上翘，嘴唇往下别。
LONG);
  set("age", 80);
  set("con", 20);
  set("cor", 20);
  set("int", 20);
  set("per", 30);
  set("attitude", "peaceful");
  set("combat_exp", 512000);
  set_skill("dodge", 70);
  set_skill("parry", 70);
  set_skill("force", 70);
  set_skill("spells", 70);
  set_skill("unarmed", 70);
 
  set("max_jing", 850);
  set("max_qi", 900);
  set("max_jing", 700);
  set("neili", 950);
  set("max_neili",950);
  set("neili", 980);
  set("max_neili", 1500);
  set("force_factor", 70);
  set("mana_factor", 75);
  setup();
      initlvl((350+random(350)),5);
  carry_object("/d/obj/cloth/skirt")->wear();
  carry_object("/d/qujing/baigudong/obj/zhuzhang");
}

void init()
{
  object me = this_object();
  object who = this_player();
  object where = environment(me);

  ::init();

  if (present("nu zi",where) ||
      present("fu ren 2",where) ||
      present("gong gong",where))
  {

    call_out ("destruct_me",1,me);  
  }
  else
  {
    remove_call_out ("greeting");
    call_out ("greeting",1,me,who);
  }
}

void destruct_me (object me)
{
  destruct (me);
}

void greeting (object me, object who)
{
  if (me->is_fighting())
    return;

  if (! who ||
      environment(who) != environment(me))
    return;

  message_vision ("$N对$n说道：唉，可见吾小女？\n",me,who);
}

void unconcious()
{
  die();
}

void die()
{
  object me = this_object();
  object where = environment(me);
  object ob = query_temp("my_killer");
  object corpse;

  if (ob)
    ob->set_temp("obstacle/baigudong_furen_killed",1);
  message_vision ("\n$N一声惨叫，扑翻在地死了。\n",me);
  command ("drop zhu zhang");
::die();
}

void continuing (object me, object where)
{
  object gonggong = new (__DIR__"gonggong");

  gonggong->move(where);
  destruct (me);
}

void kill_ob (object ob)
{
  set_temp("my_killer",ob);
  ::kill_ob(ob);
}
 
