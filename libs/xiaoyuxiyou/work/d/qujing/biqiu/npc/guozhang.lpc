// created 11/22/1997 by snowcat
#include <ansi.h>

inherit NPC;

void create()
{
  set_name("国丈", ({"guo zhang", "zhang"}));
  set("title", "玉面道人");
  set("gender", "男性");
  set("age", 60);
  set("attitude", "peaceful");
  set_level(95);

  set_skill("dodge",950);
  set_skill("parry",950);
  set_skill("force",950);
  set_skill("spells",950);
  set_skill("unarmed",950);
  set_skill("staff",950);
  set_skill("gouhunshu",950);
  set_skill("tonsillit",950);
  set_skill("ghost-steps",950);
  set_skill("jienan-zhi",950);
  set_skill("lunhui-zhang",950);
  map_skill("unarmed", "jienan-zhi");
  map_skill("force", "tonsillit");
  map_skill("spells", "gouhunshu");
  map_skill("staff", "lunhui-zhang");
  set("eff_dx",-90000);
  set("nkgain",90);

  set("force_factor", 120);
  set("mana_factor", 120);
  setup();
  carry_object("/d/obj/cloth/gongpao")->wear();
  carry_object("/d/qujing/biqiu/obj/staff")->wield();
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
  call_out ("move_to_cave",1,this_object());
}

void unconcious()
{
  object me = this_object();	
  message_vision ("\n忽然间狂风四起，天昏地暗！\n",me);
  message_vision ("等你恍恍惚惚睁开眼时，$N已无踪无影！\n",me);
  destruct (me); 
}

void die()
{
  unconcious();
}