//	/adm/simul_efun/total_light.c
//	from the Nightmare mudlib
//	returns the total amount of light available to a player
//	created by Descartes of Borg 16 january 1993

// edit by Nulvect 2012-May-19
// night time light formula was:
// return ((light-4)+((int)ASTRONOMY_D->query_moon_light()) +
//   ((int)env->query_property("night light")));
// not sure why light-4 is in there...
// old formula results in night light often being negative

#include <daemons.h>

int total_light(object who) {
  object env;
  int day, night, light;

  if (!who || !(env = environment(who))) return 0;

  // it is expected that "light" is always set
  // "night light" is optional
  day = env->query_property("light");
  night = env->query_property("night light");

  // if "night light" not set, just use the "light" property
  if (!night)
    night = day;

  if (env->query_property("indoors")) {
    light = day;
  }

  else { // outdoors
    switch (EVENTS_D->query_time_of_day()) {
      case "twilight":
      case "dawn": 
        light = (day - 1);
      break;

      case "day":
        light = day;
      break;

      case "night":
        light = night + ASTRONOMY_D->query_moon_light();
      break;
    }
  }

  // check if any objects in the room give off light
  foreach (object ob in all_inventory(env))
    light += ob->query_property("light");

  return light;
}
