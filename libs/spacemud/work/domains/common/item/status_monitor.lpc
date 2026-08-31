inherit OBJ;
inherit SPACE_CLASSES;
inherit M_GETTABLE;
inherit M_FRAME;

string station;

void setup(string st)
{
   station = st;
   set_id("status monitor", "docking monitor", "docking status monitor", "monitor");
   set_mass(1000);
   set_value(120);
   set_in_room_desc("A docking status monitor.");
   set_gettable("#It's bolted to the wall. No chance.");
}

string long()
{
   string content = "";
   mapping dock_info = SPACESTATION_D->query_docked_ships();
   dock_info = filter_mapping(dock_info, ( : strsrch($1, station) != -1 :));
   frame_init_user();
   set_frame_title("Docking status");
   set_frame_header(sprintf("%-12.12s %-30.30s %-26.26s %s\n", "Call sign", "Ship Type", "Docked at", "Docked for"));
   foreach (string file, class docking_info di in dock_info)
   {
      object ship = load_object(di.vfile);
      class ship_info si = ship->query_ship_info();
      // Should be checked before this point, so we do not have to load ships that are not at this station
      if (si.location == this_body()->query_location())
         content += sprintf(
             " <" + raw_accent() + ">%-12.12s<res> %-30.30s %-26.26s %s\n", si.name, capitalize(si.type), di.dock_name,
             di.docking_time < time() ? time_to_string(time() - di.docking_time) : "[Currently docking]");
   }
   set_frame_content(content != "" ? content
                                   : "(There are currently no docked ships at " + this_body()->query_location() + ")");
   return frame_render();
}
