inherit INDOOR_ROOM;

void setup()
{
   set_area("omega_terminal", "landing_term");
   // set_weather(1);
   set_light(1);
   set_brief("West Hallway near intersection");
   set_long("The western hallway in the landing terminal extends ahead, its metallic walls reflecting the soft ambient "
            "lighting. "
            "Doors sporadically punctuate the corridor, leading to various compartments. Passengers and crew traverse "
            "the corridor, their "
            "footsteps echoing against the metal floor. Despite the hustle and bustle, the hallway maintains an "
            "orderly flow, facilitating movement throughout the station.");
   set_state_description("electronic_door_off", "closed");
   set_state_description("electronic_door_on", "open");
   set_exits((["east":"waiting_room", "west":"w_hall2", ]));
   // set_objects(([""]));
   set_listen("You hear people running through the terminal. " +
              "It sounds like a busy terminal with people coming and going");
}
