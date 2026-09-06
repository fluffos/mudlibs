/** This file used to exist simply as a generic test of my magic system.
 * However, I realized that I honestly want to keep half of the code in
 * here, so it is being converted over to the general purpose magic verb.
 *   - al [1.31.02]
 */
#include <magic.h>
#include <const/battconst.h>

string query_action_name( mixed * action ) {
  return "Cast " + action[B_PARAM]["spell"];
}

mapping parse_arguments(string arg) {
  string *args;
  mapping result;
  int x;

  // parse string
  args = regexplode( arg, " at | on | with | using | as | by | for | to " );
  // extract spell name from head
  result = ([ "spell":args[0] ]);
  args = args[1..];
  // validate parset remains
  if (sizeof(args)%2) {
    debug("Something went wrong in parse_arguments("+arg+"):\n"+as_lpc(args));
    return result;
  }
  // turn things into a mapping
  for (x = 0; x < sizeof(args); x+=2)
    result += ([ trim(args[x]):trim(args[x+1]) ]);

  return result;
}

int main (string arg) {
  mapping args;
  object target;
  string spell;	// for some unholy reason, it works better as a string
  int cost, x;

  if ( !arg ) return notify_fail( "What do you want to cast?\n" );

  args = parse_arguments(arg);

  // validate selected spell
  if ( !member(args,"spell") ) {
    msg("You need to specify the name of the spell to cast. Type ~CCOMhelp cast~CDEF for instructions.");
    return 1;
  }
  spell = MAGIC_DAEMON->query_spell(args["spell"]);
  if (!spell) {
    notify_fail("No such spell '"+args["spell"]+"'.\n");
    return 0;
  }
  if (!member(this_player()->query_known_spells(),args["spell"])) {
    notify_fail("You don't know that spell!\n");
    return 0;
  }

  // validate parameters
  if ( member(args,"at") && member(args,"on") ) {
    msg("You may specify only one of ~CCOMat~CDEF and ~CCOMon~CDEF. How else "+
        "am I supposed to know whether your spell should affect '"+args["at"]+
        "' or '"+args["on"]+"', hmm?");
    return 1;
  }
  if ( member(args,"with") && member(args,"using") ) {
    msg("You may specify only one of ~CCOMwith~CDEF and ~CCOMusing~CDEF.");
    return 1;
  }
  if ( member(args,"as") + member(args,"by") + member(args,"for") +
       member(args,"to") > 1 ) {
    msg("Only one of ~CCOMas~CDEF, ~CCOMby~CDEF, ~CCOMfor~CDEF, or "+
        "~CCOMto~CDEF may be specified per casting. Otherwise, I've no way "+
        "of making sure your spell is cast with the right options.");
    return 1;
  }

  // standardize parameters
  if ( member(args,"at") )
    args["target"] = args["at"];
  else if ( member(args,"on") )
    args["target"] = args["on"];
  if ( member(args,"as") )
    args["option"] = args["as"];
  else if ( member(args,"by") )
    args["option"] = args["by"];
  else if ( member(args,"for") )
    args["option"] = args["for"];
  else if ( member(args,"to") )
    args["option"] = args["to"];
  if ( member(args,"with") )
    args["component"] = args["with"];
  else if ( member(args,"using") )
    args["component"] = args["using"];
  args -= ([ "at", "on", "as", "by", "for", "to", "with" ]);

  // check for violence restriction
  if ( spell->query_violent() &&
       target = present_clone("/world/nocombat",environment(this_player())) ) {
    string msg = target->query_no_msg();
    if (!msg)
       msg = "But this is such a peaceful place...";
    notify_fail(msg+"\n");
    return 0;
  }

  // validate target
  if ( !member(args,"target") ) {
    if (spell->query_violent())
      target = this_player()->query_target();
    else
      target = this_player();
    if (!target) {
      msg("~CWRNUnable to guess a target for that spell ;)~CDEF");
      return 1;
    }
  } else {
    target = single_present(args["target"],this_player());
    if (!target)
      target = single_present(args["target"],environment(this_player()));
    if (spell->query_must_hold_target() && target && environment(target) != this_player())
      return notify_fail("The spell requires that you hold that target.\n");
    if (!target)
      return notify_fail("Could not find target '"+args["target"]+"'.\n");
  }
  target->set_player_lock( this_player() );

  // put everything else into the mapping
  args["caster"] = this_player();
  args["target"] = target;
  args["step"] = 0;

  // use strong kung fu validation if defined, weak if not
  // FOR A GOOD TIME: replace the find_object() call with spell... figure out
  // why it doesn't work
  if (function_exists("validate_params",find_object(spell))) {
    string errmsg = spell->validate_params(args);
    if (errmsg != "ok") {
       notify_fail(errmsg+"\n");
       return 0;
    }
  } else if (!spell->valid_target(args)) {
	set_target( args["target"] );
	set_actor( args["caster"] );
	set_listener( args["caster"] );
    msg("~Subt ~vertis not a valid target for that spell.");
    return 1;
  }

  // do this here so the authors of individual spells can be lazy :)
  set_target(target);

  // calculate cost
  cost = MAGIC_DAEMON->query_cost(spell->query_type(),spell->query_cost());
  if (this_player()->query_mana() < cost)
    return notify_fail("You do not have enough mana (" + cost + ") to cast " + spell->query_name() + ".\n");
  args["cost"] = cost;
  args["readiness"] = spell->query_readiness_requirement();

  // modify readiness by cast count - with a freaking cap :P
  x = this_player()->query_known_spells()[args["spell"]];
  args["readiness"] = max(args["readiness"] * 0.75, args["readiness"] - x);

  // enqueue the spell
  this_player()->push_action( ({ min(1000,args["readiness"]),
                                 this_object(),
                                 args["target"],
                                 ST_STANDING,
                                 args }) );
  return 1;
}


