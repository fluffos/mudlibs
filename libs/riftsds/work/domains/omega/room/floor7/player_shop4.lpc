inherit INDOOR_ROOM;

void setup()
{
    set_area("omega_terminal", "trading_term");
    // set_weather(1);
    set_light(1);
    set_brief("Available Shop");
    set_long("   A forgotten storefront lies abandoned and forgotten. "
             "Once a hub of commerce, the shop has fallen into disrepair and neglect, the windows boarded up and the neon "
             "signs faded and flickering. But for the ambitious entrepreneur with a vision, "
             "this empty shop represents a blank canvas, ready to be transformed into "
             "something spectacular. With its high ceilings, exposed ductwork and raw "
             "concrete floors, the space has a gritty, industrial feel that lends itself to a "
             "variety of uses.\n" 
             "   The shop has an advanced security system that was left by the"
             "previous owner. This place is a diamond in the rough, waiting for the right person to "
             "bring it to life and make it shine in the bustling futuristic city.");
    set_state_description("electronic_door_off", "closed");
    set_state_description("electronic_door_on", "open");
    set_exits((["north":"ne_alley1",
    ]));
    // set_objects(([""]));
    set_listen("You hear people running through the terminal. " +
               "It sounds like a busy terminal with people coming and going");
}
