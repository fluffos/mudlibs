// Examples on the call command
// By Avelan
// April 2001

#include "defs.h";
inherit ROOM_OBJ;

void setup(){
    set_short("function calls");
    set_determinate("the ");
    set_light(100);
    set_long(@WOMBLE
This room gives you a few examples on how the call command
works, however it wouldn't be possible to give a list on 
all calls you can make, but this should give you some idea.

The call command calls on functions on objects.
You can pretty much call on every function the object has.
A list of some handy calls:

call remove_ghost() <playername>
        This call will effectively remove ghost status from 
        a player, ie. bring them back to life.
        NOTE: You're not allowed to use the call on players,
              they should use the church.

call adjust_money(<amount>,"<type>") <playername>
        This one, as you might have guessed, gives the player
        the amount of coins you want.  And of the type you
        want.  This one is not to be used to aid players
        either.

call set_<stat>(<number>) <playername>
        Sets the stat defined to something.
        Stats are str,dex,wis,int and con.

call add_skill_level("<skillname>",<value>) <playername>
        This one adjusts a skill of a player.  To lower the
        skill just use negative numbers.

A final note, as you should know, you are NOT allowed to aid the
players in any way and if found doing this, you will get punished.

WOMBLE
    );

    add_exit("back", GETSTART "basic_commands/cre_commands","path");
    add_exit("exit", GETSTART "start","path");

}
