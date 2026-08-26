// Petrarch
// Merentha Lib 1.0
// <tell>

#include <daemons.h>

string help() {
return "\
Syntax: tell <player> <message>\n\
        tell <player>@<mud> <message>\n\n\
Sends a message instantly to the player named.  When the @ is used sends a \
message to a player on a remote MUD.  The remote MUD must be connected to \
the Merentha InterMUD System.  If the MUD in question has a space in \
its name use a . in place of the space.\n\n\
Examples: tell petrarch hello\n\
          tell petrarch@Merentha.Reborn hello\n\n\
See also: say\n\
See also: muds, users, finger";
}

int command(string str) {
object ob;
string person, message, mud;
  if(!str || sscanf(str, "%s %s", person, message)!=2) return notify_fail("Tell who what?\n");
  if(strsrch(person, "@")>-1) {
    sscanf(person, "%s@%s", person, mud);
    return NETWORK_D->send_rtell_request(mud, this_player()->query_name(), person, message);
  }
  if(!ob=find_player(person)) return notify_fail("Could not locate "+person+".\n");
  message("communication", this_player()->query_cap_name()+" tells you: "+message, ob);
  message("communication", "You tell "+ob->query_cap_name()+": "+message, this_player());
  return 1;
}

