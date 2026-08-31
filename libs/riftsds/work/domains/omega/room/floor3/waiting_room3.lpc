inherit INDOOR_ROOM;

void setup()
{
   set_area("omega_terminal", "hallway");
   set_brief("Central Elevator room - 3rd Floor");
   set_long(
       "A waiting area with seats along the walls, the north corridor leading to the canteen area. The "
       "hallway itself is sleek and streamlined, with polished metallic walls. The floor beneath your feet is made of "
       "durable grey composite material.\n"
       "On the northwestern wall, a high-tech elevator is seamlessly integrated, its polished metallic doors are "
       "$elevator_door. "
       "Adjacent to the elevator, a gleaming elevator button $lamp.");
   set_state_description("elevator_door_off", "closed, and reflecting the room's surroundings");
   set_state_description("elevator_door_on", "open");
   set_state_description("lamp_off", "awaits activation, ready to transport travellers");
   set_state_description("lamp_on", "is flashing");

   set_state_description("electronic_door_off", "closed");
   set_state_description("electronic_door_on", "open");
   set_exits((["north":"canteen_hall1"]));
   set_objects((["/std/elevator_call_button":({"3/cafeteria", "^omega/room/elevator_center"}),
                        "/std/elevator_door":({"northwest", "^omega/room/elevator_center"}), ]));
   add_item("floor", "The surface has a subtle texture that provides traction and minimizes the risk of slipping, "
                     "ensuring safe passage for the station's inhabitants.");
   add_item("wall", "walls", "The walls reflect the light, creating a sense of spaciousness.");
   add_item("seat","seats","They seem to be quite worn and dirty.");
}

// Function needed to tell people about the elevator lamp in any room with an elevator.
void arrived()
{
   if (query_state("lamp"))
      tell_from_inside(this_object(), "The lamp on the button beside the elevator goes out.\n");
   clear_room_state("lamp");
}
