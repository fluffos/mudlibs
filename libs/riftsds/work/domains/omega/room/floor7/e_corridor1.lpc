inherit INDOOR_ROOM;

void setup()
{
    set_area("omega_terminal", "trading_term");
    // set_weather(1);
    set_light(1);
    set_brief("North Corridor");
    set_long("A Wide corridor leading to the north and south through trading area.");
    set_state_description("electronic_door_off", "closed");
    set_state_description("electronic_door_on", "open");
    set_exits((["east" : "e_corridor2",
                "west" : "e_corridor"

    ]));
    /*set_objects((["^common/obj/auto_door":({"east", "omeage_repair"}),
                  "/domains/common/obj/auto_door":({"west", "oemga_comapre"}),
                  "^common/obj/auto_door":({"south", "n_corridor"})
    ]));*/
    set_listen("You hear people running through the terminal. " +
               "It sounds like a busy terminal with people coming and going");
}
