// long2.c
// created 6-6-97 pickle

#include <skill.h>

inherit NPC;
//inherit F_MASTER;

void create()
{
  set_name("狴犴",({"bi an","bi","an","long","bian","dragon"}));
  set("long","龙生九子不成龙，各有所好：狴犴乃第二子，平生好讼。\n");
  set("gender", "男性");
  set("age", 39);
  set("title", "龙王九子之");
  set("class","dragon");
  set("attitude", "peaceful");
  set("max_kee", 1200);
  set("max_sen", 1000);
  set("force",1000);
  set("max_force", 1000);
  set("force_factor", 80);
  set("max_mana", 900);
  set("mana", 900);
  set("mana_factor",40);

  set("str",30);
  set("con",30);
  set("per",10+random(10));
  set("bellicosity",500);
  set("cor",30);

  set("combat_exp", 900000+random(100000));
  

        set("nkgain", 400);

  setup();  

  carry_object("/d/obj/armor/yinjia")->wear();
  carry_object("/d/xiyou/sea/obj/dragonblade")->wield();
  carry_object("/d/xiyou/sea/obj/longzhu2");
}

int accept_fight(object me)
{
  command("consider");
  command("grin");
  command("say 我作天丢了一颗明珠，一定是你这"+RANK_D->query_rude(me)+"偷的！");
  command("kill "+ me->query("id"));
  return 1;
}




