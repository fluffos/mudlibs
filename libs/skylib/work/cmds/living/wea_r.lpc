/**
 * This command lets you wear stuff.
 * Rewritten to allow wear things straight
 * to lower layers in Dec 2001 by Sandoz.
 */

inherit COMMAND_BASE;

/** @ignore yes */
mapping add_to_failed( mapping failed, string word, object thing ) {
    if( !failed[word] )
        failed += ([ word : ({ thing }) ]);
    else
        failed[word] += ({ thing });
    return failed;
} /* add_to_failed() */

/** @ignore yes */
object *sort_clothes( object *obs ) {
    return sort_array( obs, (:
               CLOTHING_H->query_clothing_depth( $1->query_type() ) -
               CLOTHING_H->query_clothing_depth( $2->query_type() ) :) );
} /* sort_clothes() */

/** @ignore yes */
mapping alt_remove( object *things, object ob, mapping failed, int stage ) {
    string ret;
    object *obs, tmp;

    if( stage++ > 4 )
        return failed;

    if( sizeof( obs = CLOTHING_H->can_wear_or_remove( ob, TP, 1 ) ) ) {
        if( sizeof( obs = CLOTHING_H->can_wear_or_remove( ob, TP, 1 ) ) ) {
            obs = sort_clothes( obs );
            foreach( tmp in obs )
                failed = alt_remove( things, tmp, failed, stage );
            stage++;
        }

        if( ret = CLOTHING_H->can_wear_or_remove( ob, TP ) )
            return add_to_failed( failed, ret, ob );
    }

    if( TP->remove_armour(ob) )
        return failed;

    if( member_array( ob, things ) != -1 &&
        member_array( ob, failed["OKAY"] ) == -1 )
        return add_to_failed( failed, "OKAY", ob );

    return add_to_failed( failed, "temp remove", ob );

} /* alt_remove() */

/** @ignore yes */
int cmd( object *things ) {
    string ret, stuff;
    object *okay, ob, *offenders, offender, *wearing;
    mapping failed;

    failed = ([ "OKAY" : ({ }) ]);

    things = sort_array( things, (:
               CLOTHING_H->query_clothing_depth( $2->query_type() ) -
               CLOTHING_H->query_clothing_depth( $1->query_type() ) :) );

    wearing = TP->query_wearing();

    foreach( ob in things ) {
        if( member_array( ob, wearing ) != -1 ) {
            failed = add_to_failed( failed, "already wearing", ob );
            continue;
        }
    }

    if( sizeof( failed["already wearing"] ) )
        things -= failed["already wearing"];

    foreach( ob in things ) {
        if( !ob->query_wearable() || ob->cannot_be_worn() ) {
            failed = add_to_failed( failed, "cannot wear", ob );
            continue;
        }

        if( ENV(ob) != TP ) {
            failed = add_to_failed( failed, "not in me", ob );
            continue;
        }

        if( member_array( ob, wearing ) != -1 ) {
            failed = add_to_failed( failed, "already wearing", ob );
            continue;
        }

        offenders = CLOTHING_H->can_wear_or_remove( ob, TP, 1 );

        if( sizeof( offenders ) ) {
            offenders = sort_clothes( offenders );
            foreach( offender in offenders )
                failed = alt_remove( things, offender, failed, 0 );
        }

        if( ret = CLOTHING_H->can_wear_or_remove( ob, TP ) ) {
            failed = add_to_failed( failed, ret, ob );
            continue;
        }

        if( ret = TP->wear_armour( ob, 0 ) ) {
            failed = add_to_failed( failed, ret, ob );
            continue;
        }

        failed["OKAY"] += ({ ob });

    }

    ret = "";
    okay = failed["OKAY"];
    map_delete( failed, "OKAY");

    if( sizeof(failed) ) {
        foreach( string key, offenders in failed ) {
          stuff = query_multiple_short( offenders, "the" );
          switch( key ) {
            case "not in me" :
              if( !sizeof(okay) )
                  ret += "You cannot wear "+stuff+", because "+
                      ( !query_group( offenders ) ? "it is" : "they are")+
                      " not in your inventory.\n";
            break;
            case "cannot wear" :
              if( !sizeof(okay) )
                  ret += "$C$"+stuff+" cannot be worn.\n";
            break;
            case "already wearing" :
              ret += "You are already wearing "+ stuff +".\n";
            break;
            case "already holding" :
              ret += "You cannot wear "+ stuff +" as you do not "
                     "have enough free limbs.\n";
            break;
            case "oh dear" :
              ret += "Something has gone wrong and you can't wear "+
                     stuff + ", please contact a creator immediately.\n";
            break;
            case "temp remove" :
              foreach( offender in offenders )
                  TP->wear_armour( offender, 0 );
            break;
            default :
              ret += "You cannot wear "+ stuff +" "+ key +".\n";
          }
        }
    }

    if( !sizeof(okay) ) {
        add_failed_mess(ret);
        return 0;
    }

    if( sizeof( failed["temp remove"] ) ) {
        add_succeeded_mess( ({ ret + "You temporarily remove "+
            query_multiple_short( failed["temp remove"] )+" to wear $I.\n",
            "$N wear$s $I.\n"}), okay );
        return 1;
    }

    add_succeeded_mess( ({ ret+"You wear $I.\n", "$N wear$s $I.\n"}), okay );
    return 1;

} /* cmd() */

/** @ignore yes */
mixed query_patterns() { return ({ "<indirect:object:me>", (: cmd($1) :) }); }
