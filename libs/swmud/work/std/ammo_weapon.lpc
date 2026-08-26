inherit WEAPON;

// Standard variables for setup
private int ammo = 1;
private int max_ammo = 1;
private int ammo_regen_rate = 0;
private int last_regen_time = time();
private int max_ammo_recharge_time = 14400;
private int last_recharge_time = time();
private string ammo_desc = "charges";

// Modification variables
private int ammo_capacity_bonus = 0;
private int ammo_regen_rate_bonus = 0;
private int max_ammo_recharge_time_bonus = 0;
private string out_of_ammo_combat_messages;
private mapping out_of_ammo_damage_types = ([ ]);
private mapping out_of_ammo_damage_bonuses = ([ ]);

void mudlib_setup()
{
   weapon::mudlib_setup();
   add_save(({ "ammo", "max_ammo", "ammo_regen_rate", "last_regen_time", "max_ammo_recharge_time", "last_recharge_time", "ammo_desc", "ammo_capacity_bonus", "ammo_regen_rate_bonus", "max_ammo_recharge_time_bonus", "out_of_ammo_combat_messages", "out_of_ammo_damage_types", "out_of_ammo_damage_bonuses" }));
}

int requires_ammo() { return 1; }

mixed direct_recharge_obj_with_obj() { return 1; }
mixed indirect_load_obj_into_obj() { return 1; }

void set_ammo(int amount)
{
   if (amount > 0)
   {
      ammo = amount;
   }

   if (max_ammo < ammo)
   {
      max_ammo = ammo;
   }
}

void adjust_ammo(int amount)
{
   if ((ammo > 0) && ((ammo + amount) < 1))
   {
      tell(owner(this_object()), "%^BOLD%^%^RED%^You used the last of the " + ammo_desc + " for your " + this_object()->short() + this_object()->wielded_attributes() + ".%^RESET%^\n");
   }

   ammo += amount;

   if (ammo < 0)
   {
      ammo = 0;
   }
   else if (ammo > max_ammo)
   {
      ammo = max_ammo;
   }
}

int query_ammo()
{
   int time = time();
   int time_left = (max_ammo_recharge_time + max_ammo_recharge_time_bonus) - (time - last_recharge_time);

   if ((time_left > 0) && ((time - last_regen_time) > 15))
   {
      int number_of_regens = ((time - last_regen_time) - ((time - last_regen_time) % 16)) / 16;
      ammo += number_of_regens * (ammo_regen_rate + ammo_regen_rate_bonus);

      last_regen_time += (number_of_regens * 16) + (number_of_regens * (16 - (ceil(time_left * 100 / (max_ammo_recharge_time + max_ammo_recharge_time_bonus) / 12.5) * 2)));

      if (ammo > (max_ammo + ammo_capacity_bonus))
      {
         ammo = max_ammo + ammo_capacity_bonus;
      }
   }

   return ammo;
}

void set_max_ammo(int amount)
{
   if (amount > 0)
   {
      max_ammo = amount;
   }

   if (max_ammo < ammo)
   {
      max_ammo = ammo;
   }
}

int query_max_ammo()
{
   return max_ammo + ammo_capacity_bonus;
}

void set_ammo_regen_rate(int value)
{
   ammo_regen_rate = value;
}

int query_ammo_regen_rate()
{
   return ammo_regen_rate + ammo_regen_rate_bonus;
}

void set_last_regen_time(int value)
{
   last_regen_time = value;
}

int query_last_regen_time()
{
   return last_regen_time;
}

void set_max_ammo_recharge_time(int value)
{
   max_ammo_recharge_time = value;
}

int query_base_max_ammo_recharge_time()
{
   return max_ammo_recharge_time;
}

int query_max_ammo_recharge_time()
{
   return max_ammo_recharge_time + max_ammo_recharge_time_bonus;
}

void set_last_recharge_time(int value)
{
   last_recharge_time = value;
}

int query_last_recharge_time()
{
   return last_recharge_time;
}

void set_ammo_desc(string value)
{
   ammo_desc = value;
}

string query_ammo_desc()
{
   return ammo_desc;
}

//:FUNCTION set_out_of_ammo_damage_type
// Set a damage type for the weapon
void set_out_of_ammo_damage_type(string type, int amount)
{
   out_of_ammo_damage_types[type] = amount;
}

mapping query_out_of_ammo_damage_types()
{
   return out_of_ammo_damage_types;
}

mapping query_damage_types()
{
   if (ammo > 0)
   {
      return ::query_damage_types();
   }

   if (sizeof(out_of_ammo_damage_types))
   {
      mapping types = ([ ]);
      int durability = ::query_durability();
      int max_durability = ::query_max_durability();

      foreach (string type in keys(out_of_ammo_damage_types) + keys(out_of_ammo_damage_bonuses))
      {
         if (floor((out_of_ammo_damage_types[type] + out_of_ammo_damage_bonuses[type]) * durability / max_durability) > 0)
         {
            types[type] = to_int(floor((out_of_ammo_damage_types[type] + out_of_ammo_damage_bonuses[type]) * durability / max_durability));
         }
      }

      return types;
   }

   return ([ "striking" : 1 ]);
}

//:FUNCTION set_out_of_ammo_damage_bonus
// Set an overall modifier of weapon class on the object.  The bonus
// does not get saved, so should only be used for temporary bonuses. (i.e. buffs)
void set_out_of_ammo_damage_bonus(string type, int bonus)
{
   out_of_ammo_damage_bonuses[type] = bonus;
}

void add_out_of_ammo_damage_bonus(string type, int value)
{
   out_of_ammo_damage_bonuses[type] += value;
}

void reset_out_of_ammo_damage_bonuses()
{
   out_of_ammo_damage_bonuses = ([ ]);
}

mapping query_out_of_ammo_damage_bonuses()
{
   return out_of_ammo_damage_bonuses;
}

void add_ammo_capacity_bonus(int value)
{
   ammo_capacity_bonus += value;
}

void reset_ammo_capacity_bonus()
{
   ammo_capacity_bonus = 0;
}

void add_ammo_regen_rate_bonus(int value)
{
   ammo_regen_rate_bonus += value;
}

void reset_ammo_regen_rate_bonus()
{
   ammo_regen_rate_bonus = 0;
}

void add_max_ammo_recharge_time_bonus(int value)
{
   max_ammo_recharge_time_bonus += value;
}

void reset_max_ammo_recharge_time_bonus()
{
   max_ammo_recharge_time_bonus = 0;
}

mixed query_combat_messages()
{
   if (ammo > 0)
   {
      return ::query_combat_messages();
   }

   if (strlen(out_of_ammo_combat_messages))
   {
      return MESSAGES_D->get_messages(out_of_ammo_combat_messages);
   }

   return MESSAGES_D->get_messages("combat-blunt");
}