inherit INDOOR_ROOM;

void setup()
{
    set_area("omega_terminal", "trading_term");
    // set_weather(1);
    set_light(1);
    set_brief("Omega Armour Trading Company");
    set_long("An Armor SHop.");
    set_state_description("electronic_door_off", "closed");
    set_state_description("electronic_door_on", "open");
 
    set_objects((["/domains/common/obj/auto_door":({"west", "n_corridor"}),
    ]));
    set_listen("You hear people running through the terminal. " +
               "It sounds like a busy terminal with people coming and going");
}
