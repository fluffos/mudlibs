#include "/players/mizan/esc.h"

id(str) { return str == "water-stains"; }

get()  { return 1; }
drop() { return 1; }

extra_look() 
{
   if(environment()) return (environment()->query_name()) + " is soaking wet from a water balloon impact";
}

reset()
{
    remove_call_out("erase_me");
    call_out("erase_me", 200);
    call_out("wash_me", 5);
}

wash_me()
{
    object ob;
    object player;
    object playerroom;

    player = environment();
    if(player)
    {
        playerroom = environment(player);
        ob = present("stains", player);
    }

    if(ob)
        if(1 == random(3))
        {
            if(playerroom)
                tell_room(playerroom, "You notice that " + player->query_name() + " seems cleaner.\n");
            if(player)
                tell_object(player, "You feel cleaner. The water balloon has washed away some grit.\n");

            destruct(ob);
        }
        else
        {
            if(playerroom)
                tell_room(playerroom, "Water drips in a steady flow from " + player->query_name() + ".\n");
            if(player)
                tell_object(player, "You are SOAKED!\nDrip... drip... drip..\n");
        }
}

erase_me()
{
    destruct(this_object());
    return 1;
}