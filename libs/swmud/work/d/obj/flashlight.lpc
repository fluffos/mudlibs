inherit OBJ;
inherit M_GETTABLE;
inherit M_VALUABLE;
inherit M_LIGHT_SOURCE;
inherit M_POWER_CELL;

void do_use();
void charge_is_fully_drained();
int query_is_lit();

void mudlib_setup()
{
   object::mudlib_setup();
   m_valuable::mudlib_setup();
   m_power_cell::mudlib_setup();
}

varargs void setup(int battery_charge)
{
   set_id("flashlight");
   set_long("A flashlight that can help you see in the dark.  It looks like you can activate it to turn it on, and deactivate it to conserve its battery power.");
   set_mass(1000);
   set_value(300);

   if (battery_charge)
   {
      set_charge(battery_charge);
   }
   else
   {
      set_charge(225);
   }
}

int is_flashlight() { return 1; }

mixed direct_activate_obj() { return 1; }
mixed direct_deactivate_obj() { return 1; }
mixed direct_use_obj() { return 1; }

void do_activate()
{
   if (!query_is_lit())
   {
      if (query_charge() > 0)
      {
         start_charge_drain();
         activate_light_source();

         this_body()->simple_action("$N $vactivate the $o.", this_object());
      }
      else
      {
         write("The battery in " + this_object()->the_short() + " seems to be used up.\n");
      }
   }
   else
   {
      write("The " + this_object()->short() + " seems to already be activated.\n");
   }
}

void do_deactivate()
{
   if (query_is_lit())
   {
      stop_charge_drain();
      deactivate_light_source();

      this_body()->simple_action("$N $vdeactivate the $o.", this_object());
   }
   else
   {
      write("The " + this_object()->short() + " seems to already be deactivated.\n");
   }
}

void do_use()
{
   do_activate();
}

void charge_is_fully_drained()
{
   object env = environment();

   deactivate_light_source();

   if (env->is_living())
   {
      tell(env, "%^BOLD%^%^RED%^The battery in your " + this_object()->short() + " has been used up.%^RESET%^\n");
   }
}

void do_check_obj()
{
   if (query_charge() > 0)
   {
      write("You check " + this_object()->the_short() + " and discover that its battery has about " + convert_time(query_charge() * 8) + " remaining.\n");

      return;
   }

   write("You check " + this_object()->the_short() + " and discover that the battery has been used up.\n");
}