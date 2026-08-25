#include "inet.h"
#include "udp.h"
nosave string my_file_name;

void wiz_commands() {
  add_action("do_echo","echo");
  add_action("do_emote_all", "emoteall");
  add_action("do_echo_to", "echoto");
  add_action("do_channels", "cre");
  add_action("do_channels","dwcre");
  add_action("do_channels","intercre");
  add_action("do_channels","sport");
  add_action("do_channels","geek");
  // Radix was here...
  if(this_object()->query_lord())
  {
     add_action("do_channels","demi");
     add_action("do_channels","thane");
    add_action("do_channels", "dwadmin");
     add_action("do_god_inform", "ginfo");
     return;
  }
  if(this_object()->query_thane())
     add_action("do_channels","thane");

} /* wiz_commands() */
void my_mess(string fish, string erk);
/* to properly columnate word_typed things */
 /*
void my_mess(string fish, string erk) {
  if(!interactive()) return;
  printf("%s%-=*s\n", fish, (int)this_player()->query_cols()-strlen(fish), 
          this_object()->fix_string(erk));
} */ /* my_mess() */

int do_god_inform(string mess)
  {
   if(!mess) 
   {
      notify_fail("Syntax: ginfo <message>\n");
      return(0);
   }
  mess = replace(mess, " ", " ");
  event(users(), "god_inform", (string)this_object()->query_cap_name() +
    " [Info]: ", mess); 
  /*
  tell_object(users(), (string)this_object()->query_cap_name() + 
              " Info: " + mess", this_object());
  */

  // my_mess("You inform: ", mess);
  return 1;
} /* do god inform */

int do_echo(string str) 
  {
  if (!str || str == "") {
    notify_fail("Syntax : echo <text>\n");
    return 0;
  }
  log_file("ECHOS", ctime(time())+" "+this_player()->query_name()+" echo's: "+
                    str+"\n");
  str += "%^RESET%^";
  my_mess("You echo: ", str);
  event(environment(), "player_echo", str + "\n");
  return 1;
} /* do_echo() */
 
int do_echo_to(string str) 
  {
  string who, what;
  object ob;
   // Radix cause Piper & Taniwha wanted it...
   if(this_player(1)->query_object_type() == "B")
   {
      notify_fail("Echoto is not available to Builders.\n");
      return(0);
   }
  if(!str || str == "") {
    notify_fail("Syntax : echoto <player> <text>\n");
    return 0;
  }
  if(sscanf(str, "%s %s", who, what) != 2) {
    notify_fail("Syntax : echoto <player> <text>\n");
    return 0;
  }
  who = lower_case(who);
  who = (string)this_object()->expand_nickname(who);
  ob = find_player(who);
  log_file("ECHOS", ctime(time())+" "+this_player()->query_cap_name()+
                    " Echoto's "+who+": " +what+"\n");
  what += "%^RESET%^";
  my_mess("You echo to " + who + ": ", what);
  event(ob, "player_echo_to", what + "\n");
  return 1;
} /* do_echo_to() */

int do_emote_all(string str) 
  {
  if(!str || str == "") {
    notify_fail("Syntax : emoteall <string>\n");
    return 0;
  }
   // Radix cause Piper & Taniwha wanted it...
   if(this_player(1)->query_object_type() == "B")
   {
      notify_fail("Emoteall is not available to Builders.\n");
      return(0);
   }
  log_file("ECHOS", ctime(time())+" "+this_player()->query_cap_name()+
                    " Emotealls: "+str+"\n");
  str += "%^RESET%^";
  my_mess("You emoteall : ", this_player()->query_cap_name()+" " + str);
  event(users(), "player_emote_all", this_player()->query_cap_name() + " "
                 + str + "\n");
  return 1;
} /* do_emote_all() */

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
  /*
  (UDP_PATH+"gwizmsg")->send_gwizmsg(str, emoted);
  */
  write("The message may take a while to reach some places.\n");
   return 1;
 } /* do_inter_creator_tell() */
