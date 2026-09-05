#ifndef PROCESS_H
#define PROCESS_H

/***************************************************************************/
/* process_msg */

/*
 *  This fn uses the efun process_string()
 *
 *  Process_string(str) allows you to call a function that returns a string.
 *  It has the form, 
 *        "@@function:filename|arg1|arg2...@@"
 *
 *  However, its form only allows specific object names. To be more useful
 *  it needs to be able to accept 'this_player(), this_object()' etc.
 *
 *
 *  Example:
 *   say(process_msg("@@query_name:$this_player()$@@ casts a fireball!\n"));
 *
 *  Now this may seem trivial, why not just say,
 *  say(this_player()->query_name()+" casts a fireball!\n");
 *
 *  The thing is that it can be used in strings of configurable objects!
 */
 

string process_msg(string str) {
  string obj_file, tmp1, tmp2, tmp3;

  if(!str) return "";

  if(this_object()) {
    obj_file = file_name(this_object());
    while(sscanf(str,"%s$this_object()$%s", tmp1, tmp2)) {
      str = tmp1 + obj_file + tmp2;
    }
  }

  if(this_player()) {
    obj_file = file_name(this_player());
    while(sscanf(str,"%s$this_player()$%s", tmp1, tmp2)) {
      str = tmp1 + obj_file + tmp2;
    }
  }

  if(previous_object()) {
    obj_file = file_name(previous_object());
    while(sscanf(str,"%s$previous_object()$%s", tmp1, tmp2)) {
      str = tmp1 + obj_file + tmp2;
    }
  }

  if(environment()) {
    obj_file = file_name(environment());
    while(sscanf(str,"%s$environment()$%s", tmp1, tmp2)) {
      str = tmp1 + obj_file + tmp2;
    }
  }

  if(environment(this_player())) {
    obj_file = file_name(environment(this_player()));
    while(sscanf(str,"%s$environment(this_player())$%s", tmp1, tmp2)) {
      str = tmp1 + obj_file + tmp2;
    }
  }
  str = process_string(str);

/* filter out failed processes - so players don't see them */

  while(sscanf(str,"%s@@%s@@%s", tmp1, tmp2, tmp3)) {
    str = tmp1 + tmp3;
  }
  return str;
}


#endif /* PROCESS_H */

