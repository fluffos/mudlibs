inherit CONTAINER;
inherit SPACE_CLASSES;

object body;
class ship_info docked_ship;
int docking_completed;

void refresh_docking();

void setup()
{
   set_id("terminal", "navterm", "navigation terminal", "nav_terminal_id");
   set_adj("navigation");
   set_long("The navigation terminal (navterm) is the navigation hub of the ship.");
   set_attached(1);
}

void comms(string s)
{
   tell_environment(this_object(), s + "\n");
}

class docking_info query_docking()
{
   class docking_info di = SPACESTATION_D->query_dock(base_name(environment()));
   return di;
}

string get_extra_long()
{
   if (!docked_ship && body && !present(body, environment()))
      body = 0;
   if (body && present(body, environment()))
      return "\n" + body->short() + " is sitting in front of the navterm right now.";
   if (docked_ship)
      return "\nIt seems locked since a ship has been docked here. Only the ship owner can access the terminal right " +
             "now.";
   else
      return "\nIt seems to be available for use.";
}

void stop_using()
{
   body = 0;
}

// Verb interactions below here.

mixed direct_use_obj()
{
   if (docking_completed && time() > docking_completed && body != this_body())
      return "#Terminal seems disabled since a ship is currently docked here.";
   return (body && body != this_body()) ? "#Sorry, but that terminal is in use by " + body->short() + " right now." : 1;
}

void do_use()
{
   object term_menu;
   if (!docked_ship && body)
   {
      if (!present(body, environment()))
         body = 0;
   }
   body = this_body();
   term_menu = new (SHIP_NAV_MENU, this_object());
   term_menu->start_menu();
}

int do_not_restore()
{
   return 1;
}

string furniture_sound()
{
   return random(3) ? 0
                    : (random(2) ? "a static electronic sound comes from the navterm"
                                 : "the navterm lets out a small 'ding!'");
}