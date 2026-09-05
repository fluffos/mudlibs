#include "/players/pestilence/ansi.h"

main(object ob) {
  string file;
  int tellme;
  if(ob) tellme++;
  if(!ob) ob = environment();
  file = "players/pestilence/closed/dark/members/" + ob->query_real_name();
  if(!save_object(file)) {
    if(tellme) tell_object(ob,"Save error...\n");
    return 0;
    }
  if(tellme) tell_object(ob,"Saving the Dark Order...\n");
  write(""+HIK+"Saving the Dark Order"+NORM+"...\n");
  return 1;

}
