inherit BLADE_BASE;

int vibro_critical_chance_base = 25;
int vibro_critical_chance_bonus = 0;
int vibro_critical_amount_base = 50;
int vibro_critical_amount_bonus = 0;

void mudlib_setup()
{
   blade_base::mudlib_setup();
   add_save(({ "vibro_critical_chance_base", "vibro_critical_chance_bonus", "vibro_critical_amount_base", "vibro_critical_amount_bonus" }));
}

int can_use_blade_energy_cell() { return 1; }

void set_vibro_critical_chance_base(int x)
{
   vibro_critical_chance_base = x;
}

void add_vibro_critical_chance_bonus(int amount)
{
   vibro_critical_chance_bonus += amount;
}

int query_vibro_critical_chance_bonus()
{
   return vibro_critical_chance_base + vibro_critical_chance_bonus;
}

void reset_vibro_critical_chance_bonus()
{
   vibro_critical_chance_bonus = 0;
}

void set_vibro_critical_amount_base(int x)
{
   vibro_critical_amount_base = x;
}

void add_vibro_critical_amount_bonus(int amount)
{
   vibro_critical_amount_bonus += amount;
}

int query_vibro_critical_amount_bonus()
{
   return vibro_critical_amount_base + vibro_critical_amount_bonus;
}

void reset_vibro_critical_amount_bonus()
{
   vibro_critical_amount_bonus = 0;
}

class event_info process_vibro_evt(class event_info evt)
{
   if ((vibro_critical_chance_base + vibro_critical_chance_bonus) > random(100))
   {
      object this_body = query_wielded_by();
      string skill = "vibroweapons";

      if (this_body->test_skill(skill))
      {
         int level = this_body->query_primary_level();
         int rank = this_body->query_skill(skill) / 100;
         int damage = evt->data["slashing"];
         int floor = damage * (vibro_critical_amount_base + vibro_critical_amount_bonus) * rank * 10 / 20000;
         int ceiling = damage * (vibro_critical_amount_base + vibro_critical_amount_bonus) * level * (10 + (rank * 9)) / 500000;
         int amount;

         if (floor < 1) { floor = 1; }

         amount = floor + random(ceiling - floor);
         evt->data["slashing"] = damage + amount;

         this_body->targetted_action("%^YELLOW%^$N $vland a perceptive strike against $t with $p $o!%^RESET%^", evt->target, this_object());

         tell(this_body, sprintf("Damage adjusted from %d to %d.\n", damage, damage + amount));
      }
   }

   return evt;
}

class event_info source_modify_event(class event_info evt)
{
   evt = blade_base::source_modify_event(evt);

   if (stringp(evt->data) || (event_damage(evt) < 1)) { return evt; }

   evt = process_vibro_evt(evt);

   return evt;
}