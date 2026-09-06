#include <form.h>
#include <battle.h>

string query_name() { return "swamp_dragon"; }

string *query_default_actions()
{
   return ({"bite","claw","tail","swamp_breath","dodge","counter"});
}

string query_action_desc(string name)
{
   return "blah, it's a dragon, what do you care?";
}

string *query_actions()
{
   return ({"bite","claw","tail","swamp_breath"});
}

string *query_reactions()
{
   return ({"dodge","counter"});
}

string query_change_message()
{
   return "~Name ~verbbelch audibly.";
}

string on_attack( object target, object actor, mapping wc ) {
  if ( target->query_reaction_enabled("dodge") && random(100) < 70 )
    return "/battle/reactions/dodge";
  else
    return 0;
}

string on_miss( object target, object actor, mapping wc ) {
  if ( target->query_reaction_enabled("counter") &&
       random(100) < (2*target->query_speed()+
                      2*target->query_form_level("animal")+
                      target->query_skill("combat.technique.counter")) )
    return "/battle/reactions/animal-counter";
  else
    return 0;
}
