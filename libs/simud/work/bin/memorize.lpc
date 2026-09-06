#include <magic.h>

string query_action_name() { return "Memorize"; }

int main(string str) {
   mapping args = ([]), skills = ([]);
   string object_name, spell, skill;
   object ob, spell_ob;
   int min_skill, x;

   if( !str || sscanf(str,"%s from %s",spell,object_name) != 2) {
      notify_fail("Usage: memorize <spell> from <scroll>\n");
      return 0;
   }

  ob = single_present( object_name, this_player() );
  if( !ob ) {
    if ( single_present( object_name, environment(this_player())) )
      notify_fail("You must be carrying the scroll to memorize it.\n");
    else
      notify_fail("I don't know what you mean by '"+str+"'.\n");
    return 0;
  }

  if (spell != ob->query_spell()) {
    notify_fail("The scroll does not contain that spell.\n");
   return 0;
  }

  if (member(this_player()->query_known_spells(), spell)) {
    notify_fail("You already know that spell!\n");
   return 0;
  }

  // make sure they have sufficient skills to learn the spell
  spell_ob = MAGIC_DAEMON->query_spell(spell);
  min_skill = max(spell_ob->query_level() * 25, 1);
  for( x = 0; x < spell_ob->query_num_steps(); x++ ) {
    skill = spell_ob->query_step_skill( (["step":x]) );
    if( this_player()->query_skill(skill) < min_skill ) {
     skills += ([ skill ]);
   }
  }
  foreach( skill : sort_array(m_indices( skills ), #'>) ) {
    msg("You do not have enough ~CACT"+skill+"~CDEF to learn this spell.");
  }
  if( sizeof(skills) ) {
    return notify_fail("Practice your skills and try again.\n");
  }

  // find the actual spell object to run checks
  args["spell"] = spell;
  args["step"] = 0;
  args["readiness"] = (MAGIC_DAEMON->query_spell(spell)->query_readiness_requirement() - ob->query_level()) * 3;
  args["object"] = ob;

  // debug("main: "+as_lpc(args));

  // enqueue the action
  this_player()->push_action( ({
                                1000,
                                this_object(),
                                this_player(),
                                ST_SITTING,
                                args
                              }) );
  // debug(as_lpc(this_player()->query_actions()));
  return 1;
}

void on_interrupt(mixed action) {
  mixed param = action[3];
  msg("You will have to start memorizing all over again.");
}

void on_action(object target, mixed param) {
  string skill;
  int rcost, steps;
  object spell_ob = MAGIC_DAEMON->query_spell( param["spell"] );

  if (!mappingp(param) || sizeof(param) < 4) {
    debug("Memorize action has misformed parameters.");
    return;
  }

  // debug("on_action: "+as_lpc(param));

  // readiness cost per step
  rcost = 500;
  if (rcost > param["readiness"])
    rcost = param["readiness"];
  this_player()->add_readiness(-rcost);
  param["readiness"] -= rcost;

  set_actor(this_player());
  set_target(param["object"]);

  // make sure they still have the scroll
  if (!param["object"] || param["object"]->query_spell() != param["spell"]) {
    this_player()->msg_local("~CACT~Name ~verbstop memorizing as ~pron suddenly ~verbrealize that the object of memorization has ceased to remain present for scrutiny...~CDEF");
    on_interrupt( ({ 0,0,0,param}) );
    return;
  }

  // check for failure
  if (!this_player()->skill_check("magic.concentration", spell_ob->query_level() * 20 + param["step"] * 3)) {
    this_player()->msg_local("~CACT~Name ~verblose ~poss concentration and ~verbstop memorizing.~CDEF");
    on_interrupt( ({ 0,0,0,param }) );
    return;
  }

  // practice scroll skill
  this_player()->practice_skill_conditional( "magic.item.scroll", spell_ob->query_level() * 25 + 20, 1);

  // continue memorizing...
  if (param["readiness"]) {
    string buf;
    // TODO: Make sure they actually still have the scroll :P
    buf = "~[030~Name ~verb"+(param["step"]?"continue":"begin")+
          " to study ~targ.~CDEF";
    this_player()->msg_local(buf);
    param["step"]++;
    this_player()->set_action( -1, ({
                                  1000,
                                  this_object(),
                                  this_player(),
                                  ST_SITTING,
                                  param }) );
    return;
  }

  // actually learn the spell
  this_player()->add_spell(param["spell"]);
  set_actor(this_player());
  set_target(param["object"]);
  this_player()->msg_local("~[030~Name ~verbfinish studying ~targ.~CDEF");
  if( param["object"]->query_num_pages() <= 1 )
    param["object"]->set_condition(-1);
  msg("~CTITYou now know how to cast the ~CBRT"+param["spell"]+"~CTIT spell.~CDEF");
}

int query_is_interruptable() { return 1; }
