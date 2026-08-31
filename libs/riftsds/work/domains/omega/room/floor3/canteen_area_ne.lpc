inherit INDOOR_ROOM;

void setup()
{
   set_area("omega_terminal", "canteen");
   set_brief("Canteen - seating area");
   set_long("An inviting atmosphere greets you in the canteen. It is a hub of social activity and nourishment for the "
            "Omega Station inhabitants, offering a respite from the cosmic journeys and a place to gather and "
            "refuel.\nThe interior of the canteen is spacious and thoughtfully designed, with a combination of modern "
            "aesthetics and comfort. The walls are adorned with large panoramic windows, allowing visitors to gaze out "
            "into the vastness of space while enjoying their meals. The views showcase breathtaking vistas of stars, "
            "nebulas, and distant planets, providing a serene backdrop to the dining experience.\n$service_hatch.");
   set_state_description("service_hatch_off", "A small service hatch in the floor is closed");
   set_state_description("service_hatch_on", "A small service hatch in the floor is open");

   set_exits((["west":"canteen_area_nw", "south":"canteen_area_se"]));
   set_combat_forbidden(1);
   set_objects((["^common/item/service_hatch":({"down", "canteen_duct1"})]));
}