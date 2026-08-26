private int charge = 1;
private int max_charge = 1;
private string charge_desc = "charge";

void charge_is_fully_drained();

void mudlib_setup()
{
   this_object()->add_save(({ "charge", "max_charge" }));
}

mixed direct_recharge_obj_with_obj() { return 1; }

void set_charge(int amount)
{
   if (amount > 0)
   {
      charge = amount;
   }

   if (max_charge < charge)
   {
      max_charge = charge;
   }
}

void adjust_charge(int amount)
{
   if ((charge > 0) && ((charge + amount) < 1))
   {
      tell(owner(this_object()), "%^BOLD%^%^RED%^You used the last of the " + charge_desc + " for your " + this_object()->short() + this_object()->wielded_attributes() + ".%^RESET%^\n");
   }

   charge += amount;

   if (charge < 0)
   {
      charge = 0;
   }
   else if (charge > max_charge)
   {
      charge = max_charge;
   }
}

int query_charge()
{
   return charge;
}

void set_max_charge(int amount)
{
   if (amount > 0)
   {
      max_charge = amount;
   }
}

int query_max_charge()
{
   return max_charge;
}

void set_charge_desc(string value)
{
   charge_desc = value;
}

string query_charge_desc()
{
   return charge_desc;
}

void start_charge_drain()
{
   set_heart_beat(8);
}

void stop_charge_drain()
{
   set_heart_beat(0);
}

void heart_beat()
{
   if (charge < 1) { return; }

   charge--;

   if (charge <= 0)
   {
      set_heart_beat(0);

      charge_is_fully_drained();
   }
}