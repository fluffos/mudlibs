inherit INDOOR_ROOM;

void setup()
{
   set_area("omega_terminal", "landing_term");
   // set_weather(1);
   set_light(1);
   set_brief("Central Elevator room - 8th Floor");
   set_long(
       "The 8th floor waiting room of the Omega Station, the sleek design and clean lines create an atmosphere of "
       "futuristic elegance. Bathed in a soft, ambient glow, the room is adorned with comfortable, cushioned chairs "
       "arranged in a circular formation, facing a large viewing window that reveals the awe-inspiring expanse of "
       "space outside.\n"
       "On the northwestern wall, a high-tech elevator is seamlessly integrated, its polished metallic doors are $elevator_door. "
       "Adjacent to the elevator, a gleaming elevator button $lamp.");
   set_state_description("elevator_door_off", "closed, and reflecting the room's surroundings");
   set_state_description("elevator_door_on", "open");
   set_state_description("lamp_off", "awaits activation, ready to transport "
                                     "individuals to their desired destinations amidst the stars");
   set_state_description("lamp_on", "is flashing");
   set_exits((["south":"s_hall3", "north":"n_hall3", "west":"w_hall3", "east":"e_hall3"]));
   set_objects((["/std/elevator_call_button":({"8/Landing Terminal", "^omega/room/elevator_center"}),
                        "/std/elevator_door":({"northwest", "^omega/room/elevator_center"}), ]));

   set_room_chat(
       ({"Some busy travellers pass through the waiting room in a hurry", "It seems like the elevator is moving again",
         "Something, somewhere, is beeping", "A small cockroach scuttles quickly into hiding under a floor tile",
         "A light in the ceiling flickers"}),
       60, 10);
}

string query_hint(int l)
{
   if (l<5)
   {
      return "This room holds the central elevator 'push button'. Explore the station until around level 5.";
   }
}

// Function needed to tell people about the elevator lamp in any room with an elevator.
void arrived()
{
   if (query_state("lamp"))
      tell_from_inside(this_object(), "The lamp on the button beside the elevator goes out.\n");
   clear_room_state("lamp");
}