void on_action(object victim, mixed param) {
  object spell;
  int rcost, steps, dc, cost;
  string skill;

  set_actor(param["caster"]);
  set_target(victim);

  /** Verify that appropriate parameters have been passed. Granted, the chances
   * of an invalid set of parameters being passed are next to nothing. However,
   * we write things like this so people can do wierd things manually with
   * minimal opportunity for buggering things up, ne?
   */
  if (!mappingp(param) || sizeof(param) < 6) {
    debug("Spell action had misformed parameters:\n"+as_lpc(param));
    return;
  }

  // get spell object
  spell = MAGIC_DAEMON->query_spell(param["spell"]);

  cost = MAGIC_DAEMON->query_cost(spell->query_type(),spell->query_cost());
  if (this_player()->query_mana() < cost) {
    msg_object(param["caster"], "You do not have enough mana (" + cost + ") to cast " + spell->query_name() + ".\n");
    return;
  }

  // validate target
  if (!spell->valid_target( param )) {
     if ( !param["target"]->query_is_living() )
        msg_object(param["caster"],"~CWRN~Prot's dead, Jim.~CDEF");
     else
        msg_object(param["caster"],"~CWRNYour target seems to have disappeared!~CDEF");
	 return;
  }

  // readiness cost per step
  steps = spell->query_num_steps();
  if (!steps)
     steps = 1;
  rcost = spell->query_readiness_requirement();
  rcost = (int)floor(rcost / steps);
  if (rcost < 75) // steps never require less than 75 readiness
    rcost = 75;
  if (rcost > param["readiness"])
    rcost = param["readiness"];
  this_player()->add_readiness(-rcost);
  param["readiness"] -= rcost;

  // check for failure
  // TODO: allow spells to specify individual skills for each step
  if( !(skill = spell->query_step_skill(param)) ) {
    // warn and fall back to old math
    if( param["step"] == 0 )
       msg("~CWRNThis spell is not practicing skills correctly. Please contact Lars.~CDEF");
    skill = "magic.mana."+spell->query_type();
    dc = max(10, param["cost"] * param["step"] / steps);
  } else {
    dc = min( max(10,	// min step difficulty is 10
                  spell->query_level() * 25 +
                  param["step"] * 5),
			  120 );	// max step difficulty is 120 ;)
  }

  //debug(param["spell"]+", skill = "+skill+", dc = "+dc,"combat");
  if (!this_player()->skill_check(skill, dc)) {
    string buf = spell->query_fail_msg(param);
    if (!buf)
       buf = "~Name ~verblose control of ~poss magic and the spell is lost.";
    this_player()->msg_local("~[030"+buf+"~CDEF");
    this_player()->add_mana(param["cost"] / -2); // lost half of the mana when failing
    msg("~CBRTYou need more ~CEMO"+skill+"~CBRT skill in order to cast this spell reliably.~CDEF");
    if ( this_player()->query_autohp() )
       "/bin/hp"->force(this_player());
    return;
  }

  // continue casting...
  if (param["step"] < steps) {
    string valid = spell->validate_params( param );
    if (function_exists("validate_params",find_object(as_string(spell))) && valid != "ok" ) {
      msg( valid );
      return 0;
    }

    string buf = spell->query_step_msg(param);

    if (!buf) {
       if (param["step"])
          buf = "~Name ~verbcontinue to chant.";
       else
          buf = "~Name ~verbbegin to chant quietly.";
    }

    set_actor(param["caster"]);
    set_target(param["target"]);
    param["caster"]->msg_local("~[030"+buf+"~CDEF");
    // recognize spell
    if (!param["step"]) {
       object obj;
       foreach( obj : all_inventory(environment(param["caster"])) ) {
          if( !obj->query_is_living() || obj == param["caster"] )
             continue;
          dc = 25 + 40 * spell->query_level() - obj->query_known_spells()[spell->query_name()];
          if( obj->skill_check("magic.intuition", dc) ) {
             set_actor( param["caster"] );
             set_listener( obj );
             msg_object(obj,"~CTITYou recognize ~npos spell as '~CBRT"+spell->query_name()+"~CTIT'.~CDEF");
          }
       }
    }
    // target of violent spell has a chance of realizing what's going on
    if (spell->query_violent() &&
        pointerp(param["target"]->query_targets()) &&
        member(param["target"]->query_targets(),param["caster"]) == -1 &&
        param["target"]->stat_check("emp",param["target"]->stat_check("cha"))) {
      set_actor(param["caster"]);
      set_target(param["target"]);
      param["caster"]->msg_local("~CWRN~Subt ~vertrealize that ~name ~verbis attacking ~objt!~CDEF");
      param["target"]->start_combat(param["caster"]);
    }
    // reenqueue the spell
    param["step"]++;
    this_player()->set_action( -1, ({ 1000 - 2*this_player()->query_skill("magic.concentration"/*"magic.spell."+spell_name*/),
                                   this_object(),
                                   param["target"],
                                   ST_STANDING,
                                   param }) );
    return;
  }

  // adjust mana
  MAGIC_DAEMON->draw_mana(param["caster"],spell->query_type(),spell->query_cost());

  // handle freak cases of mana burn
  if( param["caster"]->query_mana() < 0 ) {
    set_actor(param["caster"]);
	param["caster"]->msg_local("~CWRN~Name ~verbchannel more energy than ~pron can control!~CDEF");
	return;
  }

  // actually cast the spell
  param["caster"]->practice_spell(param["spell"]);
  if (spell->query_violent())
    param["target"]->set_env_var("cause_of_death","was slain by "+param["caster"]->query_cap_name()+"'s "+spell->query_name()+".");
  spell->on_cast(param);
  if (spell->query_violent())
    param["caster"]->start_combat(param["target"]);

  if ( this_player()->query_autohp() )
    "/bin/hp"->force(this_player());
}

int query_is_interruptable() { return 1; }

void on_interrupt(mixed action) {
  mapping param = action[4];
  string spell = MAGIC_DAEMON->query_spell(param["spell"]);
  int step = param["step"];
  int cost = param["cost"];
  int steps = spell->query_num_steps();
  int dc = 20 * ( spell->query_level() + 1 );
  //debug("on_interrupt:"+as_lpc(action));
  if (!param["caster"]->skill_check("magic.technique.channeling",dc)) {
    msg_object(param["caster"],"~CBRTThe mana from your spell escapes!~CDEF");
    param["caster"]->add_mana( -to_int(cost * step / steps) );
    // TODO: different effects for different types of mana burn
  }
}
