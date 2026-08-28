

#include <std.h>

#include <security.h>



inherit DAEMON;



object *players_only()

   {

   object *players;

   players = users();

   players = filter_array(players, "is_wizard", this_object());

   return players;

   }



int is_wizard(object dork)

   {

   if (wizardp(dork))

      return 0;

   return 1;

   }



int cmd_echotell(string str) {

  int i;

  string sucker, foo;

  object *posers;

    if(!str) {

        notify_fail("Echoall what?\n");

        return 0;

    }

   sscanf(str, "%s tells you:%s", sucker, foo);

   posers = players_only();

   for (i=0; i<sizeof(posers); i++)

      {

      message("tell", str, posers[i],

      find_player(lower_case(sucker)) );

      posers[i]->set("reply", lower_case(sucker));

      }

   message("tell", sprintf("You tell Everyone: %s.", foo),

      find_player(lower_case(sucker)) );

    seteuid(UID_LOG);

    seteuid(getuid());

    return 1;

}



void help() {

    message("help",

      "Syntax: <echoall [message]>\n\n"

      "Sends the message to all users in the game.  Abuse of this "

      "power can result in serious action from law.", this_player()

    );

}

