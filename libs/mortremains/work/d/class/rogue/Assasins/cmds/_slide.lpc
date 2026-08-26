/*
** File:  _slide.c
** Purpose: So Assassins can do cool shit at level 45
** Date: 13th of December in the year 1997
** Credits: Nightmask (I take full credit for this abomination)
** Side Note: paper Towels suck as a mode of transportation 
*/

#include <mudlib.h>
#include <rogues.h>



int cmd_slide(string name) {
  object player;
if (TP->query_level() < 25) {
     write("You must be higher level to do this ability.\n");
  return 1;
  }
  if (!this_player()->query("invisible")) {
      write("How will you travel the shadows if you are not in them?\n");
      return 1;
   }
    if (!name) {
    write ("Slide to who?\n");
    return 1;
  }

  player = find_player(name);

  if (!player) {
    write(capitalize(name)+" is not on Nightfall's Keep.\n");
    return 1;
  }

  if (!environment(player)) {
    write("That person is list in the mists.\n");
    return 1;
  }

  if (environment(TP)->query("prevent_teleport") ||
      environment(player)->query("prevent_teleport")) {
    write("Something defeats your movement.\n");
    return 1;
  }

  if (wizardp(player)) {
    write("You cannot visit the gods!\n");
    return 1;
  }
    write("You travel by way of the shadows.\n");
//TP->move_player(TP, environment(player), "SNEAK"); 
  TP->move(environment(player));

  return 1;
}

