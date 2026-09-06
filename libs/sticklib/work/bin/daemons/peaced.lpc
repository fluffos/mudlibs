/*
 * /bin/daemons/peaced.c
 *
 * Is there Peace upon the MUD?
 *
 */

#define SAVE_FILE "/data/d/peaced/peace"

status peace;

nomask void
create()
{
    if (!restore_object(SAVE_FILE)) peace = 0;
}

/*
 * Function    : nomask status query_peace()
 * Description : Is there Peace?
 * Arguments   : 
 * Returns     : 1 if there is, 0 if not.
 *
 */
nomask status
query_peace()
{
    return peace;
}

nomask void
set_peace(status p)
{
    /* No change? */
    if (peace == p) return;

    peace = p;

    if (peace)
    {
	filter_objects(users(), "tell_me",
	  "\n\n\tPeace fills the world. Player killing is now prohibited.\n\n");
    }
    else
    {
	filter_objects(users(), "tell_me",
	  "\n\n\tPeace is lifted from the world. Player killing is again possible.\n\n");
    }

    save_object(SAVE_FILE);
}
