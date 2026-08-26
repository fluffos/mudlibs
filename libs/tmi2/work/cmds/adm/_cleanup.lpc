// _cleanup.c
// global mud cleanup command
// by Emeradii@EarthMud 4/15/94
//
// Leto@Earth 2/18/95 Added verbose flag (defaults to quiet now), 
//                    prevented self-wipe and prevented max_eval error

#include <mudlib.h>

inherit DAEMON;

int clean_up(){ return 1;} // Don't wipe ourselves ;)

int cmd_cleanup(string arg) {


  object *contents;
  string results;
  object ply;
  int i, number, flag, verbose;
  int force_write;

   reset_eval_cost(); // Leto
  if (arg == "-r") {
    write("reclaim_objects gives "+reclaim_objects()+"\n");
    return 1;
  }
	if (arg == "-v") verbose = 1;
  if (arg == "-f") force_write = 1;
  else force_write = 0;
  ply = this_player();
  number = 0;
  contents = objects();
  if (arg == "-l") flag = 1;
  else flag = 0;
  write("cleanup in "+(flag ? "list" : "wipe")+" mode.\n");
  results = "";
write("size of cleanup is "+sizeof(contents)+"\n");
  for (i = 0; i < sizeof(contents); i++) {
	if(verbose) {
    results += "file: "+(objectp(contents[i])?file_name(contents[i]):"nothing"); }
    if (force_write) write("file: "+(objectp(contents[i])?file_name(contents[i]):"nothing"));
    if (!flag) {
    if (!contents[i]) {
      results += "\n\ndangling object encountered!\n\n";
    } else if (function_exists("clean_up",contents[i])) {
      contents[i]->clean_up();
			reset_eval_cost();
    }
      if  (objectp(contents[i])) {
				 if (verbose) results += " was not wiped.\n"; }
      else {
        if (verbose) results += " was wiped.\n";
        number++;
      }
    } else results += "\n";
  }
  results += number+((number == 1) ? " object was" : " objects were")+" wiped.\n";
  results += "There "+((i==1)?"was ":"were ")+i+((i==1)?" object":" objects")+".\n";
  write(results);
  rm("/log/CleanUpList");
  write_file("/log/CleanUpList",results);
  return 1;
}


string help() {
  return(wrap("syntax:  cleanup [-v|r|l|f]\n\n"+
             "  This command with the -r options will attempt to reclaim "+
             "any loose objects in the mud.  With the -l option it will "+
             "print out a list of all the objects on the mud to the screen, "+
             "use -v for a very verbose wipe. The -f flag will force a write"+
             "to your screen, handy for finding crashers :)\nAll flags, except"+
             " the l flag will call clean_up() in every object on the mud."
       ));
}
