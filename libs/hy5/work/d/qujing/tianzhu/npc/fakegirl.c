// created 11/22/1997 by snowcat
#include <ansi.h>

inherit NPC;
#include "/d/migong/romnpc2.c"
void create()
{
  set_name("¹«Ö÷", ({"gong zhu", "zhu", "princess"}));
  set("title", "ÌìóÃ¹ú");
  set("gender", "Å®ĞÔ");
  set("age", 20);
  set("attitude", "peaceful");
  set("combat_exp", 900000);
  set("combat_exp", 66800000);

  set_skill("dodge", 200);
  set_skill("parry", 200);

  set("eff_dx",-90000);
  set("nkgain",90);

  set("max_jing", 1200);
  set("max_qi", 1200);
  set("max_jing", 1200);
  set("neili", 1200);
  set("max_neili", 1200);
  set("neili", 1200);
  set("max_neili", 1200);
  set("force_factor", 120);
  set("mana_factor", 120);
  setup();
  initlvl((860+random(860)),15);
  carry_object("/d/obj/cloth/gongpao")->wear();
  carry_object("/d/qujing/tianzhu/obj/pixie")->wear();
  carry_object("/d/qujing/tianzhu/obj/zuanjie")->wear();
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
    message_vision ("$NÍùÅÔ±ßÒ»Ìø£¬Ò»×ªÑÛÒÑÎŞ×ÙÎŞÓ°£¡\n",me);
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
  message_vision ("\n$NÏÖÁËÔ­ĞÎ£¬¾¹ÊÇÒ»Ö»ÓñÍÃ¡£\n",me);
  message_vision ("Ö»ÌıÔ¶Ô¶µØ´«À´Ì«ÒõĞÇ¾ıµÄÅ­³â£º¡°ÓñÍÃ¶ù£¡¡±\n",me);
  message_vision ("\nÓñÍÃÎÅÉù¹Ô¹ÔµØÏòÍâÌøÈ¥¡£\n",me);
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

ÿ