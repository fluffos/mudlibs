/*
 * query_allies(living)
 * returns a list of living things that are allies with 'living'
 * includes party members, pets, riders, and mounts, and all permutations
 * (pets belonging to party members, party members of anyone who is riding you,
 *  mounts that your pets are riding, etc)
 *
 * Nulvect 2010-11-02
 */

#include <daemons.h>

varargs object *query_allies(object tp, object *recursed) {
  string party = PARTY_D->party_member(tp);
  object env = environment(tp);
  object *allies, *riders, *partymembers, *pets;
  object riding;

  if (nullp(tp)) return ({});
  if (nullp(recursed)) recursed = ({});

  if (party)
    partymembers = PARTY_D->query_party_members(party);
  pets = tp->query_pets();
  riders = tp->query_riders();
  riding = tp->query_riding();

  allies = ({});

  // I am using | all over the place to avoid duplicates
  // ({ 1 }) + ({ 1 }) == ({ 1, 1 })
  // ({ 1 }) | ({ 1 }) == ({ 1 })
  allies |= (partymembers || ({}) );
  allies |= (pets || ({}) );
  allies |= (riders || ({}) );
  allies |= (riding ? ({ riding }) : ({}) );

  recursed |= ({ tp });
  allies -= recursed;

  for (int i = 0; i < sizeof(allies); i++) {
    allies |= query_allies(allies[i], recursed);
  }

  allies = ({ tp }) | allies;

  return allies;
}
