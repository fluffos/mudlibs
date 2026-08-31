#include <std.h>

inherit OBJECT;

int do_lionroar(string);

void create() {
    ::create();
    set_name("stuffed lion");
    set_id(({ "lion", "stuffed lion" }));
    set_short("a stuffed lion");
    set_long("A stuffed lion. It makes you want to roar " +
        "like a lion!");
    set_weight(2);
    set_curr_value("gold", 10 + random(6));
    set_property("magic item", ({ "lionroar [who] [how]" }));
}

void init()
{
    ::init();
    add_action("do_lionroar", "lionroar");
}

int query_auto_load()
{
    return 1;
}

int do_lionroar(string str)
{
    object ob;
    string who;
    string how;
    
    if( !str )
    {
        message("info", "You roar like a lion!", this_player());
        message("info", this_player()->query_cap_name() +
            " roars like a lion!", environment(this_player()),
            this_player());
        return 1;
    }
    
    if( sscanf(str, "%s %s", who, how) == 2 )
    {
        ob = present(lower_case(who), environment(this_player()));
        if( ob )
        {
            message("info", "You roar at " + ob->query_cap_name() +
                " " + how + "!", this_player());
            message("info", this_player()->query_cap_name() +
                " roars at you " + how + "!", ob);
            message("info", this_player()->query_cap_name() +
                " roars at " + ob->query_cap_name() + " " + how + "!",
                environment(this_player()), ({ this_player(), ob }) );
            return 1;
        }
    }

    ob = present(lower_case(str), environment(this_player()));
    if( ob )
    {
        message("info", "You roar like a lion at " +
            ob->query_cap_name() + "!", this_player());
        message("info", this_player()->query_cap_name() +
            " roars like a lion at you!", ob);
        message("info", this_player()->query_cap_name() +
            " roars like a lion at " + ob->query_cap_name() +
            "!", environment(this_player()), ({this_player(), ob}));
        return 1;
    }
    
    message("info", "You roar " + str + "!", this_player());
    message("info", this_player()->query_cap_name() +
        " roars " + str + "!", environment(this_player()),
        this_player());

    return 1;
}

