// Do not remove the headers from this file! see /USAGE for more info.

inherit ELEVATOR;

#define ELV "%^SAY%^Elevator speaker says<res>, "

string query_where();

void setup()
{
   // Call setup() in ELEVATOR
   ::setup();
   // Description of the elevator make sure to mention the buttons you can press.
   // Cmds like 'look at cryo button' also works.
   set_long("The elevator inside Omega Station is a sleek, futuristic design built with "
            "functionality and safety in mind. The interior of the elevator car is spacious, allowing "
            "for a comfortable number of passengers to travel between different levels of the station. "
            "The walls are made of polished metal, giving it a modern and clean appearance.\n"
            "At the center of the elevator's interior, there is a panel neatly arranged in a "
            "vertical column. The panel features a series of illuminated buttons, each representing a "
            "different floor or destination within the space station. The buttons are touch-sensitive, "
            "responding to a gentle press with a soft glow.");
   // Set destinations with filenames of where we can go and shorthands.
   set_destinations(
       (["1/Maintenance":"^omega/room/floor1/waiting_room1",
                        "2/waiting2":"^omega/room/floor2/waiting_room2",
                       "3/cafeteria":"^omega/room/floor3/waiting_room3", "4/labs":"^omega/room/floor4/waiting_room4",
                        "5/waiting5":"^omage/room/floor5/waiting_room5",
           "6/Upper Living Quarters":"^omega/room/floor6/waiting_room6",
                   "7/Omega Trading":"^omega/room/floor7/waiting_room7",
                "8/Landing Terminal":"^omega/room/floor8/waiting_room8",
               "9/Stargate Terminal":"^omega/room/floor9/stargate_term", ]));

   set_room_chat(
       ({ELV "\"Ladies and gentlemen, this is a reminder to secure any loose objects "
         "and refrain from leaning on the doors. "
         "Safety is our top priority. Enjoy your ride.\"",
         ELV "\"Attention, station residents. A friendly reminder to check the latest "
         "station events on the information "
         "screens located in each level. There's always something exciting happening. Stay connected!\"",
         ELV "\"Attention, crew members. The station's cafeteria on Level 3 is now "
         "serving a limited-time special menu. Don't miss out on the delicious offerings. Bon appétit!\"",
         ELV "\"Emergency procedures reminder. In the event of a power outage or "
         "system malfunction, emergency lighting will activate, and communication channels will remain open. "
         "Please remain calm and await further instructions.\"",
         ELV "\"Attention, passengers. The station's research labs on Level 4 have "
         "recently achieved a major breakthrough. Come explore the forefront of scientific discovery and "
         "witness innovation in action.\""}),
       60, 10);

   // Set start position for elevator
   move_to("8/Landing Terminal");

   // Set the distance from and to each destination in seconds
   set_default_distance(10);

   // Set an elevator door direction and default location
   set_objects((["/std/elevator_door":({"southeast", "waiting_room8"})]));

   // Spawn the buttons on the wall automatically.
   // This *must* be done after the set_destinations() cal.
   setup_buttons();
}

void arrive()
{
   ::arrive();
   tell_from_inside(this_object(), ELV "\"You have arrived at " +
                                       explode(query_where(), "/")[1] + "\".");
}