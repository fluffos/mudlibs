/*
   /handlers/who.c
   Radix : April 1997
*/

/*
   TODO:
   Cache the player objects, storing the gender, race, other
   numerous queries saving all those endless queries.
*/

inherit "/std/object";

mapping who;

void create()
{
   object::create();
   who = ([ "creator" : ([ ]), "player" : ([ ]) ]);
}

void add_user(object ob)
{
   if(!ob->query_creator())
      who["player"][ob] =
         ({ ob->query_gender_string(),
            ob->query_race()
         });
   else
      who["creator"][ob] = 
         ({ ob->query_gtitle(),
            ob->query_title(),
            ob->query_extitle()
         });
   return;
}

mapping query_who() { return who; }

mapping query_creators() { return who["creator"]; }

mapping query_players() { return who["player"]; }

object * query_creator_obs() { return keys(who["creator"]); }

object * query_player_obs() { return keys(who["player"]); }
