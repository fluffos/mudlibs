/* Do not remove the headers from this file! see /USAGE for more info. */

#include <hooks.h>

varargs mixed call_hooks(string, mixed, mixed);
int query_attack_speed();
string query_random_armour_slot();
object query_target();
object get_target();
object query_weapon();
void add_event(object target, object weapon, mixed target_extra, mixed data);
int chance_to_hit(object, object);
int defend_chance(object, object);
int disarm_chance(object);
int calculate_damage(object, object);
string badly_wounded();
string very_wounded();
int panic();
void try_heal();
varargs void stop_fight(object);
int check_condition(int);
void simple_action(string);
int query_ghost();
void target_is_asleep();
void handle_events();
int try_to_ready();
object *query_readied();
void remove_readied(object);
int query_prone();
int stand_up();

void dispatch_opponent()
{
   add_event(query_target(), query_weapon(), 0, "dispatch");
}

int try_to_ready()
{
   object weapon = query_weapon();
   object *ammo = all_inventory(this_object());
   ammo = filter_array(ammo, ( : $1->is_ammo() && $1->query_ammo_type() == $2:), query_weapon()->query_ammo_type());

   if (sizeof(ammo))
   {
      ammo[0]->do_ready();
      weapon->load(ammo[0]);
      // TBUG("Ammo found, readying.");
      return 1;
   }
   // TBUG("No matching ammo found");
   return 0;
}

void take_a_swing(object target)
{
   object weapon = query_weapon();
   object ammo;
   object *effs = mapp(this_object()->query_effects()) ? values(this_object()->query_effects()) : ({});
   int chance, roll;

   if (badly_wounded())
      panic();
   else if (very_wounded() && random(10) < 4)
   {
      try_heal();
   }

   // Hooks into M_GUILD_MEMBER to fire off specials.
   if (random(100) < this_object()->query_special_chance())
   {
      this_object()->do_special();
   }

   // This handles loadable weapons - eg bows
   // If they aren't loaded - load them and return
   // If they are, treat the ammunition as the weapon for combat
   if (weapon->query_loadable())
   {
      if (!sizeof(query_readied())) // Any ammunition selected and ready ?
      {
         // TBUG("Attempting to ready ammo.");
         if (try_to_ready()) // Try to ready ammunition for next round
            return;
      }
      if (weapon->query_loaded()) // Is weapon ready to fire ?
      {
         // TBUG("We're loaded.");
         weapon->discharge(target); // Call discharge() in weapon
         // TBUG("Discharged.");
         ammo = query_readied()[0]; // Use ammo as weapon
         // TBUG("Ammo as weapon");
         if (ammo)
         {
            ammo->discharge(target); // Call discharge() in ammunition
            if (!weapon->query_loaded())
            {
               ammo->ammo_spent();
               // TBUG("Ammo spent: Removing readied.");
               remove_readied(ammo); // Remove ammunition from readied list
            }
            else
            {
               weapon = ammo;
            }
         }
      }
      else
      {
         // TBUG("Attempting to load ammo.");
         if (try_to_ready()) // Try to ready ammunition for next round
            return;
      }
   }

   // TBUG("Weapon is now: "+weapon);

   chance = chance_to_hit(weapon, target);

   foreach (object eff in effs)
   {
      if (eff)
         eff->effect_modify_chance_to_hit(weapon, target, chance);
   }

   if (chance < 2)
      chance = 2;
   if (chance > 98)
      chance = 98;

   roll = random(100);

   // TBUG(this_object()->short() + " attacks " + target->short() + " Attack chance: " + chance + " Roll: " + roll);

   if (roll > chance)
   {
      if (random(100) < disarm_chance(target) && target->query_weapon() != target)
         add_event(target, weapon, 0, "disarm");
      else
         add_event(target, weapon, 0, "miss");
   }
   else
   {
      // Add defense
      int defense = defend_chance(weapon, target);
      int damage = calculate_damage(weapon, target);
      int def_roll = random(100);
      if (defense < 5)
         defense = 5;

      // If target defended successfully, halve the damage
      if (def_roll <= defense)
      {
         damage = damage * 0.5;
         //      TBUG(this_object()->short() + " attacks " + target->short() + " Def chance: " + defense + " DEFENDED");
      }
      //    else
      //      TBUG(this_object()->short() + " attacks " + target->short() + " Def chance: " + defense + " FAIL DEFEND");

      add_event(target, weapon,
                target->query_random_armour_slot(), // Use the TARGET's armour slots, not your own, duh.
                damage);
   }
}

void attack()
{
   object target;
   mixed tmp;

   tmp = call_hooks("prevent_combat", ( : $1 + "|" + $2:));
   if (sizeof(tmp))
   {
      tmp = explode(tmp, "|");
      tmp -= ({"0"});

      // Remove mesages with # infront. They're silent attack preventions.
      foreach (string msg in tmp)
         if (msg[0..0] == "#")
            tmp -= ({msg});

      if (sizeof(tmp))
      {
         tmp = format_list(tmp);
         tell(this_object(), "Attack prevented by " + tmp + ".\n");
      }
      return;
   }

   if (!query_ghost() && query_prone())
   {
      stand_up();
      simple_action("$N $vget back up.");
      return;
   }

   /* check whether we are capable of attacking */
   if (tmp = check_condition(1))
   {
      if (tmp[ < 1] == '\n')
         write(tmp);
      /*
      else
        simple_action(tmp + "so $p blows are ineffective.");
        */
      return;
   }

   for (int n = 0; n < query_attack_speed(); n++)
   {
      /* any reason to continue the carnage? */
      if (query_ghost() || !(target = get_target()))
      {
         stop_fight();
         return;
      }

      if (target->query_asleep())
      {
         /* Our target is unconscious. We get to have our way with them
          * *evil grin*
          */
         target_is_asleep();
         return;
      }

      take_a_swing(target);
      handle_events();
   }
}
