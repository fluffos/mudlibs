//      /bin/user/_money.c
//      from the Nightmare mudlib
//      a comand to allow players to search their pockets
//      created by Descartes of Borg 25 april 1993

#include <str_fmt.h>

#include <std.h>
inherit DAEMON;

int cmd_money(string str) {
    string *currs;
    string borg;
    int i, tmp;

    if(str) return 0;  /* to allow the wiz command to work */
    currs = (string *)this_player()->query_currencies();
    if(!currs || !sizeof(currs)) {
        write("You are broke.");
        say(this_player()->query_cap_name()+" comes up with empty pockets.");
        return 1;
    }
    say(this_player()->query_cap_name()+" fishes through "+
      this_player()->query_possessive()+" pockets examining some money.");

message("info", "%^BLUE%^+=+=%^BOLD%^( %^WHITE%^Money %^BLUE%^)%^RESET%^%^BLUE%^=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+", this_player());
   for(borg = "", i=0, tmp = sizeof(currs); i<tmp; i++) {
        borg += ((this_player()->query_money(currs[i]))+" "+currs[i]);
        if(i == tmp-1) borg +=(".");
        else if(tmp > 2 && i == tmp-2) borg += (", and ");
        else if(tmp == 2) borg +=(" and ");
        else borg +=(", ");
    }
    message("info", str_fmt(borg, 3), this_player());
  write("%^BLUE%^=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=");
    return 1;
}

void help() {
    write("Syntax: <money>\n\n"
      "Allows you to search your pockets for all your money\n"
      "of all currency types.\n"
    );
}
