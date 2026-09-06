// messages by Sora
#include <magic.h>
#include <battle.h>
#include <wizard.h> // for find_thing

string query_name() { return "teleport"; }

int query_cost() { return 50; }

string query_type() { return "wind"; }

int query_num_steps() { return 8; }
string query_step_msg(mapping param) {
   switch (param["step"]) {
      case 0: return "~Name ~verbbegin whistling a high-pitched tune.";
      case 1: return "~Name ~verbbegin quickly moving ~poss left hand around in circles close to ~poss chest, first finger extended.";
      case 2: return "~Name ~verbbegin quickly moving ~poss right hand around in circles close to ~poss chest, first finger extended.";
      case 3: return "~Name ~verbcontinue whistling, and a series of tonics followed by an ascending fifth can be heard, at which point small vortices begin forming around the extended fingers.";
      case 4: return "~Name slowly ~verbmove ~poss left arm while still moving ~poss hand in circles, so that it is pointed at ~targ.";
      case 5: return "~Npos whistling gets even higher than it was before, and the vortex around the left index finger begins spinning faster than before as it begins to grow.";
      case 6: return "~Name slowly ~verbmove ~poss right arm, while still rotating the hand in circles, so that it is now pointed off into the distance.";
      case 7: return "~Npos whistling drops a couple of octaves while continuing to produce a similar tune. The vortex around the right index finger begins spinning faster than before and also begins to grow.";
      case 8: return "Both of ~npos arms stop moving in circles but the vortices, now each the size of a person, continue spinning rapidly.";
      case 9: return "~Npos whistling, back to being rather high-pitched, finally comes to a close with a rising fifth.";
   }
   return 0;
}
string query_fail_msg(mapping param) {
   switch (param["step"]) {
      case 0: return "~Name ~verbtry whistling, but can't get the high notes out.";
      case 1: return "~Name ~verbbring ~poss left hand toward ~poss chest and ~verbbegin spinning it in circles, but ~poss hand bumps into ~poss chest.\nA quick burst of air is emitted from ~poss fingers and blows some dust off to ~npos right.";
      case 2: return "As ~name ~verbbegin moving ~poss right hand in, ~poss extended fingers make contact and a gust of wind comes from the hands, pushing both of them quickly to either side of ~obje.";
      case 3: return "After a series of tonics, a horrible rising sixth is produced.\nA loud pop is heard as both of ~npos arms are pulled together, crossing ~poss chest, so each hand is pointing in the opposite direction.";
      case 4: return "~Name ~verbbegin ~verbmoving ~poss left arm to point at ~targ, but all of the spinning is just too much.";
      case 5: return "~Name ~verbtry to whistle higher, but ~verbcrack on one of the high notes.\nThe vortex slowly fades into oblivion.";
      case 6: return "~Name ~verbbegin to move ~poss right arm, but as it crosses ~poss body it enters the left vortex, accelerating the left arm through the right vortex and causing ~pron to rotate halfway around.";
      case 7: return "~Name ~verbdrop only one octave as ~pron ~verbis whistling this tune.\nThe right vortex begins to rise and the left vortex follows.\nBefore long, neither is visible any longer.";
      case 8: return "~Name ~verbstop moving ~poss right arm but the left arm's vortex keeps increasing in speed and collides with the right vortex, at which time both disappear.\nA rush of air is expulsed from the location of the vortices and ~name ~verbstruggle to keep ~poss balance.";
      case 9: return "~Name ~verbend ~poss whistling on a horrible-sounding rising 6th.\nBoth vortices enlarge rapidly but rapidly get dimmer until they disappear entirely.";
      case 10: return "As the vortices move away from ~name, they are attracted toward each other until they combine and a loud 'pop' is heard as they both disappear.";
   }
   return 0;
}
// need step messagoPes
int query_level() { return 1; }
string query_step_skill(mixed param) {
   int step = param["step"];
   if( step >= query_num_steps() )
      return "magic.mana.wind";
     return ({ "magic.technique.dancing",
           "magic.mana.wind",
           "magic.technique.singing",
           "magic.mana.wind",
           "magic.technique.chanting",
           "magic.mana.wind",
           "magic.technique.dancing",
           "magic.mana.wind" })[step];
}

