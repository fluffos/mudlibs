
/* Do not remove the headers from this file! see /USAGE for more info. */

// CLUSTER_EQUIPMENT

#include <behaviour.h>

void add_child(string node, string child);
varargs void create_node(int type, string name, mixed offspring);
object *worst_threats_present();
object *query_targets();
string badly_wounded();
string very_wounded();
void do_game_command(string str);

int no_heals = 0;

void init_equipment_cluster()
{
   // If any of these ones return true we stop here, and navigate somewhere else
   create_node(NODE_SELECTOR, "equipment_seq", ({"upgrade_true", "hurt", "find_heal"}));

   // Add equipment sequence to root sequence.
   add_child("root_sequence", "equipment_seq");
   create_node(NODE_SUCCEEDER, "upgrade_true", ({"upgrade_seq"}));

   // Look for better armour
   create_node(NODE_SELECTOR, "upgrade_seq", ({"find_armour_in_inventory", "find_armour_in_room"}));

   // Heal ourselves if needed
   create_node(NODE_SEQUENCE, "hurt", ({"safe_to_heal", "use_heal"}));
   create_node(NODE_SEQUENCE, "find_heal", ({"take_from_room", "use_heal"}));
   create_node(NODE_LEAF, "safe_to_heal");
   create_node(NODE_LEAF, "use_heal");

   // Can we find something useful to pick up?
   create_node(NODE_LEAF, "take_from_room");
   create_node(NODE_LEAF, "find_armour_in_inventory");
   create_node(NODE_LEAF, "find_armour_in_room");
}

int use_heal()
{
   object *consumables = filter_array(all_inventory(this_object()), ( : $1->is_healing() :));
   object pick;
   string limb = very_wounded() || badly_wounded();

   if (sizeof(consumables))
      pick = choice(consumables);

   if (!pick)
   {
      no_heals = 1;
      return;
   }

   // Bit defensive code here since things are very interactive and can disappear
   // quickly.
   if (pick->is_bandage() && limb)
   {
      this_object()->do_game_command("apply bandage to " + limb);
      return EVAL_SUCCESS;
   }
   else if (pick->is_food())
   {
      pick->do_eat(this_object());
      return EVAL_SUCCESS;
   }
   else if (pick->is_drink())
   {
      pick->drink_it(this_object());
      return EVAL_SUCCESS;
   }
   return EVAL_FAILURE;
}

int safe_to_heal()
{
   string wounded = this_object()->badly_wounded() || this_object()->very_wounded();
   int targets = sizeof(query_targets() - ({0}));

   // We're not fighting
   return targets ? EVAL_FAILURE : EVAL_SUCCESS;
}

int take_from_room()
{
   object *consumables;
   object pick;

   if (!environment())
      return EVAL_FAILURE;
   consumables = filter_array(all_inventory(environment()), ( : $1->is_healing() :));

   if (sizeof(consumables))
      pick = choice(consumables);
   if (!pick)
      return EVAL_FAILURE;

   // Grab it!
   do_game_command("get " + pick->short());

   // We got it!
   if (environment(pick) == this_object())
   {
      no_heals = 0;
      return EVAL_SUCCESS;
   }
   return EVAL_FAILURE;
}

int find_armour_in_inventory()
{
   object *armours = filter(all_inventory(this_object()), ( : $1->is_wearable() :));
   object *not_worn = filter(armours, ( : !$1->ob_state() :));
   int worn = 0;

   foreach (object nwa in not_worn)
   {
      object *armour_obs;
      int armour_cnt;
      string slot = nwa ? nwa->query_slot() : 0;
      if (!slot)
         continue;
      armour_obs = this_object()->query_armours(slot);
      armour_cnt = sizeof(armour_obs);

      if (!armour_cnt)
      {
         do_game_command("wear " + nwa->short());
         worn++;
      }

      // There can be more armours in same slot, but that's too much hassle.
      if (armour_cnt == 1)
      {
         // Defensive, but they can disappear...
         int current_ac = sizeof(armour_obs) ? armour_obs[0]->query_armour_class() : 0;

         // We found a better armour
         if (current_ac < nwa->query_armour_class())
         {
            do_game_command("remove " + armour_obs[0]->short());
            do_game_command("wear " + nwa->short());
            do_game_command("salvage " + armour_obs[0]->short());
            worn++;
         }
      }
   }
   return worn ? EVAL_SUCCESS : EVAL_FAILURE;
}

int find_armour_in_room()
{
   object *armours = filter(all_inventory(this_object()), ( : $1->is_wearable() :));
   object *in_room = filter(all_inventory(environment()), ( : $1->is_wearable() :));
   int worn = 0;

   foreach (object ira in in_room)
   {
      object *armour_obs;
      int armour_cnt;
      string slot = ira ? ira->query_slot() : 0;
      if (!slot)
         continue;
      armour_obs = this_object()->query_armours(slot);
      armour_cnt = sizeof(armour_obs);

      if (!armour_cnt)
      {
         do_game_command("get " + ira->short());
         do_game_command("wear " + ira->short());
         worn++;
      }

      // There can be more armours in same slot, but that's too much hassle.
      if (armour_cnt == 1)
      {
         // Defensive, but they can disappear...
         int current_ac = sizeof(armour_obs) ? armour_obs[0]->query_armour_class() : 0;

         // We found a better armour
         if (current_ac < ira->query_armour_class())
         {
            do_game_command("get " + ira->short());
            do_game_command("remove " + armour_obs[0]->short());
            do_game_command("wear " + ira->short());
            do_game_command("salvage " + armour_obs[0]->short());
            worn++;
         }
      }
   }
   return worn ? EVAL_SUCCESS : EVAL_FAILURE;
}

string equipment_features()
{
   return "<033>Equipment:\n<res>" + "\t- Heal from inventory\n"
                                     "\t- Find healing from rooms and claim\n"
                                     "\t- Wear better armours\n"
                                     "\t- Find better armours and wear them\n";
}