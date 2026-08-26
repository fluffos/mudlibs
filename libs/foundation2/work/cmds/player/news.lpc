//    /cmd//    Nightmare Mudlib
//    Lets you replay the login news
//    By Kalinash@Nightmare July 10, 1994

#include <lib.h>
#include <dirs.h>

inherit LIB_DAEMON;

int cmd(string str) {
    if(str) {
     notify_fail("Just type news.\n");
     return 0;
    }
    if(!file_exists(DIR_NEWS+"/news"))
        message("my_action", "No Global News.", this_player());
    else
        this_player()->more(DIR_NEWS+"/news");
    return 1;
}

void help() {
    message("help", "Syntax : <news>\n\nThis command allows you to "
      "replay the login news.", this_player());
    return;
}
