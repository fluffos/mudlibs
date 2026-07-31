// created 12/18/1997 by snowcat

inherit NPC;
#include "/d/migong/romnpc2.c"
void create()
{
  set_name("黄眉老佛", ({ "huangmei laofo", "huangmei", "laofo", "fo" }));
  set("title", "小雷音寺");   
  set("long", "一位面无表情却又精神焕发的老佛。\n");
  set("gender", "男性");
  set("age", 80);
  set("attitude", "heroism");
  set("per", 30);
  set("max_qi", 260000);
  set("max_jing", 260000);
  set("max_jing", 260000);
  set("neili", 360000);
  set("max_neili", 360000);
  set("force_factor", 75);
  set("max_neili", 331600);
  set("neili", 331600);
  set("mana_factor", 75);
  set("combat_exp", 1450000);
  set("combat_exp", 48000000);

  setup();
  initlvl((600+random(600)),48);
  carry_object("/d/obj/cloth/jia_sha")->wear();
  carry_object("/d/qujing/xiaoxitian/obj/mace")->wield();
 carry_object("/d/qujing/xiaoxitian/obj/baoreal");

}

void destruct_me (object me)
{
  destruct (me);
}

void die ()
{
  object me = this_object();
  object ob = query_temp("my_killer");
  object mile = new ("/d/qujing/xiaoxitian/npc/mile");
  object fabao = present ("fabao",me);

  if (ob)
  {
    ob->set_temp("obstacle/xiaoxitian_killed",1);
  mile->announce_success (ob);
  destruct (mile); 
  }
  message_vision ("\n旋风出现，弥勒佛祖走了进来。\n",me);
  message_vision ("\n$N连忙慌着跪了下来，却还身作一黄眉小童。\n",me);
  message_vision ("弥勒佛祖领着黄眉小童走了出去",me);
  if (fabao)
  {
     message_vision ("，丢下一只$n。\n",me,fabao);
     fabao->move(environment(me));
  }
  else
    message_vision ("。\n",me);
::die();
}

void mile_appearing (object who)
{
  


}

void unconcious ()
{
  die ();
}

int accept_fight(object ob)
{
  
  kill_ob(ob);
  return 1;
}

void kill_ob (object ob)
{
  object me = this_object();

  set_temp("my_killer",ob);
  call_out ("hurting",random(5)+5,me,ob);  
  ::kill_ob(ob);
}

void hurting (object me, object ob)
{
  object fabao = present ("fabao",me);

  if (fabao)
    fabao->ji_ob (ob);

  remove_call_out ("hurting");  
  call_out ("hurting",random(10)+10,me,ob);  
}
