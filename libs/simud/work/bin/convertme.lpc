#include <const.h>
#include <magic.h>

int skill_xp_to_level(string skill, int xp) {
  int level = 0;
  while (xp > this_player()->query_skill_cost(skill, level))
    level++;
  return level;
}

int main() {
  string line;
  mapping spells = this_player()->query_known_spells();

  msg("converting your spells to skills...");

  if (sizeof(spells) == 0) {
    msg("You don't know any spells.");
    return 1;
  }
  if (member(spells, 0))
    spells -= ([ 0 ]);
  foreach ( line : spells ) {
    string skill = "magic.spell."+line;
    skill = regreplace(skill," ","_",1);
    if (!this_player()->query_skill(skill)) {
       int xp = spells[line], level;
       object obj = MAGIC_DAEMON->query_spell(line);
       xp *= obj->query_num_steps();
       level = skill_xp_to_level(skill,xp);
       xp -= this_player()->query_skill_cost(skill, level);
       this_player()->set_skill(skill,level);
       this_player()->add_skill(skill,xp-1);
       this_player()->practice_skill(skill);
       msg(skill+": "+level);
    }
  }
  return 1;
}
