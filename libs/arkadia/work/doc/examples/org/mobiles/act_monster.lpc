/* Acting monster */

inherit "/std/monster";

create_monster()
{
    set_name("actor");
    set_short("actor");
    set_long("He's just looking for a film.\n");

    set_act_time(5); /* It will take 10 + random(5) seconds between each act */
    add_act("laugh"); /* Somtimes he will laugh */
    /* And sometimes he will do these commands one after another. */
    add_act(({"say I'm good you know.", "wink", "applaud"}));
}

