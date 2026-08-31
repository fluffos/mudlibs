//  Ignore by Nightshade

#include <std.h>
inherit DAEMON;

#define IMMS ({"whit", "nightshade", "seeker", "stormbringer", "wiz" })

int cmd_ignore(string str) {
  string *list, total;
  if(!str) {
    list = this_player()->query_full_ignore();
    if(sizeof(list) < 1) {
      write("You are not ignoring anyone.");
      return 1;
    }
    write("%^BLUE%^+=+=%^BOLD%^( %^WHITE%^Ignored %^BLUE%^)%^RESET%^%^BLUE%^=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=%^RESET%^\n");
    total = "   "+capitalize(list[0]);
    if(sizeof(list) > 1)
      for(int i=1; i < sizeof(list); i++)
        total += ", "+capitalize(list[i]);
    write(total);
    return 1;
  }
  str = lower_case(str);
  if(member_array(str, IMMS) != -1) return 1;
  if(this_player()->query_ignoring(str)) {
    this_player()->change_ignore(str);
    write("You are no longer ignoring "+capitalize(str)+".");
  }
  else {
    this_player()->change_ignore(str);
    write("You are now ignoring "+capitalize(str)+".");
  }
  return 1;
}

void help() {
 message("info", "Syntax: <ignore [person]>\n"
"Syntax: <ignore>\n"
"You can ignore individual players with this command.\n"
"You will not see what they tell you, say to you, or what they say on lines.\n"
"To see who you are ignoring, type <ignore> by itself.  To be able to hear\n"
"someone again, use <ignore [person]> a second time.", this_player());
}
