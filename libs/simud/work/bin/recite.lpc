#include <magic.h>

string query_action_name() { return "Recite"; }

int main(string str) {
   mapping args;
   string target_name, spell;
   int page, fail;
   object ob, target;

/*
   // temporary ban on scrolls
   msg("~CBRTSorry, but scrolls are currently disabled while magical objects "+
       "receive something of a major makeover.~CDEF");
   return 1;
*/

   if( !str ) {
      notify_fail("Usage: recite <scroll> [at <target>] [with <focus>] [as <option>]\n");
      return 0;
   }

  // not quite the same as when used by cast but close enough
  args = "/bin/cast"->parse_arguments(str);
  ob = single_present( args["spell"], this_player() );
  if( !ob ) {
    if ( single_present( args["spell"], environment(this_player())) )
      notify_fail("You must be carrying the scroll to recite it.\n");
    else
      notify_fail("I don't know what you mean by '"+str+"'.\n");
    return 0;
  } else if( ob->query_num_pages() > 1 ) {
    return notify_fail("You can't cast spells directly from a book.\n");
  }
  args["object"] = ob;

  // find the actual spell object to run checks
  spell = MAGIC_DAEMON->query_spell(ob->query_spell());
  args["spell"] = spell->query_name();

  // validate parameters - taken from cast.c
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

  // standardize parameters - taken from cast.c
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

  // check for violence restriction - also from cast.c
  if ( spell->query_violent() &&
       target = present_clone("/world/nocombat",environment(this_player())) ) {
    string msg = target->query_no_msg();
    if (!msg)
       msg = "But this is such a peaceful place...";
    notify_fail(msg+"\n");
    return 0;
  }

  // validate target - yet again, taken from cast.c
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
    if (!target) {
      notify_fail("Could not find target '"+args["target"]+"'.\n");
      return 0;
    }
  }

  // put everything else into the mapping - from cast... noticing a trend?
  args["caster"] = this_player();
  args["target"] = target;
  args["step"] = 0;

  // use strong kung fu validation if defined, weak if not - from cast
  if (function_exists("validate_params",find_object(spell))) {
    string errmsg = spell->validate_params(args);
    if (errmsg != "ok") {
       notify_fail(errmsg+"\n");
       return 0;
    }
  } else if (!spell->valid_target(args)) {
    notify_fail("'"+args["target"]->query_cap_name()+"' is not a valid target for that spell.\n");
    return 0;
  }

  // do this here so the authors of individual spells can be lazy :)
  set_target(target);

  // this is a scroll, casting is free
  args["cost"] = 0;
  // but it still takes time
  args["readiness"] = spell->query_readiness_requirement();

  // enqueue the action
  this_player()->push_action( ({
                                min(1000, args["readiness"]),
                                this_object(),
                                args["target"],
                                ST_STANDING,
                                args
                              }) );
  return 1;
}

void on_interrupt(mixed action) {
  int dc, readiness;
  if (pointerp(action)) {
    mixed param;
    param = action[3];
    if( !mappingp(param) || !param["object"] ) return;
    dc = param["object"]->query_level();
    readiness = param["readiness"] * 2;
  } else {
    debug("on_interrupt called with invalid arg: "+as_lpc(action));
    dc = 50;
    readiness = 1000;
  }
  // TODO: chance of critical failure destroying the scroll
  if (!this_player()->skill_check("magic.item.scroll", dc)) {
    msg("~CWRNYou are unable to control the broken magical energies!~CDEF");
    // TODO: make this a real mana penalty
    this_player()->add_readiness(-readiness);
  }
  msg("You will have to start reciting over again.");
}

void on_action(object target, mixed param) {
  string skill;
  int rcost, steps;
  object spell, scroll;

  set_actor(param["caster"]);
  set_target(target);

  if (!mappingp(param) || sizeof(param) < 7) {
    debug("Recite action has misformed parameters.");
    return;
  }

  spell = MAGIC_DAEMON->query_spell(param["spell"]);
  scroll = param["object"];
  if( !scroll || !find_object(to_string(scroll)) ) {
     msg_object(param["caster"],"~CWRNYour scroll seems to have dissapeared.~CDEF");
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
  rcost = spell->query_readiness_requirement() - (scroll->query_level() * 2) -
          this_player()->query_known_spells()[param["spell"]];
  rcost = (int)floor(rcost / steps);
  if (rcost < 100) // scroll steps never require less than 100 readiness
    rcost = 100;
  if (rcost > param["readiness"])
    rcost = param["readiness"];
  this_player()->add_readiness(-rcost);
  param["readiness"] -= rcost;

  // check for failure, very minimal chance, really
  if (!this_player()->skill_check("magic.concentration", 10 + param["step"])) {
    this_player()->msg_local("~CACT~Name lose ~poss concentration and ~verbstop reciting.~CDEF");
    on_interrupt( ({ 0,0,0,param }) );
    return;
  }

  // continue reciting...
  if (param["step"] < steps) {
    string buf;
    set_actor(param["caster"]);
    set_target(param["object"]);
    buf = "~[030~Name ~verb"+(param["step"]?"continue":"begin")+
          " to recite a spell from ~targ.~CDEF";
    this_player()->msg_local(buf);
    param["step"]++;
    this_player()->set_action( -1, ({
                                  1000 - 2*this_player()->query_skill("magic.concentration"),
                                  this_object(),
                                  param["target"],
                                  ST_STANDING,
                                  param }) );
    return;
  }

  // actually cast the spell
  this_player()->practice_spell(scroll->query_spell(), 0.25);
  scroll->on_recite(param);
  if (spell->query_violent())
    this_player()->start_combat(param["target"]);
}


int query_is_interruptable() { return 1; }
