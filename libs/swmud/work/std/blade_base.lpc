inherit WEAPON;
inherit CLASS_EVENT_INFO;

int event_damage(class event_info evt);

void mudlib_setup()
{
   weapon::mudlib_setup();
   add_id("blade");
   set_combat_messages("combat-blade");
}

int is_blade() { return 1; }

class event_info process_evt(class event_info evt)
{
   object wielder = query_wielded_by();
   string skill = this_object()->query_skill_used();
   int weapon_class = this_object()->query_weapon_class();
   int rank = wielder->query_skill(skill) / 100;
   int primary_level = wielder->query_primary_level();
   int luck = wielder->query_luc();
   int floor = primary_level / (15 - rank);
   int ceiling;
   int tear_chance;
   int critical_chance;

   if (floor < 1) { floor = 1; }

   if (this_object()->get("two hands"))
   {
      ceiling = weapon_class * (0.2 + (rank * 0.08));
      tear_chance = (3 * rank) + this_object()->query_tear_base() + this_object()->query_tear_bonus();
      critical_chance = rank + this_object()->query_critical_chance_base()
         + this_object()->query_critical_chance_bonus();
   }
   else
   {
      ceiling = weapon_class * (0.5 + (rank * 0.05));
      tear_chance = (2 * rank) + this_object()->query_tear_base() + this_object()->query_tear_bonus();
      critical_chance = (rank * 1.5) + this_object()->query_critical_chance_base()
         + this_object()->query_critical_chance_bonus();
   }

   if (tear_chance > random(100))
   {
      load_object("/std/effect/tear_damage");
      new("/std/effect/tear_damage", random(evt->data["slashing"]) + 1)->move(evt->target);
   }

   if ((critical_chance * luck / 100) > random(100))
   {
      int critical_adjustment = primary_level + (rank * 2);
//      int amount = 0;

      foreach (string type in keys(evt->data))
      {
         evt->data[type] += ceil(evt->data[type] * critical_adjustment / 100);
//         amount += evt->data[type] + ceil(evt->data[type] * critical_adjustment / 100);
      }

//      tell(wielder, sprintf("Damage adjusted from %d to %d.\n", event_damage(evt), amount));
   }

   return evt;
}

class event_info source_modify_event(class event_info evt)
{
   if (stringp(evt->data) || (event_damage(evt) < 1)) { return evt; }

   evt = process_evt(evt);

   return evt;
}