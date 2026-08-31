inherit INDOOR_ROOM;

void setup()
{
   set_area("omega_terminal", "maintmaze");
   set_brief("Nanorepair Nexus");
   set_long("Upon entry, this room appears as a dimly lit chamber with flickering overhead lights. Cabinets "
            "housing nanobots and drones are streaked with accumulated grime, and the air carries the weight of aged "
            "lubricants. The once-shiny repair bots now bear the scars of countless microscopic battles, their "
            "movements slower but no less determined.\nA communication panel is on the south wall here.");
   set_exits((["west":"maint1", "east":"maint3"]));
   set_listen("You hear the background noise of air treatment systemsand computer systems running behind the walls.");
   set_objects((["^omega/item/communication_panel":({"commquest3"}), "^omega/mob/tech_gremlin":1]));
}
