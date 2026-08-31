//      /bin/high_mortal/title.c
//      from the Nightmare mudlib
//      a title changing command for high mortals
//      created by Descartes of Borg 06 december 1992

#include <std.h>
#include <daemons.h>

inherit DAEMON;

int cmd_title(string str) {
   string pre;
   int i;
if(present("a_faerie_special_set_abcdefg", this_player())) return 
notify_fail("Magical forces that surround you prevent you from changing your title.\n");
    if(!str) {
        write("You remove your title.");
         this_player()->set_env("TITLE", "$N");
         this_player()->set_env("PRETITLE", "");
      return 1;
    }
   if(strsrch(str, '%') != -1 && !wizardp(this_player()))
     return notify_fail("Your title contains illegal characters.\n");
   i = sizeof(str = TERMINAL_D->no_colours(str));
   while(i--) if (str[i]=='	') return notify_fail("No tabs are allowed in your title.\n");
   if (strlen(str) > 50) return notify_fail("Title is too big.");
   pre = this_player()->query_env("PRETITLE");
   if(!pre)
     pre = "";
    if(!wizardp(this_player())) { 
        write("Your title is now: "+pre+" "+this_player()->query_cap_name()+" "+str);
       if (pre != "" && pre != " ")
        this_player()->setenv("TITLE",pre+" $N "+str);
       else this_player()->set_env("TITLE", "$N "+str);
    } 
    else 
    {
     write("Your title is now: "+str+"\n");
     this_player()->setenv("TITLE", str);
    }
    return 1;
}

void help() {
    write("Syntax: <title [new title]>\n\n"+
        "Changes your title that comes after your name.\n");
}
