inherit "/obj/tent";
#include <properties.h>
#include <secure/wizlevels.h>
#define GUILDSTR "adventurer"

create() {
  ::create();
  SetWeight(0);
  Set(P_NOSELL,1);
  Set(P_NOBUY,1);
  Set(P_NOGIVE,1);
  SetValue(0);
}


QueryAutoObject(mixed values) {
 object pl;
  if (((pl=previous_object())->QueryGuild()!=GUILDSTR) && !IS_IMMORTAL(pl)) {
     return 0;
  return 1;
  }
}


int fsleep(string arg) {
  if (arg || environment(this_player()) != this_object())
    return 0;
  if ((this_player()->QueryGuild() != "adventurer") && 
     (!IS_IMMORTAL(this_player()))) {
    write("You try to sleep, but wake up ever again, afraid that someone "
"might take advantage and rob you. Finally you give up and stay awake.\n");
    return 0;
  }
  return ::fsleep(arg);
}


int fread(string arg) {
   if (!arg || member(({"manual","tent"}), arg) == -1)
      return 0;
   if ((this_player()->QueryGuild() != "adventurer") && 
      (!IS_IMMORTAL(this_player()))) {
     write("The sign just reads: THIS IS NOT MADE FOR YOU!\n");
     return 0;
   }
   return ::fread(arg);
}
