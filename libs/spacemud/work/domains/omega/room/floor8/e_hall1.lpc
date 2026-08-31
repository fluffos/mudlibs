inherit INDOOR_ROOM;

void setup()
{
   set_area("omega_terminal", "landing_term");
   // set_weather(1);
   set_light(1);
   set_brief("Star Alley near Stellar bites seating area");
   set_long("The eastern hallway in the space station extends ahead, its metallic walls reflecting the soft ambient "
            "lighting. Doors sporadically punctuate the corridor, leading to various compartments.\n"
            "The Stellar bites Cafe is north of here.");
   set_state_description("electronic_door_off", "closed");
   set_state_description("electronic_door_on", "open");
   set_exits((["west":"e_hall2", "east":"e_hall", "north":"e_cafe"]));
   set_exit_msg("north", "$N $vpass through the automatic doors into Stellar Bites.");
   set_listen("You hear people running through the terminal. " +
              "It sounds like a busy terminal with people coming and going");
}
