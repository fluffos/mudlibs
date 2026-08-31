inherit INDOOR_ROOM;

void setup()
{
   set_area("omega_terminal", "landing_term");
   // set_weather(1);
   set_light(1);
   set_brief("Stargate Terminal");
   set_long("The room is vast, stretching up to the high ceiling in a dome-like shape. "
            "The walls are made of a gleaming metal that reflected the light of the star-filled"
            "sky outside, casting a soft glow into the room. In the center of the room is a circular"
            " platform that looked like a massive metal disc, with a pulsating energy field swirling in the center.\n"
            "An elevator door to the northwest is $elevator_door, and the lamp next to it $lamp.");
   set_state_description("elevator_door_off", "closed, and reflecting the room's surroundings");
   set_state_description("elevator_door_on", "open");
   set_state_description("lamp_off", "awaits activation, ready to transport "
                                     "individuals to their desired destinations amidst the stars");
   set_state_description("lamp_on", "is flashing");

   set_exits(([]));
   set_objects((["/std/elevator_call_button":({"9/Stargate Terminal", "^omega/room/elevator_center"}),
                        "/std/elevator_door":({"northwest", "^omega/room/elevator_center"}),
                  "^common/item/node_portal":({"/domains/omega/room/floor8/waiting_room8"})]));

   set_room_chat(({"A starcruiser quickly whizzes by above the dome.",
                   "You see a large freighter moving in, getting ready to dock.",
                   "The archway at the center of room briefly flashes.",
                   "A small meteor briefly reflects its path in the shiny platform at the center of the room."}),
                 60, 10);
}

// Function needed to tell people about the elevator lamp in any room with an elevator.
void arrived()
{
   if (query_state("lamp"))
      tell_from_inside(this_object(), "The lamp on the button beside the elevator goes out.\n");
   clear_room_state("lamp");
}