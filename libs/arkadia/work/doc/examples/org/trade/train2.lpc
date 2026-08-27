inherit "/lib/skill_raise";
inherit "/std/room";

#include <ss_types.h>
#include <stdproperties.h>

#define SS_RESCUE	67530
#define SS_BASH		67531
#define SS_KICK		67532

/*
 * Prototypes
 */
void set_up_skills();

void
create_room()
{ 
    set_short("Second Training room");
    set_long(break_string("" +
	"This is the training room on the second floor. Here only members " +
	"are allowed. The skills you can train here are all special for " +
	"the Knights of Solamnia. There is a sign on the wall with some " +
	"information. The hall is west." +
	"\n", 75));

    add_item("sign", "There are words on it, why not read it?\n");
    add_cmd_item(({"words", "sign"}), "read", "@@read");

    create_skill_raise();
    set_up_skills();

    add_prop(ROOM_I_INSIDE, 1);
}

int
read()
{
    write("" +
	"In here you can train rescueing, kicking and bashing skills. To\n" +
	"use them you do the commands 'rescue', 'ckick' or 'bash'. If you\n" +
	"rescue another being one of the living beings hitting on this\n" +
	"being will start hitting on you instead. 'ckick' stands for\n" +
	"combat kick, and if it's successful you will hurt your opponent.\n" +
	"You will have to wait a little between each kick. A bash works\n" +
	"just as a kick, but it hits harder and you have to wait a little\n" +
	"longer between each bash.\n\n" +
	"When you improve your skills here you will advance much quicker\n" +
	"than you do in normal guilds. And if you are intelligent you will\n" +
	"learn even quicker.\n");

    return 1;
}

void
init()
{
    init_skill_raise();
    ::init();
}

void
set_up_skills()
{
    sk_add_train(SS_RESCUE, "rescue people when fighting", "rescue", 50, 100 );
    sk_add_train(SS_BASH, "bash an enemy", "bash", 100, 100 );
    sk_add_train(SS_KICK, "kick an enemy", "kick", 100, 100 );
}

