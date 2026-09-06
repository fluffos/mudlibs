#include <const.h>

main(string who) {
  object victim, *everyone = ({});

  WIZ_CHECK

  if (!who)
    everyone = ({ this_player() });
  else if (who == "all")
    everyone = users();
  else if (who == "room") {
    foreach ( victim: all_inventory(environment(this_player())) ) {
      if (victim->query_is_living())
        everyone += ({ victim });
    }
  } else if (victim = find_living(who))
    everyone = ({ victim });
  else {
    msg("Could not find "+capitalize(who)+".\n");
    return 1;
  }

  foreach (victim: everyone) {
    object bleeder;
	if( victim->query_hp() < victim->query_maxhp() )
      victim->set_hp(victim->query_maxhp());
	if( victim->query_mana() < victim->query_maxmana() )
      victim->set_mana(victim->query_maxmana());
	if( victim->query_end() < victim->query_maxend() )
      victim->set_end(victim->query_maxend());
    set_actor(this_player());
    set_target(victim);
    set_listener( ({this_player(), victim}) );
    if ( environment(this_player()) == environment(victim) )
      this_player()->msg_local("~CBRT~Name ~verbhave healed ~targ.~CDEF");
    else {
      msg("~CBRT~Targ healed to full.~CDEF");
      msg_object(victim,"~CBRT~Name has healed you.~CDEF");
    }
    while (bleeder = present_clone("/battle/bleeder_object",victim))
      bleeder->end();
    command("hp",victim);
  }

  return 1;
}
