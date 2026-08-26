inherit OBJ;

void set_unoccupied();

string occupied = "";

void setup()
{
   object::setup();
   set_id("console");
   set_long("You could use this console to operate the ship.  It has lots of gauges, switches and dials attached to it.");

   set_attached(1);
}

mixed direct_use_obj() { return 1; }

void do_use()
{
   if (!strlen(occupied) || !present(occupied, environment()))
   {
      occupied = this_body()->query_userid();
      this_body()->simple_action("$N $vsit down at the console.");
      new("/d/obj/space_vehicle_shell")->start_menu();
   }
   else
   {
      tell(this_body(), capitalize(occupied) + " is already sitting at the console.\n");
   }
}

void set_unoccupied()
{
   occupied = "";
}