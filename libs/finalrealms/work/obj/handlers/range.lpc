/* A library of routines that ranged weapons/spells
 * should use.   By Wonderflug, Dec 95.
 */

/* prototypes */
int check_in_range(object me, object him, int valid_range);
int check_line_of_sight(object me, object him, int max_dist );
int* calc_deltas(object me, object him);
int* calc_directional_deltas(object me, object him);
int calc_distance(object me, object him);

// I hate this, but needed (sorry) - Radix July 1996
object *living_in_range(object me, int i);
/* end prototypes */

object *living_in_range(object me, int r)
{
    object *obs = livings();
    int i;
    obs -= ({ 0 });
    if(!environment(me)) return ({ });
    for(i=0; i<sizeof(obs); i++)
    {
	if(!environment(obs[i]) || !check_line_of_sight(me, obs[i], r))
	    obs = delete(obs,i,1);
    }
    return obs;
}

int check_in_range(object me, object him, int valid_range)
{
    int* his;
    int* mine;
    int dx, dy, dz, dtotal;

    if ( !me || !him )
	return 0;

    return ( calc_distance(me,him) <= valid_range );
}

int check_line_of_sight(object me, object him, int max_dist)
{
    int* delta;
    int count;
    string the_dir;
    int dist;
    int i, j;
    string* paths;
    object next_room;


    if ( !me || !him )
	return 0;
    if(!environment(him))
    {
	tell_object(me,"A haze obscures your aim.\n");
	return 0;
    }

    if ( environment(me) == environment(him) )
	return 1;


    delta = calc_directional_deltas( me,  him);

    count = 0;
    if ( delta[0] != 0 ) count++;
    if ( delta[1] != 0 ) count++;
    if ( delta[2] != 0 ) count++;

    if ( count == 0 )
	return 0;

    if ( count > 1 )
    {
	/* now check for diagonal directions */
	if ( delta[0] == 0 || delta[1] == 0 )
	    return 0;

	if ( delta[0] != delta[1] && delta[0] != -delta[1] )
	    return 0;

	/* now we know it must be a diagonal direction. */
	if ( delta[0] > 0 )
	{
	    if ( delta[1] > 0 )
	    {
		the_dir = "northeast";
		dist = delta[0];
	    }
	    else
	    {
		the_dir = "northwest";
		dist = delta[0];
	    }
	}
	else
	{
	    if ( delta[1] > 0 )
	    {
		the_dir = "southeast";
		dist = delta[0];
	    }
	    else
	    {
		the_dir = "southwest";
		dist = delta[1];
	    }
	}   /* else */
    }  /* if (the big messy one) */
    else
    {

	/* believe it or not, now we know that there's only one
	 * delta that is NOT zero, ie, we now that it is straight
	 * one direction from me to him.  Now we find out that direction
	 * and get the absolute distance.
	 * And yes, these if's are supposed to do assignments.
	 */
	the_dir = "none";
	if ( delta[0] > 0 && dist = delta[0] )
	    the_dir = "north";
	else if ( delta[0] < 0 && dist = -delta[0] )
	    the_dir = "south";
	else if ( delta[1] > 0 && dist = delta[1] )
	    the_dir = "east";
	else if ( delta[1] < 0 && dist = - delta[1] )
	    the_dir = "west";
	else if ( delta[2] > 0 && dist = delta[2] )
	    the_dir = "up";
	else if ( delta[2] < 0 && dist = -delta[2] )
	    the_dir = "down";
    }  /* else  (from the big if) */

    if ( the_dir == "none" || dist > max_dist )
	return 0;


    next_room = environment(me);
    for ( i=0; i < dist; i++ )
    {
	paths = next_room->query_dest_dir();
	if ( (j=member_array( the_dir, paths )) == -1 )
	    return 0;       /* no exit in the_dir */
	/** umm this obviously isnt used... Raskolnikov **/
	/* check door is open */
	/*
	    if ( next_room->query_ex_type(the_dir) == "door" )
	    {
	    }
	*/
	next_room = load_object(paths[j+1]);
    }

    /* all clear */
    return 1;
}


int* calc_deltas(object me, object him)
{
    int *his, *mine, dx, dy, dz, dtotal;

    mine = environment(me)->query_co_ord();
    his = environment(him)->query_co_ord();


    if ( sizeof(mine) != 3 || sizeof(his) != 3 )
	return 0;

    dx = his[0] - mine[0];
    dy = his[1] - mine[1];
    dz = his[2] - mine[2];

    dx = ( dx < 0 ? -dx : dx );
    dy = ( dy < 0 ? -dy : dy );
    dz = ( dz < 0 ? -dz : dz );

    return ({ dx, dy, dz });
}

int* calc_directional_deltas(object me, object him)
{
    int *his, *mine, dx, dy, dz, dtotal;

    mine = environment(me)->query_co_ord();
    his = environment(him)->query_co_ord();


    if ( sizeof(mine) != 3 || sizeof(his) != 3 )
	return 0;

    dx = his[0] - mine[0];
    dy = his[1] - mine[1];
    dz = his[2] - mine[2];

    return ({ dx, dy, dz });
}

int calc_distance(object me, object him)
{
    int* deltas;

    if ( !me || !him )
	return 10000;

    deltas = calc_deltas(me, him);

    if(sizeof(deltas) >= 3)
	return ( deltas[0] + deltas[1] + deltas[2] );
    return 10000;
}

mixed get_direction_delta(object me, object him)
{
    int* delta;
    int count;
    string the_dir;
    int dist;
    int i, j;
    string* paths;
    object next_room;


    if ( !me || !him )
	return ({ "none",0 });

    if ( environment(me) == environment(him) )
	return ({ "same", 0 });


    delta = calc_directional_deltas( me,  him);

    count = 0;
    if ( delta[0] != 0 ) count++;
    if ( delta[1] != 0 ) count++;
    if ( delta[2] != 0 ) count++;

    if ( count == 0 )
	return ({ "none", 0 });

    if ( count > 1 )
    {
	if ( delta[0] == 0 || delta[1] == 0 )
	    return ({ "none", 0 });

	if ( delta[0] != delta[1] && delta[0] != -delta[1] )
	    return ({ "none", 0 });

	if ( delta[0] > 0 )
	{
	    if ( delta[1] > 0 )
	    {
		the_dir = "northeast";
		dist = delta[0];
	    }
	    else
	    {
		the_dir = "northwest";
		dist = delta[0];
	    }
	}
	else
	{
	    if ( delta[1] > 0 )
	    {
		the_dir = "southeast";
		dist = delta[0];
	    }
	    else
	    {
		the_dir = "southwest";
		dist = delta[1];
	    }
	}  
    }  
    else
    {
	the_dir = "none";
	if ( delta[0] > 0 && dist = delta[0] )
	    the_dir = "north";
	else if ( delta[0] < 0 && dist = -delta[0] )
	    the_dir = "south";
	else if ( delta[1] > 0 && dist = delta[1] )
	    the_dir = "east";
	else if ( delta[1] < 0 && dist = - delta[1] )
	    the_dir = "west";
	else if ( delta[2] > 0 && dist = delta[2] )
	    the_dir = "up";
	else if ( delta[2] < 0 && dist = -delta[2] )
	    the_dir = "down";
    }  

    if ( the_dir == "none" )
	return ({ "none", 0 });


    next_room = environment(me);
    for ( i=0; i < dist; i++ )
    {
	paths = next_room->query_dest_dir();

	if ( (j=member_array( the_dir, paths )) == -1 )
	    return ({ "none", 0 });       

	next_room = load_object(paths[j+1]);
    }

    return ({ the_dir, dist });
}

