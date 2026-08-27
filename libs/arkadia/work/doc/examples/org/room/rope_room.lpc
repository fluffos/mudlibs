/*
 * An example room where one can tie a rope to a pole
 *
 * But not possible to tie more than one rope :)
 */

inherit "/std/room";

object tied; /* The rope that is tied here. */

void
create_room()
{
    set_short("A pole room");
    set_long("This is a room with a nice looking pole and sun in the sky.\n");

    add_item("pole", "I already told you it is nice :)\n");
    add_item("sun", "The sun is shining.\n");
}

int
tie_object(object rope, string where)
{
    if (where != "pole")
    {
	notify_fail("You fail to tie something to there.\n");
	return 0;
    }

    if (tied)
    {
	notify_fail("Something is already tied to the pole.\n");
	return 0;
    }

    tied = rope;
    return 1;
}

untie_object(rope)
{
    if (tied == rope)
    {
	tied = 0;
	return 1;
    }

    return 0;
}

query_tied() { return tied; }

