//   /adm/simul_efun/effective_light.
//   from the Nightmare mudlib
//   returns the total effective light available to a player
//   taking into effect her sight_bonus and any personal
//   object she may be carrying that modify her own personal light
//   Idea by Descartes, coded by Valodin 1-19-93

int effective_light(object who)
{
  int light;

  if(!who) return 0;
    light = total_light(who);
  if(light < 5) {
	if(light + (int)who->query_sight_bonus() > 5) light = 5;
	else light += (int)who->query_sight_bonus();
  } else {
	if(light - (int)who->query_sight_bonus() < 5) light = 5;
	else light -= (int)who->query_sight_bonus();
  }
  return light;
}
