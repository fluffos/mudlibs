/* _backstab.c
 * /cmds/skills
 * originally coded by ? on ?
 * modified by Bohemund on 9 March 1994
 * rewriten by Gregon@Nightmare June 1994 
 *   in accordance with law and approval requests: 
 *     only one attack
 *     socket available for items to attenuate backstab strength
 *     minor bugs eliminated
 *     can now aim for a limb and all damage is taken off some limb
 */
 
#include <std.h>
#define XX "%^BOLD%^RED%^"
 
inherit DAEMON;
 
int cmd_backstab(string str) {
  string who, limb, vicname, bsname, *limbs, hitlimb,knifname;
  object *weapons, *knives, victim, here, tmp_ob, *tmp_obs;
  int i, damage, tmp, murder, dex, vicdex, prot;
  
  if(!str) {
    notify_fail("Correct syntax: backstab victim [limb]\n");
    return 0;
  }
  if(this_player()->query_ghost()) {
    notify_fail("You cannot do that in your present immaterial state.\n");
    return 0;
  }
  if(this_player()->query_disabled()) return 1;
  if(environment(this_player())->query_property("no attack")) {
    notify_fail("You may not attack in this place.\n");
    return 0;
  }
  if(murder=(int)this_player()->query_skill("murder") < 5) {
    notify_fail("You aren't skilled enough to do that.\n");
    return 0;
  }
  if(sscanf(str,"%s %s",who,limb)!=2) {
    who=str;
    limb=0;
  }
 
  if(!(victim = present(lower_case(who),here=environment(this_player())))) {
    notify_fail("You don't see that target here.\n");
    return 0;
  }
  if(victim == this_player()) {
    notify_fail("Backstab yourself?\n");
    return 0;
  }
  if(victim->query_ghost()) {
    notify_fail("Backstab a ghost?\n");
    return 0;
  }
  if(!living(victim)){ 
    notify_fail("You would look pretty silly backstabbing that.\n");
    return 0;
  }
 
  vicname=victim->query_cap_name();
  if(limb && member_array(limb,limbs=(string *)victim->query_limbs()) == -1) {
    notify_fail(vicname+" does not have a "+limb+".\n");
    return 0;
  }
 
  if(victim->query_property("no backstab")) {
    notify_fail(vicname+" is immune to your backstab.");
    return 0;
  }
 
  knives = ({});
  weapons = (object *)this_player()->query_wielded();
 
  for(i=0, tmp = sizeof(weapons); i<tmp; i++) {
    if((string)weapons[i]->query_type() != "knife") continue;
    knives += ({ weapons[i] });
  }
  if(!sizeof(knives)) {
    write("You are not well equipped for backstabbing.");
    return 1;
  }
  this_player()->set_disabled();
  if(member_array(victim, (object *)this_player()->query_hunted()) != -1 ||
     member_array(victim, (object *)this_player()->query_attackers())!=-1) {
    notify_fail("You have lost the element of surprise!\n");
    return 0;
  }
  if(tmp_ob = (object)this_player()->query_current_attacker()) {
    notify_fail(sprintf("You are already in combat with %s.",
      (string)tmp_ob->query_cap_name()));
    return 0;}
 
  if(victim->is_player() && !interactive(victim)) return 0;
 
  if(!this_player()->kill_ob(victim, 0)) return 1; 
 
  bsname=(string)this_player()->query_cap_name();
  if((int)this_player()->query_stats("dexterity") + 5 < 
                              (int)victim->query_stats("dexterity")){
    message("my action", XX+vicname+" sees your attempted backstab and "
            "evades it!%^RESET%^", this_player());
    message("other action",XX+bsname+
            " just tried to backstab you!  Luckily, you are too fast for "+
            this_player()->query_objective()+".", victim);
    if(!victim->is_player()) victim->kill_ob(this_player(),0);
    return 1;
  }
 
  message("my_action",XX+"You backstab "+vicname+"!",this_player());
  tell_room(here,XX+bsname+" backstabs "+vicname+"!", 
	    ({ victim, this_player() }) );
  message("other action",XX+bsname+" backstabs you!",victim);
 
//in an item set_property("no backstab", x) will cause the damage done by the
//backstab to be reduced by x percent
  for(i=0;i<sizeof(tmp_obs=all_inventory(victim));i++) {
    if(tmp=tmp_obs[i]->query_property("no backstab") && tmp > prot) tmp=prot;
  }
 
  damage = murder;
  damage += (int)this_player()->query_sp()/5;
  damage -= vicdex=(int)victim->query_stats("dexterity");
  damage += dex=(int)this_player()->query_stats("dexterity");
  damage += (int)this_player()->query_skill("knife");
  this_player()->add_skill_points("murder",5);
  
    this_player()->set_backstab(sizeof(knives));
  for(i=0; i<sizeof(knives); i++) {
   if(limb && random(100) < (murder-vicdex) ) hitlimb=limb;
   else hitlimb=(string)victim->return_target_limb();
   knifname=(string)knives[i]->query_short();
 
   if(random(110)>((int)this_player()->mobility(0)+35+dex)) {
//almost the same way hits are determined in the game, with a slight bonus
//since have element of surprise
     message("other_combat",XX+capitalize(knifname)+" barely misses your "+
              hitlimb+".",victim);
     message("my_combat", XX+"You miss "+ vicname+"'s "+hitlimb+" by inches.",
             this_player());
     tell_room(here,bsname+" barely misses "+vicname+"'s "+hitlimb+".",
               ({victim,this_player()}) );
   }
   else {
     message("other_combat",XX+capitalize(knifname)+" tears into your "+
             hitlimb+"!",victim);
     message("my_combat",XX+"You slash into "+vicname+"'s "+hitlimb+" with "+
             knifname+"!",this_player());
     tell_room(here,bsname+" slashes "+vicname+"'s "+hitlimb+" with "+knifname+
               "!",({this_player(),victim}) );
//damage tally done here and exacted with a socket for devices or monsters 
//which can attenuate the damage
 
     damage = damage/2 +random(damage/2);
     damage -= victim->query_current_protection(hitlimb);
     if(prot) damage-=damage/prot;   
     victim->do_damage(hitlimb,damage);
      victim->check_on_limb(hitlimb);
    
   }
  }
  this_player()->add_alignment(-5);
  return 1;
}
 
void help() {
  write("Syntax: backstab <enemy> [limb]\n\n"
	"This command is used to initiate combat with the "
	"monster or player you specify. Optionally, you can add a limb "
        "to aim for on the victim.\n");
}
