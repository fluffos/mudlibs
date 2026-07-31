// created 11/22/1997 by snowcat
#include <ansi.h>

inherit NPC;
#include "/d/migong/romnpc2.c"
void create()
{
  set_name("国丈", ({"guo zhang", "zhang"}));
  set("title", "玉面道人");
  set("gender", "男性");
  set("age", 60);
  set("attitude", "peaceful");
  set("combat_exp", 1230000);
  set("combat_exp", 55800000);

  map_skill("staff", "lunhui-zhang");
  set("eff_dx",-90000);
  set("nkgain",90);

  set("max_jing", 331200);
  set("max_qi", 331200);
  set("max_jing", 331200);
  set("neili", 331200);
  set("max_neili", 331200);
  set("neili", 331200);
  set("max_neili", 331200);
  set("force_factor", 120);
  set("mana_factor", 120);
  setup();
  initlvl((600+random(600)),52);
  carry_object("/d/obj/cloth/gongpao")->wear();
  carry_object("/d/qujing/biqiu/obj/staff")->wield();
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
  call_out ("move_to_cave",1,this_object());
}

void move_to_cave (object me)
{
  object where = environment(me);
  object room = load_object("/d/qujing/biqiu/dong");

  if (! where ||
      where->query("short") == "清华洞")
    return;
 
  message_vision ("\n忽然间狂风四起，天昏地暗！\n",me);
  message_vision ("等你恍恍惚惚睁开眼时，$N已无踪无影！\n",me);
  me->move(room);
}

void unconcious()
{
  object ob = query_temp("my_killer");
  object me = this_object();
object king = new ("/d/qujing/biqiu/npc/king");
  if (ob)
  {
    ob->set_temp("obstacle/biqiu_guozhang",1);
  king->announce_success (ob);
  destruct (king); 
  }
  message_vision ("\n$N现了原形，竟是一只白鹿往天上慌慌张张地蹿去。\n",
                  me);
  message_vision ("天上传来南极老人的怒斥：“孽鹿！连老夫的拐杖也偷了去！\n\n",
                  me);
::die();
}



void destruct_me(object me)
{
  destruct(me);
}

void die()
{
  unconcious();
}

