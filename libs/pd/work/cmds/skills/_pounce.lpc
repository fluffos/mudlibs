#include <std.h>
#include <daemons.h>
#include <damage_types.h>
#include <damage.h>

inherit DAEMON;

int abil();

string type() { return "attack"; }

int cmd_pounce(string str) {
  object victim;
  int i, tmp;

  if (!abil()) 
    return notify_fail("What?\n");

  if(!str)
    return notify_fail("Pounce whom?\n");

  if (this_player()->query_rest_type())
    return notify_fail("You are not in a position to perform that action\n");

  if(this_player()->query_ghost())
    return notify_fail("You appear to be dead.\n");

  if(this_player()->query_busy()) return notify_fail("You are busy.");

  if(environment(this_player())->query_property("no attack"))
    return notify_fail("Some mystical force prevents you from that.\n");

  if(this_player()->query_sp() < 25)
    return notify_fail("You are too tired to pounce on your victim.\n");

  if(!(victim = present(lower_case(str),environment(this_player())))) 
    return notify_fail("You do not see that here.\n");

  if(victim == this_player())
    return notify_fail("Pounce on yourself?\n");

  if(!living(victim))
    return notify_fail("You can not pounce on that.\n");

  if(member_array(victim, (object *)this_player()->query_hunted()) != -1 ||
   member_array(victim, (object *)this_player()->query_attackers())!=-1) {
    return notify_fail("You have lost the element of surprise!\n");
  }

  if(this_player()->query_current_attacker())
    return notify_fail("You are already in combat with something else!\n");

  if(victim->is_player() && !interactive(victim)) return 0;

  if (victim->query_skill("perception") + victim->query_stats("wisdom") >
   this_player()->query_skill("nature"))
    tell_object(victim, ""+this_player()->query_cap_name()+" attempts to sneak behind you unnoticed!");

  this_player()->set_paralyzed(1,"You are concentrating on your meal.");

  call_out("do_dmg", 1, victim, this_player());

  write("You sneak around behind "+victim->query_cap_name()+"!");

  return 1;
}
int do_dmg(object victim) {
  int i, tmp, dex;
  object  tp;
  string tt, tk;
  int j, spUse;
  float mod = 0;

  if (!victim){
    write("Your meal is not here.");
    tell_room(environment(this_player()), this_player()->query_cap_name()+" snarls.", ({ this_player() }));
    return 1;
  }

  if (environment(this_player()) != environment(victim)){
    write("Your meal is not here.");
    tell_room(environment(this_player()),
     this_player()->query_cap_name()+" snarls.", ({ this_player() }));
    return 1;
  }

  if(!this_player()->kill_ob(victim)) {
    write(victim->query_cap_name()+" can't be attacked by you yet.");
    return 1;
  }

  if (random(victim->query_stats("dexterity")/2) +
   (victim->query_stats("dexterity")/2) >
   this_player()->query_stats("dexterity") + 5 ) 
  {
    write("You miss your pounce!");
    say(this_player()->query_cap_name()+" misses an attempt to pounce on "
     +(string)victim->query_cap_name(), victim);
    tell_object(victim, ""+this_player()->query_cap_name()+" misses an attempt to pounce on you!");
    return 1;
  }



  tt = victim->return_target_limb();

  write("You pounce on "+victim->query_cap_name()+"!");

  write("You sink your claws deep into "+(string)victim->query_cap_name() + "'s "+tt+"!");
  say(""+this_player()->query_cap_name() +"'s pounce on "+victim->query_cap_name() 
   + " hits its mark!", victim);
  tell_object(victim, ""+this_player()->query_cap_name()+"'s claws sink deep into you!");

  /****( Damage: )***********************************************/

  j = BALANCE3_D->get_damage( this_player(), victim, 4, ({ "attack", "melee", "melee" }),
   ({ "dexterity", "dexterity", "strength" }), ({"dexterity", "strength"}) );    
  j = j * 1.7;
  /**************************************************************/

  this_player()->add_skill_points("attack", j/20);
  this_player()->add_skill_points("melee", j/25);

  victim->do_damage("target", j, this_player()->query_unarmed_damage_type() | DAMAGE_PIERCE,
    this_player()->query_unarmed_damage_flags(), this_player() );

  this_player()->add_sp(-BALANCE3_D->get_cost(j, 4, "sp"));

  if(victim->query_hp() < 0)
    victim->heart_beat();
  return 1;
}

void help() {
  write("Syntax: pounce <enemy>\n\n"
   "A lion can pounce on the target and sink their "
   "claws deep into the victim.\n"
  );
}

int abil() {
  object tp;
  tp = this_player();
  if(!tp->query("lion")) return 0;
  if(tp->query_level() < 65) return 0;
  return 1;
}
