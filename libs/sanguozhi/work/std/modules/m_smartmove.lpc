/* Do not remove the headers from this file! see /USAGE for more info. */

/*
** smartmove.c
**
** A smarter movement system for some objects.  It handles movement from
** room to room.
*/

#include <move.h>
#include <playerflags.h>
#include <hooks.h>
#include <size.h>
#include <daemons.h>

varargs mixed move(mixed dest, string where);
string *get_player_message(string message, mixed arg);
int test_flag(int which);
string * action(object * x, string s);
void simple_action(string s);


private nomask int move_me_there(string dest, string arg, object last_loc)
{
    object env;
    object d;
    mixed  r;
    string txt;
    string *msgs;

    if ( (r = move(dest)) != MOVE_OK)
    {
        if(!stringp(r)) {
            if(r == MOVE_NO_ERROR) 
                return 1;

            write("你停留在原地，驻足不前。\n");
            return 0;
        }

        switch(r) {
        case MOVE_NO_DEST:
            write("你被阻挡住了，这个方向没有路。\n");
            return 0;
        case MOVE_NO_ROOM:
            d = load_object(dest);
            if(d->query_max_capacity()-d->query_capacity()-VERY_LARGE < 0) {
                if(sizeof(filter(all_inventory(d),(:$1->is_living():)))) {
                    write("那里已经有东西，容不下你的身体了。");
                } else {
                    write("你去不成那里。\n");
                }
            } else {
                write("你的负荷超重了，哪儿也去不成。\n");
            }
            return 0;
        default:
            write("你还留在原地。\n");
            return 0;
        }
    }

    //### bogus place to show the path... probably should be handled in
    //### another way
    if ( test_flag(F_DISPLAY_PATH) )
    {
        printf("[ %s ]\n", file_name(environment(this_body())));
    }

    if ( !arg )
        arg = "某处";
    else arg = DIRECTION_D->cdir(arg);

    env = environment();

    txt = last_loc->query_exit_msg(arg);

    // This should be done better when smartmove gets cleaned up.  Right now
    // Furniture uses it, and anything else inheriting NON_ROOM probably does.
    if(!txt)
        txt = environment()->handle_exit_msgs(last_loc);
    if ( !txt )
    {
        msgs = get_player_message("leave", arg);
        tell_from_inside(last_loc, msgs[1], 0, ({ env }));
    }
    else
    {
        msgs = action(({this_object()}), txt);
        tell_from_outside(this_object(), msgs[0]);
        tell_from_inside(last_loc, msgs[1], 0, ({ env }));
    }


    //###there is a note in room.c about this being bogus
    txt = env->query_enter_msg(arg);
    if ( !txt )
    {
        msgs = get_player_message("enter", arg);
        tell_from_outside(env, msgs[1], 0, ({ this_object() }));
    }
    else
    {
        simple_action(txt);
    }

    return r == MOVE_OK;
}

//:FUNCTION notify_move
//Basically do a this_body()->force_look().
//Seperated out so vehicles could change this
//without having to override the move_to() function.

void notify_move()
{
      this_body()->force_look();
}


//:FUNCTION move_to
//Move the object to a new location.  Returns 1 if the move was successful,
//0 otherwise.  The first arg is a filename, the second is the direction
//that caused the movement to that destination.

//:HOOK person_left
//Called when a person successfully leaves a room in a certain direction
//(called by the room).  The return value is ignored.  The person moving
//is given by this_body().  The direction is passed as an argument.
int move_to(string dest, mixed dir)
{
    mixed ret;
    object where = environment();

    dest = evaluate(dest);
    if (move_me_there(dest, dir, where)) {
        where->call_hooks("person_left", HOOK_IGNORE, 0, dir);

    }

    if ( where != environment() )
    {
        this_object()->notify_move();
        return 1;
    }
    return 0;
}

varargs mixed call_hooks();

int go_somewhere(string arg)
{
    object env = environment( this_object());
    string value = env->query_exit_value(arg);


    // This should have been trapped already, but just in case:
    if( !value )
        return call_other( env, "do_go_" + arg );
    if (value[0] == '#') {
        write(value[1..]);
        return 0;
    }

    if (env->call_hooks("block_" + arg, HOOK_LOR, 0, arg)
      || env->call_hooks("block_all", HOOK_LOR, 0, arg))
        return 0;

    return move_to(value, arg);
}


void do_go_somewhere( string arg )
{
    int ret = 0;
    object *inv;
    object env = environment( this_object());
    int i;
    // allowed by the room itself; some sort of 'special' exit
    if( function_exists( "do_go_" + arg, env ))
        ret = call_other(env, "do_go_" + arg);
    if(!ret)
        ret=go_somewhere( arg );
    if(ret)
    {
	inv = all_inventory( env );
		for ( i =0; i< sizeof(inv);i++)
    		{
        		if ( inv[i]->query("leader") )
        		{
            			if (inv[i]->query("leader") == this_object())
            			{
					if((environment(this_object())==this_object()->query_room())
						&&(!this_object()->query_room()->is_troop())) {
				                // set_this_player(inv[i]); // set_this_player() unavailable in this driver build (no NO_ADD_ACTION) -- no-op'd, this_player() is whatever it naturally is here
				                this_user()->do_go_somewhere(arg);
					}
				}
        		}
    		 }
/*       { use hook in the char_d to deal with the room problem.
          string p_id,p_room;
          p_id=this_object()->query_id()[0];
          p_room=file_name(environment(this_object()));
          CHAR_D->set_char(p_id,"room",p_room);
       }
*/
    }
    return;
}
