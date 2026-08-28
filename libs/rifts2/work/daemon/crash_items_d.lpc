/*
 * A daemon which keeps track of a player's crash-protected items.
 * the maintenance function is called out of the user's heart_beat.
 *
 * Diewarzau 8/3/96
 * DarkeLIB 1.0
 */
#include <dirs.h>

void add_crash_items(object tp, object *inv) {
  string *dir;
  object ob;
  int idx = 1;
  int i;
  string file, line;

  if(!tp || !inv) return;
  seteuid(getuid());
  dir = map_array(get_dir(sprintf(DIR_OBJECTS+"/crash/%s_*",
				  (string)tp->query_name())),
		  (: $2 + $1 :), DIR_OBJECTS+"/crash/");
  map_array(dir, (: rm :));
  foreach(ob in inv) {
    ob->save_me(sprintf("%s_%d", (string)tp->query_name(),
			idx));
    rename(sprintf(DIR_OBJECTS+"/%s_%d.o", (string)tp->query_name(),
	       idx),
       sprintf(DIR_OBJECTS+"/crash/%s_%d.tmp",
	       (string)tp->query_name(), idx));
    file = sprintf(DIR_OBJECTS+"/crash/%s_%d",
		   (string)tp->query_name(), idx);
    if(virtualp(ob)) {
      write_file(file+".o", sprintf("#%s", base_name(ob))+"\n");
      i = 2;
      while(line=read_file(file+".tmp", i, 1)) {
	write_file(file+".o", line);
	i++;
      }
      rm(file+".tmp");
    }
    else {
      rename(file+".tmp", file+".o");
    }
    idx++;
  }
}

void restore_crash_items(object tp) {
  int idx;
  string *dir;
  object ob;
  string file, obfile;

  seteuid(getuid());
  dir = map_array(get_dir(sprintf(DIR_OBJECTS+"/crash/%s_*",
                                  (string)tp->query_name())),
                  (: $2 + $1 :), DIR_OBJECTS+"/crash/");
  if(!dir || !sizeof(dir)) return;
  map_array(dir, (: rename($1, replace_string($1, $2, $3)) :),
	    "crash/", "");
  dir = map_array(dir, (: replace_string :), "crash/", "");
  foreach(file in dir) {
    obfile = replace_string(read_file(file, 1, 1), "#", "");
    obfile = replace_string(obfile, "\n", "");
    ob = new(obfile);
    idx = strsrch(file, "/", -1);
    if(idx == -1) {
      message("info", "-*>? Error in restoring one of your crash items.",
	      tp);
      continue;
    }
    ob->restore_me(replace_string(file[idx+1..], ".o", ""));
    rm(file);
    ob->move(tp);
    message("info", "-*> %^CYAN%^Item restored:%^RESET%^ "+
	    (string)ob->query_short()+".", tp);
  }
  return;
}

