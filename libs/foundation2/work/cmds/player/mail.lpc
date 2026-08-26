//      /bin/high_mortal/_mail.c
//      from the Nightmare Mudlib
//      the mail command
//      made for reasonable compatibility with Huthar's mailer
//      created by Descartes of Borg 27 july 1993

#include <lib.h>
#include <objects.h>

inherit LIB_DAEMON;

int cmd(string str) {
    object ob;

    if(!creatorp(this_player()) && !high_mortalp(this_player()) &&
      !ambassadorp(this_player())) return 0;
    ob = new(OB_POSTAL);
    ob->eventMove(this_player());
    ob->start_post(str);
    return 1;
}

void help() {
    write("Syntax: <mail ([player])(@[mud])\n\n"
      "Allows you to send mail from anywhere on the mud, as where as\n"
      "read your mail.  If you just wish to read it, type \"mail\"\n"
      "without any arguments.  If you wish to send mail to another\n"
      "player on the mud, give the player (or list of players) as\n"
      "an argument.  You may include players on other muds listed\n"
      "in the \"muds\" comman simply by placing and \"@\" followed\n"
      "the mud name after the player's name (ex: mail descartes@imaginary).\n"
    );
}
