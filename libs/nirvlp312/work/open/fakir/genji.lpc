#include "/players/fakir/color.h"
inherit "room/room";
int found;

reset(arg) 
{
    if(arg) return;
    found = 0;
    set_light(-1);
    short_desc = "Square Room of Stone (Obscure)";
    long_desc =
"   Obscure stone walls form a square box-like room.  Within each wall,\n"+
"motionless warriors grip long handled axes and heavy mace-like weapons.\n"+
"They wear bands of gold and silver on each forearm, signifying rank or\n"+
"status.  The still warriors stare without expression and silently strain\n"+
"to escape the imprisoning walls.  A stone 'square' hangs without support\n"+
"in the center of the room.  Three square doorways slowly spin counter\n"+
"clock-wise within the stone walls.\n";
items = ({
"room",    "A square room with walls of obscure stone",
"walls",   "Square in design, with sharp corners. They are made of obscure stone",
"warriors","Broad shouldered and well built, with bands of gold and silver around each arm",
"bands",   "Precious gold and silver bands, hammered thin and braided for strength",
"square",  "A square stone once imbued with strange magics.\n"+
           "It is now cracked and broken...its magic gone.\n"+
           "You may try to 'turn' the square if you wish",
"stone",   "Once glowing with a strange magic, the stone is now dark",
"doorways","Square doors that spin counter clock-wise at a slow but steady pace",
});

dest_dir = ({
"/players/fakir/genji/rm1d","door1",
"/players/fakir/genji/rm3d","door2",
"/players/fakir/genji/rm5d","door3",
});
}

init()  
{
    ::init();
    add_action("turn_square","turn");
}

turn_square(arg)  
{
    if(!arg || arg != "square") 
    {
      notify_fail(BROWN+"Try to turn the square.\n"+OFF);
      return 0; 
    }
    if(found==0) 
    { 
      write("You turn the square.\n");
      say(this_player()->query_name() + " turns the square.\n");
      call_out("turn_square2", 5); 
       /* call the function 'turn_square2' in 5 seconds */
      found = 1;
    }
    else
    {
      write("You turn the square and nothing happens.\n");
      say(this_player()->query_name() + " turns the square.\n");
    }
      return 1;
}

turn_square2(object who)
{
    tell_room(this_object(),
BROWN + "A harsh voice rumbles...\n\n" +
"\t'The square was broken in some past age.  Its magic is lost and\n"+
"\t will never return.  You may leave as you came...  Now begone.'\n"+
    OFF);
    
    call_out("turn_square3", 5);
}

turn_square3()
{
    tell_room(this_object(), BROWN + "\
I SAID BEGONE!  ELSE I SHALL TAKE WHAT YOU HAVE GAINED!\n" + OFF);

    call_out("turn_square4", 5);
}

turn_square4()
{
    tell_room(this_object(), "\
\t*A dark mist begins to form within the square...\n");
}
