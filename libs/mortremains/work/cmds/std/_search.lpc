// (??-??-96) Written by Chronos@AFD
// (04-06-98) Ported by Chronos.
// Cyanide placed the code in here on about 4-12-98

inherit DAEMON;

int cmd_search(string str) {
  string tmp;
  if (!TP->query("vision")) {
    write("How can you search when you can't see a thing?\n");
    return 1; 
  }
/* Not needed here.
  if (TP->query_rest_status()) {
   write("You cannot do that while resting or sleeping.\n") ;
  return 1;
  }
*/
  if (TP->query("blind")) {
    write("You're blind!  You can't search for things right now.\n");
    return 1;
  }
  if (!str) {
    write("Search what?\n");
    return 1; 
  }
  tmp=environment(TP)->query("search_func/"+str);
  if (tmp) {
    call_other(environment(TP), str);
    return 1;
  }
  tmp=environment(TP)->query("search_desc/"+str);
  if (!tmp) {
    tmp = environment(TP)->query("item_desc/"+str);
    if (!tmp) {
    write("You can't search that.\n");
    return 1; 
     }
     write("You find nothing of interest.\n");
     return 1;
  }
  write(tmp);
  return 1;
}

string help() {
  return (@ENDHELP
Usage: search <object>

This command lets you search an object for hidden things.
ENDHELP
  );
}
