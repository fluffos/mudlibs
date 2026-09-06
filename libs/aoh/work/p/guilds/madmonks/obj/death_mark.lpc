/* The death of priest with all the "Brimborium" */

#include "/secure/config.h"
#include "/secure/wizlevels.h"
#include <moving.h>

int player_died()
{
  int    level;
  object player;
  string name;
  int    gender;

  player = previous_object();

  player->SetGhost(1);
  if((level = (int)player->QueryLevel()) > 1)
    player->SetLevel(level - 1);
  player->SetDrink(0);
  player->SetFood(0);
  player->SetAlcohol(0);

#ifdef LOG_KILLS
  {
    object attacker;
    if ((attacker = this_player()) && query_ip_number(attacker)) {
      log_file("KILLER", ctime(time()) + " " +
	       attacker->QueryRealName() + "(" +
	       attacker->QueryLevel() + ") killed " +
	       player->QueryRealName() + "(" + level + ").\n");
      attacker->SetKills(attacker->QueryKills()+1);
    } else {
      log_file("KILLS", player->QueryRealName() + "(" + level +
	       ") killed by " + attacker->QueryName() + "(" +
	       attacker->QueryRealName() + "), creator: " + getuid(attacker) +
	       ".\n");
    }
  }
#endif

tell_object(player,
       "You can see an old and dirty man standing besides your inventory.\n"
       "He shakes his head and looks very confused. You remember him as\n"
       "your friendly teacher but now he looks at you with dark black and\n"
       "hard looking eyes. Or .... Uhhhh ...... this arent eyes,.. this are\n\n"
       "...................STONES, black STONES......................\n\n\n");
tell_object(player,
       "Balgarion says: LOOKS LIKE MAGICTCS DIDNT TEACH YOU WELL.\n"
       "                BUT I HOPE I TEACHED YOU WHAT TO DO NOW!\n\n");
tell_object(player,
       "Balgarion says: NOW YOU HAVE THE JOICE: LIFE OR HONOUR!\n"
       "                JUST TYPE ONE OF IT NOW!!!!            \n\n");
    player->move("/players/balgarion/guild/room/choice",M_TELEPORT);
    return 1;
  }
