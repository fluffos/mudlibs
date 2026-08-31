/*
** equip.c -- material pouch command
**
** Tsath, 2020
*/

//: PLAYERCOMMAND
//$$ see: skills, hp, stats, score, materials
// USAGE
//   ``equip``
//
// Shows your wielded and worn weapons and armours, their durability
// and some primary stats. The command also shows your spell failure chance
// which increases with the more medium and heavy armour you wear, the latter
// having a greater impact.
//
// Reparing and salvaging
// ----------------------
//
// You can repair your gear using the ``repair`` verb using components from
// ``salvage`` if you are next to a crafting bench. The components can be
// seen by using the ``materials`` command.
//
// You can easily salvage by using ``salvage all`` which will salvage all
// your damaged equipment. You can salvage other things by salvaging
// them one by one, i.e. ``salvage mace`` to salvage your non-damaged mace.
//
// Use ``repair all`` to repair all your equipment. The command will give you
// an estimate of the cost in materials and coins (if needed) before you
// decide to repair or not. Be careful not to repair things you do not want
// to keep. It does not pay to repair things you want to sell.
//
// .. TAGS: RST

inherit CMD;
inherit M_FRAME;
inherit M_WIDGETS;
inherit CLASS_WEAR_INFO;

mapping short_names = DAMAGE_D->query_short_names();

string short_damage_types(string *types)
{
   return format_list(map(types, ( : short_names[$1] :)));
}

string format_slots(object a, string *slots)
{
   if (a->also_covers())
      slots += a->also_covers();

   if (member_array("left foot", slots) != -1 && member_array("right foot", slots) != -1)
   {
      slots -= ({"left foot", "right foot"});
      slots += ({"feet"});
   }

   if (member_array("left leg", slots) != -1 && member_array("right leg", slots) != -1)
   {
      slots -= ({"left leg", "right leg"});
      slots += ({"legs"});
   }

   if (member_array("left arm", slots) != -1 && member_array("right arm", slots) != -1)
   {
      slots -= ({"left arm", "right arm"});
      slots += ({"arms"});
   }

   if (member_array("left hand", slots) != -1 && member_array("right hand", slots) != -1)
   {
      slots -= ({"left hand", "right hand"});
      slots += ({"hands"});
   }

   if (member_array("arms", slots) != -1 && member_array("legs", slots) != -1 && member_array("torso", slots) != -1)
   {
      slots -= ({"arms", "legs", "torso"});
      slots += ({"full body"});
   }

   if (member_array("arms", slots) != -1 && member_array("head", slots) != -1 && member_array("torso", slots) != -1)
   {
      slots -= ({"arms", "head", "torso"});
      slots += ({"upper body"});
   }

   slots = map(slots, ( : capitalize($1) :));
   return format_list(slots);
}

private
void main(string arg)
{
   object *weapons = ({});
   object *armours = ({});
   object body;
   int nothing_worn = 1;
   int nothing_wielded = 1;
   if (arg)
      arg = trim(arg);

   if (strlen(arg) > 0 && wizardp(this_user()))
   {
      body = find_body(arg) || present(arg, environment(this_body()));
      if (!body)
      {
         out("Cannot find '" + arg + "'.\n");
         return;
      }
      write("Equip for " + body->short() + ":\n");
   }
   else
      body = this_body();

   foreach (string limb in body->query_wielding_limbs())
   {
      if (member_array(body->query_weapon(limb), weapons) == -1)
         weapons += ({body->query_weapon(limb)});
   }

   // foreach (string limb in body->query_armour_slots())
   foreach (string limb in body->query_limbs())
   {
      if (body->find_wi(limb) && member_array(body->find_wi(limb), armours) == -1)
      {
         armours += ({((class wear_info)body->find_wi(limb))->primary});
         armours += ({((class wear_info)body->find_wi(limb))->secondary});
      }
   }

   weapons = filter_array(weapons, ( : $1:));
   armours = filter_array(armours, ( : $1:));
   frame_init_user();

   if (sizeof(weapons))
   {
      set_frame_title("Weapons");
      frame_add_column("Weapon", weapons->short());
      frame_add_column("WC", weapons->query_weapon_class() );
      frame_add_column("Durability", map(weapons, ( : $1->durability_percent() + "%" :)));
      frame_add_column("Damage Type", map(weapons, (
                                                       : short_damage_types($1->query_loadable() && $1->loaded_with()
                                                                                ? $1->loaded_with()->query_damage_type()
                                                                                : $1->query_damage_type())
                                                       :)));
      frame_add_column("Properties", map(weapons, ( : format_list($1->query_properties()) :)));
      nothing_wielded = 0;
      write(frame_render_columns());
   }

   if (sizeof(armours))
   {
      frame_init_user();
      set_frame_title("Armours");
      frame_add_column("Item", armours->short());
      frame_add_column("Worn on", map(armours, ( : format_slots($1, ({$1->query_slot()})) :)));
      frame_add_column("AC", map(armours, ( : $1->query_armour_class() || "-" :)));
      frame_add_column("Durabilty", map(armours, (
                                                     : $1->query_armour_class() ? $1->durability_percent() + "%" : "-"
                                                     :)));
      frame_add_column("Modifiers", map(armours, (
                                                     : ($1->query_stat_mod() >= 0 ? "+" : "") + // Add +
                                                               $1->query_stat_mod() +           //
                                                               $1->stat_mods_string(1)
                                                           ? $1->stat_mods_string(1)
                                                           : "" // something
                                                     :)));
      write(frame_render_columns());
      nothing_worn = 0;
   }

   if (nothing_worn & nothing_wielded)
      printf("You are wielding and wearing nothing.\n");
   else if (nothing_worn)
      printf("\n\n(You are wearing nothing)\n");
   else if (nothing_wielded)
      printf("\n\n(You are wielding nothing)\n");
}
