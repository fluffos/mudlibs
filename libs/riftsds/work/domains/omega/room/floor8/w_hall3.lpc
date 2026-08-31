inherit INDOOR_ROOM;

void setup()
{
    set_area("omega_terminal", "landing_term");
    // set_weather(1);
    set_light(1);
    set_brief("West Hallway 3");
    set_long("A hallway leading to the West Landing.");
    set_state_description("electronic_door_off", "closed");
    set_state_description("electronic_door_on", "open");
    set_exits((["east":"waiting_room8",
                "west":"w_hall2",
    ]));
    // set_objects(([""]));
    set_listen("You hear people running through the terminal. " +
               "It sounds like a busy terminal with people coming and going");
}
