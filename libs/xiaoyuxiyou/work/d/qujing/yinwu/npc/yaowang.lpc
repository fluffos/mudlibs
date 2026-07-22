// created 11/22/1997 by snowcat
#include <ansi.h>

inherit NPC;

void create()
{
  set_name("妖王", ({"yao wang", "wang"}));
  set("title", "连环洞");
  set("gender", "男性");
  set_level(78);
  set("attitude", "peaceful");

  set_skill("dodge",780);
  set_skill("parry",780);
  set_skill("force",780);
  set_skill("spells",780);
  set_skill("unarmed",780);
  set_skill("gouhunshu",780);
  set_skill("tonsillit",780);
  set_skill("ghost-steps",780);
  set_skill("jienan-zhi",780);
  set_skill("lunhui-zhang",780);
  map_skill("unarmed", "jienan-zhi");
  map_skill("force", "tonsillit");
  map_skill("spells", "gouhunshu");
  set("eff_dx",-90000);
  set("nkgain",90);

  set("force_factor", 120);
  set("mana_factor", 120);
  setup();
  carry_object("/d/obj/cloth/shoupiqun")->wear();
}

void die()
{
  object me = this_object();
  message_vision ("\n$N瘫痪在地，竟是一只艾叶花皮豹子。\n它朝你瞅了一眼，摇摇尾巴跑走了。\n",me);
  destruct(me);
}

void unconcious()
{
  die();
}