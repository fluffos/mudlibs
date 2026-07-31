// created by smile 12/08/1998
#include <ansi.h>

inherit NPC;
#include "/d/migong/romnpc2.c"
void create()
{
  set_name("白骨精", ({"baigu jing", "jing"}));
  set("title", "白骨夫人");
  set("long",@LONG
    白骨夫人乃是千年白骨精修炼成形，前世是怨死鬼魂不
得超生，修炼成形后，怨恨人类，于是发誓要吃尽天下人。
LONG);
 set("gender", "女性");
  set("age", 40);
  set("attitude", "friendly");
  set("combat_exp", 1000000);
  set_skill("dodge", 100);
  set_skill("parry", 100);
  set_skill("force", 100);
  set_skill("spells", 100);
  set_skill("unarmed", 100);
 

  set("max_jing", 1100);
  set("max_qi", 1100);
  set("max_jing", 1100);
  set("neili", 1200);
  set("max_neili", 1200);
  set("neili", 1500);
  set("max_neili", 1500);
  set("force_factor", 100);
  set("mana_factor", 80);

  setup();
  initlvl((350+random(350)),5);
  carry_object("/d/qujing/baigudong/obj/renpipifeng")->wear();
  carry_object("/d/qujing/baigudong/obj/baigugun")->wield();
}

void init ()
{
  object ob = this_player();
  object me = this_object();
  call_out("greeting", 1, ob);
} 

void greeting(object ob)
{
  int bool_var;
  if( !ob || environment(ob) != environment() ) return;
  
  if (ob && interactive(ob))
  {
    bool_var=0;
    if(ob->query("obstacle/baigudong")=="done") return;
    if(ob->query_temp("obstacle/baigudong_nuzi_killed")!=0) bool_var=1;
    if(ob->query_temp("obstacle/baigudong_furen_killed")!=0) bool_var=1;
    if(ob->query_temp("obstacle/baigudong_gonggong_killed")!=0) bool_var=1;
    if(bool_var==1)
     {
      command("consider "+ob->query("id"));
      message_vision ("$N大怒道：又是你个"+RANK_D->query_rude(ob)+"！\n",this_object());
      this_object()->kill_ob(ob);
     }
  }
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

void unconcious()
{
  object ob = query_temp("my_killer");
  object me = this_object();
  object gutou = new("/d/qujing/baigudong/obj/fenkulou");
  object shanshen = new ("/d/qujing/baigudong/npc/shanshen");
  object where;
  where =environment(me);
  if (ob)
  {
    ob->set_temp("obstacle/baigudong_baigujing_killed",1);
  shanshen->announce_success (ob);
  destruct (shanshen); 
  }
  message_vision ("\n$N惨叫一声，化成一堆骷髅，散落在地上。\n",me);
  gutou->move(where);
    command("drop pifeng");
  message_vision (HIY "黑面山神哈哈大笑几声，出现在山壁中！\n\n" NOR,me);
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

