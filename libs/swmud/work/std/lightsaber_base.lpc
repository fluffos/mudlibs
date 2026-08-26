inherit WEAPON;
inherit M_LIGHT_SOURCE;

#include <lightsaber.h>

string color_crystal = choice(({ "blue", "green", "yellow", "red" }));
string lens_name = "lens_1";
string emitter_name = "emitter_1";
string ecell_name = "ecell_1";
int deflection_bonus = 0;
int alignment = 0;
string name_crystal = "";

void mudlib_setup()
{
   add_id("lightsaber", "saber");
   weapon::mudlib_setup();
   set_combat_messages("combat-blade");
   set_skill_used("saber combat");
   set_repair_skill("saber repair");
   set_repair_learn_requirement("lightsaber repair");
   set_repair_guilds(({"jedi"}));
   set_parts_type("lightsaber");
   add_save(({ "color_crystal", "lens_name", "emitter_name", "ecell_name", "deflection_bonus", "alignment", "name_crystal" }));

   // Give time for saved inventory to be loaded first, or to add a specific color at creation
   call_out("check_if_lightsaber_has_components", 5);
}

void check_if_lightsaber_has_components()
{
   if (this_object())
   {
      if (strlen(color_crystal)
         && !sizeof(filter_array(all_inventory(this_object()), (: $1->id("lightsaber_color_crystal") :))))
      {
         new("/d/com/saber/crystal_color", color_crystal)->move(this_object());
      }

      if (strlen(lens_name)
         && !sizeof(filter_array(all_inventory(this_object()), (: $1->id("lightsaber_lens") :))))
      {
         new("/d/com/saber/" + lens_name)->move(this_object());
      }

      if (strlen(emitter_name)
         && !sizeof(filter_array(all_inventory(this_object()), (: $1->id("lightsaber_emitter") :))))
      {
         new("/d/com/saber/" + emitter_name)->move(this_object());
      }

      if (strlen(ecell_name)
         && !sizeof(filter_array(all_inventory(this_object()), (: $1->id("lightsaber_ecell") :))))
      {
         new("/d/com/saber/" + ecell_name)->move(this_object());
      }

      this_object()->assemble();
   }
}

int is_lightsaber() { return 1; }

string query_wield_message()
{
   call_out("activate_light_source", 1);

   clear_adj();
   call_out("add_adj", 2, get_lightsaber_color_code(color_crystal) + "%^RESET%^");

   return "$N $vactivate $p $o, which produces a glowing " + get_lightsaber_color_code(color_crystal) + "%^RESET%^ blade.";
}

string query_unwield_message()
{
   deactivate_light_source();

   remove_adj(get_lightsaber_color_code(color_crystal) + "%^RESET%^");

   return "$N $vshut down $p $o.";
}

void set_lightsaber_color(string lightsaber_color)
{
   color_crystal = lightsaber_color;
}

string query_lightsaber_color()
{
   return color_crystal;
}

void set_lightsaber_lens(string lens)
{
   lens_name = lens;
}

string query_lightsaber_lens()
{
   return lens_name;
}

void set_lightsaber_emitter(string emitter)
{
   emitter_name = emitter;
}

string query_lightsaber_emitter()
{
   return emitter_name;
}

void set_lightsaber_ecell(string ecell)
{
   ecell_name = ecell;
}

string query_lightsaber_ecell()
{
   return ecell_name;
}

void add_deflection_bonus(int amount)
{
   deflection_bonus += amount;
}

int query_deflection_bonus()
{
   return deflection_bonus;
}

void reset_deflection_bonus()
{
   deflection_bonus = 0;
}

void set_lightsaber_alignment(int align)
{
   alignment = align;
}

void set_lightsaber_name_crystal(string value)
{
   name_crystal = value;
}

mixed direct_attach_obj_to_obj() { return 1; }
mixed direct_detach_obj_from_obj() { return 1; }
mixed direct_holster_obj_to_obj() { return 0; }
mixed direct_unholster_obj_from_obj() { return 0; }

