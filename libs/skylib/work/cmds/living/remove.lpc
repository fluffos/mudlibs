/**
 * This command makes the player to remove stuff they're wearing.
 * Partly rewritten in Dec 2001 by Sandoz.
 */

inherit COMMAND_BASE;

/** @ignore yes */
mapping add_to_failed( mapping failed, string word, object thing ) {
    if( !failed[word] )
        failed += ([ word : ({ thing }) ]);
    else if( member_array( thing, failed[word] ) == -1 )
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
mapping alt_remove( object player, object *things, object ob, mapping failed,
                    int stage ) {
    string result;
    object *obs, tmp;

    if( stage++ > 2 )
        return failed;

    if( sizeof( obs = CLOTHING_H->can_wear_or_remove( ob, TP, 1 ) ) ) {
        if( sizeof( obs = CLOTHING_H->can_wear_or_remove( ob, player, 1 ) ) ) {
            obs = sort_clothes( obs );
            foreach( tmp in obs )
              failed = alt_remove( player, things, tmp, failed, stage );
            stage++;
        }
        if( result = CLOTHING_H->can_wear_or_remove( ob, player ) )
            return add_to_failed( failed, result, ob );
    }

    if( player->remove_armour(ob) )
        return failed;

    if( member_array( ob, things ) != -1 &&
        member_array( ob, failed["OKAY"] ) == -1 )
        return add_to_failed( failed, "OKAY", ob );

    return add_to_failed( failed, "temp remove", ob );

} /* alt_remove() */

/** @ignore yes */
int cmd( object *things ) {
    string result, stuff;
    object *okay, ob, *offenders, offender;
    mapping failed;

    failed = ([ "OKAY" : ({ }) ]);

    // Sort the things array in clothing order.
    // This should make remove all work.
    things = sort_clothes( things );
    foreach( ob in things ) {
      if( member_array( ob, TP->query_wearing() ) == -1 ) {
          failed = add_to_failed( failed, "not wearing", ob );
          continue;
      }
      if( sizeof( offenders = CLOTHING_H->can_wear_or_remove( ob, TP, 1 ) ) ) {
          offenders = sort_clothes( offenders );
          foreach( offender in offenders )
              failed = alt_remove( TP, things, offender, failed, 0 );
      }
      if( result = CLOTHING_H->can_wear_or_remove( ob, TP ) ) {
          failed = add_to_failed( failed, result, ob );
          continue;
      }
      if( TP->remove_armour(ob) ) {
          failed = add_to_failed( failed, "cannot remove", ob );
          continue;
      }
      failed["OKAY"] += ({ ob });
    }

    result = "";
    okay = failed["OKAY"];
    map_delete( failed, "OKAY");

    if( sizeof(failed) ) {
        foreach( string key, offenders in failed ) {
          stuff = query_multiple_short( offenders, "the" );
          switch( key ) {
            case "not wearing" :
              if( !sizeof(okay) )
                  result += "You are not wearing "+ stuff +".\n";
            break;
            case "cannot remove" :
              result += "You cannot remove "+ stuff +".\n";
            break;
            case "temp remove" :
              foreach( offender in offenders )
                TP->wear_armour( offender, 0 );
            break;
            default :
              result += "You cannot remove "+ stuff +" "+ key +".\n";
          }
        }
    }

    if( !sizeof(okay) ) {
        add_failed_mess(result);
        return 0;
    }

    if( sizeof( failed["temp remove"] ) ) {
        add_succeeded_mess( ({
            result+"You temporarily remove "+query_multiple_short(
            failed["temp remove"] )+" to remove $I.\n",
            "$N remove$s $I.\n"
            }), okay );
        return 1;
    }

    add_succeeded_mess( ({
        result+"You remove $I.\n", "$N remove$s $I.\n"
        }), okay );
    return 1;

} /* cmd() */

/** @ignore yes */
mixed query_patterns() {
    return ({ "<indirect:object:me>", (: cmd($1) :) });
} /* query_patterns() */
