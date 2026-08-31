inherit INDOOR_ROOM;

void setup()
{
   set_area("omega_terminal", "maintmaze");
   set_brief("Echo Chamber");
   set_long("This dimly lit room is revealed, shrouded in a haze of dust particles. The once-pristine sound-dampening "
            "materials on the walls now show signs of wear, their effectiveness diminished by years of neglect. The "
            "suspended audio-visual orb is coated in a fine layer of grime, capturing the passage of time. Despite its "
            "grimy appearance, the Echo Chamber continues to serve its dual purpose, offering a uniquely muted and "
            "visually obscured space for auditory testing in the heart of the maintenance maze.\nA communication panel "
            "is on the south wall here.");
   set_exits((["south":"maint11", "north":"maint3"]));
   set_listen("You hear the background noise of air treatment systems and computer systems running behind the walls.");
   set_objects((["^omega/item/communication_panel":({"commquest2"}), "^omega/mob/tech_gremlin":1]));
}
