inherit INDOOR_ROOM;

void setup()
{
   set_area("omega_terminal", "maintmaze");
   set_brief("Station systems overview");
   set_long("This chamber is engulfed in a haze of faint flickering lights. The holographic arrays seem worn, and some "
            "calibration tools are scattered across the floor. The central platform, once gleaming, now bears smudges "
            "and traces of technical residue.\nA communication panel is on the south wall here.");
   add_item("arrays", "tools", "They look quite advanced.");
   set_exits((["east":"maint13", "west":"maint11"]));
   set_listen("A low hum is heard here.");
   set_objects((["^omega/item/communication_panel":({"commquest4"}), "^omega/mob/tech_gremlin":1]));
}
