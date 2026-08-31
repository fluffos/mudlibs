inherit INDOOR_ROOM;

void setup()
{
    set_area("omega_terminal", "trading_term");
    // set_weather(1);
    set_light(1);
    set_brief("Alley Way");
    set_long("A small alley leading east and west There is more shops located here."
             "A shop to the north and south is for sell");
    // set_state_description("electronic_door_off", "closed");
    // set_state_description("electronic_door_on", "open");
    set_exits((["west":"n_corridor1",
                "east":"ne_alley1",
               "north":"player_shop1",
               "south":"player_shop2",
    ]));
    // set_objects(([""]));
    set_listen("You hear people running through the terminal. " +
               "It sounds like a busy terminal with people coming and going");
}
