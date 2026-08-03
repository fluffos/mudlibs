//By toto for XAXY

#include <dbase.h>

void die()
{
	object ob;
	ob=this_object();
  if (environment())
    message("sound", "\n" + ob->query("name")+"大喊一声:木马救命," + ob->query("name") + "又复活了！\n\n", environment());

  set("eff_kee", ob->query("max_kee"));
  set("eff_gin", ob->query("max_gin"));
  set("eff_sen", ob->query("max_sen"));
  set("kee", ob->query("max_kee"));
  set("gin", ob->query("max_gin"));
  set("sen", ob->query("max_kee"));
  set("force", ob->query("max_force"));
  set("mana", ob->query("max_mana"));
}

void unconcious()
{
  die ();
}
