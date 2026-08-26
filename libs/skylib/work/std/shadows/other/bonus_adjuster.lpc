// Gototh, 09/09/98

/*
 * This shadow increases a skill bonuses by a certain percentage.
 */
#include <skills.h>

inherit "/std/effect_shadow";

/**
 * @ignore yes
 */
varargs int query_skill_bonus(string word, int true) {
  int i, bonus;
  mixed args;
  string querying;


  mapping skills_to_modify;

  bonus = player->query_skill_bonus(word, true);

  if(true) {
    return bonus;
  }

  args = arg();

  /*
   * Create a mapping of the skills to modify and the percentages
   * to modify them by.
   */
  skills_to_modify = ([ ]);
  for(i = 0; i < sizeof(args); i += 3) {
    if(!skills_to_modify[args[i]]) {
      skills_to_modify[args[i]] = ({ });
    }
    skills_to_modify[args[i]] += ({ args[i + 1] });
  }

  /*
   * Check if the bonus being queried is to be modified.
   */
  querying = SKILL_H->query_skill(explode(word, "."));
  if(!skills_to_modify[querying]) {
    return bonus;
  }

  /*
   * Adjust the bonus by the correct percentage.
   */

  tell_creator(find_living("gototh"), "bonus: %O\n", bonus);

  tell_creator(find_living("gototh"), "skills_to_modify[querying][i]: %O\n",
    skills_to_modify[querying][i]);

  for(i = 0; i < sizeof(skills_to_modify[querying]); i++) {
    if(skills_to_modify[querying][i] < 0) {
      bonus -= ((bonus * -(skills_to_modify[querying][i])) / 100);
    } else {
      bonus += ((bonus * skills_to_modify[querying][i]) / 100);
    }
  }
  tell_creator(find_living("gototh"), "bonus: %O\n", bonus);
  return bonus;
} /* query_skill_bonus() */
