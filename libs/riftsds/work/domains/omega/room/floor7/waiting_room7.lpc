inherit INDOOR_ROOM;

void setup()
{
  set_area("omega_terminal", "trading_term");
  // set_weather(1);
  set_light(1);
  set_brief("Waiting Room");
  set_long("A waiting room, more to come :).");
  set_state_description("electronic_door_off", "closed");
  set_state_description("electronic_door_on", "open");
  set_exits((["north":"n_corridor",
               "west":"w_corridor",
               "east" : "e_corridor",
               "south" : "s_corridor"
  ]));
  set_objects((["/std/elevator_call_button":({"7/Omega Trading",
                                              "^omega/room/elevator_center"}),
                       "/std/elevator_door":({"northwest", "^omega/room/elevator_center"}),
  ]));
}

// Function needed to tell people about the elevator lamp in any room with an elevator.
void arrived()
{
  if (query_state("lamp"))
    tell_from_inside(this_object(), "The lamp on the button beside the elevator goes out.\n");
  clear_room_state("lamp");
}