int query_readiness_requirement() { return 2000; }

int valid_target( mapping param ) {
  if (param["target"]->query_is_living())
    return environment(param["target"]) == environment(param["caster"]);
  else {
    if (param["caster"]->query_is_living())
      return environment(param["target"]) == param["caster"];
    else
      return environment(param["target"]) == param["owner"]; // scrolls, etc...
  }
  return 0;
}

object find_peon(mapping param) {
  object *list = clones("/monsters/human");
  if( !param["caster"]->query_recognize(param["option"]) )
    return 0;
  debug( "recognized name, filtering list", "magic" );
  list = filter(list, (: $1->query_name() == lower_case(param["option"]) :));
  if( sizeof(list) == 1 ) {
    // debug( as_lpc(list[0]) , "magic" );
    return list[0];
  } else {
    // debug( as_lpc(list) , "magic" );
    return 0;
  }
}

string validate_params( mapping param ) {
  object env = param["target"];
  // validate target first
  if (!valid_target( param )) {
    return param["target"]->query_cap_name()+" is not a valid target for teleportation.";
  }

  while (env) {
    if (env->query_var("no_teleport"))
      return "Something prevents you from teleporting from here.";
    env = environment(env);
  }
  // then validate destination
  if (!param["option"])
    return "You really should specify a destination.";
  } else if (!(env = find_player(param["option"])) &&
             !(env = find_peon(param)) || env->query_invis()) {
    return "Could not find any such player or peon "+capitalize(param["option"])+" to teleport to.";
  } else
    param["destination"] = env; // note, parameter is being added to the list

  //debug(as_lpc(param));
  if (param["destination"] == environment(this_player()) || environment(this_player()) == environment(param["destination"])) {
     set_actor(param["target"]);
     set_listener(this_player());
     return process_grammar("~Pron ~verbis already there (which is here). My, but that was quick work.");
  }

  while (env) {
    if (env->query_var("no_teleport")) {
      set_target(param["option"]);
      return "Something is preventing teleportation to " + find_player(param["option"])->query_cap_name() + "'s location.";
    }
    env = environment(env);
  }

  return "ok";
}

// laziness
#define COBJ   ((object)param["caster"])
#define TOBJ   ((object)param["target"])
#define DOBJ   ((object)param["destination"])
#define CNAME   COBJ->query_cap_name()
#define TNAME   TOBJ->query_cap_name()
#define DNAME   DOBJ->query_cap_name()

/**
 * NOTE: Programming for extended situations that use the accept object is not
 *       for the faint of heart. The following four methods are quite ugly in
 *       nature and as such, I will attempt to chart the flow of stuff:
 *
 * on_cast():
 * ----------
 * spell is successfully cast
 * if the target is a living other than the caster
 *    if the target trusts the caster
 *       accept the spell (call on_accept1)
 *    else
 *       reject it (call on_reject1)
 * else
 *    magically accept the first phase (call on_accept1)
 *
 * on_accept1():
 * -------------
 * else
 *    if the destination player trusts the caster
 *       accept the spell (call on_accept2)
 *    else
 *       reject it (call on_reject2)
 *
 * on_accept2():
 * -------------
 * now that trust is established all around, actually teleport
 *
 * on_reject[12]():
 * ----------------
 * someone (destination or target) don't trust the caster, don't port
 */

