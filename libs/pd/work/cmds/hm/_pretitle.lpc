#include <std.h>
#include <daemons.h>

inherit DAEMON;

int cmd_pretitle(string str) {
if(present("a_faerie_special_set_abcdefg", this_player()))
notify_fail("Magical forces that surround you prevent you from changing your pretitle.\n");
    if(!str) {
        write("You remove your title.");
        this_player()->set_env("TITLE", "");
        this_player()->set_env("PRETITLE", "");
        return 1;
    }
    if (this_player()->query_level() < 50 && !wizardp(this_player()))
      return notify_fail("You must achieve the rank of elite before you can do "
        "this.\n");
    str = TERMINAL_D->no_colours(str);
    if (sizeof(str) > 20) return notify_fail("That is too long.\n");
    if(!wizardp(this_player())) { 
//     if (this_player()->query_level() > 99)
//        str += "%^BOLD%^%^WHITE%^%^";
//     else str += "";
     str += "";
     write("Your title is now: "+str+" "+this_player()->query_cap_name());
        this_player()->setenv("PRETITLE", str);
        this_player()->setenv("TITLE", str+" $N");
    } 
    else 
    {
     write("Your title is now: "+str+"\n");
     this_player()->setenv("TITLE", str);
    }
    return 1;
}

void help() {
    write("Syntax: <pretitle [new pretitle]>\n\n"+
        "Changes your pretitle that comes before your name.\n");
}
