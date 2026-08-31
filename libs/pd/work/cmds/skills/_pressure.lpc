//By Daboura
// Loosly based on disease

#include <std.h>
#include <daemons.h>
#include <damage_types.h>
#include <damage.h>
inherit DAEMON;

void help() 
{
  write("Syntax: <pressure [(living)]>\n"
   "A more powerful wizard can boil the blood "
   "of their opponent, causing them great "
   "pain and harm. It is an evil spell.\n");
}

int spell() 
{
  object tp, ob;
  tp = this_player();

  if (!tp) return 0;
  if (tp->query_subclass() != "wizard") return 0;
  if (tp->query_level() < 40) return 0;
  if (tp->query_skill("conjuring") < 180) return 0;
  if (tp->query_skill("wizardry") < 240) return 0;
  return 1;
}

string type() { return "attack"; }

int spell_hit(object, object, int, int);

int cmd_pressure(string str) 
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

  if((int)tp->query_mp() < 150) 
  {
    return notify_fail("Too low on magic power.\n");
  }

  if (str) ob = present(str, environment(tp));
  else ob = tp->query_current_attacker();

  if (!ob) return notify_fail("Cause pressure on whom?");

  if(!living(ob)) 
  {
    notify_fail(ob->query_cap_name()+" is not a living thing!\n");
    return 0;
  }
  if(ob == tp) 
  {
    return notify_fail("THat would not be wise.\n");
  }

  if(ob->is_player() && !interactive(ob)) 
  {
    notify_fail("You cannot attack link-dead players.\n");
    return 0;
  }
  if(ob->query("fog123"))
  {
    return notify_fail("The fog blocks your spell!\n");
  }
  if(ob->query("pres123"))
  {
    return notify_fail("The pressure is already upon them!\n");
  }
  if(!tp->kill_ob(ob)) 
  {
    write(ob->query_cap_name()+" can't be attacked by you yet.");
    return 1;
  }

  attack = BALANCE3_D->get_damage( tp, ob, 3, ({ "magic attack", "wizardry", "wizardry", "conjuring" }),
   ({ "intelligence", "wisdom", "intelligence" }), ({ "wizardry", "conjuring" }) );
  if(attack < 10) attack = 10;
  attack = attack/2;

  rounds = 3;

  write("%^ORANGE%^You throw your hands to your side and %^BOLD%^%^BLACK%^clench%^RESET%^%^ORANGE%^ your fists %^BOLD%^%^RED%^tight%^RESET%^%^ORANGE%^, suddenly "
   +ob->query_cap_name()+ " begins to yell in %^BOLD%^RED%^pain%^RESET%^%^ORANGE%^!%^RESET%^\n");

  message("target", "%^ORANGE%^" +tp->query_cap_name()+ " throws "
   +tp->query_possessive()+ " hands down to " +tp->query_possessive()+
   " side and clenches " +tp->query_possessive()+ " fists %^BOLD%^%^BLACK%^tight%^RESET%^%^ORANGE%^, suddenly you feel like your %^BOLD%^%^RED%^blood%^RESET%^%^ORANGE%^ is %^BLUE%^b%^RED%^o%^BLUE%^i%^RED%^l%^BLUE%^i%^RED%^n%^BLUE%^g%^RESET%^%^ORANGE%^!",
   ob);

  message("room", "%^ORANGE%^" +tp->query_cap_name()+ " throws "
   +tp->query_possessive()+ " hands down to " +tp->query_possessive()+
   " side and clenches " +tp->query_possessive()+ " fists %^BOLD%^%^BLACK%^tight%^RESET%^%^ORANGE%^, suddenly " 
   +ob->query_cap_name()+
   "begins to yell in %^BOLD%^RED%^pain%^RESET%^%^ORANGE%^!%^RESET%^",
   environment(tp), ({tp,ob}));


  tp->add_skill_points("wizardry", (attack/20));
  tp->add_alignment(-5+random(5));
  tp->add_skill_points("conjuring", (attack/20));
  tp->add_mp(-BALANCE3_D->get_cost(attack, 3, "mp"));

  if(!ob || environment(ob) != environment(tp)) 
  {       
    return 1;
  }
  ob->set("pres123", 1);
  call_out("spell_hit",1, ob, tp, attack, rounds);

  return 1;
}


int spell_hit(object ob, object tp, int attack, int rounds) 
{
  if(!ob || !tp)
  {       
    return 1;
  }
  if(environment(ob) != environment(tp))
  {
    ob->set("pres123", 0);
    return 1;
  }
  message("target", "%^BOLD%^%^RED%^Your blood boils, causing you to bleed everywhere!%^RESET%^", ob);

  message("room", "%^ORANGE%^Blood pours out of "+ob->query_cap_name()+" causing " 
   +ob->query_objective()+ " to scream in pain!%^RESET%^"
   , environment(tp), ob);  

  ob->do_damage("none", attack, DAMAGE_MAGIC, DAMAGE_NO_SEVER | DAMAGE_BYPASS_ARMOUR, tp);
  attack = attack/2;

  ob->force_me("scream");
  if (rounds > 0)
  {
    rounds--;
    call_out("spell_hit",2, ob, tp, attack, rounds);
  }
  else
  {
    ob->set("pres123", 0);
  }   
  return 1;
}
