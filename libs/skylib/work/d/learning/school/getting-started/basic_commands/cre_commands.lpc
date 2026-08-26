// Some basic commands for creators
// Made for the Divided-Sky by Avelan
// April 2001

#include "defs.h";
inherit ROOM_OBJ;

void setup(){
    set_short("creator commands");
    set_light(100);
    set_determinate("the ");
    set_long(@YEP
In here, you will find some examples of the basic commands
all creators should know about.

ed -         Starts the editing program, see the edtutor for details.

update - Use this command to update a file after you make changes
         to it.  Syntax is either update <path/filename> or
         update <itemname> to update an item you're allready
         carrying.

clone - Clones the object into the game.  Use this to bring
        that little object you have coded actually into the game.
        Syntax is clone <path/filename>.

goto -         Moves you to the target.  You can either 'goto' directly
               into a room or you can also use this to go to a player/npc.
               The syntax is either goto <path/roomname> or
               goto <npc/player name>.
        Also you should ask for permission before 'going' to a player.

dest -  This destroys an item that's cloned into the game.  It also
        works on rooms and players so be carefull when using this. ;)
        Syntax is dest <itemname/playername>, you can also use
        'dest all in here' which destroys every item in the room except
        you.
        NOTE: You are NOT allowed to dest players under any circumstances.

trans -        Transports a player to you.  Be carefull when using this since
        all the people don't like to be transported, always ask for their
        permission before transsing anyone.  Also remember that no players
        should be allowed access to rooms which are in development or
        otherwise off limits, this includes the creator commons.
        Syntax trans <playername>.
        Also remember to do 'return <playername>' to return them to
        where they came from.
YEP
    );

    add_exit("back",GETSTART "start","path");
    add_exit("calls",GETSTART "basic_commands/calls","path");

}