// accept/reject pair for the first phase of casting
void on_accept1( mixed param ) {
  object obj;
  // check for trust first
  if (DOBJ->query_trust(COBJ->query_name())) {
    msg_object(COBJ, DNAME+" trusts you, automatically accepting spell.");
    msg_object(DOBJ, "You trust "+CNAME+", automatically accepting spell.");
    this_object()->on_accept2(param);
    return;
  }
  // no trust exists, do it the hard way
  obj = clone_object("/obj/accept");
  obj->set_verb(this_object());
  obj->set_yes("on_accept2", param);
  obj->set_no("on_reject2", param);
  obj->start(DOBJ);

  //debug(as_lpc(param));
  set_actor(TOBJ);
  msg_object(COBJ, "It is now up to "+DNAME+" to accept the spell.");
  msg_object(DOBJ, CNAME+" wants to teleport ~name to you.");
}
void on_reject1( mixed param ) {
  set_actor(COBJ);
  set_target(TOBJ);
  set_listener(this_player());
  msg_object(COBJ, TNAME+" has rejected the spell.");
  msg_object(DOBJ, CNAME+" will not be sending ~targ to you.");
  msg_object(TOBJ, CNAME+" will not be teleporting you to "+DNAME+" after all.");
}

// accept/reject pair for the second phase of casting
void on_accept2( mixed param ) {
  set_target(TOBJ);
  COBJ->msg_local("~[030~Subt ~vertis briefly surrounded by a rapidly spinning vortex of wind and ~vertis gone!~CDEF");
  msg_object(TOBJ,"You are chilled as you rush through the plane of air.");
  // determine where object winds up
  if ( TOBJ->query_is_living() || 
      (DOBJ->query_held_weight() + TOBJ->query_weight() > DOBJ->query_weight_capacity())) {
       TOBJ->move(environment(DOBJ));
       TOBJ->set_coord(WALK_DAEMON->query_random_adjacent(DOBJ));
    TOBJ->validate_position();
    DOBJ->msg_local("~[030~Subt ~vertappear with a loud pop!~CDEF");
  } else {
    // put small items in the destination's inventory
    TOBJ->move(DOBJ);
    set_actor(DOBJ);
    DOBJ->msg_local("~[030Pop! ~Subt ~vertappear in ~npos hands!~CDEF");
  }
}
void on_reject2( mixed param ) {
  set_actor(COBJ);
  set_target(TOBJ);
  set_listener(this_player());
  msg_object(COBJ, DNAME+" has rejected the spell.");
  msg_object(DOBJ, CNAME+" will not be sending "+TNAME+" to you.");
  msg_object(TOBJ, CNAME+" will not be teleporting you to "+DNAME+" after all.");
}

varargs int on_cast(mapping param) {
  object obj;
  obj = param["destination"];

  string valid = validate_params( param );
  if ( valid != "ok" ) {
    msg( valid );
    return 0;
  }

  if (!member(param,"destination")){
    msg("You must specify another player as the destination point for this spell. Ie: "+
        "~CCOMcast teleport on bucket of money to lars~CDEF to send the bucket of "+
        "money to me ;).");
    return 0;
  }
  if (environment(param["destination"]) == environment(param["caster"]) ) {
    msg("You can't teleport something such a short distance!");
    return 0;
  }
  if( param["destination"]->query_ignore(param["caster"]->query_name()) ) {
    msg("They are ignoring you.");
    return 0;
  }

  param["caster"]->practice_skill_conditional("magic.mana.wind",50,3);
  set_actor(param["caster"]);
  set_target(param["target"]);
  param["caster"]->msg_local("~[030One vortex moves and engulfs ~targ while the other travels off into the distance.~CDEF");

  if (param["target"]->query_is_living() && param["target"] != param["caster"]) {
    if (param["target"]->query_trust(param["caster"]->query_name())) {
      set_listener(param["caster"]);
      msg("~Subt trusts you, automatically accepting spell.");
      msg_object(param["target"], "You trust ~Name, automatically accepting spell.");
      on_accept1(param);
    } else {
      set_listener(param["caster"]);
      msg("~Subt must first accept the spell.");
      obj = clone_object("/obj/accept");
      obj->set_verb(this_object());
      obj->set_yes("on_accept1", param);
      obj->set_no("on_reject1", param);
      obj->start(param["target"]);
    }
  } else {
    on_accept1( param );
  }

  return 1;
}
