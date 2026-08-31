inherit INDOOR_ROOM;

void setup()
{
   set_area("omega_terminal", "landing_term");
   // set_weather(1);
   set_light(1);
   set_brief("West Hallway near Medical Station");
   set_long("The hallway in the space station extends ahead, its metallic walls reflecting the soft ambient lighting. "
            "Doors sporadically punctuate the corridor, leading to various compartments. The hum of machinery fills "
            "the air, underscoring the station's constant activity. Passengers and crew traverse the corridor, their "
            "footsteps echoing against the metal floor. Despite the hustle and bustle, the hallway maintains an "
            "orderly flow, facilitating movement throughout the station.\nA green blinking plus indicates a medical "
            "station just north of here.");
   set_state_description("electronic_door_off", "closed");
   set_state_description("electronic_door_on", "open");
   set_exits((["west":"w_hall1", "east":"w_hall3", "north":"w_clinic", ]));
   // set_objects(([""]));
   set_listen("You hear people running through the terminal. " +
              "It sounds like a busy terminal with people coming and going");
}
