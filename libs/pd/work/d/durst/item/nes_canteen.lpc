#include <std.h>
#include <durst.h>

inherit OBJECT;

int IsFull;

void create() {
    ::create();
    set_name("nesoo_canteen");
    set_short("a small canteen");
    set_long("a small canteen");
    set_id(({ "canteen", "small canteen" }));
    set_weight(3);
    IsFull = 0;
}

void init()
{
    ::init();
    add_action("fill_canteen", "fill");
    add_action("give_canteen", "give");
}

string query_short()
{
    if( IsFull != 0 )
        return "a small canteen (filled)";
    else
        return "a small canteen";
}

string query_long()
{
    if( IsFull != 0 )
        return "A small canteen made from a sheep's stomach."
            " It is filled with water.";
    else
        return "A small canteen made from a sheep's stomach."
            " If you found a body of water, you could fill it.";
}

int fill_canteen(string str)
{
    if( str == "canteen" || str == "canteen with water" ||
        str == "canteen from pool" )
    {
        if( present("nesoo_pool", environment(this_player())) )
        {
            if( IsFull != 0 )
            {
                write("The canteen is already filled!");
            }
            else
            {
                write("You fill the canteen with water from the pool.");
                say(this_player()->query_cap_name()+" fills a canteen"
                    " with water from the pool.", this_player());
                IsFull = 1;
            }
        }
        else
        {
            write("Nothing to fill it with!");
        }
        return 1;
    }
    else
        return 0;
}

int give_canteen(string str)
{
    if( str == "canteen to man" || str == "canteen to nomad")
    {
        if( present("parched nomad", environment(this_player())) )
        {
            if( IsFull != 0 )
            {
                write("You give the canteen to the parched nomad.");
                say(this_player()->query_cap_name()+" gives a canteen to a
parched nomad.",
                    this_player());
                write("A parched nomad drinks the water from the canteen.");
                say("A parched nomad drinks the water from the canteen.",
this_player());
                write("You feel like you have performed a good deed.");
                this_player()->set_mini_quest("parched_nomad", 50,
                    "You brought water to a parched nomad.");
                this_object()->remove();
                return 1;
            }
        }
    }
    
    return 0;
}
