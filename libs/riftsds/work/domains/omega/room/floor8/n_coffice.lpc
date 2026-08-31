inherit INDOOR_ROOM;

void setup()
{
    set_area("omega_terminal", "landing_term");
    set_brief("Landing Control Office");
    set_long("This is the control office for the North Landing zone.");
    set_state_description("electronic_door_off", "closed");
    set_state_description("electronic_door_on", "open");
    set_exits((["south":"n_landing2",
                //"west":"n_ccloset",
               //"north":"n_computer_office"
               ]));
    // set_objects(([""]));
    set_listen("You hear people running through the terminal. " +
               "It sounds like a busy terminal with people coming and going");
}
