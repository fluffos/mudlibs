
inherit COMMAND_BASE;

/** @ignore yes */
private int do_move( object dest ) {
    string tname;
    object env;

    if( !TP || !dest )
        return 0;

    if( env = ENV(TP) ) {
        if( env == dest )
            return notify_fail("You look around and realise you "
                "are already there.\n");
        if( tname = env->query_terrain() )
            TP->set_last_location( ({ tname, env->query_co_ord() }) );
        else
            TP->set_last_location( base_name( env ) );
    }

    TP->move_with_look( dest, TP->query_mmsgin(), TP->query_mmsgout() );
    return 1;

} /* do_move() */

/** @ignore yes */
int cmd( string str ) {
    object who, dest, *obs;
    string *names, nick;

    if( !str )
        return notify_fail("Teleport where?\n");

    nick = TP->expand_nickname(str);
    who = find_living(nick);

    if( !who && objectp( dest = TP->get_obvar(str) ) )
        return do_move( dest );

    if( who ) {
        if( who->query_property("no_goto") ) {
            add_failed_mess("It appears $I doesn't want people to randomly "
                "goto "+who->HIM+".\n", ({ who }) );
            return 0;
        }

        if( dest = ENV(who) )
            return do_move( dest );

        if( !clonep(who) ) {
            obs = filter( children( file_name(who) ) - ({ who }),
                        (: ENV($1) && $1->query_name() == $2 :), str );
            if( sizeof(obs) ) {
                dest = ENV( obs[0] );
                return do_move( dest );
            }
        }

        return notify_fail( CAP(nick)+" is not standing in a location.\n");

    } else {
        if( !dest = find_object(str) ) {
            if( sizeof( names = TP->get_cfiles(str) ) ) {
                str = names[0];
                catch( dest = load_object(str) );
            } else
                return notify_fail("No such room.\n");
        }

        if( !dest )
            return notify_fail("Failed to load "+str+"\n");

        if( !dest->query_property("location") && ( !( dest = ENV(dest) ) ||
            !dest->query_property("location") ) )
            return notify_fail("Not a room: "+str+"\n");

        return do_move( dest );

    }

} /* cmd() */

/** @ignore yes */
int do_allow() {
    if( !TP->query_property("no_goto") ) {
        write("You are already allowing people to goto you.\n");
        return 1;
    }

    TP->remove_property("no_goto");
    write("You are now allowing people to goto you.\n");
    return 1;

} /* do_allow() */

/** @ignore yes */
int do_disallow() {
    if( TP->query_property("no_goto") ) {
        write("You are already not allowing people to goto you.\n");
        return 1;
    }

    TP->add_property("no_goto", 1 );
    write("You are no longer allowing people to goto you.\n");
    return 1;

} /* do_disallow() */

/** @ignore yes */
mixed query_patterns() {
    return ({
        "disallow", (: do_disallow() :),
        "allow", (: do_allow() :),
        "<string'room|person'>", (: cmd($4[0]) :),
    });
} /* query_patterns() */
