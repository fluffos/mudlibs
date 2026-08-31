inherit INDOOR_ROOM;

void setup()
{
   set_area("omega_terminal", "canteen");
   set_brief("Canteen - counter");
   set_long("An inviting atmosphere greets you in the canteen. It is a hub of social activity and nourishment for the "
            "Omega Station inhabitants, offering a respite from the cosmic journeys and a place to gather and "
            "refuel.\nThe interior of the canteen is spacious and thoughtfully designed, with a combination of modern "
            "aesthetics and comfort. The walls are adorned with large panoramic windows, allowing visitors to gaze out "
            "into the vastness of space while enjoying their meals. The views showcase breathtaking vistas of stars, "
            "nebulas, and distant planets, providing a serene backdrop to the dining experience.");
   set_exits((["south":"canteen_hall2", "north":"canteen_area_nw", "east":"canteen_area_se"]));
   set_objects((["^omega/npc/floor3/canteen_sales":1]));
   set_combat_forbidden(1);
   
   // This is really Liam's item, but adding it here since it's easier. Liam is a non-combatant, so he'll always be in
   // this room.
   add_item("pin", "It's a small pin, pinned to Liam's shirt. It has the face of some kind of long eared goblin and "
                   "below it says 'WELCOME YOU ARE'.");
}