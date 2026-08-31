/* Do not remove the headers from this file! see /USAGE for more info. */

/*
** NPC_BOSS (Tsath 2020-2021)
**
** Functions for monsters bosses.
**
*/

#define CAN_SLAY_AFTER 10

int query_level();
int query_ghost();

int drops_loot = 0;
private
mapping slayers = ([]);

int is_boss()
{
   return 1;
}

// Anti-sniping mechanics
int check_for_loot(object slayer)
{
   if (slayers[slayer->query_name()])
   {
      if (time() > slayers[slayer->query_name()] + CAN_SLAY_AFTER)
         return 1;
      else
         return 0;
   }

   slayers[slayer->query_name()] = time();
   return 1;
}

mapping slayers()
{
   return slayers;
}

void slain_by(object slayer)
{
   if (slayer->is_body() && query_ghost() && check_for_loot(slayer))
   {
      LOOT_D->drop_chest(slayer, query_level());
   }
}

//: FUNCTION boss_loot
// void boss_loot()
// Makes the monster drop boss loot
void boss_loot()
{
   drops_loot = 1;
}