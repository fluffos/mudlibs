inherit LIGHTSABER_BASE;

int blade_setup = 2;

void mudlib_setup()
{
   add_id("double-bladed lightsaber", "double saber", "dsaber");
   lightsaber_base::mudlib_setup();
   set("two_hands", 1);
   set_weapon_speed(2);
   set_to_hit_base(-25);
   add_save(({ "blade_setup" }));
}

string query_wield_message()
{
   string color = query_lightsaber_color();
//   light();

   clear_adj();
   call_out("add_adj", 1, get_lightsaber_color_code(color) + "%^RESET%^");

   if (blade_setup == 2)
   {
      return "$N $vactivate $p $o, which produces a glowing " + get_lightsaber_color_code(color) + "%^RESET%^ blade at both ends.";
   }

   return "$N $vactivate $p $o, which produces a glowing " + get_lightsaber_color_code(color) + "%^RESET%^ blade.";
}

void do_press_wrd(string wrd)
{
   if (wrd == "button")
   {
      if (blade_setup == 2)
      {
         blade_setup = 1;

         set_weapon_speed(1);
         set_to_hit_base(0);

         if (query_wielded_by())
         {
            this_body()->simple_action("$N $vpress a button on the $o, which shuts down one of the blades.", this_object());
         }
         else
         {
            this_body()->simple_action("$N $vpress a button on the $o.", this_object());
         }
      }
      else if (blade_setup == 1)
      {
         blade_setup = 2;

         set_weapon_speed(2);
         set_to_hit_base(-25);

         if (query_wielded_by())
         {
            this_body()->simple_action("$N $vpress a button on the $o, which produces another glowing blade.", this_object());
         }
         else
         {
            this_body()->simple_action("$N $vpress a button on the $o.", this_object());
         }
      }
   }
}

mixed direct_attach_obj_to_obj() { return 0; }
mixed direct_detach_obj_from_obj() { return 0; }