//  Buddy List by Nightshade

#include <std.h>
inherit DAEMON;

int cmd_buddylist(string str) {
  string *list, total;
  if(!str) {
    list = this_player()->query_full_buddy();
    if(sizeof(list) > 400) {
      for(int i=1; i < sizeof(list); i++)
        this_player()->remove_buddy(list[i]);
      list = ({});
    }
    if(sizeof(list) < 1) {
      write("No buddies in list.");
      return 1;
    }
    write("%^BLUE%^+=+=%^BOLD%^( %^WHITE%^Buddy List %^BLUE%^)%^RESET%^%^BLUE%^=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=%^RESET%^\n");
    if(member_array("all", this_player()->query_full_buddy()) != -1) {
      write("   All players are your buddies.");
      return 1;
    }
    total = "   "+capitalize(list[0]);
    if(sizeof(list) > 1)
      for(int i=1; i < sizeof(list); i++)
        total += ", "+capitalize(list[i]);
    write(total);
    return 1;
  }
    if(str == "all") {
    if(member_array(str, this_player()->query_full_buddy()) == -1) {
      this_player()->add_buddy(str);
      write("All players added to buddy list.");
    }
    else {
      this_player()->remove_buddy(str);
      write("All players no longer in buddy list.");
    }
    return 1;
  }
  if(sscanf(str,"add %s", str) == 1) {
    str = lower_case(str);
      if( sizeof( this_player()->query_full_buddy() ) >= 400 )
      return notify_fail("Your buddylist is full.\n");
    if(member_array(str, this_player()->query_full_buddy())+1) {
      write(capitalize(str)+" is already in your list!");
      return 1;
    }
    this_player()->add_buddy(str);
    write(capitalize(str)+" added to your list.");
    return 1;
  }
  if(sscanf(str,"remove %s", str) == 1) {
    if(!this_player()->remove_buddy(str) && !this_player()->remove_buddy(lower_case(str)))
      write("Buddy not found.");
    else
      write(capitalize(str)+" removed.");
    return 1;
  }
  write("Syntax: <buddylist add [person]>\nSyntax: <buddylist remove [person]>\nSyntax: <buddylist>\n");
  return 1;
}

void help() {
 message("info", "Syntax: <buddylist add [person]>\n"
"Syntax: <buddylist remove [person]>\n"
"Syntax: <buddylist>\n"
"Syntax: <buddylist all>\n"
"The buddylist informs you when people on your list come on and offline.\n"
"If you type only <buddylist>, it will display everyone in your list.\n"
"<buddylist all> will make everyone your \"buddy\".", this_player());
}
