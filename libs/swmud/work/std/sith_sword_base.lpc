inherit BLADE_BASE;

int deflection_base = 0;
int deflection_bonus = 0;
int steal_life_chance_base = 0;
int steal_life_chance_bonus = 0;
int steal_life_amount_base = 0;
int steal_life_amount_bonus = 0;

void mudlib_setup()
{
   blade_base::mudlib_setup();
   add_save(({ "deflection_base", "deflection_bonus", "steal_life_chance_base", "steal_life_chance_bonus", "steal_life_amount_base", "steal_life_amount_bonus" }));
}

int is_sith_alchemy_weapon() { return 1; }

void set_deflection_base(int x)
{
   deflection_base = x;
}

void add_deflection_bonus(int amount)
{
   deflection_bonus += amount;
}

int query_deflection_bonus()
{
   return deflection_base + deflection_bonus;
}

void reset_deflection_bonus()
{
   deflection_bonus = 0;
}

void set_steal_life_chance_base(int x)
{
   steal_life_chance_base = x;
}

void add_steal_life_chance_bonus(int amount)
{
   steal_life_chance_bonus += amount;
}

int query_steal_life_chance_bonus()
{
   return steal_life_chance_base + steal_life_chance_bonus;
}

void reset_steal_life_chance_bonus()
{
   steal_life_chance_bonus = 0;
}

void set_steal_life_amount_base(int x)
{
   steal_life_amount_base = x;
}

void add_steal_life_amount_bonus(int amount)
{
   steal_life_amount_bonus += amount;
}

int query_steal_life_amount_bonus()
{
   return steal_life_amount_base + steal_life_amount_bonus;
}

void reset_steal_life_amount_bonus()
{
   steal_life_amount_bonus = 0;
}

int valid_wield()
{
   if (owner(this_object())->query_jedi_alignment() >= 0)
   {
      if (owner(this_object())->query_jedi_alignment() > 0)
      {
         tell(owner(this_object()), "You resist the temptation to wield something that has been created using the energies of the Dark side of the Force.\n");

         return 0;
      }

      tell(owner(this_object()), "An overwhelming sense of fear prevents you from wielding it.\n");

      return 0;
   }

   return 1;
}

class event_info process_sith_sword_evt(class event_info evt)
{
   if ((steal_life_chance_base + steal_life_chance_bonus) > random(100))
   {
      object this_body = query_wielded_by();
      string skill = "sith weapons";
      int level = this_body->query_guild_level("jedi");

      if (this_body->has_learned_skill("sith weaponry") && this_body->can_feel_force() && (level > 0)
         && this_body->test_skill(skill))
      {
         int rank = this_body->query_skill(skill) / 100;
         int damage = event_damage(evt);
         int floor = damage * (steal_life_amount_base + steal_life_amount_bonus) * rank * 10 / 20000;
         int ceiling = damage * (steal_life_amount_base + steal_life_amount_bonus) * level * (10 + (rank * 9)) / 500000;
         int amount;

         if (floor < 1) { floor = 1; }

         amount = floor + random(ceiling - floor);

         if (amount > damage)
         {
            evt->data["unstoppable"] = amount - damage;
         }

         tell(this_body, capitalize(this_object()->the_short()) + " steals life force from " + evt->target->short() + " and uses it to feed your own.\n");

         this_body->heal_us(amount, "all", 1);
      }
   }

   return evt;
}

class event_info source_modify_event(class event_info evt)
{
   evt = blade_base::source_modify_event(evt);

   if (stringp(evt->data) || (event_damage(evt) < 1)) { return evt; }

   evt = process_sith_sword_evt(evt);

   return evt;
}