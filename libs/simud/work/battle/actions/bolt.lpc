#include <battle.h>
#include <magic.h>

BATTLE_ACTION( 1000, "spellcaster" )

string query_action_name() {
   return "Bolt";
}

void on_action( object victim ) {
   string spell, *spells, f, l, *actions, spell_type;
   int mana;

   mana = this_player()->query_mana();
   actions = this_player()->query_form_actions();
   spell_type = lower_case(query_action_name());

   // pick a spell at random
   spells = filter(m_indices(this_player()->query_known_spells()),
               (:
                  if( sscanf($1,"%s %s",f,l) != 2 )
                      return 0;
                  return (l == spell_type) &&
                         (member(actions, f) != -1) &&
                         (mana >= MAGIC_DAEMON->query_spell_cost($1));
               :)
            );

   if (sizeof(spells) > 0) {
      spell = spells[random(sizeof(spells))];
      //*** Old way:
      // "/bin/cast"->main(spell+" at "+victim->query_name());
      //*** New way:
      // since this is an automatic action anyhow, pick the target the same way
      "/bin/cast"->main(spell);
   } else {
      // deduct readiness for trying to autocast so we don't loop
      msg("~CWRNYou are unable to cast a ~CBRT"+spell_type+"~CWRN spell right now.~CDEF");
      this_player()->add_readiness(-400);
   }

}
