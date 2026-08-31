inherit INDOOR_ROOM;

void setup()
{
   set_area("omega_terminal", "duct");
   set_brief("Behind the hatch");
   set_long("A stark contrast from the bustling and vibrant dining area, the $service_hatch leads to a service area "
            "consisting "
            "of low, dimly lit corridors with an unsettling atmosphere. The air feels stagnant and slightly musty, "
            "carrying a faint metallic tang that lingers in the surroundings.\n"
            "The corridors are narrow and cramped, barely accommodating the passage of a single person. Dull, "
            "flickering fluorescent lights cast long shadows, adding an eerie ambiance to the environment. The walls, "
            "covered in faded and peeling paint, reveal signs of wear and neglect.");
   set_state_description("service_hatch_off", "closed service hatch");
   set_state_description("service_hatch_on", "now open small service hatch");

   set_exits((["north":"canteen_duct2", "south":"canteen_duct6"]));
   set_objects((["^common/item/service_hatch":({"up", "canteen_area_ne"}), "../../mob/space_roach":1]));
}