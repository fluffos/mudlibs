/* Do not remove the headers from this file! see /USAGE for more info. */

/*
** loot_d.c -- Controls spawns in the domains
** This daemon manages materials, loot, salvage, upgrade and crafting.
**
** Tsath 2019-10-14
**
*/

inherit M_DAEMON_DATA;
inherit M_DICE;
#define PRIV_NEEDED "Mudlib:daemons"

string currency_type = DOMAIN_D->query_currency("std") || "gold";

object coins_treasure(int level, string currency)
{
   float coins = 0.0;
   int p = random(100) + 1;

   switch (level)
   {
   case 1..16:
      switch (p)
      {
      case 1..30:
         coins += (x_dice(5, 6) * (level / 16.0)) * 0.01;
         break;
      case 31..60:
         coins += (x_dice(4, 6) * (level / 16.0)) * 0.05;
         break;
      case 61..70:
         coins += (x_dice(3, 6) * (level / 16.0)) * 0.1;
         break;
      case 71..95:
         coins += (x_dice(3, 6) * (level / 16.0));
         break;
      case 96..100:
         coins += (x_dice(1, 6) * (level / 16.0)) * 10.0;
         break;
      }
      break;
   case 17..40:
      switch (p)
      {
      case 1..30:
         coins += (x_dice(4, 6) * ((level - 16) / 23.0));
         coins += (x_dice(1, 6) * ((level - 16) / 23.0)) * 0.5;
         break;
      case 31..60:
         coins += (x_dice(6, 6) * ((level - 16) / 23.0));
         coins += (x_dice(2, 6) * ((level - 16) / 23.0)) * 10.0;
         break;
      case 61..70:
         coins += (x_dice(1, 6) * ((level - 16) / 23.0)) * 0.5;
         coins += (x_dice(2, 6) * ((level - 16) / 23.0)) * 10.0;
         break;
      case 71..95:
         coins += (x_dice(4, 6) * ((level - 16) / 23.0)) * 10.0;
         break;
      case 96..100:
         coins += (x_dice(5, 6) * ((level - 16) / 23.0)) * 10.0;
      };
      break;
   case 41..64:
      switch (p)
      {
      case 1..20:
         coins += (x_dice(4, 6) * 10 * ((level - 40) / 23.0));
         coins += (x_dice(1, 6) * 10 * ((level - 40) / 23.0)) * 10.0;
         break;
      case 21..35:
         coins += (x_dice(4, 6) * 20 * ((level - 40) / 23.0));
         coins += (x_dice(1, 6) * 10 * ((level - 40) / 23.0)) * 10.0;
         break;
      case 36..75:
         coins += (x_dice(2, 6) * 100 * ((level - 40) / 23.0));
         coins += (x_dice(1, 6) * 10 * ((level - 40) / 23.0)) * 10.0;
         break;
      case 76..100:
         coins += (x_dice(4, 6) * 10 * ((level - 40) / 23.0)) * 10.0;
         break;
      }
      break;
   case 65..80:
      switch (p)
      {
      case 1..15:
         coins += (x_dice(2, 6) * 200 * ((level - 40) / 23.0));
         coins += (x_dice(8, 6) * 10 * ((level - 40) / 23.0)) * 10.0;
         break;
      case 16..55:
         coins += (x_dice(2, 6) * 1000 * ((level - 40) / 23.0));
      case 56..100:
         coins += (x_dice(2, 6) * 1000 * ((level - 40) / 23.0));
         coins += (x_dice(1, 6) * 100 * ((level - 40) / 23.0)) * 10.0;
         break;
      }
      break;
   }

   TBUG(currency);
   return new (COINS, coins, currency);
}

