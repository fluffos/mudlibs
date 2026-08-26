inherit WEAPON;
inherit M_GETTABLE;
inherit M_VALUABLE;

#include <syringe_bottle.h>

string type = "";
int doses = 0;

void mudlib_setup()
{
   weapon::mudlib_setup();
   m_valuable::mudlib_setup();
   add_save( ({ "type", "doses" }) );
}

void setup()
{
   set_id("syringe");
   set_long("A syringe that you can use to inject something into a living thing.");
   set_mass(10);
   set_value(450);

   set_combat_messages("combat-inject");
   set_damage_type("slashing", 5);
   set_skill_used("slash 1h");
   set_durability(1);
   set_chance_to_be_damaged(100);
   set_weapon_speed(2);
}

void fill_with(object thing)
{
   if (thing->is_syringe_bottle())
   {
      if (type && doses)
      {
         clear_id();
         set_id("syringe");
         write("%^RED%^You empty the last " + doses + " doses of " + type + " liquid in " + this_object()->the_short() + ".%^RESET%^\n");
      }

      type = thing->query_liquid_type();
      doses = thing->get_a_fill();

      environment()->my_action("$N $vfill the $o with " + doses + " doses of " + type + " liquid.", this_object());
      environment()->other_action("$N $vfill the $o with " + type + " liquid.", this_object());

      clear_id();
      set_id("syringe filled with " + format_liquid_color(type) + " liquid", "syringe");
      set_long("A syringe that you can use to inject something into a living thing.\nIt is filled with " + format_liquid_color(type) + " liquid.");
   }
   else
   {
      tell(environment(), "You're not able to fill " + this_object()->the_short() + " with " + thing->the_short() + ".\n");
   }
}

string query_liquid_type() { return type; }
int query_doses_left() { return doses; }

string get_a_dose()
{
   if (doses > 0)
   {
      doses--;

      if (doses <= 0)
      {
         type = "";
         clear_id();
         set_id("syringe");
         set_long("A syringe that you can use to inject something into a living thing.");

         write("%^RED%^You used the last dose in " + this_object()->short() + ".%^RESET%^\n");
      }

      return type;
   }

   return 0;
}

int can_fill_obj() { return 1; }
int can_fill_obj_with_obj() { return 1; }

int is_inject_syringe() { return 1; }

void do_check_obj()
{
   if (strlen(type) && (doses > 0))
   {
      write("The syringe contains " + doses + " doses of " + type + " liquid.\n");
   }
   else
   {
      write("The syringe is empty.\n");
   }
}