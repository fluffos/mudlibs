inherit INDOOR_ROOM;

void setup()
{
   set_area("omega_terminal", "canteen");
   set_brief("Canteen - vending machines");
   set_long("An inviting atmosphere greets you in the canteen. It is a hub of social activity and nourishment for the "
            "Omega Station inhabitants, offering a respite from the cosmic journeys and a place to gather and "
            "refuel.\n"
            "The interior of the canteen is spacious and thoughtfully designed, with a combination of modern "
            "aesthetics and comfort. The walls are adorned with large panoramic windows, allowing visitors to gaze out "
            "into the vastness of space while enjoying their meals. The views showcase breathtaking vistas of stars, "
            "nebulas, and distant planets, providing a serene backdrop to the dining experience.");
   set_exits((["east":"canteen_area_ne", "south":"canteen_area_sw"]));
   set_objects((["^omega/npc/floor3/canteen_cleaner":1]));
   set_combat_forbidden(1);
}