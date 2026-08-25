/*
** equip.c -- material pouch command
**
** Tsath, 2020
*/

//: PLAYERCOMMAND
//$$ see: skills, hp, stats, score, pouch
// USAGE equip
//
// Shows your wielded and worn weapons and armours, their durability
// and some primary stats. The command also shows your spell failure chance
// which increases with the more medium and heavy armour you wear, the latter
// having a greater impact.
//
// Reparing and salvaging
//---
// You can repair your gear using the 'repair' verb using components from
//'salvage' if you are next to a crafting bench. The components can be
// seen in your 'pouch'.
//
// You can easily salvage by using 'salvage all' which will salvage all
// your damaged equipment. You can salvage other things by salvaging
// them one by one, i.e. 'salvage mace' to salvage your non-damaged mace.
//
// Use 'repair all' to repair all your equipment. The command will give you
// an estimate of the cost in materials and coins (if needed) before you
// decide to repair or not. Be careful not to repair things you do not want
// to keep. It does not pay to repair things you want to sell.

#include <config.h>

inherit CMD;
inherit M_FRAME;
inherit M_WIDGETS;
inherit CLASS_WEAR_INFO;

mapping short_names = DAMAGE_D->query_short_names();

int item_length(string *shorts)
{
   int width = this_user()->query_screen_width() - 60;
   int uni = uses_unicode();
   int smallest = max(map(shorts, ( : strlen($1) :)));
   string ellipsis = uni ? "…" : "...";
   int l = strlen(ellipsis);
   if (smallest < 8)
      smallest = 8;
   if (smallest < width)
      width = smallest;

   return CLAMP(width - l, 0, 100);
}

string ellipsis_name(string name, string *names)
{
   int width = item_length(names);
   int uni = uses_unicode();
   string ellipsis = uni ? "…" : "...";
   if (simplify())
      return capitalize(name);

   if (strlen(name) - strlen(ellipsis) > width)
   {
      name = !width ? "..." : trim(name[0..width]) + ellipsis;
   }
   return capitalize(name);
}

private
void main(string arg)
{
   object *weapons = ({});
   object *armours = ({});
   object body;
   int nothing_worn = 1;
   int nothing_wielded = 1;
   int width;
   int uni = uses_unicode();
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
      string *props = ({});
      string content = "";
      width = item_length(weapons->short()) + (uni ? 2 : 4);
      set_frame_title("Weapons");
      set_frame_header(
          sprintf("%-" + width + "s  %-7s  %-5s  %-11s  %s", "Weapon", "WC", "Dura", "Damage Type", "Properties"));
      foreach (object w in weapons)
      {
         string *types =
             w->query_loadable() && w->loaded_with() ? w->loaded_with()->query_damage_type() : w->query_damage_type();
         types -= ({0});
         types = map_array(types, ( : short_names[$1] :));
         props = w->query_properties() || ({});
         content += sprintf(" %-" + width + "." + width + "s  %-7s  %-5s  %11-s  %s\n",
                            ellipsis_name(w->short(), weapons->short()),
                            "" + w->query_weapon_class() +
                                (w->query_to_hit_bonus() > 0
                                     ? "(+" + w->query_to_hit_bonus() + ")"
                                     : (w->query_to_hit_bonus() < 0 ? "(" + w->query_to_hit_bonus() + ")" : "")),
                            "" + w->durability_percent() + "%", implode(types, ","), format_list(props));
      }
      set_frame_content(content);
      write(frame_render());
      nothing_wielded = 0;
   }

   if (sizeof(armours))
   {
      string content = "";
      width = item_length(armours->short()) + (uni ? 2 : 4);
      set_frame_title("Armours");
      set_frame_header(sprintf("%-" + width + "." + width + "s  %-21s  %-3s  %-5s  %s", "Item", "Worn on", "AC", "Dura",
                               "Modifiers"));
      foreach (object a in armours)
      {
         string *slots = ({a->query_slot()});

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

         if (member_array("arms", slots) != -1 && member_array("legs", slots) != -1 &&
             member_array("torso", slots) != -1)
         {
            slots -= ({"arms", "legs", "torso"});
            slots += ({"full body"});
         }

         if (member_array("arms", slots) != -1 && member_array("head", slots) != -1 &&
             member_array("torso", slots) != -1)
         {
            slots -= ({"arms", "head", "torso"});
            slots += ({"upper body"});
         }

         slots = map_array(slots, ( : capitalize($1) :));

         content += sprintf(" %-" + width + "." + width + "s  %-21s  %-3s  %-5s  %s\n",
                            ellipsis_name(a->short(), armours->short()), format_list(slots),
                            "" + (a->query_armour_class() || "-"),
                            a->query_armour_class() ? "" + a->durability_percent() + "%" : "-",
                            (a->query_stat_bonus() ? capitalize(a->query_stat_bonus()) + " " +
                                                         (a->query_stat_mod() >= 0 ? "+" : "") + a->query_stat_mod()
                             : a->stat_mods_string(1) ? a->stat_mods_string(1)
                                                      : ""), );
      }
      set_frame_content(content);
      write(frame_render());
      nothing_worn = 0;
   }

   if (nothing_worn & nothing_wielded)
      printf("You are wielding and wearing nothing.\n");
   else if (nothing_worn)
      printf("\n\n(You are wearing nothing)\n");
   else if (nothing_wielded)
      printf("\n\n(You are wielding nothing)\n");
}
