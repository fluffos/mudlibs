inherit LIGHTSABER_BASE;

string color = choice(({ "%^YELLOW%^yellow", "%^BOLD%^%^BLUE%^bright blue", "%^BOLD%^%^GREEN%^bright green" }));

void setup()
{
   set_id("practice lightsaber", "practice saber");
   set_long("The case is made of polished silver metal covered in black rubber grips, with a single activation button.  The energy focus of this practice lightsaber is designed to make it as non-lethal as possible, although it is still possible to cause injury.");
   set_damage_type("energy", 10);
   set_durability(50);
   set_mass(3000);
   set_value(1500);
}

class event_info source_modify_event(class event_info evt)
{
   object this_body = query_wielded_by();
   int level = this_body->query_guild_level("jedi");

   if (stringp(evt->data)) { return evt; }

   if (level && this_body->has_learned_skill("lightsaber combat"))
   {
      int damage = evt->data[1];
      int target_health = evt->target->query_health();

      if (damage < 5)
      {
         damage = 5;

//         tell(this_body, sprintf("Damage adjusted from %d to %d.\n", evt->data[1], damage));
      }
      else if (damage > this_object()->query_weapon_class())
      {
         damage = this_object()->query_weapon_class();

//         tell(this_body, sprintf("Damage adjusted from %d to %d.\n", evt->data[1], damage));
      }
      else if (damage > (5 + level))
      {
         damage = 5 + level;

//         tell(this_body, sprintf("Damage adjusted from %d to %d.\n", evt->data[1], damage));
      }

      if (((target_health - damage) < 1) && (target_health > 1))
      {
//         tell(this_body, "Adjusting damage from " + evt->data[1] + " to " + (damage - (damage - target_health) - 1) + ".\n");
         damage = damage - (damage - target_health) - 1;
      }

      evt->data[1] = damage;
   }
   else if (((500 - this_body->query_agi() - this_body->query_dex() - this_body->query_per() - this_body->query_luc() - this_body->query_for()) / 5.0) > random(100))
   {
      int damage = evt->data[1];
      int health = this_body->query_health();

      if (((health - damage) < 1) && (health > 1))
      {
//         tell(this_body, "Adjusting damage from " + evt->data[1] + " to " + (damage - (damage - health) - 1) + ".\n");
         evt->data[1] = damage - (damage - health) - 1;
      }

      this_body->start_fight(evt->target);
      evt->target->start_fight(this_body);
      evt->target = this_body;
   }
   else
   {
      evt->data[1] = random(this_body->query_primary_level() / 5);
   }

   return evt;
}