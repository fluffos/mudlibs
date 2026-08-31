/* Do not remove the headers from this file! see /USAGE for more info. */

//: MODULE
// Daemon for space station controlling.

#define MAX_DOCKING_MINUTES 2

inherit M_DAEMON_DATA;
inherit SPACE_CLASSES;

private
mapping docked_ships = ([]);
private
int dock_count = 0;
private
mapping stations = ([]);
private
mapping docks = ([]);

string find_ship(string docked_ship)
{
   foreach (string room, class docking_info di in docked_ships)
   {
      if (di->vfile == docked_ship)
         return room;
   }
   return 0;
}

void update_docks(string station, string filename)
{
   string rooms = filter(objects(), ( : $1->is_docking_room() && strsrch(base_name($1), $(filename)) != -1 :));
   docks[station] = ([]);
   foreach (object r in rooms)
   {
      string file = base_name(r);
      if (docked_ships[file])
         docks[station][file] = 1;
      else
         docks[station][file] = 0;
   }
   save_me();
}

private
void update_docking_status()
{
   foreach (string station, mapping m in docks)
      foreach (string room, int used in m)
      {
         if (docked_ships[room])
            docks[station][room] = 1;
         else
            docks[station][room] = 0;
      }
}

int claim_dock(string room_file, string docked_ship, int docking_time, string who)
{
   class docking_info di = new (class docking_info);
   string docked_already = find_ship(docked_ship);
   if (docked_already)
      room_file = docked_already;

   di->vfile = docked_ship;
   di->docking_time = docking_time;
   di->who = lower_case(who);
   di->dock_name = load_object(room_file)->short();

   if (!docked_ships[room_file])
   {
      docked_ships[room_file] = di;
      dock_count++;
      update_docking_status();
      save_me();

      return 1;
   }
   return 0;
}

mapping query_dockss()
{
   return docks;
}

mapping query_docked_ships()
{
   return docked_ships;
}

mapping query_docks(string station)
{
   return docks[station];
}

class docking_info query_dock(string room_file)
{
   if (docked_ships[room_file])
   {
      return docked_ships[room_file];
   }
   return 0;
}

int release_dock(string room_file)
{
   if (docked_ships[room_file])
   {
      dock_count--;
      map_delete(docked_ships, room_file);
      update_docking_status();
      save_me();
      return 1;
   }
   return 0;
}

void set_config(string location, float docking_fee, float storage_fee)
{
   class spacestation_config sc = new (class spacestation_config);
   sc->docking_fee = docking_fee;
   sc->storage_fee = storage_fee;

   stations[location] = sc;
   save_me();
}

class spacestation_config query_config(string location)
{
   return stations[location];
}

void attempt_undock(string docked_at, class docking_info di)
{
   object ship = find_object(di->vfile);
   object dock = load_object(docked_at);
   object terminal = present("docking_terminal_id", dock);

   if (!ship || (ship && ship->is_ship_empty()))
   {
      if (terminal)
      {
         // Undocking by force and sending ship back to long term parking.
         terminal->clear_docking();
         map_delete(docked_ships, docked_at);
         SHIP_D->notify_owner(di->who, "Your idle ship has been undocked");
         save_me();
      }
   }
}

void undock(string docked_at, class docking_info di)
{
   object ship = find_object(di->vfile);
   object dock = load_object(docked_at);
   object terminal = present("docking_terminal_id", dock);

   if (ship && terminal)
   {
      // Normal undocking
      terminal->undocking();
      map_delete(docked_ships, docked_at);
      save_me();
   }
}

void undock_passive_ships()
{
   foreach (string room, class docking_info di in docked_ships)
   {
      int docked_at = di->docking_time;
      int late = docked_at + (MAX_DOCKING_MINUTES * 60) < time();
      if (late)
      {
         attempt_undock(room, di);
      }
   }
   call_out("undock_passive_ships", 120);
}

string domain_file(mixed file)
{
   string *parts;
   if (objectp(file))
      file = base_name(file);
   parts = explode(file, "/");
   if (sizeof(parts) > 2 && parts[0] == "domains")
      return parts[1];
   else
      return "std";
}

string stat_me()
{
   string out = "Docked ships:\n";
   mapping ship_count = ([]);
   foreach (string room in keys(docked_ships))
   {
      ship_count[domain_file(room)]++;
   }

   foreach (string domain, int count in ship_count)
      out += domain + ": " + count + "\n";

   return out;
}

// Initial creation of this daemon.
void create()
{
   ::create();
   set_privilege("Mudlib:daemons");
   call_out("undock_passive_ships", 120);
}
