inherit WEAPON;
inherit M_GETTABLE;
inherit M_VALUABLE;

void do_use();
void do_use_on_liv(object living);
void perform_scan(object living);

void setup()
{
   set_id("health scanner", "scanner");
   set_long("A health scanner that you can use on a living thing.");
   set_mass(5);
   set_value(1000);

   set_combat_messages("combat-blunt");
   set_damage_type("striking", 5);
   set_skill_used("strike 1h");
   set_durability(1);
   set_weapon_speed(1);
}

mixed direct_use_obj() { return 1; }
mixed direct_use_obj_on_liv() { return 1; }

void do_use()
{
   object target = this_body()->get_target();

   if (target) { do_use_on_liv(target); }
   else { write("Use scanner on what?\n"); }
}

void do_use_on_liv(object living)
{
   if (living != this_body())
   {
      this_body()->targetted_action("$N $vcheck $p1 health with the scanner.", living);
   }
   else
   {
      this_body()->simple_action("$N $vcheck $p health with the scanner.");
   }

   perform_scan(living);
}

void perform_scan(object living)
{
   int percent = (100 * living->query_health()) / living->query_max_health();

   tell(this_user(), "\n%^BOLD%^%^RED%^The scanner reads: " + living->short() + " is at " + percent + "% health.%^RESET%^\n");
}