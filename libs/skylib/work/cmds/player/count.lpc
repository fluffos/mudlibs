/**
 * Count command by Sandoz - 31st July 2001.
 */

inherit COMMAND_BASE;

/** @ignore yes */
string query_cont_short( object thing ) {
    string *sorted_amount_names, size, biggest_size, biggest_plural;
    int biggest_amount, how_many, amount;
    mapping amount_types;

    amount = thing->query_amount();
    amount_types = thing->query_amount_types();

    if( !amount || !sizeof(amount_types) )
        return "";

    sorted_amount_names = sort_array( keys( amount_types ),
        (: $3[$1][0] - $3[$2][0] :), amount_types );

    biggest_size = sorted_amount_names[0];

    foreach( size in sorted_amount_names ) {
        if( amount < amount_types[size][0] )
            break;
        biggest_size = size;
    }

    biggest_amount = amount_types[biggest_size][0];
    biggest_plural = amount_types[biggest_size][1];
    how_many = ( amount + biggest_amount / 2 ) / biggest_amount;

    if( how_many > thing->query_max_seen() )
        return "many "+ biggest_plural+" of "+thing->short();

    switch( how_many ) {
      case 0 :
        return "";
      case 1 :
        return "one "+biggest_size+" of "+thing->short();
      default :
        return query_num( how_many ) +" "+ biggest_plural+" of "+
               thing->short();
    }

} /* query_cont_short() */

/** @ignore yes */
int do_count( string things, object *containers ) {
    object *obs, ob, *tmp, thing;
    string *ret, *cont, c_short;
    mapping found;

    if( sizeof( explode( things, "," ) ) > 1 ) {
        add_failed_mess("You can only $V one type of thing at a time.\n");
        return 0;
    }

    if( strsrch( things, "," ) != -1 ) {
        add_failed_mess("You can only $V things.\n");
        return 0;
    }

    if( things ==  "all" || things[0..6] == "all in ") {
        add_failed_mess("You cannot $V all, please try to $V one type of "
            "thing at a time.\n");
        return 0;
    }

    if( !sizeof( containers ) ) {
        obs = match_objects_for_existence( things, TP );
        obs += match_objects_for_existence( things, deep_inventory(TP) );
    } else {
        obs = match_objects_for_existence( things, containers );
    }

    if( !sizeof(obs) ) {
        if( !sizeof(containers) ) {
            add_failed_mess("You don't appear to have any "+things+".\n");
        } else {
            add_failed_mess("There is no "+things+" in "+
                             query_multiple_short( containers, "the")+".\n");
        }
        return 0;
    }

    if( sizeof( filter( obs, (: $1->query_property("money") :) ) ) ) {
        add_failed_mess("Please use the 'money' command to count your "
            "money.\n");
        return 0;
    }

    found = ([ ]);
    ret = ({ });

    /* sort objects by containers */
    foreach( ob in obs ) {
        if( undefinedp( found[ENV(ob)] ) )
            found[ENV(ob)] = ({ ob });
        else
            found[ENV(ob)] += ({ ob });
    }

    /* make a string for each container */
    foreach( ob in keys(found) ) {
        /* weed out continuous objects */
        if( sizeof( tmp = filter( found[ob], (: $1->query_continuous() :) ) ) ) {
            cont = ({ });
            /* extract continuous objects from the mapping */
            found[ob] -= tmp;
            /* make an array of continuous object shorts */
            foreach( thing in tmp ) {
                if( sizeof( c_short = query_cont_short( thing ) ) ) {
                    cont += ({ c_short });
                }
            }
        }
        
        if( sizeof(cont) && sizeof(found[ob]) ) {
            ret += ({ query_multiple_short(cont)+" and "+
                      query_multiple_short(found[ob])+" in "+
                    ( ob == TP ? "your inventory" : ob->poss_short() ) });
        } else if( !sizeof(cont) ) {
            ret += ({ query_multiple_short(found[ob])+" in "+
                    ( ob == TP ? "your inventory" : ob->poss_short() ) });
        } else {
            ret += ({ query_multiple_short(cont)+" in "+
                    ( ob == TP ? "your inventory" : ob->poss_short() ) });
        }
    }

    add_succeeded_mess(({ "You count "+query_multiple_short(ret)+", with a "
        "total of "+query_num( sizeof( obs ) )+" item"+
        ( sizeof( obs ) > 1 ? "s" : "" )+".\n", "" }), ({ }) );

    return 1;

} /* do_count() */

/** @ignore yes */
mixed query_patterns() {
   return ({ "<string'things'> in <indirect:object:me'container'>",
             (: do_count( $4[0], $1 ) :),
             "<string'things'>",
             (: do_count( $4[0], 0 ) :) });
} /* query_patterns() */
