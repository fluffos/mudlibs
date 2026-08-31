//By Daboura
// Loosly based on disease

#include <std.h>
#include <daemons.h>
#include <damage_types.h>
#include <damage.h>
inherit DAEMON;

void help() 
{
  write("Syntax: <fog [(living)]>\n"
   "The wizard creates a poisonous fog "
   "around the target, causing the target "
   "damage as they breathe.\n");
}

int spell() 
{
  object tp, ob;
  tp = this_player();

  if (!tp) return 0;
  if (tp->query_subclass() != "wizard") return 0;
  if (tp->query_level() < 15) return 0;
  return 1;


  return 1;
}


string type() { return "attack"; }

int spell_hit(object, object, int, int);

int cmd_fog(string str) 
{
  object tp, ob;
  int attack, wisdom, skip, which, i, rounds;
  string what, *strengths, *weaknesses;
  object *inv;

  rounds = 0;

  if (!spell()) 
  {
    write("What?\n");
    return 1;
  }

  tp = this_player();

  if(tp->query_ghost()) 
  {
    return notify_fail("Your voice is hollow.\n");
  }
  if (this_player()->query_busy())
    return notify_fail("You are busy.\n");

  if(environment(tp)->query_property("no magic")) 
  {
    notify_fail("Something seems to be blocking your concentration.\n");
    return 0;
  }
  if(environment(tp)->query_property("no attack")) 
  {
    notify_fail("Something seems to be blocking your concentration.\n");
    return 0;
  }

  if((int)tp->query_mp() < 50) 
  {
    return notify_fail("Too low on magic power.\n");
  }

  if (str) ob = present(str, environment(tp));
  else ob = tp->query_current_attacker();

  if (!ob) return notify_fail("Cast fog around whom?");

  if(!living(ob)) 
  {
    notify_fail(ob->query_cap_name()+" is not a living thing!\n");
    return 0;
  }
  if(ob == tp) 
  {
    return notify_fail("That would not be wise.\n");
  }

  if(ob->is_player() && !interactive(ob)) 
  {
    notify_fail("You cannot attack link-dead players.\n");
    return 0;
  }

  if(!tp->kill_ob(ob)) 
  {
    write(ob->query_cap_name()+" can't be attacked by you yet.");
    return 1;
  }
  if(ob->query("fog123"))
  {
    return notify_fail("The fog already surrounds them!\n");
  }
  if(ob->query("pres123"))
  {
    return notify_fail("Some strange force prevents it!\n");
  }

  attack = BALANCE3_D->get_damage( tp, ob, 1,
   ({ "magic attack", "wizardry", "wizardry", "conjuring" }),
   ({ "intelligence", "wisdom", "intelligence" })
  );
  if(attack < 10) attack = 10;
  if(attack > 400) attack = 400 + tp->query_level();
  attack = attack/2;

  rounds = 3;

  write("%^ORANGE%^You extend your pointer finger, and a mass of %^GREEN%^c%^MAGENTA%^o%^GREEN%^l%^MAGENTA%^o%^GREEN%^r%^MAGENTA%^e%^GREEN%^d %^MAGENTA%^f%^GREEN%^o%^MAGENTA%^g %^ORANGE%^comes from it and rushes toward "
   +ob->query_cap_name()+ ", surrounding them!%^RESET%^\n");

  message("target", "%^ORANGE%^" +tp->query_cap_name()+ " points at you, and from "
   +tp->query_possessive()+ " finger tip comes a rush of %^GREEN%^c%^MAGENTA%^o%^GREEN%^l%^MAGENTA%^o%^GREEN%^r%^MAGENTA%^e%^GREEN%^d %^MAGENTA%^f%^GREEN%^o%^MAGENTA%^g%^ORANGE%^, surrounding you!%^RESET%^\n",
   ob);

  message("room", "%^ORANGE%^" +tp->query_cap_name()+ " points " +tp->query_possessive()+
   " finger at " +ob->query_cap_name()+ ", and from it comes a rush of %^GREEN%^c%^MAGENTA%^o%^GREEN%^l%^MAGENTA%^o%^GREEN%^r%^MAGENTA%^e%^GREEN%^d %^MAGENTA%^f%^GREEN%^o%^MAGENTA%^g%^ORANGE%^!%^RESET%^\n",
   environment(tp), ({tp,ob}));


  ob->add_poisoning(attack/10);

  // don't set this, so we can cast another spell same round
  //tp->set_magic_round(1);
  tp->add_skill_points("wizardry", (attack/20));
  tp->add_alignment(-(2+random(2)));
  tp->add_skill_points("conjuring", (attack/20));
  tp->add_mp(-BALANCE3_D->get_cost(attack, 1, "mp")*2/3);


  if(!ob || environment(ob) != environment(tp)) 
  {       
    return 1;
  }
  ob->set("fog123", 1);
  call_out("spell_hit",1, ob, tp, attack, rounds);

  return 1;
}

int spell_hit(object ob, object tp, int attack, int rounds) 
{
  if(!ob || !tp) 
  {       
    return 1;
  }
  if(ob && tp)
    if(environment(ob) != environment(tp))
    {
      ob->set("fog123", 0);
      return 1;
    }
  message("target", "%^BOLD%^%^RED%^You breathe in a poisonous fog that surrounds you!%^RESET%^", ob);

  message("room", "%^ORANGE%^"+ob->query_cap_name()+" hacks and weezes as " +ob->query_subjective()+ " breathes in the fog surrounding "
   +ob->query_objective()+"!%^RESET%^", environment(tp), ob);  

  ob->do_damage("none", attack, DAMAGE_MAGIC | DAMAGE_POISON, DAMAGE_NO_SEVER | DAMAGE_BYPASS_ARMOUR, tp);
  attack = attack/2;

  ob->force_me("cough");
  if (rounds > 0)
  {
    rounds--;
    call_out("spell_hit",2, ob, tp, attack, rounds);
  }
  else
  {
    ob->set("fog123", 0);
  }   
  return 1;
}
