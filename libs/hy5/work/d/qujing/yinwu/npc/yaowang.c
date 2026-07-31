// created 11/22/1997 by snowcat
#include <ansi.h>

inherit NPC;
#include "/d/migong/romnpc2.c"
void create()
{
  set_name("妖王", ({"yao wang", "wang"}));
  set("title", "连环洞");
  set("gender", "男性");
  set("age", 40);
  set("attitude", "peaceful");
  set("combat_exp", 600000);
  set("combat_exp", 60000000);

  set_skill("dodge", 110);
  set_skill("parry", 110);
  set_skill("force", 110);
set("str",200);

  set("max_jing", 12000);
  set("max_qi", 12000);
  set("max_jing", 12000);
  set("neili", 12000);
  set("max_neili", 12000);
  set("neili", 12000);
  set("max_neili", 12000);
  set("force_factor", 120);
  set("mana_factor", 120);
  setup();
  initlvl((700+random(700)),38);
  carry_object("/d/obj/cloth/shoupiqun")->wear();
}

int accept_fight (object ob)
{
  
  kill_ob (ob);
  return 1;
}

void kill_ob (object ob)
{
  set_temp("no_return",1);
  set_temp("my_killer",ob);
  ::kill_ob(ob);
}

void die()
{
  object ob = query_temp("my_killer");
  object me = this_object();
  object where = environment(me);

  if (ob)
  {
    object tudi = new ("/d/qujing/yinwu/npc/tudi");
    ob->set_temp("obstacle/yinwu_yaowang",1);
    tudi->move(where);
    tudi->announce_success(ob);
  }
  message_vision ("\n$N瘫痪在地，竟是一只艾叶花皮豹子。\n",me);
  me->set("name","艾叶花皮豹子");
  ::die();
}

void unconcious()
{
  die();
}

