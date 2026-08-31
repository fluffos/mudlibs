#include <triggers.h>

inherit LIVING;
inherit M_CONVERSATION;
inherit M_ACTIONS;
inherit M_TRIGGERS;

void setup()
{
    ::setup();
    set_name("Terminal Attendant");
    set_id("attendant");
    set_gender(2);
    set_proper_name("Kimby Watson");

    set_in_room_desc("A friendly looking attendant.");
    set_long("The attendant is wearing a police uniform from before the wars. The jacket lies draped across the back of "
             "the camping chair, his sleeves are turned up and his hands are dirty from bike grease.\n");
    set_gender(1);

    set_actions(10, ({"say Hello and Welcome to Omega Terminal.",
                     "Say Can I help you with anything?",
                     "smile"}));
    add_pattern(
        "%s help", function() {
            respond("say how can I help you?");
        });

    set_options((["hello":"Hello!"]));

    set_responses((["hello":"Hello there!@@attendant"]));
    set_start(({"hello"}));
}