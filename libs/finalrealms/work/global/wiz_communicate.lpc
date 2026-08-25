#include "inet.h"
#include "udp.h"
nosave string my_file_name;

void wiz_commands() {

} /* wiz_commands() */

void my_mess(string fish, string erk);

/* to properly columnate word_typed things */
 /*
void my_mess(string fish, string erk) {
  if(!interactive()) return;
  printf("%s%-=*s\n", fish, (int)this_player()->query_cols()-strlen(fish), 
          this_object()->fix_string(erk));
} */ /* my_mess() */

/*
int do_inter_creator_tell(string str) 
  {
  int emoted;
   
  if (!str)
  str = "";
  else
   if (str[0] != ' ') 
    {
    emoted = sscanf(str, "@ %s", str);
    if (!emoted) {
      notify_fail("Invalid flag to "+query_verb()+".\n");
      return 0;
      }
    }
   else if (sscanf(str, " @ %s", str))
     emoted = 1;
    else
     sscanf(str, " %s", str);
   if (!this_object()->query_creator())
     return 0;
   if (!str) {
     notify_fail("Sytnax: "+query_verb()+" <mess>\n");
     return 0;
     }
  if (this_object()->check_earmuffs("inter-creator-tell")) {
    notify_fail("You cannot inter thingy if you are not on the channel.\n");
    return 0;
    }
  INTERCREATORD->do_intercreator(str, emoted);

  write("The message may take a while to reach some places.\n");
  this_object()->set_trivial_action();
   return 1;
 }*/ /* do_inter_creator_tell() */