int valid_wield()
{
   if (!strlen(color_crystal))
   {
      tell(owner(this_object()), "You are unable to wield your " + this_object()->short() + " while it has no color crystal.\n");

      return 0;
   }
   else if (!strlen(lens_name))
   {
      tell(owner(this_object()), "You are unable to wield your " + this_object()->short() + " while it has no lens.\n");

      return 0;
   }
   else if (!strlen(emitter_name))
   {
      tell(owner(this_object()), "You are unable to wield your " + this_object()->short() + " while it has no emitter.\n");

      return 0;
   }
   else if (!strlen(ecell_name))
   {
      tell(owner(this_object()), "You are unable to wield your " + this_object()->short() + " while it has no energy cell.\n");

      return 0;
   }
   else if ((alignment > 0) && (owner(this_object())->query_jedi_alignment() < 0))
   {
      tell(owner(this_object()), "You are unable to wield your " + this_object()->short() + " while you are too far from the Light side of the Force.\n");

      return 0;
   }
   else if ((alignment < 0) && (owner(this_object())->query_jedi_alignment() > 0))
   {
      tell(owner(this_object()), "You are unable to wield your " + this_object()->short() + " while it is tainted by the Dark side of the Force.\n");

      return 0;
   }
   else if (strlen(name_crystal) && (owner(this_object())->query_userid() != name_crystal))
   {
      tell(owner(this_object()), "You are unable to wield your " + this_object()->short() + " while it contains a " + name_crystal + " focusing crystal.\n");

      return 0;
   }

   return 1;
}

class event_info source_modify_event(class event_info evt)
{
   object this_body = query_wielded_by();
   int level = this_body->query_guild_level("jedi");

   if (stringp(evt->data)) { return evt; }

   if ((level > 0) && this_body->has_learned_skill("lightsaber combat") && this_body->can_feel_force())
   {
      int rank = this_body->query_skill("saber combat") / 100;
      int spec = this_body->query_guild_specialization_rank("jedi", "lightsaber");
      int rank_spec = (rank + spec) < 0 ? 0 : (rank + spec);
      int min_damage = 0 + (level / (15 - rank)) + rank_spec;
      int damage = evt->data["energy"];
      int max_skill_damage = damage * (40 + (rank * 6)) / 100;

      if (min_damage < 0) { min_damage = 0; }

//      tell(this_body, sprintf("Original Damage: %i\nMin Damage: %i\nMax Skill Damage: %i\n", evt->data["energy"], min_damage, max_skill_damage));

      if (damage < min_damage)
      {
         damage = min_damage;
      }
      else
      {
         max_skill_damage = (max_skill_damage >= min_damage ? max_skill_damage : min_damage);

         if (damage > max_skill_damage)
         {
            damage = max_skill_damage;
         }
      }

//      tell(this_body, sprintf("Damage: %i\n", damage));

      if (this_body->has_learned_skill("combat sense") && this_body->test_skill("combat sense"))
      {
         int force = this_body->query_for();
         rank += this_body->query_skill("combat sense") / 100;

         if (spec <= 0) { spec = this_body->query_guild_specialization_rank("jedi", "sense"); }

         rank_spec = (rank + spec) < 0 ? 0 : (rank + spec);

         if (((level * 4) + force + (rank_spec * 10)) > random(1500))
         {
            damage += damage * level * force * rank_spec / 75000;

            this_body->simple_action("$N $vdeliver a critical strike with $p lightsaber!");

//            tell(this_body, sprintf("Critical Damage: %i\n", damage));
         }
      }
/*
      if (damage != evt->data["energy"])
      {
         tell(this_body, sprintf("Damage adjusted by %i.\n", (damage - evt->data["energy"])));
      }
*/
      evt->data["energy"] = damage;
   }
   else if ((this_body->query_agi() + this_body->query_dex() + this_body->query_per() + this_body->query_luc() + this_body->query_for()) > random(500))
   {
      evt->data["energy"] = evt->data["energy"] * (this_body->query_agi() + this_body->query_dex() + this_body->query_per() + this_body->query_luc() + this_body->query_for()) / 500;
   }
   else
   {
      evt->data = "miss";
   }

   return evt;
}