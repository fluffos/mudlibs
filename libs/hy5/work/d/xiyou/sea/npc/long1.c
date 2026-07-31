#include <skill.h>

inherit NPC;

void create()
{
  set_name("蒲牢",({"pu lao","pu","lao","long","pulao","dragon"}));
  set("long","龙生九子不成龙，各有所好：蒲牢乃第一子，平生好鸣。\n");
  set("gender", "男性");
  set("age", 41);
  set("title", "龙王九子之");
  set("class","dragon");
  set("attitude", "peaceful");
  set("max_kee", 1200);
  set("max_sen", 1000);
  set("force", 1000);
  set("max_force", 1000);
  set("force_factor", 60);
  set("max_mana", 800);
  set("mana", 1000);
  set("mana_factor", 30);

  set("str",30);
  set("con",30);
  set("per",10+random(10));
  set("bellicosity",500);
  set("cor",30);

  set("combat_exp", 900000+random(100000));
 

        set("nkgain", 400);

  setup();  

  carry_object("/d/obj/armor/yinjia")->wear();
  carry_object("/d/xiyou/sea/obj/dragonspear")->wield();
  carry_object("/d/xiyou/sea/obj/longzhu1");
}

int accept_fight(object me)
{
  command("jump");
  command("say 我最喜欢打架了。咱们比划比划！");
  return 1;
}


