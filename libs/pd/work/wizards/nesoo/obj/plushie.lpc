#include <std.h>

inherit OBJECT;

int cmd_pull(string);

void create() {
    ::create();
    set_name("Nesoo plushie");
    set_id(({ "plushie", "nesoo plushie" }));
    set_short("a Nesoo plushie");
    set_long("The cute Bastet form of the Nesoo plushie is " +
            "covered in smooth, soft, velvety fur. Curiously, " +
            "its tail occasionally twitches. There is a <pull " +
            "string> on its back.");
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
        return notify_fail("Patience is a virtue.\n");
    
    rand = random(50 + random(50 + random(100)));
    rand = random(7);
    
    msg_tp = "The Nesoo plushie ";
    msg_room = this_player()->query_cap_name() + "'s Nesoo plushie ";
    
    switch( rand )
    {
        case 0:
            msg_tp += "baps you with a stupid stick!";
            msg_room += "baps " + this_player()->query_objective() +
                    " with a stupid stick!";
            break;
        case 1:
            msg_tp += "cackles demonically!";
            msg_room += "cackles demonically!";
            break;
        case 2:
            msg_tp += "purrs contentedly.";
            msg_room += "purrs contentedly.";
            break;
        case 3:
            msg_tp += "sticks its tongue out at you.";
            msg_room += "sticks its tongue out at " +
                    this_player()->query_objective() + ".";
            break;
        case 4:
            msg_tp += "licks you.";
            msg_room += "licks " + this_player()->query_objective() + ".";
            break;
        case 5:
            msg_tp += "gives you a big hug.";
            msg_room += "hugs " + this_player()->query_objective() + ".";
            break;
        case 6:
        default:
            msg_tp += "ponders the cosmos.";
            msg_room += "ponders the cosmos.";
    }
    
    this_player()->set_disable();
    
    message("info", "You pull the string on the back of your " +
            "Nesoo plushie.", this_player());
    message("info", this_player()->query_cap_name() + " pulls the " +
            "string on the back of " + this_player()->query_possessive() +
            " Nesoo plushie.", environment(this_player()), this_player());
    
    message("info", msg_tp, this_player());
    message("info", msg_room, environment(this_player()), this_player());
    return 1;
}

int query_auto_load()
{
    return 1;
}

