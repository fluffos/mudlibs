#include "/players/reflex/lib/lib.h"
#include "/players/reflex/lib/include/ansi.h"
inherit ROOM;

    void create() {
        ::create();

    set_short(BLU+"Reflex's Office"+NORM);
    set_long(
        "This is the office of the Sage Reflex.  There is a desk\n"+ 
        "with a computer on it in front of a window overlooking\n"+ 
        "Nirvana.  There is a leather chair behind the desk, it\n"+
        "looks very large and comfortable.  You see an inbox and\n"+
        "outbox, and a chair facing the desk.  The office is lit\n"+
        "dimly, and you get a feeling of "+BLU+"power"+NORM+" here....\n\n"+
        "There is a shimmering "+BLU+"portal"+NORM+" in the wall...\n"
        );
    set_items(([
        "computer" :
        "A Tower of "+BOLD+"Power"+NORM+"!  500Mhz AMD K7 Workstation, "+
        "it must\n have 256MB of RAM, and at least a 18GB SCSI HD...\n"+ 
        "Must be used for work....Is that Final Fantasy 7 you see on\n"+
	"on the screen..?\n",
        "portal" :
        "<><><><><><><><><><><><><><><><><><><><><><><><><><><><><>\n"+
        "<> You can go to any of the following places:           <>\n"+        
        "<> -Advance-  -Church-  -Boards--  ---------  --------- <>\n"+
        "<> -Assembly  -Post---  -Templar-  -Clean---  --------- <>\n"+
        "<><><><><><><><><><><><><><><><><><><><><><><><><><><><><>\n",
        "desk" :
        "A large ornate solid oak desk...Rather intimidating...\n",
        "inbox" :
        "Stacked to overflowing with papers and things to be done...\n",
        "outbox" :
        "Strangly, much emptier than the inbox....\n",
        "chair" :
        "A large comfortable looking armchair.\n",
        ]));
    set_smells(([
        "default" : 
        "You smell genuine leather, must be the chair...\n",
        "desk" :
        "You smell oak...what did you expect..?\n",
        "leather" :
        "Its real...\n",
        "computer" :
        "Ahhhhh...nice, new plastic...\n",
        "inbox" :
        "Paper..ink...rotten sandwich...\n",
        "outbox" :
        "Paper..ink...rotten apple...\n",
        "portal" :
        "ZAAAAP!!!\n\nYour nose smarts!\n",
        "armchair" :
        "You smell leather...\n",
        ]));
    set_sounds(([
        "default" :
        "You hear the music of Doom coming from the computer...\n",
        "computer" :
        "You hear the gentle whirr of the fan, and the somewhat\n"+
        "louder sounds of Final Fantasy 7...\n",
        "portal" :
        "Humms just like a lightsaber....\n",
        "sandwich" :
        "This sucker is so rotten it is singing in a low tone!\n",
    ]));
    set_chat_frequency(300);
    load_chats(({
        "The computer hums quietly...\n",
        "The "+BLU+"portal "+NORM+"shimmers...\n",
        "A secretary bustles into the room...\n"+
        "Secretary says:  Are you ever going to get caught up?\n"+
        "Sighing, the secretary dumps some more papers on the inbox.\n"+
        "The secretary turns and walks out.\n",
        }));
    set_exits(([
        "assembly" : "/players/mythos/closed/guild/assembly",
        "templar" : "/players/boltar/templar/adv_guild",
        "clean" : "/players/reflex/clean",
        "advance" : "/room/adv_guild",
        "church" : "/room/church",
        "post" : "/room/post",
        "boards" : "/room/adv_inner",
        ]));
    set_light(1);
}
