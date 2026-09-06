/* death_room.c */
/* Mrpr 901119 */
/* Graah 941123 (!) */
#include <room.h>
#include <areas.h>

#define WRITE(x) players[j]->tell_me(x)
#define SPEAK(x) players[j]->tell_me("Death says: " + x)
#define TP this_player()

object death;

void
init_room()
{
    int cl;

    if (!death) death = clone_object(AREA_TRISTEZA+"death/death");
    if (!present(death,this_object()))
    {
	move_object(death,this_object());
	tell_here("Death arrives from a coffee break.", ({ death }));
    }

    if (!TP->query_npc() && (TP != death))
    {
	cl = (int)TP->query_coder_level();
	if ((int)TP->query_ghost() != 1)
	{
	    if (!cl && TP->query_invis())
		TP->vis();

	    if (cl > 299)
		tell_here("Death says: HELLO, DEAR COLLEAGUE, HOW ARE YOU TODAY?",
		  ({ death }) );
	    else if (cl > 99)
		tell_here("Death says: HELLO, " +
		  capitalize((string)TP->query_real_name()) + ".",
		  ({ death }) );
	    else
		tell_here(
		  "Death says: WELL, WELL, WE SEEM TO HAVE A MORTAL VISITOR HERE.",
		  ({ death }) );
	}
    }
}

void
create_room()
{
    set_short("Death's workroom");
    set_long(
      "A dark room lighted with a dark light that seems to defy darkness not so \
much by actually illuminating the room as by being a darkpoint in less \
dark surroundings. In the strange light (dark?) you can see a desk, placed \
in center, covered with books and diagrams. The walls are covered with \
bookshelves filled with dark tomes bound in leather that gleam with \
strange runes.");
    set_light_level(LT_LIGHTS);
    set(PREVENT_TELEPORT);
    set(ROOM_WD,WD_NONE);
    set(PREVENT_SHOUT);

    add_command("west", "west_cmd");
}

/* Secret exit */
status
west_cmd()
{
    TP->tell_me("To your amazement, you manage to pass through the wall!");
    TP->move_player("through west wall#"+AREA_TRISTEZA+"death/winding");
    return 1;
}

/* To make him regain scythe and robe */
new_death() {
    if(present("death",this_object()))
	destruct(present("death",this_object()));
}
