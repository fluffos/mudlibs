#include <ansi.h>

  void unconcious()
{
  die();
}

void powerup()
{
object me = this_object();
message_vision(HIY"方舟给于我力量吧"NOR,me);
me->set("kee",query("max_kee"));
me->set("eff_kee",query("max_kee"));
me->set("sen",query("max_sen"));
me->set("eff_sen",query("max_sen"));
me->set("force",query("max_force"));
me->set("mana",query("max_mana"));
me->clean_condition();
return;
}

