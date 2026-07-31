// created 11/22/1997 by snowcat
#include <ansi.h>

inherit NPC;

void create()
{
  set_name("公主", ({"gong zhu", "zhu", "princess"}));
  set("title", "天竺国");
  set("gender", "女性");
  set("age", 20);
  set("attitude", "peaceful");
  set_level(110);

  set_skill("dodge",1100);
  set_skill("parry",1100);
  set_skill("force",1100);
  set_skill("spells",1100);
  set_skill("unarmed",1100);
  set_skill("staff",1100);
  set_skill("moonshentong",1100);
  set_skill("moonforce",1100);
  set_skill("moondance",1100);
  set_skill("baihua-zhang",1100);
  map_skill("unarmed", "baihua-zhang");
  map_skill("force", "moonforce");
  map_skill("spells", "moondance");
  set("eff_dx",-90000);
  set("nkgain",90);

  set("force_factor", 120);
  set("mana_factor", 120);
  setup();
  carry_object("/d/obj/cloth/gongpao")->wear();
  carry_object("/d/qujing/tianzhu/obj/pixie")->wear();
  carry_object("/d/qujing/tianzhu/obj/zuanjie")->wear();
}

int accept_fight (object ob)
{
  ob->apply_condition ("killer",100);
  kill_ob (ob);
  return 1;
}

void kill_ob (object ob)
{
  set_temp("no_return",1);
  set_temp("my_killer",ob);
  ::kill_ob(ob);
  call_out ("move_to_cave",5+random(10),this_object());
}

void move_to_cave (object me)
{
  object where = environment(me);
  string location = "/d/qujing/maoying/tuxue1";
  object room;
  int i = 9;

  while (i--)
  {
    location[strlen(location)-1] = '1'+random(3);
    room = load_object(location);
    if (room != where)
    break;
  }

  if (me->is_fighting())
  {
    message_vision ("$N往旁边一跳，一转眼已无踪无影！\n",me);
    me->move(room);
  }
}

void unconcious()
{
  object ob = query_temp("my_killer");
  object me = this_object();

  if (ob)
  {
    ob->set_temp("obstacle/tianzhu_killed",1);
  }
  message_vision ("\n$N现了原形，竟是一只玉兔。\n",me);
  message_vision ("只听远远地传来太阴星君的怒斥：“玉兔儿！”\n",me);
  message_vision ("\n玉兔闻声乖乖地向外跳去。\n",me);
  destruct(me);
}

void die()
{
  unconcious();
}