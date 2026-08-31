inherit INDOOR_ROOM;

void setup()
{
   set_area("omega_terminal", "landing_term");
   set_brief("Landing Terminal West 2");
   set_long("Ship Landing for visitors and deliveries. You must speak with the coordinaotor for extended stay.");
   set_state_description("electronic_door_off", "closed");
   set_state_description("electronic_door_on", "open");
   set_exits((["south":"sw_ship_bay", "north":"w_landing1", ]));
   // set_objects(([""]));
   set_listen("You hear people running through the terminal. " +
              "It sounds like a busy terminal with people coming and going");
}
