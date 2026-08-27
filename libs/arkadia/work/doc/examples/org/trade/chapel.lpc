inherit "/std/room";
inherit "/lib/guild_support"; 

#include <macros.h>
#include <stdproperties.h>

void
create_room()
{ 
    set_short("The chapel");
    set_long(break_string("" +
	"You are in the Chapel devoted to Paladine. There is a small altar " +
	"in one end where you can kneel and meditate to ask Paladine about " +
	"your stats, and also change your learning preferences." +
	"\n", 75));

    add_prop(ROOM_I_INSIDE, 1);
    add_prop(ROOM_M_NO_ATTACK, "The feeling of peace is too great here.\n");
}

void
init()
{
    ::init();
    init_guild_support();
}

void
gs_hook_start_meditate()
{
    write("" +
	"You kneel before the altar of Paladine and close your eyes.\n" +
	"A feeling of great ease and self control falls upon you.\n" +
	"You block of your senses and concentrate solely upon your\n" +
	"own mind. You feel Paladine with you and he gives you the\n" +
	"power to <estimate> your different stats and <set> the\n" +
	"learning preferences at your own desire. Just <rise> when\n" +
	"you are done meditating.\n");
}

int
gs_hook_rise()
{
    write("As if ascending from a great depth, you rise to the surface\n" +
	  "of your consciousness. You exhale and feel very relaxed as\n" +
	  "you get up and leave the altar.\n");
    say(QCTNAME(this_player()) + " rises from the altar.\n");
}

