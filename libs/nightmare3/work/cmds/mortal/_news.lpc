//    /cmds/mortal/_news.c
//    Nightmare Mudlib
//    Lets you replay the login news
//    By Kalinash@Nightmare July 10, 1994

#include <std.h>
#include <dirs.h>

inherit DAEMON;

int cmd_news(string str) {
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
