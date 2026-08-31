inherit CONTAINER;
inherit SPACE_CLASSES;

object body;
class ship_info docked_ship;
int docking_completed;

void refresh_docking();

void setup()
{
   set_id("terminal", "interface", "terminal interface", "docking_terminal_id");
   set_adj("docking");
   set_long("The docking terminal serves as the control center for " +
            "all incoming and outgoing ships. The terminal is a futuristic panel with an array of buttons " +
            "and screens displaying various data related to the docking process, such as ship speed, " +
            "trajectory, and distance.");
   add_relation("in");
   set_default_relation("in");
   set_max_capacity(10);
   set_mass(1000);
   set_value(120);
   set_attached(1);
   call_out("refresh_docking", 0);
}

void comms(string s)
{
   tell_environment(this_object(), s + "\n");
}

void ship_comms(string s)
{
   if (docked_ship && docked_ship->vfile)
   {
      if (find_object(docked_ship->vfile))
         tell_from_outside(find_object(docked_ship->vfile), s + "\n");
   }
}

int is_docking_completed()
{
   return time() > docking_completed;
}

void refresh_docking()
{
   class docking_info di = SPACESTATION_D->query_dock(base_name(environment()));
   if (di)
   {
      docking_completed = di->docking_time;
      docked_ship = SHIP_D->find_ship(di->vfile);
      body = find_body(di->who);
   }
}

string ship_state()
{
   int time_left = docking_completed - time();
   refresh_docking();
   if (docking_completed && time_left > 0)
      return "The docking bay is opening the clamps, getting ready for docking.";

   return docked_ship ? capitalize(add_article(docked_ship->type)) + " is docked outside the window, ready to board."
                      : "The docking bay outside is available.";
}

void clear_docking()
{
   int time_left = docking_completed - time();
   if (!docked_ship)
      return;
   refresh_docking();
   if (time_left > 0)
   {
      comms(capitalize(add_article(docked_ship->type)) + " changes direction and heads away from the docking bay.");
   }
   else
      comms(capitalize(add_article(docked_ship->type)) + " undocks and heads into space.");

   SHIP_D->long_term_parked(docked_ship->name);
   SHIP_D->undock_ship(docked_ship->name);
   if (!SPACESTATION_D->release_dock(base_name(environment())))
      TBUG("Failed to clear DOCK at " + base_name(environment()));
   docking_completed = 0;
   docked_ship = 0;
}

void set_docking(class ship_info si, int t)
{
   if (!body)
      body = this_body();
   if (SPACESTATION_D->claim_dock(base_name(environment()), si->vfile, t, body->query_name()))
   {
      docking_completed = t;
      docked_ship = si;
      SHIP_D->dock_ship(si->name, base_name(environment()));
   }
   else
   {
      clear_docking();
   }
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
      return "\n" + body->short() + " is standing in front of the terminal right now.";
   if (docked_ship)
      return "\nIt seems locked since a ship has been docked here. Only the ship owner can access the terminal right " +
             "now.";
   else
      return "\nIt seems to be available for use.";
}

void start_story()
{
   int time_left = docking_completed - time();
   if (time_left > 0)
      call_out("do_docking_story", random(6) + 4);
}

void do_docking_story()
{
   int time_left = docking_completed - time();
   if (!docked_ship)
   {
      comms("You see a ship heading to long term docking in the far distance.");
      ship_comms("You feel the ship turn around and move away from the station.");
   }

   switch (time_left)
   {
   case -20..10:
      if (is_docking_completed())
      {
         comms("The ship approaches the airlock, and completes the docking.");
         ship_comms("The airlock meets the station and docking is completed.");
         SHIP_D->notify_owner(body, "ship docked at " + environment()->short());
         return;
      }
      break;
   case 11..20:
      if (random(2))
      {
         ship_comms("The ship meets the docking clamps.");
         comms("You see " + add_article(docked_ship->type) + " meeting the docking clamps.");
      }
      else
      {
         ship_comms("A final bit of wobbling, but then the ship meets the docking clamps.");
         comms("The floor rumbles below you as " + add_article(docked_ship->type) + " begins docking.");
      }
      break;
   case 21..50:
      if (!random(6))
         comms(capitalize(add_article(docked_ship->type)) + " approaches the docking bay.");
      break;
   case 51..60:
      comms("You can see a ship approaching the station through the window.");
      ship_comms("You see the terminal approaching through the ship windows.");
      break;
   case 90..100:
      comms("A ship can be seen through the window leaving the long term docking.");
      break;
   }
   if (time_left > 0)
      call_out("do_docking_story", random(6) + 4);
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
   term_menu = new (DOCKING_MENU, this_object());
   term_menu->start_menu();
}

mixed indirect_put_obj_wrd_obj(object ob1, string wrd, object ob2)
{
   return "#That doesn't seem to fit into the terminal.";
}

// Can be put into things.
mixed indirect_get_obj_from_obj(object ob1, string wrd, object ob2)
{
   return "#Does not seem to be possible to get things from the terminal?";
}