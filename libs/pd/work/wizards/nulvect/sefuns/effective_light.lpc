//   /adm/simul_efun/effective_light.
//   from the Nightmare mudlib
//   returns the total effective light available to a player
//   taking into effect her sight_bonus and any personal
//   object she may be carrying that modify her own personal light
//   Idea by Descartes, coded by Valodin 1-19-93
//  recoded by Nulvect 2012-Feb-11

int effective_light(object who) {
  int light;
  int sight;

  if (!who) return 0;

  // make sure newbies can see
  if (userp(who) && who->query_level() <= 5) return 1;

  // start with ambient light
  light = total_light(who);

  // add light from objects we're carrying, like torches
  foreach (object ob in all_inventory(who))
    light += ob->query_property("light");

  sight = who->query_sight_bonus();

  // for + sight bonus, make it effectively lighter if it's dark
  while (light < 0 && sight > 0) {
    light++; sight--;
  }

  // for - sight bonus, make it effectively darker unless it's fairly light already
  while (light < 1 && sight < 0) {
    light--; sight++;
  }

  return light;
}
