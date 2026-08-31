#include <std.h>

inherit OBJECT;

int cmd_pull(string);

void create() {
    ::create();
    set_name("Daboura plushie");
    set_id(({ "plushie", "daboura plushie" }));
    set_short("a Daboura plushie");
    set_long("The Daboura plushie is a dark, sinister Centaur, " +
            "with coarse black hair. His tail sways occasionally, " +
            "as if swatting at imaginary flies. There is a <pull " +
            "string> on the back of the human torso.");
    set_weight(1);
}

void init()
{
    ::init();
    add_action("cmd_pull", "pull"); // function, command
}

int cmd_pull(string str)
{
    string msg_tp = "";
    string msg_room = "";
    int rand = 0;
    
    if( !str || str != "string" )
        return notify_fail("Pull what?\n");
    
    if( this_player()->query_disable() )
        return notify_fail("Not now.\n");
    
    rand = random(50 + random(50 + random(100)));
    rand = random(7);
    
    msg_tp = "The Daboura plushie ";
    msg_room = this_player()->query_cap_name() + "'s Daboura plushie ";
    
    switch( rand )
    {
        case 0:
            msg_tp += "growls: I think I'll \"balance\" " +
                    this_player()->query_subclass() +"s next.";
            msg_room = msg_tp;
            break;
        case 1:
            msg_tp += "cackles demonically!";
            msg_room = msg_tp;
            break;
        case 2:
            msg_tp += "scowls at you.";
            msg_room += "scowls at "+ this_player()->query_objective() + ".";
            break;
        case 3:
            msg_tp += "grumbles.";
            msg_room = msg_tp;
            break;
        case 4:
            msg_tp = "The Daboura plushie's eyes glow red.";
            msg_room = msg_tp;
            break;
        case 5:
            msg_tp += "glares at you.";
            msg_room += "glares at " + this_player()->query_objective() + ".";
            break;
        case 6:
        default:
            msg_tp += "grumbles: I always did hate the " +
                    capitalize(this_player()->query_race()) +
                    " race, maybe I should remove it.";
            msg_room = msg_tp;
    }
    
    this_player()->set_disable();
    
    message("info", "You pull the string on the back of your " +
            "Daboura plushie.", this_player());
    message("info", this_player()->query_cap_name() + " pulls the " +
            "string on the back of " + this_player()->query_possessive() +
            " Daboura plushie.", environment(this_player()), this_player());
    
    message("info", msg_tp, this_player());
    message("info", msg_room, environment(this_player()), this_player());
    return 1;
}

int query_auto_load()
{
    return 1;
}

