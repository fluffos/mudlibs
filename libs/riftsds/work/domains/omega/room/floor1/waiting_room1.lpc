inherit INDOOR_ROOM;

void setup()
{
   set_area("omega_terminal", "mall_term");
   // set_weather(1);
   set_light(1);
   set_brief("Central Elevator room - 1st Floor");
   set_long("The elevator room on the maintenance floor of the space station is a functional and utilitarian space. It "
            "features a compact and sturdy design to accommodate the station's vertical transport needs efficiently. "
            "The room is well-lit with practical fluorescent lighting and is devoid of any decorative elements.\n"
            "There's a $lamp control panel with buttons and digital displays to operate the elevator. The elevator "
            "doors are $elevator_door.");
   set_exits((["north":"n_hall3"]));
   set_objects(
       (["/std/elevator_call_button":({"1/Maintenance", "^omega/room/elevator_center"}),
                "/std/elevator_door":({"northwest", "^omega/room/elevator_center"}), "^std/junk/random_trash":1]));

   set_state_description("elevator_door_off", "dirty, scuffed and closed");
   set_state_description("elevator_door_on", "open");
   set_state_description("lamp_off", "dark");
   set_state_description("lamp_on", "flashing");

   set_room_chat(({"A cockroach scuttles across the floor, quickly hiding behind a cabinet.",
                   "Something starts to hum.", "A light in the ceiling turns off.", "A light in the ceiling flickers"}),
                 60, 10);
}

// Function needed to tell people about the elevator lamp in any room with an elevator.
void arrived()
{
   if (query_state("lamp"))
      tell_from_inside(this_object(), "The lamp on the button beside the elevator goes out.\n");
   clear_room_state("lamp");
}

string *query_hint(int level)
{
   if (level < 10)
   {
      return ({"The pile of trash can be searched for random items - 'search trash'.",
               "After you find something you can 'salvage' it, and see what you found using 'materials'."});
   }
}