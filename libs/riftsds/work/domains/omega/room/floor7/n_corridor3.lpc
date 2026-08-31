inherit INDOOR_ROOM;

void setup()
{
    set_area("omega_terminal", "trading_term");
    // set_weather(1);
    set_light(1);
    set_brief("North Corridor");
    set_long("A Wide corridor leading to the north and south through trading area."
             "Leading to the left and right a smaller corridoors.");
    //set_state_description("electronic_door_off", "closed");
    //set_state_description("electronic_door_on", "open");
    set_exits((["south":"n_corridor2",
                "north" : "n_corridor4",
    ]));
    /*set_objects((["^common/obj/auto_door":({"east", "omeage_repair"}),
                  "/domains/common/obj/auto_door":({"west", "oemga_comapre"}),
                  "^common/obj/auto_door":({"south", "n_corridor"})
    ]));*/
    set_listen("You hear people running through the terminal. " +
               "It sounds like a busy terminal with people coming and going");
}
