inherit INDOOR_ROOM;

void setup()
{
    set_area("omega_terminal", "landing_term");
    // set_weather(1);
    set_light(1);
    set_brief("Terminal Center Elevator");
    set_long("A waiting room with an elevator on the north west wall. $lamp");
    set_state_description("electronic_door_off", "closed");
    set_state_description("electronic_door_on", "open");

    // This adds the lamp description to the long description when the elevator
    // is in transit to this room. See the $lamp above, and put it where you
    // want it.
    set_state_description("lamp_on", "The lamp beside the elevator is lit.");
    set_exits((["south":"s_hall4",
                "north":"n_hall4",
                 "west":"w_hall4",
                 "east":"e_hall4"]));

    // Elevator setup:
    // Elevator door, direction of door, and name of elevator room.
    // Elevator call button, name of this destination (must match the names
    //    in the elevator room!), and the name of the elevator room.
    set_objects((["/std/elevator_door":({"northwest", "^omega/room/elevator_mid"}),
           "/std/elevator_call_button":({"docking", "^omega/room/elevator_mid"}),
    ]));
    set_listen("You hear people running through the terminal. " +
               "It sounds like a busy terminal with people coming and going");
}

void arrived()
{
    if (query_state("lamp"))
        tell_from_inside(this_object(), "The lamp on the button beside the elevator goes out.\n");
    clear_room_state("lamp");
}
