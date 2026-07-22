//Cracked by Roath
 
inherit NPC;
#include <ansi.h>

void create()
{
  set_name("猪怪", ({ "zhu guai","pig" }));
  set("age", 600);
  set("gender", "男性");
  set("long", "一个野猪怪。\n");
  set("attitude", "peaceful");
  set("str", 50);
  set("per", 10);
  set_level(50);
  set("force_factor", 50);
  set("mana_factor", 50);
  set_skill("unarmed",500);
  set_skill("dodge",500);
  set_skill("parry",500);
  set_skill("rake",500);
  set_skill("force",500);
  set_skill("spells",500);
  set_skill("baguazhou",500);
  set_skill("yanxing-steps",500);
  set_skill("skyriver-rake",500);
  map_skill("force", "lengquan-force");
  map_skill("spells", "baguazhou");
  map_skill("rake", "skyriver-rake");
  map_skill("parry", "skyriver-rake");
  map_skill("dodge", "yanxing-steps");
  setup();
  carry_object("/d/kaifeng/obj/jiuchipa")->wield();
  carry_object("/d/obj/armor/tongjia")->wear();
}

void die()
{
  object me = this_object();
  message_vision(HIR"只见$N变成道道金光直冲云霄。\n"NOR,me);
  message_vision(HIR"原来$N是个天官下凡，投错了胎。\n"NOR,me);
  destruct(me) ;
}