void drop_corpse(object adversary)
{
   string corpse_filename = adversary->query_corpse_filename();
   string corpse_long = adversary->query_corpse_long();
   string in_room_singular = adversary->in_room_singular();
   string in_room_plural = adversary->in_room_plural();
   string dom = file_domain(adversary);
   string cur = DOMAIN_D->query_currency(dom) || "gold"; // Use "gold" as fallback.

   // Handling of players dropping corpses
   if (adversary->is_body())
   {
      string player_domain = explode(base_name(environment(adversary)), "/")[1];
      object stone_room = DOMAIN_D->find_soul_stone_in_domain(player_domain, adversary);
      object corpse = new (corpse_filename, adversary->query_name(), corpse_long);

      // If we do not have a stone room, we give up and move to void.
      if (!objectp(stone_room))
         stone_room = load_object(VOID_ROOM);

      corpse->override_room_desc(in_room_singular, in_room_plural);
#ifdef PLAYERS_DROP_EQUIPMENT_AT_DEATH
      all_inventory(adversary)->set_worn(0);
      all_inventory(adversary)->set_damaged();
      all_inventory(adversary)->reduce_value_by(10);
      all_inventory(adversary)->move(corpse);
#endif
      corpse->move(environment(adversary));
      adversary->move(stone_room);
   }
   else // everybody else
   {
      object corpse = new (corpse_filename, adversary->query_name(), corpse_long);
      object death_location = environment(adversary);
      adversary->move(HEAVEN);
      corpse->override_room_desc(in_room_singular, in_room_plural);
      if (sizeof(all_inventory(adversary)))
      {
         all_inventory(adversary)->set_worn(0);
         all_inventory(adversary)->set_damaged();
         all_inventory(adversary)->reduce_value_by(10);
         all_inventory(adversary)->move(corpse);
         coins_treasure(adversary->query_level(), cur)->move(corpse);
      }
      if (adversary->query_drops_pelt())
      {
         object pelt = new (PELT);
         pelt->set_pelt_size(adversary->query_level());
         pelt->set_pelt_type(adversary->query_drops_pelt());
         pelt->move(corpse);
      }
      corpse->move(death_location);
   }
}

object *create_gems(int num, int cap)
{
   object *gems = ({});
   int c = 0;
   while (c < num)
   {
      gems += ({new (GEM, cap)});
      c++;
   }
   return gems;
}

object *create_art(int num, int value)
{
   object *art = ({});
   int c = 0;
   while (c < num)
   {
      art += ({new (ART_OBJECT, value)});
      c++;
   }
   return art;
}

object *loot_chest(int level, object env)
{
   object *loot = ({});
   float coins = 0.0;
   object t;
   object *t_ar = ({});
   int roll = random(100);
   string dom = file_domain(env);
   string cur = DOMAIN_D->query_currency(dom) || "gold"; // Use "gold" as fallback.
   int count;

   // Chest coins first
   switch (level)
   {
   case 0..16:
      coins += (x_dice(6, 6) * 100 * (level / 16.0)) * 0.01;
      coins += (x_dice(3, 6) * 100 * (level / 16.0)) * 0.1;
      coins += (x_dice(2, 6) * 10 * (level / 16.0));

      if (coins > 0)
         loot += ({new (COINS, coins, cur)});
      // Gems

      switch (roll)
      {
      case 1..6:
         break;
      case 7..16:
         count = x_dice(2, 6);
         count *= level / 16.0;
         loot += create_gems(count, 10);
         break;
      case 17..26:
         count = x_dice(2, 4);
         count *= level / 16.0;
         loot += create_art(count, 25);
         break;
      case 27..36:
         count = x_dice(2, 6);
         count *= level / 16.0;
         loot += create_gems(count, 50);
         break;
      case 37..44:
         count = x_dice(2, 6);
         count *= level / 16.0;
         loot += create_gems(count, 10);
         break;
      case 45..52:
         count = x_dice(2, 6);
         count *= level / 16.0;
         loot += create_art(x_dice(2, 4), 25);
         break;
      case 53..60:
         count = x_dice(2, 6);
         count *= level / 16.0;
         loot += create_gems(count, 50);
         break;
      case 61..65:
         count = x_dice(2, 6);
         count *= level / 16.0;
         loot += create_gems(count, 10);
         break;
      case 66..70:
         count = x_dice(2, 4);
         count *= level / 16.0;
         loot += create_art(count, 25);
         break;
      case 71..75:
         count = x_dice(2, 6);
         count *= level / 16.0;
         loot += create_gems(count, 50);
         break;
      case 76..78:
         count = x_dice(2, 6);
         count *= level / 16.0;
         loot += create_gems(count, 10);
         break;
      case 79..80:
         count = x_dice(2, 6);
         count *= level / 16.0;
         loot += create_art(count, 25);
         break;
      case 81..85:
         count = x_dice(2, 6);
         count *= level / 16.0;
         loot += create_gems(count, 50);
         break;
      case 86..92:
         count = x_dice(2, 6);
         count *= level / 16.0;
         loot += create_art(count, 25);
         break;
      case 93..97:
         count = x_dice(2, 6);
         count *= level / 16.0;
         loot += create_gems(count, 64);
         break;
      case 98..99:
         count = x_dice(2, 4);
         count *= level / 16.0;
         loot += create_art(count, 25);
         break;
      case 0:
         count = x_dice(2, 6);
         count *= level / 16.0;
         loot += create_gems(count, 64);
         break;
      }
   }

   return loot;
}

void drop_chest(object slayer, int level)
{
   object chest;
   object *loot = loot_chest(level, environment(slayer));
   if (!slayer || !slayer->is_body())
      slayer = this_body();
   chest = new ("/std/loot_chest", slayer);
   loot->move(chest);
}

void create()
{
   ::create();
}
