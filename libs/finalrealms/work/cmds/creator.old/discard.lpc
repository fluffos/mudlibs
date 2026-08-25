#include <standard.h>
#include <cmd.h>
inherit CMD_BASE;

void setup(){

position = 1;
}



/* This is for querying about objects who don't want to be destructed */
nosave object discard_obj;

protected int cmd(string str, object me) {
  string *file_names;
  int loop;
  string err;

  if (!str) {
    notify_fail("Discard what?\n");
    return 0;
  }
  file_names = this_player()->get_cfiles(str);
  for(loop = 0; loop < sizeof(file_names); loop++) {
    str = file_names[loop];
   discard_obj = find_object(str);
    if (!discard_obj) {
      if (file_size(str) < 0) notify_fail("No such file " + str + "\n");
      else {
        write(str + " is not loaded.\n");
      }
      continue;
    }

    /* Hamlet's addition */
    if(environment(discard_obj)) {
      tell_object(me,str + " has an environment.  Discarding is not "
                     "allowed.\n");
      continue;
    }

    err = catch(discard_obj->dest_me());
    this_player()->handle_error(err, "dest_me");
    if (discard_obj) {
      write("That object has a violent objection to being dested.\n");
      write("Are you sure you want to do this? ");
      input_to("no_discard");
      return 1;
    }
  }
  write("Ok.\n");
  return 1;
} /* discard() */

void no_discard(string s) {
   string err;

   if (this_player()->affirmative(s)) {
      err = catch(discard_obj->dwep());
      this_player()->handle_error(err, "DWEP");
      if (discard_obj) {
         write("It REALLY doesn't want to be discarded.\n");
         destruct(discard_obj);
         if (discard_obj) {
            write("It didn't destruct.\n");
            return;
         }
      }
   }
   write("Ok.\n");
   discard_obj = 0;
} /* no_discard() */
  
